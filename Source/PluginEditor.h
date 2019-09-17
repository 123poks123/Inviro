/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "OutPutDrop.h"
#include "InPutDrop.h"
#include "Node.h"

//==============================================================================
/**
*/
class MaggsA3AudioProcessorEditor  : public AudioProcessorEditor

{
public:
    MaggsA3AudioProcessorEditor (MaggsA3AudioProcessor&, AudioProcessorValueTreeState&);
    ~MaggsA3AudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
       
    void mouseDrag(const MouseEvent&) override;
    
    
    
private:
    
    OutPutDrop outputDropGui;
    
    InPutDrop inputDropGui;
    
    MaggsA3AudioProcessor& processor;
    
    AudioProcessorValueTreeState& valueTreeState;
    
    float xPosition, yPosition, diameter;
    
    Colour colour = Colours::greenyellow;
    
    Node node = Node(xPosition, yPosition, diameter, colour);
   
    
    float panXValue;
    float panYValue;
  
    

    Image bgImage;
    
    
    
    
    
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MaggsA3AudioProcessorEditor)
};
