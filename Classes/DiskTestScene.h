#ifndef __DISK_SCENE_H__
#define __DISK_SCENE_H__

#include "cocos2d.h"

class DiskTestScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCallbackBack(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(DiskTestScene);

	float first_x1, first_y1;
	float move_x2, move_y2;
	float first_rotation ;

};

#endif // __HELLOWORLD_SCENE_H__

