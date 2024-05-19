#include "processor/PluginProcessor.h"
#include "PluginEditor.h"
#include "ProjectInfo.h"

namespace {{ cookiecutter.__namespace }}::Gui {

//==============================================================================
{{ cookiecutter.__project_pascal }}AudioProcessorEditor::{{ cookiecutter.__project_pascal }}AudioProcessorEditor ({{ cookiecutter.__namespace }}::Processor::{{ cookiecutter.__project_pascal }}AudioProcessor& p)
    : AudioProcessorEditor (&p)
    , mAudioProcessor (p)
{
    juce::ignoreUnused (mAudioProcessor);

    setSize (640, 480);
    setResizable(true, true);
}

//==============================================================================
void {{ cookiecutter.__project_pascal }}AudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    g.setColour(juce::Colours::white);
    g.setFont(15.0f);
    g.drawFittedText({{ cookiecutter.__namespace }}::ProjectInfo::projectName, getLocalBounds(), juce::Justification::centred, 1);
}


} // namespace {{ cookiecutter.__namespace }}::Gui