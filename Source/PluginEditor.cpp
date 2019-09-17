/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MaggsA3AudioProcessorEditor::MaggsA3AudioProcessorEditor (MaggsA3AudioProcessor& p, AudioProcessorValueTreeState& vts)
: AudioProcessorEditor (&p), processor (p), valueTreeState(vts), outputDropGui(p), inputDropGui(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setOpaque(true);
    setResizable(false, false);
    setSize(600, 500);
    
    xPosition = proportionOfWidth(0.5);
    
    node.setXPosition(xPosition);
    
    yPosition = proportionOfWidth(0.5);
    
    node.setXPosition(yPosition);
    
    node.setDiameter(40);
    
    addAndMakeVisible(&outputDropGui);
    
    addAndMakeVisible(&inputDropGui);

    bgImage = ImageCache::getFromMemory(BinaryData::Easy_background_draft_png, BinaryData::Easy_background_draft_pngSize);
   
 
    
}

MaggsA3AudioProcessorEditor::~MaggsA3AudioProcessorEditor()
{
    

}
    

//==============================================================================
void MaggsA3AudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll(Colours::black);
    
    g.drawImageWithin(bgImage, 0, 0, getWidth(), getHeight(), RectanglePlacement::fillDestination);
    
    g.setColour(Colours::ghostwhite);
    g.setFont (Font("Herculanum", 45.0f, Font::italic));
    g.drawFittedText("Inviro", 15 , 12, getWidth(), 50, Justification::centredTop, 1);
    
    node.drawNode(g);
  
   
}

void MaggsA3AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    Rectangle<int> area  = getLocalBounds();
    
    //const int componentHeigth = 200;
    const int componentWidth = 200;
    
    inputDropGui.setBounds(10, 10,180,100);
    
    outputDropGui.setBounds(400,10,180,100);
    
    
    
   
}




void MaggsA3AudioProcessorEditor::mouseDrag(const MouseEvent& m)
{
    
    if(m.mouseWasDraggedSinceMouseDown())
    {
        float newPanXValue = m.getDistanceFromDragStartX() + m.getMouseDownX();
        float newPanYValue = m.getDistanceFromDragStartY() + m.getMouseDownY();
        
        //map the values
        panXValue = jmap(newPanXValue, 0.0f, 600.0f, 0.0f, 1.0f);
        panYValue = jmap(newPanYValue, 0.0f, 500.0f, 0.0f, 1.0f);
      
        processor.parameters.getParameter("panx")->setValueNotifyingHost(panXValue);
        processor.parameters.getParameter("pany")->setValueNotifyingHost(panYValue);
        node.setXPosition(newPanXValue);
        node.setYPosition(newPanYValue);
        repaint();
        
    }
}




