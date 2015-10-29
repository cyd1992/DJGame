//Author by CYD
#ifndef __AUDIOTEST_SCENE_H__
#define __AUDIOTEST_SCENE_H__

#include "cocos2d.h"

#include "audio/include/AudioEngine.h"

class AudioTestScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCallbackBack(cocos2d::Ref* pSender);
	void menuCallbackPlay(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(AudioTestScene);

	cocos2d::MenuItemFont* playItem;
	cocos2d::experimental::AudioProfile _audioProfile;
	float _time;
	float _minDelay;
	int _audioCount;
	int _idBack;
	bool _backFlag;
};

#endif // __HELLOWORLD_SCENE_H__#pragma once
