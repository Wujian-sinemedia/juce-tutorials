#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    frequencySlider.setSliderStyle(juce::Slider::SliderStyle::LinearBarVertical);
    frequencySlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 20);
    frequencySlider.setRange(50, 5000, 0.1);
    frequencySlider.setTextValueSuffix(" Hz");
    frequencySlider.addListener(this);
    addAndMakeVisible(frequencySlider);

    durationSlider.setSliderStyle(juce::Slider::SliderStyle::LinearBarVertical);
    durationSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 20);
    durationSlider.setRange(1.0 / frequencySlider.getMaximum(), 1.0 / frequencySlider.getMinimum());
    durationSlider.setTextValueSuffix(" s");
    durationSlider.addListener(this);
    addAndMakeVisible(durationSlider);

    setSize(600, 400);

    frequencySlider.setValue(500.0);
    frequencySlider.setSkewFactorFromMidPoint(500.0);
    durationSlider.setSkewFactorFromMidPoint(0.002);
}

MainComponent::~MainComponent()
{

}

//==============================================================================
void MainComponent::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::darkslateblue);
}

void MainComponent::resized()
{
    juce::Rectangle<int> dialArea = getLocalBounds();

    frequencySlider.setBounds(dialArea.removeFromLeft(getLocalBounds().getWidth() / 2));

    durationSlider.setBounds(dialArea.removeFromLeft(getLocalBounds().getWidth() / 2));
}
