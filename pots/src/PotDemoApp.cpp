#include "App.h"
#include "MainComponent.h"

class PotDemo : public App
{
public:
    PotDemo()
    {
    }

    const char *getApplicationName() const override
    {
        return ("PotDemo");
    }
    const char *getApplicationVersion() const override
    {
        return ("1.0.0");
    }
    const char *getApplicationSandbox() const override
    {
        return ("potdemo");
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
START_ELECTRA_APPLICATION(PotDemo)
