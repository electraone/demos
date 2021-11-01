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
    //items.addItem(19, "Nineteen");

    items2.addItem(1, "One");
    items2.addItem(2, "Two");
    items2.addItem(4, "Four");

    list = new List;
    list->setColour(Colours::orange);
    list->assignPot(0, items.getNumItems());
    list->assignListData(items2);
    list->assignListData(items);

    addAndMakeVisible(list);

    setBounds(0, 0, 1024, 560);
}

MainComponent::~MainComponent()
{
}

void MainComponent::paint(Graphics &g)
{
    g.fillAll(Colours::black);
}

void MainComponent::resized()
{
    list->setBounds(100, 100, 170, 100);
}
