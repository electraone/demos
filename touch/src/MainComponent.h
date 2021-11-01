#pragma once

#include "Component.h"
#include "FaderVertical.h"

class MainComponent : public Component
{
public:
    MainComponent();
    ~MainComponent() override;

    void paint(Graphics &g) override;
    void resized(void) override;

private:
    FaderVertical *fader[5];
};
