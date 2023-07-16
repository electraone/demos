#include "MainComponent.h"
#include "helpers.h"
#include <vector>

MainComponent::MainComponent()
{
    items.addItem(0, "Zero");
    items.addItem(1, "One");
    items.addItem(2, "Two");
    items.addItem(4, "Four");
    items.addItem(8, "Eight");
    items.addItem(9, "Nine");
    items.addItem(10, "Ten");
    items.addItem(11, "Eleven");
    items.addItem(12, "Twelve");
    items.addItem(13, "Thirteen");
    items.addItem(14, "Fourteen");
    items.addItem(15, "Fifteen");
    items.addItem(16, "Sixteen");
    items.addItem(17, "Seventeen");
    items.addItem(18, "Eightteen");

    list = new List(&items);
    list->setColour(Colours565::orange);
    list->assignPot(0, items.getNumItems());

    addAndMakeVisible(list);

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
    list->setBounds(100, 100, 170, 100);
}
