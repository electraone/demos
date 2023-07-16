#include "App.h"
#include "MainComponent.h"

class SliderDemo : public App
{
public:
    SliderDemo()
    {
    }

    const char *getApplicationName(void) const override
    {
        return ("SliderDemo");
    }
    const char *getApplicationVersion(void) const override
    {
        return ("1.0.0");
    }
    const char *getApplicationSandbox(void) const override
    {
        return ("sliders");
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
START_ELECTRA_APPLICATION(SliderDemo)
