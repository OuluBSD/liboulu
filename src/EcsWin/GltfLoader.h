#pragma once

EXTERN_C {
interface ID3D11Device;
interface ID3D11DeviceContext3;
}

NAMESPACE_ECS_BEGIN



	
// Creates a Pbr Model from tinygltf model with the specified root transform.
std::shared_ptr<Pbr::Model> FromGltfObject(
    const Pbr::Resources& pbrResources,
    const tinygltf::Model& gltfModel,
    DirectX::CXMMATRIX rootTransform);

// Creates a Pbr Model from tinygltf model.
inline std::shared_ptr<Pbr::Model> FromGltfObject(
    const Pbr::Resources& pbrResources,
    const tinygltf::Model& gltfModel)
{
    return FromGltfObject(pbrResources, gltfModel, DirectX::XMMatrixIdentity());
}

// Creates a Pbr Model from glTF 2.0 GLB file content with the specified root transform.
std::shared_ptr<Pbr::Model> FromGltfBinary(
    const Pbr::Resources& pbrResources,
    _In_reads_bytes_(bufferBytes) const byte* buffer,
    uint32_t bufferBytes,
    DirectX::CXMMATRIX rootTransform);

// Creates a Pbr Model from glTF 2.0 GLB file content.
inline std::shared_ptr<Pbr::Model> FromGltfBinary(
    const Pbr::Resources& pbrResources,
    _In_reads_bytes_(bufferBytes) const byte* buffer,
    uint32_t bufferBytes)
{
    return FromGltfBinary(pbrResources, buffer, bufferBytes, DirectX::XMMatrixIdentity());
}


NAMESPACE_ECS_END
