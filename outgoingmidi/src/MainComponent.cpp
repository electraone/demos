#include "MainComponent.h"

MainComponent::MainComponent() : device1(MidiInterface::Type::MidiUsbDev, 0)
{
    slider = new SliderHorizontal;

    slider->setColour(Colours565::deepskyblue);
    slider->setRange(0, 127);

    slider->onValueChange = [this](int16_t value) {
        System::logger.write(LOG_ERROR, "value = %d", value);
        MidiMessage cc = MidiMessage::controllerEvent(1, 1, value);
        device1.sendMessage(MidiInterface::Type::MidiUsbDev, 0, cc);
    };
    addAndMakeVisible(slider);

    setBounds(0, 0, 1024, 560);
}

MainComponent::~MainComponent()
{
}

void MainComponent::handleIncomingMidiMessage(const MidiInput &midiInput,
                                              const MidiMessage &midiMessage)
{
    if (midiMessage.isController()) {
        if (midiMessage.getControllerNumber() == 1) {
            slider->setValue(midiMessage.getControllerValue());
        }
    }
    if (midiMessage.isSysEx()) {
        System::logger.write(LOG_ERROR, "SysEx length: %d", midiMessage.getSysExDataSize());

        System::logger.write(LOG_ERROR, "---< sysex start: interface=%s, port=%d >---",
                   MidiInterface::getName(midiInput.getInterfaceType()),
                   midiInput.getPort());

        SysexBlock sysexBlock = midiMessage.getSysExBlock();
        size_t sysexLength = sysexBlock.getLength();

        for (size_t i = 0; i < sysexLength; i++) {
            uint8_t sysexByte = sysexBlock.peek(i);
            System::logger.write(LOG_ERROR, "%d> %X (%c)", i, sysexByte, sysexByte);
        }

        System::logger.write(LOG_ERROR, "---------------------");
    } else {
        System::logger.write(LOG_ERROR, "message received: %s", midiMessage.getDescription());
    }
}

void MainComponent::paint(Graphics &g)
{
    g.fillAll(Colours565::black);
    g.printText(0,
                100,
                "Outgoing MIDI",
                TextStyle::largeTransparent,
                getWidth(),
                TextAlign::center);
}

void MainComponent::resized()
{
    slider->setBounds(337, getHeight() / 2, 350, 60);
}
