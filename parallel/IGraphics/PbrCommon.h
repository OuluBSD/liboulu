//
// Shared data types and functions used throughout the Pbr rendering library.
//

#pragma once


NAMESPACE_PARALLEL_BEGIN


namespace Pbr
{
namespace Internal
{
    void ThrowIfFailed(dword hr);
}


template <class Gfx> struct PrimitiveT;
template <class Gfx> struct ResourcesT;
template <class Gfx> struct ModelT;


using NodeIndex = uint16; // This type must align with the type used in the Pbr shaders.

constexpr Pbr::NodeIndex root_node_idx = 0;

// Vertex structure used by the PBR shaders.
struct Vertex
{
    vec3			position;
    vec3			normal;
    vec4			tangent;
    vec2			tex_coord;
    NodeIndex		mdl_transform_idx; // Index into the node transforms

    //static const D3D11_INPUT_ELEMENT_DESC vtx_desc[5];
};

struct PrimitiveBuilder
{
    Vector<Pbr::Vertex>		vertices;
    Vector<uint32>			indices;

    PrimitiveBuilder& AddSphere(float diameter, uint32 tessellation, Pbr::NodeIndex transform_idx = Pbr::root_node_idx);
    PrimitiveBuilder& AddCube(float side_length, Pbr::NodeIndex transform_idx = Pbr::root_node_idx);
};

/*namespace Texture
{
    NativeShaderResourcesRef LoadImage(NativeDeviceRef device, const byte* file_data, uint32 file_size);
    NativeShaderResourcesRef CreateFlatCubeTexture(NativeDeviceRef device, const vec4& color, DXGI_FORMAT format = DXGI_FORMAT_R8G8B8A8_UNORM);
    NativeShaderResourcesRef CreateTexture(NativeDeviceRef device, const byte* rgba, uint32 size, int width, int height, DXGI_FORMAT format);
    NativeSamplerStateRef CreateSampler(NativeDeviceRef device, D3D11_TEXTURE_ADDRESS_MODE addressMode = D3D11_TEXTURE_ADDRESS_CLAMP);
}*/

// Catch changes to a value of type T for lazy sync with DirectX.
template <typename T>
class TrackChanges
{
public:
    TrackChanges() { change_count = 0; }
    TrackChanges(TrackChanges<T>&& o) : value(std::move(o.value)) { change_count = 0;  }
    TrackChanges(const TrackChanges<T>& o) : value(o.Get()) { change_count = 0;  }

    TrackChanges<T>& operator=(TrackChanges<T>&& o)
    {
        ++change_count;
        value = std::move(o.value);
        return *this;
    }

    TrackChanges<T>& operator=(const TrackChanges<T>& o)
    {
        ++change_count;
        value = o.value;
        return *this;
    }

    template <typename Func>
    void Set(Func func)
    {
        ++change_count;
        func(value);
    }

    bool UpdateChangeCountBookmark(uint32* change_count_bookmark) const
    {
        uint32 new_value = *change_count_bookmark;
        uint32 prev = change_count.exchange(new_value);
        return prev != new_value;
    }

    const T& Get() const { return value; }

private:
    T value;
    mutable AtomicInt change_count;
};

}

NAMESPACE_PARALLEL_END

