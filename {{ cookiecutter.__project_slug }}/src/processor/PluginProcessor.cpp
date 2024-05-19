#include "PluginProcessor.h"
#include "Utils.h"
// #include "gui/PluginEditor.h"

namespace {{ cookiecutter.__namespace }}::Processor {

{{ cookiecutter.__project_pascal }}AudioProcessor::{{ cookiecutter.__project_pascal }}AudioProcessor() 
    : params(*this) 
    {}

//==============================================================================
void {{ cookiecutter.__project_pascal }}AudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    juce::ignoreUnused (sampleRate, samplesPerBlock);
}

void {{ cookiecutter.__project_pascal }}AudioProcessor::releaseResources()
{
}

void {{ cookiecutter.__project_pascal }}AudioProcessor::processBlock (juce::AudioBuffer<float>& buffer,
                                              [[maybe_unused]] juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    const auto totalNumInputChannels  = getTotalNumInputChannels();
    const auto totalNumOutputChannels = getTotalNumOutputChannels();

    if (!params.active->get()) {
        buffer.clear();
        return;
    }

    // Clear extra channel data.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i) {
        buffer.clear (i, 0, buffer.getNumSamples());
    }

    #ifdef JUCE_DEBUG
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        {{ cookiecutter.__namespace }}::Utils::protectYourEars(buffer.getWritePointer (channel), buffer.getNumSamples());
    }
    #endif

    buffer.applyGain(params.gain->get());
}

//==============================================================================
// juce::AudioProcessorEditor* {{ cookiecutter.__project_pascal }}AudioProcessor::createEditor()
// {
//     return new {{ cookiecutter.__namespace }}::Gui::{{ cookiecutter.__project_pascal }}AudioProcessorEditor (*this);
// }

} // namespace {{ cookiecutter.__namespace }}::Processor

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new {{ cookiecutter.__namespace }}::Processor::{{ cookiecutter.__project_pascal }}AudioProcessor();
}
