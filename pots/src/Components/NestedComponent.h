#pragma once

#include "Ui.h"

class NestedComponent final : public Component
{
public:
    NestedComponent()
    {
        knob1 = new Knob();
        knob2 = new Knob();

        knob1->setColour(Colours565::mediumpurple);
        knob2->setColour(Colours565::red);

        knob1->setName("knob3");
        knob2->setName("knob4");

        knob1->setMinimum(0.0f);
        knob1->setMaximum(127.0f);
        knob1->setValue(64.0f);

        knob2->setMinimum(0.0f);
        knob2->setMaximum(127.0f);
        knob2->setValue(64.0f);

        knob1->assignPot(2);
        knob2->assignPot(3);

        addAndMakeVisible(knob1);
        addAndMakeVisible(knob2);
    }

    ~NestedComponent() = default;

    void paint(Graphics &g) override
    {
        g.fillAll(Colours565::black);
        g.setColour(Colours565::darkgrey);
        g.drawRoundRect(0, 0, getWidth(), getHeight(), 20);
    }

    void resized(void) override
    {
        knob1->setBounds(50, 50, 70, 70);
        knob2->setBounds(220, 50, 70, 70);
    }

    void onPotChange(const PotEvent &potEvent) override
    {
        System::logger.write(LOG_ERROR, "pot %s moving", potEvent.getEventComponent()->getName());
    }

private:
    Knob *knob1;
    Knob *knob2;
};
