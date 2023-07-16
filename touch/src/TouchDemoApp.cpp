#include "App.h"
#include "MainComponent.h"

class TouchDemo : public App
{
public:
    TouchDemo()
    {
    }

    const char *getApplicationName() const override
    {
        return ("TouchDemo");
    }
    const char *getApplicationVersion() const override
    {
        return ("1.0.0");
    }
    const char *getApplicationSandbox() const override
    {
        return ("touch");
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
START_ELECTRA_APPLICATION(TouchDemo)
