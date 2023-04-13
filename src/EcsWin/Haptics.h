#pragma once

NAMESPACE_TOPSIDE_BEGIN


namespace SpatialInputUtilities::Haptics
{
	
// Creates a continuous haptic feedback on the given SpatialInteractionSource.
static inline void SendContinuousBuzzForDuration(
    winrt::Windows::UI::Input::Spatial::SpatialInteractionSource const& source,
    winrt::Windows::Foundation::TimeSpan const& playDuration,
    float intensity = 1.0f)
{
    using namespace winrt::Windows::Devices::Haptics;
    using namespace winrt::Windows::Foundation::Collections;
    using namespace winrt::Windows::UI::Input::Spatial;

    if (const SpatialInteractionController controller = source.Controller())
    {
        if (const SimpleHapticsController hapticsController = controller.SimpleHapticsController())
        {
            // Find the continuous buzz haptic feedback.
            static const uint16_t ContinuousBuzzWaveform = winrt::Windows::Devices::Haptics::KnownSimpleHapticsControllerWaveforms::BuzzContinuous();
            const IVectorView<SimpleHapticsControllerFeedback> supportedFeedback = hapticsController.SupportedFeedback();
            auto continuousBuzz = std::find_if(
                begin(supportedFeedback),
                end(supportedFeedback),
                [](SimpleHapticsControllerFeedback const& sf) { return sf.Waveform() == ContinuousBuzzWaveform; });

            // Apply controller haptics
            if (continuousBuzz != end(supportedFeedback))
            {
                hapticsController.SendHapticFeedbackForDuration(*continuousBuzz, intensity, playDuration);
            }
        }
    }
}

}


NAMESPACE_TOPSIDE_END
