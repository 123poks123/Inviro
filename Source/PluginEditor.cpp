/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
//#include "OutPutDrop.h"

//==============================================================================
MaggsA3AudioProcessorEditor::MaggsA3AudioProcessorEditor (MaggsA3AudioProcessor& p, AudioProcessorValueTreeState& vts)
: AudioProcessorEditor (&p), processor (p), valueTreeState(vts) //outputDropGui(p), inputDropGui(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setOpaque(true);
    setResizable(false, false);
    setSize(600, 500);
    
    
    
    outputMenu.addItem("Stereo", 1);
    outputMenu.addItem("Quad", 2);
    outputMenu.addItem("5.1", 3);
    outputMenu.addItem("7.1", 4);
    outputMenu.addItem("Octophonic", 5);
    outputMenu.addItem("9.1", 6);
    
    outputMenu.addListener(this);
    outputBox = new AudioProcessorValueTreeState::ComboBoxAttachment (processor.parameters, "outputmenu", outputMenu);
    
    //Set up Node
    xPosition = 300;
    
    node.setXPosition(xPosition);
    
    yPosition = 300;
    
    node.setXPosition(yPosition);
    
    node.setDiameter(40);
    
    //Make Menus Visable
    
    addAndMakeVisible(outputMenu);
    
    //addAndMakeVisible(&outputDropGui);
    
    //addAndMakeVisible(&inputDropGui);
        
    
    stereoImage = ImageCache::getFromMemory(BinaryData::Background_Stereo_Draft_png, BinaryData::Background_Stereo_Draft_pngSize);
    
    quadImage = ImageCache::getFromMemory(BinaryData::Background_Quad_Draft_png, BinaryData::Background_Quad_Draft_pngSize);
    
    octophonicImage = ImageCache::getFromMemory(BinaryData::Background_Octophonic_Draft_png, BinaryData::Background_Octophonic_Draft_pngSize);
    
    if( processor.parameters.getParameter("outputmenu")->getValue() == 0)
    {
        bgImage = stereoImage;
      
    }
    
    else if(processor.parameters.getParameter("outputmenu")->getValue() == 1)
    {
        bgImage = quadImage;
        
        
    }
    
    else if(processor.parameters.getParameter("outputmenu")->getValue() == 4)
    {
        bgImage = octophonicImage;
       
        
    }

   
    
    
   
    
}

MaggsA3AudioProcessorEditor::~MaggsA3AudioProcessorEditor()
{
  
}
    

//==============================================================================
void MaggsA3AudioProcessorEditor::paint (Graphics& g)
{
    
    
    
    g.fillAll(Colours::black);
    

   
   
    g.drawImageWithin(bgImage, 0, 0, getWidth(), getHeight(), RectanglePlacement::fillDestination);
    
    
    /*if( processor.parameters.getParameter("outputmenu")->getValue() == 0)
    {
         g.drawImageWithin(stereoImage, 0, 0, getWidth(), getHeight(), RectanglePlacement::fillDestination);
        
    }
    else if(processor.parameters.getParameter("outputmenu")->getValue() == 1)
    {
        g.drawImageWithin(quadImage, 0, 0, getWidth(), getHeight(), RectanglePlacement::fillDestination);
        
    }
    else if(processor.parameters.getParameter("outputmenu")->getValue() == 4)
    {
         g.drawImageWithin(octophonicImage, 0, 0, getWidth(), getHeight(), RectanglePlacement::fillDestination);
    
    }*/
   
    
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
    
    //inputDropGui.setBounds(10, 10,180,100);
    
    //outputDropGui.setBounds(400,10,180,100);
    
    outputMenu.setBounds(410, 25, 165, 20);
    
   
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

void MaggsA3AudioProcessorEditor::comboBoxChanged(ComboBox* box)
{
    
    
    
    std::make_unique<AudioParameterFloat>("outputmenu" , //parameter ID
                                          "output" , //Parameter Name
                                          0.0f, //min value
                                          5.0f, //Max Value
                                          0.0f //Default Value
                                          );
    
    float output = *processor.parameters.getRawParameterValue("outputmenu");
    
    if( output == 0)
    {
        bgImage = stereoImage;
        repaint();
    }
    
    else if(output == 1)
    {
        bgImage = quadImage;
        repaint();
        
    }
    
    else if(output == 4)
    {
        bgImage = octophonicImage;
        repaint();
        
    }
    
  
}

