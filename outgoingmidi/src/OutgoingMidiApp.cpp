#include "App.h"
#include "MainComponent.h"

class OutgoingMidi : public App
{
public:
    OutgoingMidi()
    {
    }

    const char *getApplicationName(void) const override
    {
        return ("OutgoingMidi");
    }
    const char *getApplicationVersion(void) const override
    {
        return ("1.0.0");
    }
    const char *getApplicationSandbox(void) const override
    {
        return ("omidi");
    }

    void initialise(void)
    {
        mainWindow.display();
        logMessage("setup completed");
    }

    void touchMove(TouchEvent &touchEvent)
    {
        if (Component *component = touchEvent.getEventComponent()) {
            component->onTouchMove(touchEvent);
        }
    }

    class MainWindow : public Window
    {
    public:
        MainWindow()
        {
            setOwnedContent(new MainComponent());
            setVisible(true);
        }
    };

private:
    MainWindow mainWindow;
};

// This macro instructs main() routine to launch the app.
START_ELECTRA_APPLICATION(OutgoingMidi)
