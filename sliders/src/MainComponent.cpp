#include "MainComponent.h"
#include "helpers.h"

MainComponent::MainComponent()
{
    sliderHorizontal = new SliderHorizontal;
    sliderVertical = new SliderVertical;
    barHorizontal = new BarHorizontal;
    barVertical = new BarVertical;
    knobLeft = new Knob;
    knobRight = new Knob;

    sliderHorizontal->setColour(Colours::slateblue);
    sliderHorizontal->setMinimum(0.0f);
    sliderHorizontal->setMaximum(127.0f);
    sliderHorizontal->setValue(64.0f);
    sliderHorizontal->assignPot(3);

    sliderVertical->setColour(Colours::crimson);
    sliderVertical->setMinimum(0.0f);
    sliderVertical->setMaximum(127.0f);
    sliderVertical->setValue(64.0f);
    sliderVertical->assignPot(1);

    barHorizontal->setColour(Colours::darkseagreen);
    barHorizontal->setMinimum(-127.0f);
    barHorizontal->setMaximum(127.0f);
    barHorizontal->setValue(64.0f);
    barHorizontal->assignPot(4);

    barVertical->setColour(Colours::red);
    barVertical->setMinimum(0.0f);
    barVertical->setMaximum(127.0f);
    barVertical->setValue(64.0f);
    barVertical->assignPot(2);

    knobLeft->setColour(Colours::orangered);
    knobLeft->setMinimum(0.0f);
    knobLeft->setMaximum(127.0f);
    knobLeft->setValue(64.0f);
    knobLeft->assignPot(0);

    knobRight->setColour(Colours::olive);
    knobRight->setMinimum(-127.0f);
    knobRight->setMaximum(127.0f);
    knobRight->setValue(64.0f);
    knobRight->assignPot(5);

    addAndMakeVisible(sliderHorizontal);
    addAndMakeVisible(sliderVertical);
    addAndMakeVisible(barHorizontal);
    addAndMakeVisible(barVertical);
    addAndMakeVisible(knobLeft);
    addAndMakeVisible(knobRight);

    setBounds(0, 0, 1024, 560);
}

MainComponent::~MainComponent()
{
}

void MainComponent::paint(Graphics &g)
{
    g.fillAll(ElectraColours::rgb565NumericBlack);
    g.printText(0,
                500,
                "Slider demo",
                TextStyle::largeTransparent,
                getWidth(),
                TextAlign::center);
}

void MainComponent::resized()
{
    knobLeft->setBounds(70, 150, 100, 100);
    sliderHorizontal->setBounds(530, 150, 250, 60);
    sliderVertical->setBounds(200, 150, 60, 250);
    barHorizontal->setBounds(530, 310, 250, 60);
    barVertical->setBounds(360, 150, 60, 250);
    knobRight->setBounds(854, 150, 100, 100);
}
