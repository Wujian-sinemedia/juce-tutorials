/*
  ==============================================================================

    SunComponent.cpp
    Created: 20 Oct 2022 10:27:37pm
    Author:  vivek

  ==============================================================================
*/

#include <JuceHeader.h>
#include "SunComponent.h"

//==============================================================================
SunComponent::SunComponent()
{

}

SunComponent::~SunComponent()
{

}

void SunComponent::paint (juce::Graphics& g)
{
    g.setColour(juce::Colours::yellow); // set colour yellow
    g.drawEllipse(400, 50, 50, 50, 10.0f); // draw ellipse
}

void SunComponent::resized()
{

}
