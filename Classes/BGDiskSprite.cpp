#include "BGDiskSprite.h"

USING_NS_CC;

BGDiskSprite::BGDiskSprite()
{
	_rotate = RepeatForever::create(RotateBy::create(10, 360));
}

BGDiskSprite::~BGDiskSprite()
{

}

BGDiskSprite* BGDiskSprite::create(const std::string& filename)
{
	BGDiskSprite *sprite = new (std::nothrow) BGDiskSprite();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void BGDiskSprite::StartRotate()
{
	this->runAction(_rotate);
}

void BGDiskSprite::StopRotate()
{
	this->stopAction(_rotate);
}


