#ifndef __FX_DISK_SPRITE_H__
#define __FX_DISK_SPRITE_H__

#include "cocos2d.h"

class FXDiskSprite : public cocos2d::Sprite
{
public:
	FXDiskSprite();
	virtual ~FXDiskSprite();
	static FXDiskSprite* create(const std::string& filename);

	float first_x1, first_y1;
	float move_x2, move_y2;
	float first_rotation;

	void RegistListener();


};



#endif
