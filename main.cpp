//
// Created by chrha on 8/21/2024.
//

#include <juce_gui_extra/juce_gui_extra.h>

class MainWindow : public juce::DocumentWindow
{
public:
    MainWindow() : DocumentWindow ("App", juce::Colours::black, allButtons)
    {
        auto label = new juce::Label ("", juce::String ("My version is: ") + APP_VERSION);
        label->setBounds (20, 20, 300, 30);
        setContentOwned (label, true);
        centreWithSize (400, 200);
    }

    void closeButtonPressed() override
    {
        juce::JUCEApplication::getInstance()->systemRequestedQuit();
    }
};

class App : public juce::JUCEApplication
{
public:
    const juce::String getApplicationName() override { return "App"; }
    const juce::String getApplicationVersion() override { return APP_VERSION; }

    void initialise (const juce::String& commandLineParameters) override
    {
        window.addToDesktop (0);
        window.setVisible (true);
    }

    void shutdown() override {}

private:
    MainWindow window;
};

START_JUCE_APPLICATION (App)
