/*
  ==============================================================================

    OutPutDrop.h
    Created: 7 Aug 2019 1:38:40pm
    Author:  Alex Maggs

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//==============================================================================
/*
*/
class OutPutDrop    : public Component,
                      private ComboBox::Listener
{
public:
    OutPutDrop(MaggsA3AudioProcessor&);
    ~OutPutDrop();

    void paint (Graphics&) override;
    void resized() override;
    
    void comboBoxChanged(ComboBox*) override;

private:
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OutPutDrop)
    
    ComboBox outputMenu;
    
    ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> outputBox;
    
    MaggsA3AudioProcessor& processor;
  
};
