#include "interativeMgr.h"

#pragma region Interative Element
ofEvent<void> interativeMgr::interativeElement::_showTextFinish = ofEvent<void>();

//-------------------------------------------------
interativeMgr::interativeElement::interativeElement()
	:_eState(eState_Wait)
	,_isSetup(false)
{
	_animLoopAlpha.setDuration(0.5);
	_animLoopAlpha.setRepeatType(AnimRepeat::PLAY_ONCE);
	_animLoopAlpha.reset(0.0);

	_animTextAlpha.setDuration(1.0);
	_animTextAlpha.setRepeatType(AnimRepeat::PLAY_ONCE);
	_animTextAlpha.reset(0.0);
}

//-------------------------------------------------
bool interativeMgr::interativeElement::setup(string name)
{
	_isSetup = true;
	_isSetup &= _lightImg.loadImage("images/" + name + ".png");

	_loopText.setPlayer(ofPtr<ofxHapPlayer>(new ofxHapPlayer()));
	_isSetup &= _loopText.loadMovie("videos/" + name + "_loop.mov");
	_loopText.setLoopState(ofLoopType::OF_LOOP_NORMAL); 

	_textVideo.setPlayer(ofPtr<ofxHapPlayer>(new ofxHapPlayer()));	
	_isSetup &= _textVideo.loadMovie("videos/" + name + "_text.mov");
	_textVideo.setLoopState(ofLoopType::OF_LOOP_NONE);

	if(!_isSetup)
	{
		ofLog(OF_LOG_ERROR, "[interativeMgr]setup failed : " + name);
	}
	return _isSetup;
}

//-------------------------------------------------
void interativeMgr::interativeElement::update(float fDelta)
{
	if(!_isSetup)
	{
		return;
	}
	
	_animLoopAlpha.update(fDelta);
	_animTextAlpha.update(fDelta);

	if(_eState != eState_ShowText)
	{
		_loopText.update();
	}
	
	if(_eState != eState_Looping && _eState != eState_BacktoLooping)
	{
		_textVideo.update();
	}

	switch(_eState)
	{
	case eState_CrossFade:
		{
			if(_animTextAlpha.hasFinishedAnimating() && _animTextAlpha.getPercentDone() == 1.0)
			{
				_eState = eState_ShowText;
			}
		}
		break;
	case eState_ShowText:
		{
			if(_textVideo.getIsMovieDone())
			{
				BacktoLooping();
				ofNotifyEvent(_showTextFinish);
			}
		}
		break;
	case eState_BacktoLooping:
		{
			if(_animLoopAlpha.hasFinishedAnimating() && _animLoopAlpha.getPercentDone() == 1.0)
			{
				_eState = eState_Looping;
			}
		}
		break;
	}
}

//-------------------------------------------------
void interativeMgr::interativeElement::draw()
{
	if(!_isSetup)
	{
		return;
	}

	ofPushStyle();
	{
		ofPushMatrix();
		ofTranslate(_loopPos);
		{
			ofSetColor(255, 255, 255, _animLoopAlpha.getCurrentValue());
			_loopText.draw(_loopText.width * -0.5, _loopText.height * -0.5);
		}
		ofPopMatrix();			

		ofPushMatrix();
		ofTranslate(_imgPos);
		{
			ofSetColor(255, 255, 255, _animTextAlpha.getCurrentValue());
			_lightImg.draw(_lightImg.width * -0.5, _lightImg.height * -0.5);
		}
		ofPopMatrix();	
		
		if(_eState != eState_BacktoLooping && _eState != eState_Looping)
		{
			ofPushMatrix();
			ofTranslate(_textPos);
			{
				ofSetColor(255, 255, 255, _animTextAlpha.getCurrentValue());
				_textVideo.draw(_textVideo.width * -0.5, _textVideo.height * -0.5);
			
			}
			ofPopMatrix();	
		}
		
	}
	ofPopStyle();
}

//-------------------------------------------------
void interativeMgr::interativeElement::reset()
{
	_eState = eState_Wait;
	_animTextAlpha.reset(0.0);
	_animLoopAlpha.reset(0.0);
	
	_loopText.stop();
	_loopText.setFrame(0);
	_loopText.update();

	_textVideo.stop();
	_textVideo.setFrame(0);
	_textVideo.update();
}

//-------------------------------------------------
void interativeMgr::interativeElement::start()
{
	if(_eState == eState_Wait)
	{
		_eState = eState_BacktoLooping;
		_animLoopAlpha.animateFromTo(0.0, 255.0);
		_loopText.play();
	}
}

