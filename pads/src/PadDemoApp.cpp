#include "App.h"
#include "MainComponent.h"

class PadDemo : public App
{
public:
    PadDemo()
    {
    }

    const char *getApplicationName(void) const override
    {
        return ("PadDemo");
    }

    const char *getApplicationVersion(void) const override
    {
        return ("1.0.0");
    }

    const char *getApplicationSandbox(void) const override
    {
        return ("pads");
    }

    void initialise(void)
    {
        System::logger.write(LOG_ERROR, "setup completed");
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
START_ELECTRA_APPLICATION(PadDemo)
