#include "MainComponent.h"

MainComponent::MainComponent()
{
    knob1 = new Knob();
    knob2 = new Knob();
    knob5 = new Knob();
    knob6 = new Knob();
    nestedComponent = new NestedComponent;

    knob1->setColour(Colours565::khaki);
    knob2->setColour(Colours565::lawngreen);
    knob5->setColour(Colours565::purple);
    knob6->setColour(Colours565::moccasin);

    knob1->setMinimum(0.0f);
    knob1->setMaximum(127.0f);
    knob1->setValue(64.0f);

    knob2->setMinimum(0.0f);
    knob2->setMaximum(127.0f);
    knob2->setValue(64.0f);

    knob5->setMinimum(0.0f);
    knob5->setMaximum(127.0f);
    knob5->setValue(64.0f);

    knob6->setMinimum(0.0f);
    knob6->setMaximum(127.0f);
    knob6->setValue(64.0f);

    knob1->setName("knob1");
    knob2->setName("knob2");
    knob5->setName("knob5");
    knob6->setName("knob6");

    assignAllPots();

    knob2->assignPot(1);
    knob5->assignPot(4);
    knob6->assignPot(5);

    addAndMakeVisible(knob1);
    addAndMakeVisible(knob2);
    addAndMakeVisible(knob5);
    addAndMakeVisible(knob6);
    addAndMakeVisible(nestedComponent);
    setBounds(0, 0, 1024, 560);
}

MainComponent::~MainComponent()
{
}

void MainComponent::onPotChange(const PotEvent &potEvent)
{
    if (potEvent.getPotId() == 0) {
        knob1->applyValue(potEvent.getRelativeChange());
    }
}

void MainComponent::paint(Graphics &g)
{
    g.fillAll(Colours565::black);
    g.printText(0,
                100,
                "PotDemo",
                TextStyle::largeTransparent,
                getWidth(),
                TextAlign::center);
}

void MainComponent::resized()
{
    knob1->setBounds(50, 200, 70, 70);
    knob2->setBounds(220, 200, 70, 70);
    knob5->setBounds(730, 200, 70, 70);
    knob6->setBounds(900, 200, 70, 70);
    nestedComponent->setBounds(340, 150, 340, 170);
}
