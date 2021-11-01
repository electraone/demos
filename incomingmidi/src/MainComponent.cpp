#include "MainComponent.h"
#include "helpers.h"

MainComponent::MainComponent()
{
    setBounds(0, 0, 1024, 560);
}

MainComponent::~MainComponent()
{
}

void MainComponent::handleIncomingMidiMessage(const MidiInput &midiInput,
                                              const MidiMessage &midiMessage)
{
    logMessage("midi message: iface: %d, port: %d, event: %s",
               midiInput.getInterfaceType(),
               midiInput.getPort(),
               midiMessage.getDescription());

    if (midiMessage.isSysEx()) {
        logMessage("---< sysex start: interface=%s, port=%d >---",
                   MidiInterface::getName(midiInput.getInterfaceType()),
                   midiInput.getPort());

        SysexBlock sysexBlock = midiMessage.getSysExBlock();
        size_t sysexLength = sysexBlock.getLength();

        for (size_t i = 0; i < sysexLength; i++) {
            byte sysexByte = sysexBlock.peek(i);
            logMessage("%d> %d (%c)", i, sysexByte, sysexByte);
        }

        logMessage("---------------------");
    }
}

void MainComponent::paint(Graphics &g)
{
    g.fillAll(ElectraColours::rgb565NumericBlack);
    g.printText(0,
                getHeight() / 2,
                "Incoming MIDI",
                TextStyle::largeTransparent,
                getWidth(),
                TextAlign::center);
}

void MainComponent::resized()
{
}
