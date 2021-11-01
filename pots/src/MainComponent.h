#pragma once

#include "Ui.h"
#include "NestedComponent.h"

class MainComponent : public Component
{
public:
    MainComponent();
    ~MainComponent() override;

    void onPotChange(const PotEvent &potEvent) override;

    void paint(Graphics &g) override;
    void resized(void) override;

private:
    Knob *knob1;
    Knob *knob2;
    Knob *knob5;
    Knob *knob6;
    NestedComponent *nestedComponent;
};
