#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent : public juce::Component, public juce::Slider::Listener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint(juce::Graphics&) override;
    void resized() override;

    void sliderValueChanged(juce::Slider* slider) override { // writing an abstract function // called when slider value is changed with a pointer to the slider
        // checks which slider value is changed and runs code for the corresponding slider
        if (slider == &frequencySlider) {
            durationSlider.setValue(1.0 / frequencySlider.getValue());
        }
        else if (slider == &durationSlider) {
            frequencySlider.setValue(1.0 / durationSlider.getValue());
        }
    }

private:
    //==============================================================================
    // Your private member variables go here...


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)

    juce::Slider frequencySlider;
    juce::Slider durationSlider;
};
