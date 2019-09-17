/*
  ==============================================================================

    InPutDrop.cpp
    Created: 7 Aug 2019 2:02:32pm
    Author:  Alex Maggs

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "InPutDrop.h"

//==============================================================================
InPutDrop::InPutDrop(MaggsA3AudioProcessor& p) :
processor(p)

{
    setSize(200, 200);
    
    inputMenu.addItem("Mono", 1);
    inputMenu.addItem("Stereo", 2);
    /*inputMenu.addItem("Quad", 3);
    inputMenu.addItem("5.1", 4);
    inputMenu.addItem("7.1", 5);
    inputMenu.addItem("Octagonal", 6);
    inputMenu.addItem("9.1", 7);*/
    
    addAndMakeVisible(&inputMenu);
    inputMenu.addListener(this);
    
    inputBox = new AudioProcessorValueTreeState::ComboBoxAttachment (processor.parameters, "inputmenu", inputMenu);
}

InPutDrop::~InPutDrop()
{
}

void InPutDrop::paint (Graphics& g)
{
    g.fillAll (Colours::black);
}

void InPutDrop::resized()
{
    Rectangle<int> area  = getLocalBounds().reduced(20);
    
    inputMenu.setBounds(area.removeFromTop(20));

}
void InPutDrop::comboBoxChanged(ComboBox* box)
{
    
}
