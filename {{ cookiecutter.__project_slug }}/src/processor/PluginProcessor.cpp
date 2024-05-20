#include "PluginProcessor.h"
{%- if cookiecutter.include_ear_protection %}
#include "Utils.h"
{%- endif -%}
{% if cookiecutter.include_gui_example %}
#include "gui/PluginEditor.h"
{%- endif %}

namespace {{ cookiecutter.namespace }}::Processor {

{{ cookiecutter.__project_pascal }}AudioProcessor::{{ cookiecutter.__project_pascal }}AudioProcessor() 
    : mParams(*this) 
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

    // Don't process if the plugin is inactive.
    if (!mParams.active->get()) {
        buffer.clear();
        return;
    }

    // Clear extra channel data.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i) {
        buffer.clear (i, 0, buffer.getNumSamples());
    }
{% if cookiecutter.include_ear_protection %}
    #ifdef JUCE_DEBUG
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        {{ cookiecutter.namespace }}::Utils::protectYourEars(buffer.getWritePointer (channel), buffer.getNumSamples());
    }
    #endif
{% endif %}
    // Apply gain.
    buffer.applyGain(mParams.gain->get());
}
{% if cookiecutter.include_gui_example %}
juce::AudioProcessorEditor* {{ cookiecutter.__project_pascal }}AudioProcessor::createEditor() {
    return new {{ cookiecutter.namespace }}::Gui::{{ cookiecutter.__project_pascal }}AudioProcessorEditor (*this);
}
{% endif %}
} // namespace {{ cookiecutter.namespace }}::Processor

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new {{ cookiecutter.namespace }}::Processor::{{ cookiecutter.__project_pascal }}AudioProcessor();
}
