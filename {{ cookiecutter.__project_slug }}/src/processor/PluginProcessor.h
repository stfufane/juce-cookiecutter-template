#pragma once

#include <juce_audio_processors/juce_audio_processors.h>
#include "BaseProcessor.h"
#include "Params.h"

namespace {{ cookiecutter.namespace }}::Processor {

//==============================================================================
class {{ cookiecutter.__project_pascal }}AudioProcessor final : public BaseProcessor
{
public:
    {{ cookiecutter.__project_pascal }}AudioProcessor();
    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) final;
    void releaseResources() final;
    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) final;
    {% if cookiecutter.include_gui_example %}
    juce::AudioProcessorEditor* createEditor() final;
    {% endif %}
    const Params& getParams() const noexcept { return mParams; }

private:
    //==============================================================================
    Params mParams;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR ({{ cookiecutter.__project_pascal }}AudioProcessor)
};

} // namespace {{ cookiecutter.namespace }}::Processor