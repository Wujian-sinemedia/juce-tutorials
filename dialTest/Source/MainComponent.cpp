#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    dial1.setSliderStyle(juce::Slider::SliderStyle::Rotary);
    dial1.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(dial1);

    dial2.setSliderStyle(juce::Slider::SliderStyle::Rotary);
    dial2.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(dial2);

    dial3.setSliderStyle(juce::Slider::SliderStyle::Rotary);
    dial3.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(dial3);

    dial4.setSliderStyle(juce::Slider::SliderStyle::Rotary);
    dial4.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(dial4);

    setSize (600, 100);
}

MainComponent::~MainComponent()
{
    
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    
}

void MainComponent::resized()
{
    juce::Rectangle<int> dialArea = getLocalBounds();

    dial1.setBounds(dialArea.removeFromLeft(getLocalBounds().getWidth() / 4));
    dial2.setBounds(dialArea.removeFromLeft(getLocalBounds().getWidth() / 4));
    dial3.setBounds(dialArea.removeFromLeft(getLocalBounds().getWidth() / 4));
    dial4.setBounds(dialArea.removeFromLeft(getLocalBounds().getWidth() / 4));

    // removeFrom... removes a part from the area and returns the removed area (dial is placed here)
    // the removed area is reduced from the original area
}
