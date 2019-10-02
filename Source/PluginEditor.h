/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//#include "OutPutDrop.h"
//#include "InPutDrop.h"
#include "Node.h"

//==============================================================================
/**
*/
class MaggsA3AudioProcessorEditor  : public AudioProcessorEditor,
                                     private ComboBox::Listener

{
public:
    MaggsA3AudioProcessorEditor (MaggsA3AudioProcessor&, AudioProcessorValueTreeState&);
    ~MaggsA3AudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
       
    void mouseDrag(const MouseEvent&) override;
    
    void comboBoxChanged(ComboBox*) override;
    
    
    
private:
    
    //OutPutDrop outputDropGui;
    
   
    
    //InPutDrop inputDropGui;
    
    MaggsA3AudioProcessor& processor;
    
    AudioProcessorValueTreeState& valueTreeState;
    
    float xPosition = 300, yPosition = 300, diameter = 40;
    
    Colour colour = Colours::greenyellow;
    
    Node node = Node(xPosition, yPosition, diameter, colour);
    
    int outputGui;
   
    
    float panXValue;
    float panYValue;
  
    
    Image bgImage;
    
    Image stereoImage;
    Image quadImage;
    Image octophonicImage;
    
    ComboBox outputMenu;
    
    ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> outputBox;
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MaggsA3AudioProcessorEditor)
};
