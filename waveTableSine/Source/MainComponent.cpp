#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
    setSize (600, 200);

    frequencySlider.setSliderStyle(Slider::Rotary);
    frequencySlider.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
    frequencySlider.setRange(50.0, 5000.0, 0.1);
    frequencySlider.setTextValueSuffix(" Hz");
    frequencySlider.setValue(440.0);
    frequencySlider.setSkewFactorFromMidPoint(440.0);
    frequencySlider.addListener(this);
    addAndMakeVisible(frequencySlider);

    amplitudeSlider.setSliderStyle(Slider::Rotary);
    amplitudeSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
    amplitudeSlider.setRange(0.0, 1,0);
    amplitudeSlider.setValue(0.25);
    amplitudeSlider.addListener(this);
    addAndMakeVisible(amplitudeSlider);

    lookAndFeel.setColour(juce::Slider::thumbColourId, juce::Colours::chartreuse);
    lookAndFeel.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::chartreuse);
    lookAndFeel.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::black);

    frequencySlider.setLookAndFeel(&lookAndFeel);
    amplitudeSlider.setLookAndFeel(&lookAndFeel);

    // Some platforms require permissions to open input channels so request that here
    if (juce::RuntimePermissions::isRequired (juce::RuntimePermissions::recordAudio)
        && ! juce::RuntimePermissions::isGranted (juce::RuntimePermissions::recordAudio))
    {
        juce::RuntimePermissions::request (juce::RuntimePermissions::recordAudio,
                                           [&] (bool granted) { setAudioChannels (granted ? 2 : 0, 2); });
    }
    else
    {
        // Specify the number of input and output channels that we want to open
        setAudioChannels (2, 2);
    }
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    frequency = 440;
    phase = 0;
    amplitude = 0.25;
    waveTableSize = 1024;
    sr = sampleRate;

    increment = frequency * waveTableSize / sr;

    for (int i = 0; i < waveTableSize; i++) {
        waveTable.insert(i, sin(2.0 * double_Pi * i / waveTableSize));
    }
}

void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    float* const leftChannel = bufferToFill.buffer->getWritePointer(0, bufferToFill.startSample);
    float* const rightChannel = bufferToFill.buffer->getWritePointer(1, bufferToFill.startSample);

    for (int sample = 0; sample < bufferToFill.numSamples; sample++) {
        
        leftChannel[sample] = waveTable[(int)phase] * amplitude;
        rightChannel[sample] = waveTable[(int)phase] * amplitude;

        phase = fmod((phase + increment), waveTableSize);
    }
}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::crimson);
}

void MainComponent::resized()
{
    Rectangle<int> dialArea = getLocalBounds();

    frequencySlider.setBounds(dialArea.removeFromLeft(getLocalBounds().getWidth() / 2));
    amplitudeSlider.setBounds(dialArea.removeFromLeft(getLocalBounds().getWidth() / 2));
}
