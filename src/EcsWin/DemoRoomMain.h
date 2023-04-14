#pragma once


NAMESPACE_TOPSIDE_BEGIN


// Updates, renders, and presents holographic content using Direct3D.

	
class DemoRoomMain
{
public:
    DemoRoomMain();
    ~DemoRoomMain();

    // Sets the holographic space. This is our closest analogue to setting a new window
    // for the app.
    void SetHolographicSpace(
        winrt::Windows::Graphics::Holographic::HolographicSpace const& holographicSpace);

    // Starts the holographic frame and updates the content.
    void Update();

    // Handle saving and loading of app state owned by AppMain.
    void SaveAppState();
    void LoadAppState();

private:
    std::unique_ptr<Engine>        m_engine;

    // Cached pointer to device resources.
    std::shared_ptr<DX::DeviceResources> m_deviceResources;

    // Render loop timer.
    DX::StepTimer                        m_timer;
};


NAMESPACE_TOPSIDE_END
