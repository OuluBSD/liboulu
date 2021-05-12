#pragma once


NAMESPACE_OULU_BEGIN

	
////////////////////////////////////////////////////////////////////////////////
// TextRenderer
// Responsible for rendering text onto a 2D texture provided a string
class TextRenderer
{
public:
    TextRenderer(
        Shared<DX::DeviceResources> deviceResources,
        uint32_t textureWidth,
        uint32_t textureHeight,
        float fontSize);

    ~TextRenderer();

    void RenderTextOffscreen(const String& str);

    void CreateDeviceDependentResources();
    void ReleaseDeviceDependentResources();

    ID3D11ShaderResourceView* GetTexture() const { return m_shaderResourceView.Get(); };
    ID3D11SamplerState*       GetSampler() const { return m_pointSampler.Get(); };

private:
    // Cached pointer to device resources.
    Shared<DX::DeviceResources> dev_res;

    // Direct3D resources for rendering text to an off-screen render target.
    Microsoft::WRL::ComPtr<ID3D11Texture2D>             m_texture;
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>    m_shaderResourceView;
    Microsoft::WRL::ComPtr<ID3D11SamplerState>          m_pointSampler;
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView>      m_renderTargetView;
    Microsoft::WRL::ComPtr<ID2D1RenderTarget>           m_d2dRenderTarget;
    Microsoft::WRL::ComPtr<ID2D1SolidColorBrush>        m_whiteBrush;
    Microsoft::WRL::ComPtr<IDWriteTextFormat>           m_textFormat;

    // CPU-based variables for configuring the offscreen render target.
    const uint32_t m_textureWidth;
    const uint32_t m_textureHeight;
    const float m_fontSize;
};


NAMESPACE_OULU_END

