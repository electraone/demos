#include "MainComponent.h"
#include "helpers.h"

MainComponent::MainComponent()
{
    for (uint8_t col = 0; col < numCols; col++) {
        for (uint8_t row = 0; row < numRows; row++) {
            pad[col][row] = new Pad;
            pad[col][row]->setColour((col % 4) == 0 ? Colours565::darkorange
                                                    : Colours565::darksalmon);
            if (col == 0) {
                pad[col][row]->setColour(
                    Colours565::lighter(Colours565::darkorange, 0.50));
            }

            if (col == 1) {
                pad[col][row]->setColour(
                    Colours565::lighter(Colours565::darksalmon, 0.50));
            }
            addAndMakeVisible(pad[col][row]);
        }
    }

    setBounds(0, 0, 1024, 560);
}

MainComponent::~MainComponent()
{
}

void MainComponent::paint(Graphics &g)
{
    g.fillAll(Colours565::black);
}

void MainComponent::resized()
{
    uint8_t beat = 0;

    for (uint8_t col = 0; col < numCols; col++) {
        for (uint8_t row = 0; row < numRows; row++) {
            pad[col][row]->setBounds(
                28 + beat + (col * 60), 20 + (row * 60), 40, 40);
        }

        if (((col + 1) % 4) == 0) {
            beat += 10;
        }
    }
}

uint32_t MainComponent::getRandomColour(void)
{
    uint8_t red = random(6, 31);
    uint8_t green = random(6, 63);
    uint8_t blue = random(6, 32);

    return ((red << 11) | (green << 5) | blue);
}
