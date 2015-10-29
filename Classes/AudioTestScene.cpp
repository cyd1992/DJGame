#include "AudioTestScene.h"
#include "MenuScene.h"
#include "AudioComponent.h"

USING_NS_CC;
using namespace cocos2d::experimental;

Scene* AudioTestScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = AudioTestScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool AudioTestScene::init()
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
	auto closeItem = MenuItemFont::create("Back", CC_CALLBACK_1(AudioTestScene::menuCallbackBack, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	auto sprite1 = Sprite::create("CyanSquare.png");
	sprite1->setPosition(Vec2(visibleSize.width * 0.2, visibleSize.height * 0.2) );
// 	CCLOG("%f-----%f",visibleSize.width ,visibleSize.height);
// 	CCLOG("%f-----%f", origin.x, origin.y);
	addChild(sprite1, 10);


	//audio
	_audioCount = 0;
	_minDelay = 1.0f;
	_time = 0.0f;
	_backFlag = false;

	_audioProfile.name = "AudioTestScene";
	_audioProfile.maxInstances = 3;
	_audioProfile.minDelay = 0.1;


	// Make sprite1 touchable
	auto listener1 = EventListenerTouchOneByOne::create();
	listener1->setSwallowTouches(true);

	listener1->onTouchBegan = [&](Touch* touch, Event* event) {
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);
		
		//log("touched!");

		if (rect.containsPoint(locationInNode))
		{
			//auto temp =  static_cast<AudioTestScene*>(target->getParent());
			

			log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
			target->setOpacity(180);

			//if (_backFlag == false) {

				_backFlag = true;
				_idBack = AudioEngine::play2d("music/t2.mp3", false, 1.0f, &_audioProfile);
				int id = _idBack;
				log("_idBack: %d", _idBack);
				AudioEngine::setFinishCallback(id, [&](int id, const std::string& filePath) {
					_audioCount -= 1;
					log("finished!");
					_backFlag = false;
				});
				if (id != AudioEngine::INVALID_AUDIO_ID) {
					_time = _minDelay;
					_audioCount += 1;
					//char show[30];
					//sprintf(show, "audio count:%d", _audioCount);
					//_showLabel->setString(show);
					log("_idBack: %d", _idBack);
					
				}
			//}

			return true;
		}

		

		return false;
	};

	listener1->onTouchMoved = [](Touch* touch, Event* event) {
// 		auto target = static_cast<Sprite*>(event->getCurrentTarget());
// 		target->setPosition(target->getPosition() + touch->getDelta());
		//log("moved!");
	};

	listener1->onTouchEnded = [=](Touch* touch, Event* event) {
 		auto target = static_cast<Sprite*>(event->getCurrentTarget());
// 		log("sprite onTouchesEnded.. ");
 		target->setOpacity(255);

		auto temp = static_cast<AudioTestScene*>(target->getParent());

		AudioEngine::stop(temp->_idBack);
// 		if (target == sprite2)
// 		{
// 			containerForSprite1->setLocalZOrder(100);
// 		}
// 		else if (target == sprite1)
// 		{
// 			containerForSprite1->setLocalZOrder(0);
// 		}

		//log("moved!");
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, sprite1);

	auto drumSprite = DrumSprite::create("CyanSquare.png");
	drumSprite->setPosition(Vec2(visibleSize.width * 0.4, visibleSize.height * 0.2));
	drumSprite->setMusicFile("music/t1.mp3");

	addChild(drumSprite, 10);

	drumSprite->RegistListener();

	

	return true;
}


void AudioTestScene::menuCallbackBack(Ref* pSender)
{
	Director::getInstance()->replaceScene(MenuScene::createScene());

}
