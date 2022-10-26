#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);

    addAndMakeVisible(dial);
    dial.setSliderStyle(Slider::Rotary);
    dial.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    dial.setLookAndFeel(&customLookAndFeel);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll(Colours::aliceblue);
}

void MainComponent::resized()
{
    dial.setBounds(getBounds());
}
