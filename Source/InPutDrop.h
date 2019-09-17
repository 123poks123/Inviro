/*
  ==============================================================================

    InPutDrop.h
    Created: 7 Aug 2019 2:02:32pm
    Author:  Alex Maggs

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//==============================================================================
/*
*/
class InPutDrop    : public Component,
                     private ComboBox::Listener
{
public:
    InPutDrop(MaggsA3AudioProcessor&);
    ~InPutDrop();

    void paint (Graphics&) override;
    void resized() override;
    
    void comboBoxChanged(ComboBox*) override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (InPutDrop)
    ComboBox inputMenu;
    
    ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> inputBox;
    
    MaggsA3AudioProcessor& processor;
};