//-------------------------------------------------
bool interativeMgr::interativeElement::showText()
{
	if(_eState == eState_Looping)
	{
		_textVideo.play();
		_textVideo.setVolume(0.0);
		_eState = eState_CrossFade;
		_animLoopAlpha.animateTo(0.0);
		_animTextAlpha.animateFromTo(0.0, 255.0);
		return true;
	}
	return false;
}

//-------------------------------------------------
void interativeMgr::interativeElement::BacktoLooping()
{
	_eState = eState_BacktoLooping;
	_animTextAlpha.animateFromTo(255.0, 0.0);
	_animLoopAlpha.animateFromTo(0.0, 255.0);
	_textVideo.stop();
	_textVideo.setFrame(0);
	_textVideo.update();
}

//-------------------------------------------------
bool interativeMgr::interativeElement::getIsLoop()
{
	return _eState == eState_Looping;
}

//-------------------------------------------------
void interativeMgr::interativeElement::setPos(ofVec2f loopPos, ofVec2f textPos, ofVec2f imgPos)
{
	_textPos = textPos;
	_imgPos = imgPos;
	_loopPos = loopPos;
}

//-------------------------------------------------
void interativeMgr::interativeElement::setTextFadeDuration(float fduration)
{
	_animTextAlpha.setDuration(fduration);
}
#pragma endregion

#pragma region InterativeMgr
//-------------------------------------------------
void interativeMgr::setup()
{
	bool success_ = true;
	success_ &= addElement(eType_Massage);
	success_ &= addElement(eType_Flower);
	success_ &= addElement(eType_Food);
	success_ &= addElement(eType_Luxurious);
	success_ &= addElement(eType_Story);

	//Story button	
	_StoryBtnEnable = false;
	_StoryBtnTrigger = false;
	_canTrigger = true;
	_StorySelect.setPlayer(ofPtr<ofxHapPlayer>(new ofxHapPlayer));
	_StorySelect.setLoopState(ofLoopType::OF_LOOP_NONE);	
	_isStoryPlay = false;
	success_ &= _StorySelect.loadMovie("videos/storyLight.mov");

	_StoryCloseBtn.loadImage("images/btnClose.png");
	_storyAudio.loadSound("audios/story_text.mp3");

	_isSetup = success_;

	ofAddListener(interativeElement::_showTextFinish, this, &interativeMgr::onElementFinish);
}

//-------------------------------------------------
void interativeMgr::update(float delta, ofVec2f Ctrlpos)
{
	if(!_isSetup)
	{
		return;
	}

	for(auto& Iter_ : _elementMgr)
	{
		Iter_.second.update(delta);
	}
		
	updateStoryBtn();

	if(!_isStoryPlay)
	{
		if(!_canTrigger)
		{
			return;
		}
		//Mouse over check
		if(cINTERATIVE_MASSAGE_POS.distance(Ctrlpos) < cINTERATIVE_TRIGGER_DISTANCE)
		{
			if(_elementMgr[eType_Massage].showText())
			{
				_canTrigger = false;
			}
		}
		else if(cINTERATIVE_LUXURIOUS_POS.distance(Ctrlpos) < cINTERATIVE_TRIGGER_DISTANCE)
		{
			if(_elementMgr[eType_Luxurious].showText())
			{
				_canTrigger = false;
			}
		}
		else if(cINTERATIVE_FOOD_POS.distance(Ctrlpos) < cINTERATIVE_TRIGGER_DISTANCE)
		{
			if(_elementMgr[eType_Food].showText())
			{
				_canTrigger = false;
			}
		}
		else if(cINTERATIVE_FLOWER_POS.distance(Ctrlpos) < cINTERATIVE_TRIGGER_DISTANCE)
		{
			if(_elementMgr[eType_Flower].showText())
			{
				_canTrigger = false;
			}			
		}

		if(cINTERATIVE_STORY_POS.distance(Ctrlpos) < cINTERATIVE_TRIGGER_DISTANCE && _elementMgr[eType_Story].getIsLoop())
		{
			triggerStoryBtn(true);
		}
		else
		{
			triggerStoryBtn(false);
		}
	}
	else
	{
		if(cINTERATIVE_STORY_CLOSE.inside(Ctrlpos))
		{
			_elementMgr[eType_Story].BacktoLooping();
			_storyAudio.stop();
			_StoryBtnEnable = true;
			_isStoryPlay = false;
			bool storyPlay_ = false;
			ofNotifyEvent(_InterativeStoryEvent, storyPlay_);
		}
		else
		{
			bool storyNowPlaying_ = !_elementMgr[eType_Story].getIsLoop();

			if(storyNowPlaying_ == false && _isStoryPlay == true)
			{
				_storyAudio.stop();
				_StoryBtnEnable = true;
				_isStoryPlay = false;
				bool storyPlay_ = false;
				ofNotifyEvent(_InterativeStoryEvent, storyPlay_);
			} 
		}
	}
	
}

