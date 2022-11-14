/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainPluginAudioProcessorEditor::GainPluginAudioProcessorEditor (GainPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (75, 300);

    sliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, GAIN_ID, gainSlider);

    gainSlider.setSliderStyle(Slider::LinearBarVertical);
    gainSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 20);
    gainSlider.setRange(-48.0f, 6.0f);
    //gainSlider.setValue(-0.0f);
    //gainSlider.setSkewFactorFromMidPoint(-9.0f);
    gainSlider.setTextValueSuffix(" dB");
    gainSlider.setNumDecimalPlacesToDisplay(2);

    lookAndFeel.setColour(Slider::trackColourId, Colours::crimson);
    lookAndFeel.setColour(Slider::textBoxTextColourId, Colours::black);

    gainSlider.setLookAndFeel(&lookAndFeel);

    addAndMakeVisible(gainSlider);
}

GainPluginAudioProcessorEditor::~GainPluginAudioProcessorEditor()
{
}

//==============================================================================
void GainPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(Colours::white);
}

void GainPluginAudioProcessorEditor::resized()
{
    gainSlider.setBounds(getBounds());
}
