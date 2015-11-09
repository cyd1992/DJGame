#ifndef __DRUM_PANEL1_H__
#define __DRUM_PANEL1_H__

#include "cocos2d.h"
#include "DJPanel.h"

#include "audio/include/AudioEngine.h"

class DrumPanel1 : public DJPanel
{
public:
	static DrumPanel1 *create();
	virtual bool init();

	cocos2d::experimental::AudioProfile _audioProfile;

};



#endif