//-------------------------------------------------
void interativeMgr::draw()
{
	ofPushStyle();
	{
		
		for(auto& Iter_ : _elementMgr)
		{
			Iter_.second.draw();
		}

		ofSetColor(255);
		ofPushMatrix();
		ofTranslate(cINTERATIVE_STORY_POS);
		{
			_StorySelect.draw(_StorySelect.width * -0.5, _StorySelect.height * -0.5);
		}
		ofPopMatrix();

		if(_isStoryPlay)
		{
			ofSetColor(255);
			_StoryCloseBtn.draw(cINTERATIVE_STORY_CLOSE);
		}
	}
	ofPopStyle();
}

//-------------------------------------------------
void interativeMgr::reset()
{
	_StoryBtnEnable = false;
	_StoryBtnTrigger = false;
	_isStoryPlay = false;
	_canTrigger = true;

	for(auto& Iter_ : _elementMgr)
	{
		Iter_.second.reset();
	}
}

//-------------------------------------------------
bool interativeMgr::addElement(eInterativeType eType)
{
	bool bResult_ = true;
	interativeElement _newElement;

	switch(eType)
	{
	case eType_Massage:
		{
			_newElement.setPos(ofVec2f(420, 465), ofVec2f(420, 465), ofVec2f(420, 244));
			bResult_ &= _newElement.setup("massage");
		}
		break;
	case eType_Flower:
		{
			_newElement.setPos(ofVec2f(664, 953), ofVec2f(664, 953), ofVec2f(664, 734));
			bResult_ &= _newElement.setup("flower");
		}
		break;
	case eType_Food:
		{
			_newElement.setPos(ofVec2f(969, 465), ofVec2f(969, 465), ofVec2f(969, 244));
			bResult_ &= _newElement.setup("food");
		}
		break;
	case eType_Luxurious:
		{
			_newElement.setPos(ofVec2f(1240, 953), ofVec2f(1240, 953), ofVec2f(1240, 734));
			bResult_ &= _newElement.setup("luxurious");
		}
		break;
	case eType_Story:
		{
			_newElement.setPos(ofVec2f(1514, 465), ofVec2f(1920.0/2.0, 1080.0/2.0), ofVec2f(1514, 244));
			_newElement.setTextFadeDuration(2.0);
			bResult_ &= _newElement.setup("story");

		}
		break;
	}	

	if(bResult_)
	{
		_elementMgr.insert(make_pair(eType, _newElement));
	}

	return bResult_;
}

//-------------------------------------------------
void interativeMgr::startElement(eInterativeType eType)
{
	if(_elementMgr.find(eType) != _elementMgr.end())
	{
		_elementMgr[eType].start();
	}
}

//-------------------------------------------------
void interativeMgr::updateStoryBtn()
{
	if(!_StoryBtnEnable)
	{
		return;
	}

	if(_StoryBtnTrigger)
	{
		_StorySelect.update();
		if(_StorySelect.getIsMovieDone())
		{
			_StoryBtnEnable = false;
			_StorySelect.stop();
			_StorySelect.setFrame(0);
			_StorySelect.update();
			_StoryBtnTrigger = false;

			_isStoryPlay = true;
			_elementMgr[eType_Story].showText();
			_storyAudio.play();

			bool storyPlay_ = true;
			ofNotifyEvent(_InterativeStoryEvent, storyPlay_);
		}
	}
}

//-------------------------------------------------
void interativeMgr::enableStoryBtn()
{
	_StoryBtnEnable = true;
}

//-------------------------------------------------
void interativeMgr::onElementFinish()
{
	if(!_canTrigger)
	{
		_canTrigger = true;
	}
}

//-------------------------------------------------
void interativeMgr::triggerStoryBtn(bool bval)
{
	if(!_StoryBtnTrigger && bval)
	{
		_StorySelect.play();
		_StoryBtnTrigger = true;
		

	}
	else if(_StoryBtnTrigger && !bval)
	{
		_StorySelect.stop();
		_StorySelect.setFrame(0);
		_StorySelect.update();
		_StoryBtnTrigger = false;
	}
}
#pragma endregion

