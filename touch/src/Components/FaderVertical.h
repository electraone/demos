#pragma once

#include "Component.h"
#include "System.h"

class FaderVertical final : public Component
{
public:
    FaderVertical() : value (0), faderPosition (0)
    {
    }

    ~FaderVertical() = default;

    void paint(Graphics &g) override
    {
        g.fillAll(Colours565::black);

        g.setColour(Colours565::darkorange);
        g.fillRoundRect(0, 0, getWidth(), getHeight(), 20);

        g.setColour(Colours565::black);
        g.fillRect(0, 0, getWidth(), faderPosition);

        g.setColour(Colours565::white);
        g.drawRoundRect(0, 0, getWidth(), getHeight(), 20);
    }

    void onTouchDown(const TouchEvent &touchEvent) override
    {
        System::logger.write(LOG_ERROR, "callback: %s down", getName());
        repaint();
    }

    void onTouchMove(const TouchEvent &touchEvent) override
    {
        float stepDetail = getHeight() / (float)(max);
        int16_t newValue =
            constrain(ceil(touchEvent.getY() / stepDetail), min, max);
        setValue(newValue);
    }

    void onTouchUp(const TouchEvent &touchEvent) override
    {
        System::logger.write(LOG_ERROR, "callback: %s up", getName());
        repaint();
    }

    void setValue(int16_t newValue)
    {
        value = newValue;
        faderPosition = map(newValue, min, max, 0, getHeight());
        System::logger.write(LOG_ERROR, "callback: %s has new value: %d", getName(), value);
        repaint();
    }

private:
    static const int16_t min = 0;
    static const int16_t max = 127;
    int16_t value;
    int16_t faderPosition;
};
