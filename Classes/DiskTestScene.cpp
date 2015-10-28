#include "DiskTestScene.h"
#include "MenuScene.h"

#include "math.h"

USING_NS_CC;

Scene* DiskTestScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = DiskTestScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool DiskTestScene::init()
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
	auto closeItem = MenuItemFont::create("Back", CC_CALLBACK_1(DiskTestScene::menuCallbackBack, this));

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


	// add disk sprite
	auto sprite = Sprite::create("disk.png");

	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	//sprite->setOpacity(0);
	first_rotation = 0.0;
	
	// Make sprite1 touchable
	auto listener1 = EventListenerTouchOneByOne::create();
	listener1->setSwallowTouches(true);

	listener1->onTouchBegan = [&](Touch* touch, Event* event) {
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);

		//log("touched!");
		log("sprite began... x = %f, y = %f", touch->getLocation().x, touch->getLocation().y);
		if (rect.containsPoint(locationInNode))
		{
			//auto temp =  static_cast<AudioTestScene*>(target->getParent());

			first_x1 = touch->getLocation().x;//locationInNode.x;
			first_y1 = touch->getLocation().y;//locationInNode.y;
			first_rotation = target->getRotation();//((Sprite*)(target->getParent()->getChildByTag(100)))->getRotation();
			//log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
			//target->setOpacity(180);
			

			
			return true;
		}



		return false;
	};

	listener1->onTouchMoved = [&](Touch* touch, Event* event) {
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		//target->setPosition(target->getPosition() + touch->getDelta());
		//target->setRotation();
		Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
		move_x2 = touch->getLocation().x;//locationInNode.x;
		move_y2 = touch->getLocation().y;// locationInNode.y;
		
		//log("sprite move... x = %f, y = %f", touch->getLocation().x, touch->getLocation().y);
		Vec2 originV = Vec2(480, 270);

		float x1 = first_x1;
		float y1 = first_y1;

		Vec2 p1 = Vec2(x1, y1) - originV;
		Vec2 p2 = Vec2(move_x2, move_y2) - originV;
		
// 		float a = originV.getDistance(Vec2(first_x1, first_y1));
// 		float b = originV.getDistance(Vec2(move_x2, move_y2));
// 		float c = (Vec2(first_x1, first_y1)).getDistance(Vec2(move_x2, move_y2));

		//float cosin = (a*a + b*b - c*c) / (2 * a*b);


		float angle = p2.getAngle(p1);
		//if (angle > 179.99) angle += 180;
		//if (angle < -179.99) angle -= 180;
// 		float delta_x = first_x1 - move_x2;
// 		float delta_y = first_y1 - move_x2;

		//log("sprite began... x = %f, y = %f , angle = %f", touch->getLocation().x, touch->getLocation().y, angle*180/3.1415);

		//((Sprite*)(target->getParent()->getChildByTag(100)))->setRotation(first_rotation + angle * 180.0 / 3.1415);
		target->setRotation(first_rotation + angle * 180.0 / 3.1415);
	};

	listener1->onTouchEnded = [&](Touch* touch, Event* event) {
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		

// 		Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
// 		move_x2 = locationInNode.x;
// 		move_y2 = locationInNode.y;
// 
// 		Vec2 originV = Vec2(480.0, 270.0);
// 
// 		Vec2 p1 = Vec2(first_x1, first_y1) - originV;
// 		Vec2 p2 = Vec2(move_x2, move_y2) - originV;
// 
// 		float angle = p2.getAngle(p1);
// 
// 		log(" x1 = %f, y1 = %f ", first_x1, first_y1);
// 		log(" x2 = %f, y2 = %f ", move_x2, move_y2);
// 
// 		log("angle = %f ", angle *2*180.0/3.1415);

	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, sprite);



	// add the sprite as a child to this layer
	this->addChild(sprite, 0);



	return true;
}


void DiskTestScene::menuCallbackBack(Ref* pSender)
{
	Director::getInstance()->replaceScene(MenuScene::createScene());

}
