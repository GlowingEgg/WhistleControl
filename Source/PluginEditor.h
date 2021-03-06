/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class WhistleControlAudioProcessorEditor  : public AudioProcessorEditor,
                                            private Slider::Listener,
                                            public Timer
{
public:
    WhistleControlAudioProcessorEditor (WhistleControlAudioProcessor&);
    ~WhistleControlAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged (Slider* slider) override;
    void timerCallback() override;
    WhistleControlAudioProcessor* getProcessor() const { return static_cast<WhistleControlAudioProcessor*>(
                                                        getAudioProcessor());
    
    }
    Slider inputVolume;

private:
    
    WhistleControlAudioProcessor& processor;
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WhistleControlAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
