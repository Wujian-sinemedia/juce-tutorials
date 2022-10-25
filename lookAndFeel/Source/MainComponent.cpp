#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);

    addAndMakeVisible(dial1);
    dial1.setSliderStyle(juce::Slider::Rotary);
    dial1.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 20);

    addAndMakeVisible(dial2);
    dial2.setSliderStyle(juce::Slider::Rotary);
    dial2.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 20);

    lookAndFeel1.setColour(juce::Slider::thumbColourId, juce::Colours::chartreuse);
    lookAndFeel1.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::chartreuse);
    lookAndFeel1.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::black);
    dial1.setLookAndFeel(&lookAndFeel1); // create a lookAndFeel object and pass it to dial objects setLookAndFeel function
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::crimson);
}

void MainComponent::resized()
{
    const int border = 20;
    const int dialWidth = getWidth() / 2 - border;
    const int dialHeight = getWidth() / 2 - border - 100;

    dial1.setBounds(border, border, dialWidth, dialHeight);
    dial2.setBounds(getWidth() / 2, border, dialWidth, dialHeight);
}
