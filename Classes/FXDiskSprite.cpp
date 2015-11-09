#include "FXDiskSprite.h"

USING_NS_CC;

FXDiskSprite::FXDiskSprite()
{

}

FXDiskSprite::~FXDiskSprite()
{

}

FXDiskSprite* FXDiskSprite::create(const std::string& filename)
{
	FXDiskSprite *sprite = new (std::nothrow) FXDiskSprite();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void FXDiskSprite::RegistListener()
{
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
		Vec2 originV = Vec2(this->getPositionX(), this->getPositionY());

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


	

	};

	listener1->retain();

	(this->getParent())->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1, this);
}
