#pragma once

#include "Component.h"
#include "MidiInputCallback.h"

class MainComponent : public Component, private MidiInputCallback
{
public:
    MainComponent();
    ~MainComponent() override;

    void handleIncomingMidiMessage(const MidiInput &midiInput,
                                   const MidiMessage &midiMessage) override;

    void paint(Graphics &g) override;
    void resized(void) override;
};
