#include "BaseProcessor.h"
#include "Params.h"

namespace {{ cookiecutter.namespace }}::Processor {

//==============================================================================
BaseProcessor::BaseProcessor()
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
{
}

//==============================================================================
const juce::String BaseProcessor::getName() const
{
    return JucePlugin_Name;
}

bool BaseProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool BaseProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool BaseProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double BaseProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int BaseProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int BaseProcessor::getCurrentProgram()
{
    return 0;
}

void BaseProcessor::setCurrentProgram (int index)
{
    juce::ignoreUnused (index);
}

const juce::String BaseProcessor::getProgramName (int index)
{
    juce::ignoreUnused (index);
    return {};
}

void BaseProcessor::changeProgramName (int index, const juce::String& newName)
{
    juce::ignoreUnused (index, newName);
}

//==============================================================================
bool BaseProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}

//==============================================================================
bool BaseProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* BaseProcessor::createEditor()
{
    return new juce::GenericAudioProcessorEditor(*this);
}

//==============================================================================
void BaseProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    juce::XmlElement xml("PluginState");
    for (const auto& param : getParameters()) {
        xml.setAttribute(getParamID(param), param->getValue());
    }
    copyXmlToBinary(xml, destData);
}

void BaseProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    auto xml = getXmlFromBinary(data, sizeInBytes);
    if (!xml) {
        return;
    }
    for (auto& param: getParameters()) {
        param->setValueNotifyingHost(static_cast<float>(xml->getDoubleAttribute(getParamID(param), param->getValue())));
    }
}

} // namespace {{ cookiecutter.namespace }}::Processor