#pragma once

#include <JuceHeader.h>
using namespace juce;

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/

class CustomLookAndFeel : public juce::LookAndFeel_V4
{
public:
    // we are creating a customLookAndFeel class inherited from lookAndFeel class
    // and overriding the function drawRotarySlider
    void drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float rotatoryStartAngle, float rotatoryEndAngle, juce::Slider& slider) override
    {
        float diameter = jmin(width, height);
        float radius = diameter / 2;
        float centerX = x + width / 2;
        float centerY = y + height / 2;
        float rx = centerX - radius;
        float ry = centerY - radius;
        float angle = rotatoryStartAngle + sliderPos * (rotatoryEndAngle - rotatoryStartAngle);

        Rectangle<float> dialArea (rx, ry, diameter, diameter);

        g.setColour(Colours::limegreen);
        g.fillEllipse(dialArea);

        Path dialTick;
        dialTick.addRectangle(0, -radius, 10.0f, radius * 0.33);
        g.setColour(Colours::aliceblue);
        g.fillPath(dialTick, AffineTransform::rotation(angle).translated(centerX, centerY));
    }
};

class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)

    Slider dial;
    CustomLookAndFeel customLookAndFeel;
};
