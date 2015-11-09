#include "DiskPanel1.h"

#include "BGDiskSprite.h"

USING_NS_CC;

DiskPanel1 *DiskPanel1::create()
{
	DiskPanel1 *ret = new (std::nothrow) DiskPanel1();
	if (ret && ret->init())
	{
		ret->autorelease();
		return ret;
	}
	else
	{
		CC_SAFE_DELETE(ret);
		return nullptr;
	}
}

bool DiskPanel1::init()
{
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	//add color layer
	auto layer1 = LayerColor::create(Color4B(0, 0, 192, 50));

	addChild(layer1, 0);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	visibleSize.width = visibleSize.width / 2;

	auto sprite2 = BGDiskSprite::create("disk.png");
	sprite2->setScale(0.75);

	sprite2->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(sprite2, 1);

	sprite2->StartRotate();

	return true;
}