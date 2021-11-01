#pragma once

#include "Ui.h"

class MainComponent : public Component
{
public:
    MainComponent();
    ~MainComponent() override;

    void paint(Graphics &g) override;
    void resized(void) override;

private:
    SliderHorizontal *sliderHorizontal;
    SliderVertical *sliderVertical;
    BarHorizontal *barHorizontal;
    BarVertical *barVertical;
    Knob *knobLeft;
    Knob *knobRight;
};
