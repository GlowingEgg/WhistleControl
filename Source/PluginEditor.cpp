/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
WhistleControlAudioProcessorEditor::WhistleControlAudioProcessorEditor (WhistleControlAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    inputVolume.setSliderStyle(Slider::LinearBarVertical);
    inputVolume.setRange(0.0, 127.0, 1.0);
    inputVolume.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    inputVolume.setPopupDisplayEnabled (true, this);
    inputVolume.setValue(65.0);
    inputVolume.addListener(this);
    addAndMakeVisible (&inputVolume);
}

WhistleControlAudioProcessorEditor::~WhistleControlAudioProcessorEditor()
{
}

//==============================================================================
void WhistleControlAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::black);

    g.setColour (Colours::palevioletred);
    g.setFont (15.0f);
    g.drawFittedText ("Input Volume", 18, 10, getWidth(), 30, Justification::topLeft, 1);
}

void WhistleControlAudioProcessorEditor::resized()
{
    inputVolume.setBounds (40, 30, 20, getHeight() - 60);
}

void WhistleControlAudioProcessorEditor::sliderValueChanged (Slider* slider)
{
    processor.inputVelocity = inputVolume.getValue();
}
void WhistleControlAudioProcessorEditor::timerCallback(){
    WhistleControlAudioProcessor* processor = getProcessor();
}
