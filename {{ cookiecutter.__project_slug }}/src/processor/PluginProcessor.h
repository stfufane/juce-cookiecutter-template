#pragma once

#include <juce_audio_processors/juce_audio_processors.h>
#include "BaseProcessor.h"
#include "Params.h"

namespace {{ cookiecutter.__namespace }}::Processor {

//==============================================================================
class {{ cookiecutter.__project_pascal }}AudioProcessor final : public BaseProcessor
{
public:
    {{ cookiecutter.__project_pascal }}AudioProcessor();
    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    // By default a generic editor is used in BaseProcessor. Uncomment this to use a custom editor.
    // juce::AudioProcessorEditor* createEditor() override;
private:
    //==============================================================================
    {{ cookiecutter.__namespace }}::Processor::Params params;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR ({{ cookiecutter.__project_pascal }}AudioProcessor)
};

} // namespace {{ cookiecutter.__namespace }}::Processor