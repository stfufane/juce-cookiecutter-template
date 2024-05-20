#pragma once

#include "processor/PluginProcessor.h"
#include "AttachedComponent.hpp"
#include <juce_gui_basics/juce_gui_basics.h>

namespace {{ cookiecutter.namespace }}::Gui {

//==============================================================================
class {{ cookiecutter.__project_pascal }}AudioProcessorEditor final : public juce::AudioProcessorEditor
{
public:
    explicit {{ cookiecutter.__project_pascal }}AudioProcessorEditor ({{ cookiecutter.namespace }}::Processor::{{ cookiecutter.__project_pascal }}AudioProcessor&);
    ~{{ cookiecutter.__project_pascal }}AudioProcessorEditor() override = default;
    
    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    {{ cookiecutter.namespace }}::Processor::{{ cookiecutter.__project_pascal }}AudioProcessor& mAudioProcessor;

    std::unique_ptr<AttachedComponent<juce::ToggleButton, juce::ButtonParameterAttachment>> mActive;
    std::unique_ptr<AttachedComponent<juce::Slider, juce::SliderParameterAttachment>> mGain;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR ({{ cookiecutter.__project_pascal }}AudioProcessorEditor)
};

} // namespace {{ cookiecutter.namespace }}::Gui