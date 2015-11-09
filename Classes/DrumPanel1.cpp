#include "DrumPanel1.h"

#include "AudioComponent.h"

USING_NS_CC;

DrumPanel1 * DrumPanel1::create()
{
	DrumPanel1 *ret = new (std::nothrow) DrumPanel1();
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

bool DrumPanel1::init()
{
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	visibleSize.width = visibleSize.width / 2;

	//add color layer
	auto layer1 = LayerColor::create(Color4B(192, 0, 0, 50));

	addChild(layer1, 0);

	//audio profile
	_audioProfile.name = "DrumPanel";
	_audioProfile.maxInstances = 3;
	_audioProfile.minDelay = 0.1;

	//add drums
	auto drumSprite = DrumSprite::create("CyanSquare.png");
	drumSprite->setPosition(Vec2(visibleSize.width * 0.34, visibleSize.height * 0.2));
	drumSprite->setMusicFile("music/beat1.mp3");

	addChild(drumSprite, 10);

	drumSprite->RegistListener(_audioProfile);

	auto drumSprite2 = DrumSprite::create("CyanSquare.png");
	drumSprite2->setPosition(Vec2(visibleSize.width * 0.6, visibleSize.height * 0.2));
	drumSprite2->setMusicFile("music/beat2.mp3");

	addChild(drumSprite2, 10);

	drumSprite2->RegistListener(_audioProfile);

	return true;
}


