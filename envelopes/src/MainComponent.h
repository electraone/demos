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
    ADSR *adsr;
    ADR *adr;
    AR *ar;
    AHDSR *ahdsr;
    ADSSR *adssr;
    Env5Seg *env5Seg;
};
