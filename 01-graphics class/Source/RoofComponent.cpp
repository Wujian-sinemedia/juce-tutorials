/*
  ==============================================================================

    RoofComponent.cpp
    Created: 20 Oct 2022 10:11:08pm
    Author:  vivek

  ==============================================================================
*/

#include <JuceHeader.h>
#include "RoofComponent.h"

//==============================================================================
RoofComponent::RoofComponent()
{

}

RoofComponent::~RoofComponent()
{
}

void RoofComponent::paint (juce::Graphics& g)
{
    juce::Path p; // creates a path object p
    g.setColour(juce::Colours::red); // set g's colour to red
    p.startNewSubPath(200, 190); // start from this point
    p.lineTo(400, 190); // draw line to this point
    p.lineTo(300, 140); // ...
    p.closeSubPath();
    g.fillPath(p); // fill the path with red colour

    g.strokePath(p, juce::PathStrokeType(2.0f)); // draw the path to g
}

void RoofComponent::resized()
{

}
