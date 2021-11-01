#include "MainComponent.h"

MainComponent::MainComponent() : device1(MidiInterface::Type::MidiUsbDev, 0)
{
    slider = new SliderHorizontal;

    slider->setColour(Colours::deepskyblue);

    slider->onValueChange = [this](int16_t value) {
        logMessage("value = %d", value);
        MidiMessage cc = MidiMessage::controllerEvent(1, 1, value);
        device1.sendMessageNow(cc);
    };

    slider->onDragEnd = [this](int8_t value) {
        logMessage("Final value = %d", value);
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
        logMessage("SysEx length: %d", midiMessage.getSysExDataSize());

        logMessage("---< sysex start: interface=%s, port=%d >---",
                   MidiInterface::getName(midiInput.getInterfaceType()),
                   midiInput.getPort());

        SysexBlock sysexBlock = midiMessage.getSysExBlock();
        size_t sysexLength = sysexBlock.getLength();

        for (size_t i = 0; i < sysexLength; i++) {
            byte sysexByte = sysexBlock.peek(i);
            logMessage("%d> %X (%c)", i, sysexByte, sysexByte);
        }

        logMessage("---------------------");
    } else {
        logMessage("message received: %s", midiMessage.getDescription());
    }
}

void MainComponent::paint(Graphics &g)
{
    g.fillAll(ElectraColours::rgb565NumericBlack);
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
