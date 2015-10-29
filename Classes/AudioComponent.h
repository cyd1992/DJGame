#ifndef __AUDIO_COMPONENT_SCENE_H__
#define __AUDIO_COMPONENT_SCENE_H__

#include "cocos2d.h"

#include "audio/include/AudioEngine.h"

#include <string>

class DrumSprite : public cocos2d::Sprite
{
public:
	DrumSprite();
	virtual ~DrumSprite();

	int _id = 6;

	static DrumSprite* create(const std::string& filename);

	static cocos2d::experimental::AudioProfile _audioProfile;

	void setMusicFile(const std::string& musicFile);
	
	void RegistListener();

	std::string* _musicFile;

};






#endif
