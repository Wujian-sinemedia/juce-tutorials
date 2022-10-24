/*
  ==============================================================================

    GrassComponent.cpp
    Created: 20 Oct 2022 9:08:41pm
    Author:  vivek

  ==============================================================================
*/

#include <JuceHeader.h>
#include "GrassComponent.h"

//==============================================================================
GrassComponent::GrassComponent()
{

}

GrassComponent::~GrassComponent()
{

}

void GrassComponent::paint (juce::Graphics& g)
{
    g.setColour(juce::Colours::forestgreen); // set colour to green
    g.drawLine(0, 325, getWidth(), 325, 10.0f); // draw a line to g;
}

void GrassComponent::resized()
{
    
}
