#ifndef __BG_DISK_SPRITE_H__
#define __BG_DISK_SPRITE_H__

#include "cocos2d.h"

class BGDiskSprite : public cocos2d::Sprite
{
public:
	BGDiskSprite();
	virtual ~BGDiskSprite();
	static BGDiskSprite* create(const std::string& filename);

	cocos2d::RepeatForever* _rotate;

	void StartRotate();
	void StopRotate();
};



#endif
