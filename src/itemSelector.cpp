#include "itemSelector.h"

void itemSelector::setup()
{
	_itemSelector.setPlayer(ofPtr<ofxHapPlayer>(new ofxHapPlayer));
	_itemSelector.setLoopState(ofLoopType::OF_LOOP_NONE);
	_itemSelector.loadMovie("videos/btnlightItem.mov");

	_clickAudio.loadSound("audios/click.wav");
	_clickAudio.setLoop(false);
	_clickAudio.setMultiPlay(true);

	_pos.set(0);
	_startCheck = false;
	_Callback = nullptr;
}

//-------------------------------------------------
void itemSelector::update()
{
	if(!_startCheck)
	{
		return;
	}

	_itemSelector.update();
	if(_itemSelector.getIsMovieDone())
	{	
		if(_Callback)
		{
			_clickAudio.play();
			_Callback();
		}
		stopCheck();
	}

}

//-------------------------------------------------
void itemSelector::draw()
{
	if(!_startCheck)
	{
		return;
	}

	ofPushStyle();
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	ofSetColor(255);
	{
		_itemSelector.draw(_pos);
	}
	ofPopStyle();
}

//-------------------------------------------------
void itemSelector::startCheck(std::function<void()> callback, ofVec2f pos)
{
	_Callback = callback;
	_pos = pos;
	_itemSelector.play();

	_startCheck = true;
}

//-------------------------------------------------
void itemSelector::stopCheck()
{
	_Callback = nullptr;
	_startCheck = false;
	_itemSelector.stop();
	_itemSelector.setFrame(0);
	_itemSelector.update();

}