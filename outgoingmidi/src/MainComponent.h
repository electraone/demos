#pragma once

#include "Ui.h"
#include "MidiOutput.h"
#include "MidiBase.h"
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

private:
    Slider *slider;
    MidiOutput device1;
};
