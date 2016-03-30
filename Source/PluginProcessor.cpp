#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
WhistleControlAudioProcessor::WhistleControlAudioProcessor()
{
}

WhistleControlAudioProcessor::~WhistleControlAudioProcessor()
{
}

//==============================================================================
const String WhistleControlAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool WhistleControlAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool WhistleControlAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool WhistleControlAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double WhistleControlAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int WhistleControlAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int WhistleControlAudioProcessor::getCurrentProgram()
{
    return 0;
}

void WhistleControlAudioProcessor::setCurrentProgram (int index)
{
}

const String WhistleControlAudioProcessor::getProgramName (int index)
{
    return String();
}

void WhistleControlAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void WhistleControlAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void WhistleControlAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void WhistleControlAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    for (int channel = 0; channel < getTotalNumInputChannels(); ++channel)
    {
        buffer.clear();
    }
    MidiBuffer output;
    MidiMessage message;
    
    if(getTotalNumInputChannels() == 2){
        const float* sample0 = buffer.getReadPointer(0);
        const float* sample1 = buffer.getReadPointer(1);
        int numSamples = buffer.getNumSamples();
        while (numSamples > 0) {
            *sample0++;
            *sample1++;
            numSamples--;
        }
    }
    else{
        const float* sample0 = buffer.getReadPointer(0);
        const float* sample1 = buffer.getReadPointer(0);
        int numSamples = buffer.getNumSamples();
        while (numSamples > 0) {
            *sample0++;
            *sample1++;
            numSamples--;
        }

    }

//==============================================================================
}
bool WhistleControlAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* WhistleControlAudioProcessor::createEditor()
{
    return new WhistleControlAudioProcessorEditor (*this);
}

//==============================================================================
void WhistleControlAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void WhistleControlAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new WhistleControlAudioProcessor();
}
