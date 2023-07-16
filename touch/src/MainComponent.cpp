#include "MainComponent.h"
#include "helpers.h"

MainComponent::MainComponent()
{
    for (uint8_t i = 0; i < 5; i++) {
        fader[i] = new FaderVertical();
        addAndMakeVisible(fader[i]);
    }

    fader[0]->setName("v1");
    fader[1]->setName("v2");
    fader[2]->setName("v3");
    fader[3]->setName("v4");
    fader[4]->setName("v5");

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
    for (uint8_t i = 0; i < 5; i++) {
        fader[i]->setBounds(162 + (i * 150), 100, 100, 400);
    }
}
