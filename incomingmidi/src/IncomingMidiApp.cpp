#include "App.h"
#include "MainComponent.h"

class IncomingMidi : public App
{
public:
    IncomingMidi()
    {
    }

    const char *getApplicationName() const override
    {
        return ("IncomingMidi");
    }
    const char *getApplicationVersion() const override
    {
        return ("1.0.0");
    }
    const char *getApplicationSandbox() const override
    {
        return ("imidi");
    }

    void initialise(void)
    {
        mainWindow.display();
        logMessage("setup completed");
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
START_ELECTRA_APPLICATION(IncomingMidi)
