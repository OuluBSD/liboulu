#pragma once


NAMESPACE_SERIAL_BEGIN


////////////////////////////////////////////////////////////////////////////////
// QuadRenderer
// Responsible for rendering quads in a 3D scene provided a transform matrix and texture
class QuadRenderer
{
public:
    QuadRenderer(std::shared_ptr<DeviceResources> deviceResources);

    void SetViewProjection(
        const winrt::Windows::Foundation::Numerics::float4x4& worldToViewLeft,
        const winrt::Windows::Foundation::Numerics::float4x4& viewToProjLeft,
        const winrt::Windows::Foundation::Numerics::float4x4& worldToViewRight,
        const winrt::Windows::Foundation::Numerics::float4x4& viewToProjRight);

    void CreateDeviceDependentResources();
    void ReleaseDeviceDependentResources();

    void Bind();
    void Render(
        winrt::Windows::Foundation::Numerics::float4x4 const& matrix,
        ID3D11ShaderResourceView* texture);
    void Unbind();

private:
    // Cached pointer to device resources.
    std::shared_ptr<DeviceResources> m_deviceResources;

    // Direct3D resources for quad geometry.
    Microsoft::WRL::ComPtr<ID3D11InputLayout>           m_inputLayout;
    Microsoft::WRL::ComPtr<ID3D11Buffer>                m_vertexBuffer;
    Microsoft::WRL::ComPtr<ID3D11Buffer>                m_indexBuffer;
    Microsoft::WRL::ComPtr<ID3D11VertexShader>          m_vertexShader;
    Microsoft::WRL::ComPtr<ID3D11GeometryShader>        m_geometryShader;
    Microsoft::WRL::ComPtr<ID3D11PixelShader>           m_pixelShaderRGB;
    Microsoft::WRL::ComPtr<ID3D11Buffer>                m_modelConstantBuffer;
    Microsoft::WRL::ComPtr<ID3D11Buffer>                m_renderingConstantBuffer;

    // Direct3D resources for the default texture.
    Microsoft::WRL::ComPtr<ID3D11SamplerState>          m_samplerState;

    // System resources for quad geometry.
    uint32_t                                            m_indexCount = 0;
};


NAMESPACE_SERIAL_END
