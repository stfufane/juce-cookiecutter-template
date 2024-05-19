#pragma once

#include "processor/PluginProcessor.h"

namespace {{ cookiecutter.__namespace }}::Gui {

//==============================================================================
class {{ cookiecutter.__project_pascal }}AudioProcessorEditor final : public juce::AudioProcessorEditor
{
public:
    explicit {{ cookiecutter.__project_pascal }}AudioProcessorEditor ({{ cookiecutter.__namespace }}::Processor::{{ cookiecutter.__project_pascal }}AudioProcessor&);
    ~{{ cookiecutter.__project_pascal }}AudioProcessorEditor() override = default;
    
    //==============================================================================
    void paint (juce::Graphics&) override;

private:
    {{ cookiecutter.__namespace }}::Processor::{{ cookiecutter.__project_pascal }}AudioProcessor& mAudioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR ({{ cookiecutter.__project_pascal }}AudioProcessorEditor)
};

} // namespace {{ cookiecutter.__namespace }}::Gui