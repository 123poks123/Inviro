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
        
    
    stereoImage = ImageCache::getFromMemory(BinaryData::Background_Stereo_Semi_Final_png, BinaryData::Background_Stereo_Semi_Final_pngSize);
    
    quadImage = ImageCache::getFromMemory(BinaryData::Background_Quad_Semi_Final_png, BinaryData::Background_Quad_Semi_Final_pngSize);
    
    fivePointOneImage = ImageCache::getFromMemory(BinaryData::Background_5_1_Semi_Final_png, BinaryData::Background_5_1_Semi_Final_pngSize);
    
    sevenPointOneImage = ImageCache::getFromMemory(BinaryData::Background_7_1_Semi_Final_png, BinaryData::Background_7_1_Semi_Final_pngSize);
    
    octophonicImage = ImageCache::getFromMemory(BinaryData::Background_Octophonic_Semi_Final_png, BinaryData::Background_Octophonic_Semi_Final_pngSize);
    
    ninePointOneImage =ImageCache::getFromMemory(BinaryData::Inviro_Coming_soon_png, BinaryData::Inviro_Coming_soon_pngSize);
    
    
    
    if( processor.parameters.getParameter("outputmenu")->getValue() == 0)
    {
        bgImage = stereoImage;
      
    }
    
    else if(processor.parameters.getParameter("outputmenu")->getValue() == 1)
    {
        bgImage = quadImage;
        
        
    }
    
    else if(processor.parameters.getParameter("outputmenu")->getValue() == 2)
    {
        bgImage = fivePointOneImage;
        
        
    }
    
    else if(processor.parameters.getParameter("outputmenu")->getValue() == 3)
    {
        bgImage = sevenPointOneImage;
        
        
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
   
    
    g.setColour(Colours::ghostwhite);
    g.setFont (Font("Avenir", 45.0f, Font::italic));
    //g.drawFittedText("Inviro", 15 , 12, getWidth(), 50, Justification::centredTop, 1);
    
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
    
    outputMenu.setBounds(415, 55, 165, 20);
    
   
}




void MaggsA3AudioProcessorEditor::mouseDrag(const MouseEvent& m)
{
    
    if(m.mouseWasDraggedSinceMouseDown())
    {
        float newPanXValue = m.getDistanceFromDragStartX() + m.getMouseDownX();
        float newPanYValue = m.getDistanceFromDragStartY() + m.getMouseDownY();
        
        if(newPanXValue > 590)
        {
            newPanXValue = 590;
        }
        if(newPanXValue < 10)
        {
            newPanXValue = 10;
        }
        if(newPanYValue > 490)
        {
            newPanYValue = 490;
        }
        if(newPanYValue < 130)
        {
            newPanYValue = 130;
        }
        
        //map the values
        panXValue = jmap(newPanXValue, 10.0f, 590.0f, 0.0f, 1.0f);
        panYValue = jmap(newPanYValue, 130.0f, 490.0f, 0.0f, 1.0f);
      
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
    
    else if(output == 2)
    {
        bgImage = fivePointOneImage;
        repaint();
        
    }
    
    else if(output == 3)
    {
        bgImage = sevenPointOneImage;
        repaint();
        
    }
    
    else if(output == 4)
    {
        bgImage = octophonicImage;
        repaint();
        
    }
    
    else if(output == 5)
    {
        bgImage = ninePointOneImage;
        repaint();
        
    }
    
  
}

void MaggsA3AudioProcessorEditor::keepNodeInField(float &newX, float &newY, Node selectedNode)
{
    if (newX > 590)
        newX = 590;
    if (newX < 10)
        newX = 10;
    if (newY > 490)
        newY = 490;
    if (newY < 130)
        newY = 130;
}
