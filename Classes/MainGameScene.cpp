#include "MainGameScene.h"
#include "MenuScene.h"

#include "math.h"
#include "AudioComponent.h"

#include "DiskPanel1.h"
#include "DrumPanel1.h"

#include "DJScheduler.h"

#include "XMLParserUtil.h"

USING_NS_CC;
using namespace cocos2d::experimental;

Scene* MainGameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MainGameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MainGameScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemFont::create("Back", CC_CALLBACK_1(MainGameScene::menuCallbackBack, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	////////////////////////////

	//sprite2 
	//auto sprite2 = Sprite::create("disk.png");
	//sprite2->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height*0.5 + origin.y));
	//sprite2->setScale(0.25f);
	//sprite2->setTag(100);

	//this->addChild(sprite2, 10);

	//preload music
	AudioEngine::preload("music/beat1.mp3", [](bool isSuccess) {
		if (isSuccess)
		{
			//stateLabel->setString("status:load success");
			log("load music/beat1.mp3  succeed!");
		}
		else
		{
			//stateLabel->setString("status:load fail");
			log("load music/beat1.mp3  failed!");
		}
	});

	AudioEngine::preload("music/lv1/back1.mp3", [](bool isSuccess) {
		if (isSuccess)
		{
			//stateLabel->setString("status:load success");
			log("load music/beat1.mp3  succeed!");
		}
		else
		{
			//stateLabel->setString("status:load fail");
			log("load music/beat1.mp3  failed!");
		}
	});

	// panel test
	auto panel = DrumPanel1::create();//LayerColor::create(Color4B(192,0,0,100));
									  //panel->ignoreAnchorPointForPosition(false);
	panel->setPosition(0, 0);
	panel->setTag(101);
	//panel->setColor(Color3B(192, 0, 0));
	addChild(panel, 0);


	auto panel2 = DiskPanel1::create();//LayerColor::create(Color4B(192,0,0,100));
									  //panel->ignoreAnchorPointForPosition(false);
	panel2->setPosition(visibleSize.width / 2, 0);
	//panel->setColor(Color3B(192, 0, 0));
	addChild(panel2, 1);

	// scheduler test
	auto sche = DJScheduler::create();
	addChild(sche);
	//sche->schedule(CC_SCHEDULE_SELECTOR(DJScheduler::callback1), 0.2f);
	//audio profile
	_audioProfile.name = "MainGameScene";
	_audioProfile.maxInstances = 3;
	_audioProfile.minDelay = 0.1;

	XMLParseUtil::ParseLevel("level/level1.xml");
	XMLParseUtil::PrintVec();

	_backId = AudioEngine::play2d("music/lv1/back1.mp3", false, 1.0f, &_audioProfile);
	log("backid: %d", _backId);
	//start back music


	sche->StartTimer();

	//note test
// 	auto note = NoteSprite::create("note.png");
// 	note->setPosition(visibleSize.width *0.17, visibleSize.height *1.2);
// 	panel->addChild(note);
// 	note->StartDrop();



	return true;
}


void MainGameScene::menuCallbackBack(Ref* pSender)
{
	log("backid: %d", _backId);
	AudioEngine::stop(_backId);
	
	Director::getInstance()->replaceScene(MenuScene::createScene());

}
