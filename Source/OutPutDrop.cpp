/*
  ==============================================================================

    OutPutDrop.cpp
    Created: 7 Aug 2019 1:38:40pm
    Author:  Alex Maggs

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "OutPutDrop.h"


//==============================================================================
OutPutDrop::OutPutDrop(MaggsA3AudioProcessor& p) :
processor(p)
{
    setSize(200, 200);
    
    outputMenu.addItem("Stereo", 1);
    outputMenu.addItem("Quad", 2);
    outputMenu.addItem("5.1", 3);
    outputMenu.addItem("7.1", 4);
    outputMenu.addItem("Octophonic", 5);
    outputMenu.addItem("9.1", 6);
    
    addAndMakeVisible(&outputMenu);
    outputMenu.addListener(this);
    
    outputBox = new AudioProcessorValueTreeState::ComboBoxAttachment (processor.parameters, "outputmenu", outputMenu);
}

OutPutDrop::~OutPutDrop()
{
    
}

void OutPutDrop::paint (Graphics& g)
{
  

    g.fillAll (Colours::black);

    
   
}

void OutPutDrop::resized()
{
    
    Rectangle<int> area  = getLocalBounds().reduced(20);
    
    outputMenu.setBounds(area.removeFromTop(20));
 
}

void OutPutDrop::comboBoxChanged(ComboBox* box)
{
    
}
