#pragma once

#include "juce_core/system/juce_PlatformDefs.h"
#include <juce_audio_processors/juce_audio_processors.h>

namespace {{ cookiecutter.__namespace }}::Processor {

struct Params 
{
    Params(juce::AudioProcessor& processor) {
        active = new juce::AudioParameterBool("active", "Active", true);
        gain = new juce::AudioParameterFloat("gain", "Gain", 0.0f, 1.0f, 0.5f);

        processor.addParameter(active);
        processor.addParameter(gain);
    }

    juce::AudioParameterBool* active = nullptr;
    juce::AudioParameterFloat* gain = nullptr;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Params)
};

} // namespace {{ cookiecutter.__namespace }}::Processor