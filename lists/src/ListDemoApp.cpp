#include "App.h"
#include "MainComponent.h"

class ListDemo : public App
{
public:
    ListDemo()
    {
    }

    const char *getApplicationName(void) const override
    {
        return ("ListDemo");
    }

    const char *getApplicationVersion(void) const override
    {
        return ("1.0.0");
    }

    const char *getApplicationSandbox(void) const override
    {
        return ("lists");
    }

    void initialise(void) override
    {
        mainWindow = new MainWindow;
        System::logger.write(LOG_ERROR, "setup completed");
    }

    class MainWindow : public Window
    {
    public:
        MainWindow() : mainComponent(nullptr)
        {
            setOwnedContent(new MainComponent);
            setVisible(true);
        }

    private:
        MainComponent *mainComponent;
    };

private:
    MainWindow *mainWindow;
};

// This macro instructs main() routine to launch the app.
START_ELECTRA_APPLICATION(ListDemo)
