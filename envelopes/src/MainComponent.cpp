#include "MainComponent.h"
#include "helpers.h"
#include <vector>

MainComponent::MainComponent()
{
    adsr = new ADSR;
    adsr->setColour(Colours565::darkslateblue);
    adsr->assignPot(0);
    adsr->setActiveSegment(ADSR::sustain);
    adsr->setMin(ADSR::attack, -127.0f);
    adsr->setMax(ADSR::attack, 127.0f);

    adsr->setMin(ADSR::decay, -127.0f);
    adsr->setMax(ADSR::decay, 127.0f);

    adsr->setMin(ADSR::sustain, -127.0f);
    adsr->setMax(ADSR::sustain, 127.0f);

    adsr->setMin(ADSR::release, -127.0f);
    adsr->setMax(ADSR::release, 127.0f);

    adsr->setValue(Envelope::delay, 63.0f);
    adsr->setValue(ADSR::attack, 127.0f);
    adsr->setValue(ADSR::decay, 127.0f);
    adsr->setValue(ADSR::sustain, 63.0f);
    adsr->setValue(ADSR::release, 127.0f);
    adsr->useDelay(false);
    addAndMakeVisible(adsr);

    adr = new ADR;
    adr->setColour(Colours565::coral);
    adr->assignPot(1);
    adr->setActiveSegment(ADR::decay);

    adr->setMin(ADR::attack, 0.0f);
    adr->setMax(ADR::attack, 127.0f);

    adr->setMin(ADR::decay, 0.0f);
    adr->setMax(ADR::decay, 127.0f);

    adr->setMin(ADR::release, 0.0f);
    adr->setMax(ADR::release, 127.0f);

    adr->setValue(ADR::attack, 63.0f);
    adr->setValue(ADR::decay, 63.0f);
    adr->setValue(ADR::release, 127.0f);
    adr->useDelay(false);
    addAndMakeVisible(adr);

    ar = new AR;
    ar->setColour(Colours565::darkolivegreen);
    ar->assignPot(2);
    ar->setActiveSegment(AR::release);

    ar->setMin(AR::attack, 0.0f);
    ar->setMax(AR::attack, 127.0f);

    ar->setMin(AR::release, 0.0f);
    ar->setMax(AR::release, 127.0f);

    ar->setValue(Envelope::delay, 1.0f);
    ar->setValue(AR::attack, 63.0f);
    ar->setValue(AR::release, 63.0f);
    ar->useDelay(false);
    addAndMakeVisible(ar);

    ahdsr = new AHDSR;
    ahdsr->setColour(Colours565::magenta);
    ahdsr->assignPot(3);
    ahdsr->setActiveSegment(AHDSR::sustain);
    ahdsr->setMin(AHDSR::sustain, -1.0f);
    ahdsr->setMax(AHDSR::sustain, 1.0f);
    ahdsr->setValue(Envelope::delay, 0.75f);
    ahdsr->setValue(AHDSR::attack, 0.5f);
    ahdsr->setValue(AHDSR::hold, 0.5f);
    ahdsr->setValue(AHDSR::decay, 0.5f);
    ahdsr->setValue(AHDSR::sustain, 0.5f);
    ahdsr->setValue(AHDSR::release, 1.0f);
    ahdsr->useDelay(false);
    addAndMakeVisible(ahdsr);

    adssr = new ADSSR;
    adssr->setColour(Colours565::khaki);
    adssr->assignPot(6);
    adssr->setActiveSegment(ADSSR::breakPoint);
    adssr->setMin(ADSSR::sustain, -1.0f);
    adssr->setMax(ADSSR::sustain, 1.0f);
    adssr->setMin(ADSSR::breakPoint, -1.0f);
    adssr->setMax(ADSSR::breakPoint, 1.0f);
    adssr->setValue(Envelope::delay, 0.5f);
    adssr->setValue(ADSSR::attack, 0.5f);
    adssr->setValue(ADSSR::decay, 1.0f);
    adssr->setValue(ADSSR::breakPoint, 0.25f);
    adssr->setValue(ADSSR::slope, 1.0f);
    adssr->setValue(ADSSR::sustain, 0.5f);
    adssr->setValue(ADSSR::release, 1.0f);
    adssr->useDelay(false);
    addAndMakeVisible(adssr);

    env5Seg = new Env5Seg;
    env5Seg->setColour(Colours565::mediumaquamarine);
    env5Seg->assignPot(7);
    env5Seg->setActiveSegment(Env5Seg::rate2);
    env5Seg->setMin(Env5Seg::level1, 0.0f);
    env5Seg->setMax(Env5Seg::level1, 127.0f);
    env5Seg->setMin(Env5Seg::level2, 0.0f);
    env5Seg->setMax(Env5Seg::level2, 127.0f);
    env5Seg->setMin(Env5Seg::level3, 0.0f);
    env5Seg->setMax(Env5Seg::level3, 127.0f);
    env5Seg->setMin(Env5Seg::level4, -127.0f);
    env5Seg->setMax(Env5Seg::level4, 127.0f);

    env5Seg->setMin(Env5Seg::rate1, 0.0f);
    env5Seg->setMax(Env5Seg::rate1, 127.0f);
    env5Seg->setMin(Env5Seg::rate2, 0.0f);
    env5Seg->setMax(Env5Seg::rate2, 127.0f);
    env5Seg->setMin(Env5Seg::rate3, 0.0f);
    env5Seg->setMax(Env5Seg::rate3, 127.0f);
    env5Seg->setMin(Env5Seg::rate4, 0.0f);
    env5Seg->setMax(Env5Seg::rate4, 127.0f);

    env5Seg->setValue(Envelope::delay, 127.0f);
    env5Seg->setValue(Env5Seg::rate1, 127.0f);
    env5Seg->setValue(Env5Seg::level1, 127.0f);
    env5Seg->setValue(Env5Seg::rate2, 127.0f);
    env5Seg->setValue(Env5Seg::level2, 63.0f);
    env5Seg->setValue(Env5Seg::rate3, 127.0f);
    env5Seg->setValue(Env5Seg::level3, 31.0f);
    env5Seg->setValue(Env5Seg::rate4, 127.0f);
    env5Seg->setValue(Env5Seg::level4, 0.0f);
    env5Seg->useDelay(false);
    addAndMakeVisible(env5Seg);

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
    adsr->setBounds(100, 100, 170, 100);
    adr->setBounds(300, 100, 170, 100);
    ar->setBounds(500, 100, 170, 100);
    ahdsr->setBounds(700, 100, 170, 100);

    adssr->setBounds(100, 300, 170, 100);
    env5Seg->setBounds(300, 300, 170, 100);
}
