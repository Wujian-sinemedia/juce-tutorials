#pragma once

#include <JuceHeader.h>

using namespace juce;

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::AudioAppComponent, public Slider::Listener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;

    void sliderValueChanged(Slider* slider) override {
        if (slider == &frequencySlider) {
            frequency = (double) frequencySlider.getValue();
            phase = 0;
            amplitude = 0.25;
            waveTableSize = 1024;

            increment = frequency * waveTableSize / sr;

            for (int i = 0; i < waveTableSize; i++) {
                waveTable.insert(i, sin(2.0 * double_Pi * i / waveTableSize));
            }
        }

        if (slider == &amplitudeSlider) {
            amplitude = (double) amplitudeSlider.getValue();
        }
    }

private:
    Array<float> waveTable;
    double waveTableSize;
    double frequency;
    double phase;
    double amplitude;
    double increment;
    double sr;

    Slider frequencySlider;
    Slider amplitudeSlider;

    LookAndFeel_V4 lookAndFeel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)

};
