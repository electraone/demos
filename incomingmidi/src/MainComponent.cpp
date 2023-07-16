#include "MainComponent.h"
#include "System.h"

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
    System::logger.write(LOG_ERROR, "midi message: iface: %d, port: %d, event: %s",
               midiInput.getInterfaceType(),
               midiInput.getPort(),
               midiMessage.getDescription());

    if (midiMessage.isSysEx()) {
        System::logger.write(LOG_ERROR, "---< sysex start: interface=%s, port=%d >---",
                   MidiInterface::getName(midiInput.getInterfaceType()),
                   midiInput.getPort());

        SysexBlock sysexBlock = midiMessage.getSysExBlock();
        size_t sysexLength = sysexBlock.getLength();

        for (size_t i = 0; i < sysexLength; i++) {
            uint8_t sysexByte = sysexBlock.peek(i);
            System::logger.write(LOG_ERROR, "%d> %d (%c)", i, sysexByte, sysexByte);
        }

        System::logger.write(LOG_ERROR, "---------------------");
    }
}

void MainComponent::paint(Graphics &g)
{
    g.fillAll(Colours565::black);
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
