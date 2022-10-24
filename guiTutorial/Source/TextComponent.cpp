/*
  ==============================================================================

    TextComponent.cpp
    Created: 20 Oct 2022 10:37:47pm
    Author:  vivek

  ==============================================================================
*/

#include <JuceHeader.h>
#include "TextComponent.h"

//==============================================================================
TextComponent::TextComponent()
{

}

TextComponent::~TextComponent()
{

}

void TextComponent::paint (juce::Graphics& g)
{
    juce::Font theFont("Cambria", "Regular", 36.0f); // creates a font object thefont
    g.setFont(theFont); // sets thefont to g
    g.drawText("The House of the rising sun", 10, 10, 600, 60, juce::Justification::topLeft); // writes text to g
}

void TextComponent::resized()
{

}
