#ifndef __MAIN_GAME_SCENE_H__
#define __MAIN_GAME_SCENE_H__

#include "cocos2d.h"
#include "audio/include/AudioEngine.h"

class MainGameScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCallbackBack(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(MainGameScene);

	int _backId;
	cocos2d::experimental::AudioProfile _audioProfile;

	float first_x1, first_y1;
	float move_x2, move_y2;
	float first_rotation;

};

#endif
