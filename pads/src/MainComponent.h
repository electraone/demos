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
    static uint32_t getRandomColour(void);

    static constexpr uint8_t numCols = 16;
    static constexpr uint8_t numRows = 8;

    Pad *pad[numCols][numRows];
};
