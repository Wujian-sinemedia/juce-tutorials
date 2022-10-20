/*
  ==============================================================================

    WallComponent.cpp
    Created: 20 Oct 2022 8:31:12pm
    Author:  vivek

  ==============================================================================
*/

#include <JuceHeader.h>
#include "WallComponent.h"

//==============================================================================
WallComponent::WallComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

WallComponent::~WallComponent()
{
}

void WallComponent::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    juce::Rectangle<float> wall(200, 200, 200, 120);
    g.fillCheckerBoard(wall, 20, 10, juce::Colours::sandybrown, juce::Colours::saddlebrown);
    g.drawRect(wall);
}

void WallComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
