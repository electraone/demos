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
    List *list;

    ListData items;
    ListData items2;
};
