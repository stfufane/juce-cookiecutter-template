#pragma once

#include "juce_core/system/juce_PlatformDefs.h"
#include <juce_audio_processors/juce_audio_processors.h>

namespace {{ cookiecutter.namespace }}::Processor {

struct Params 
{
    Params() = delete;
    explicit Params(juce::AudioProcessor& processor) {
        active = new juce::AudioParameterBool("active", "Active", true);
        gain = new juce::AudioParameterFloat("gain", "Gain", 0.0f, 1.0f, 0.5f);

        processor.addParameter(active);
        processor.addParameter(gain);
    }

    juce::AudioParameterBool* active = nullptr;
    juce::AudioParameterFloat* gain = nullptr;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Params)
};

inline juce::String getParamID(juce::AudioProcessorParameter* param) {
    if (auto paramWithID = dynamic_cast<juce::AudioProcessorParameterWithID*>(param))
        return paramWithID->paramID;

    return param->getName(50);
}

} // namespace {{ cookiecutter.namespace }}::Processor