#include "DJScheduler.h"
#include "XMLParserUtil.h"
#include "NoteInfo.h"
#include "DrumPanel1.h"
#include "AudioComponent.h"

USING_NS_CC;
//float DJScheduler::_time = 0.0f;
int DJScheduler::_id = 0;


void DJScheduler::callback1(float dt)
{
	
	if(_id<XMLParseUtil::_vec.size())
	_note = (NoteInfo)XMLParseUtil::_vec.at(_id);

	Size visibleSize = Director::getInstance()->getVisibleSize();

	//CCLOG("time: %f",_time);
	if (_time < 60.0f)
	{
		float note_time = _note._time;
		float pre_time = _time + 1.5;
		if (abs(note_time - pre_time) < 0.01)
		{
			//drumpane's tag is 101;
			DrumPanel1* panel = (DrumPanel1*)(this->getParent()->getChildByTag(101));

			//note test
			auto noteSprite = NoteSprite::create("note.png");
			if(_note._index == 0) noteSprite->setPosition(visibleSize.width *0.17, visibleSize.height *1.2);
			else if(_note._index == 1) noteSprite->setPosition(visibleSize.width *0.3, visibleSize.height *1.2);
			noteSprite->setOpacity(100);
			panel->addChild(noteSprite);
			noteSprite->StartDrop();

			_id++;
		}

		_time += dt;
		//CCLOG("dt: %f    time: %f", dt,_time);
	}
}

void DJScheduler::StartTimer()
{
	schedule(CC_SCHEDULE_SELECTOR(DJScheduler::callback1), 0.1f);
}

DJScheduler* DJScheduler::create()
{
	DJScheduler * ret = new (std::nothrow) DJScheduler();
	if (ret && ret->init())
	{
		ret->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(ret);
	}
	return ret;
}



