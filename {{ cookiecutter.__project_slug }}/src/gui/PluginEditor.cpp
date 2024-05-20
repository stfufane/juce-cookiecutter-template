#include "processor/PluginProcessor.h"
#include "PluginEditor.h"
#include "ProjectInfo.h"

namespace {{ cookiecutter.namespace }}::Gui {

//==============================================================================
{{ cookiecutter.__project_pascal }}AudioProcessorEditor::{{ cookiecutter.__project_pascal }}AudioProcessorEditor ({{ cookiecutter.namespace }}::Processor::{{ cookiecutter.__project_pascal }}AudioProcessor& p)
    : AudioProcessorEditor (&p)
    , mAudioProcessor (p)
{
    const auto& params = mAudioProcessor.getParams();

    mActive = std::make_unique<AttachedComponent<juce::ToggleButton, juce::ButtonParameterAttachment>>(
        *params.active, *this,
        [](juce::ToggleButton&) { },
        "Active"
    );

    mGain = std::make_unique<AttachedComponent<juce::Slider, juce::SliderParameterAttachment>>(
        *params.gain, *this,
        [](juce::Slider& slider) {
            slider.setRange(0., 1.0, 0.01);
            slider.setNumDecimalPlacesToDisplay(0);
            slider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
        },
        "Gain"
    );

    setSize (640, 480);
    setResizable(true, true);
}

//==============================================================================
void {{ cookiecutter.__project_pascal }}AudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    g.setColour(juce::Colours::white);
    g.setFont(24.0f);
    g.drawFittedText({{ cookiecutter.namespace }}::ProjectInfo::projectName, getLocalBounds(), juce::Justification::centred, 1);
}

void {{ cookiecutter.__project_pascal }}AudioProcessorEditor::resized()
{
    auto bounds = getLocalBounds().reduced(10);

    mActive->getComponent().setBounds(bounds.removeFromTop(30));
    mGain->getComponent().setBounds(bounds.removeFromTop(100));
}


} // namespace {{ cookiecutter.namespace }}::Gui