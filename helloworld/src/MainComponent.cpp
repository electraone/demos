#include "MainComponent.h"
#include "helpers.h"

MainComponent::MainComponent()
{
    setBounds(0, 0, 1024, 560);
}

MainComponent::~MainComponent()
{
}

void MainComponent::paint(Graphics &g)
{
    g.fillAll(Colours565::black);
    g.printText(0,
                getHeight() / 2,
                "Hello world!",
                TextStyle::largeTransparent,
                getWidth(),
                TextAlign::center);
}

void MainComponent::resized()
{
}
