#include "ofChanelApp.h"

//--------------------------------------------------------------
void ofChanelApp::setup()
{
	ofBackground(0);
	ofSetVerticalSync(true);

	//Leap Motion
	_LeapController.addListener(_LeapListener);

	//Theatre
	_Theatre.setup();
	ofAddListener(_Theatre._TheatreEvent, this, &ofChanelApp::onChanelTheatreEvent);
	
	//Cursor
	setupCursor();

	//Timer
	_fMainTimer = ofGetElapsedTimef();
	_IdleTimer = -1;
	
	//BGM
	setupBGM();
	
	_useLeap = true;
	_showMouse = true;

#ifndef _DEBUG
	ofToggleFullscreen();
	ofHideCursor();
	_showMouse = false;
#endif//_DEBUG

	
}

//--------------------------------------------------------------
void ofChanelApp::update()
{
	auto fDelta_ = ofGetElapsedTimef() - _fMainTimer;
	_fMainTimer += fDelta_;

	//Leap
	if(_useLeap)
	{
		updateLeap();
	}
	else
	{
		_CtrlPos = ofVec2f(ofGetMouseX(), ofGetMouseY());
	}

	if(_IdleTimer > -1.0)
	{
		_IdleTimer -= fDelta_;
		if(!_IdleTrigger1 && _IdleTimer < cIDLE_TIME_TRIGGER_1)
		{
			_IdleTrigger1 = true;
			_Theatre.idleTriggerFirst();
		}

		if(!_IdleTrigger2 && _IdleTimer < cIDLE_TIME_TRIGGER_2)
		{
			_IdleTrigger2 = true;
			_Theatre.idleTriggerSecond();
			_IdleTimer = -1;
		}
	}

	_Theatre.update(fDelta_, _CtrlPos);
	updateBGM(fDelta_);
	ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofChanelApp::draw()
{
	//drawLeap();
	drawBeforeTheatre();
	_Theatre.draw();
	drawAfterTheatre();
}

//--------------------------------------------------------------
void ofChanelApp::keyPressed(int key)
{
	switch(key)
	{
	case 'n':
		{
			_Theatre._Director.TransitTo(NAME_MGR::S_Product);
			break;
		}
	case 't':
		{
			_Theatre.displayIntro();
			break;
		}
	case 'c':
		{
			_showMouse ^= true;
			if(_showMouse)
			{
				ofShowCursor();
			}
			else
			{
				ofHideCursor();
			}
			break;
		}
	case 'f':
		{
			ofToggleFullscreen();
			break;
		}
	case 'm':
		{
			_useLeap	^= true;
			break;
		}
	}
}

#pragma region Theatre
//--------------------------------------------------------------
void ofChanelApp::drawBeforeTheatre()
{
}

//--------------------------------------------------------------
void ofChanelApp::drawAfterTheatre()
{
	drawCursor(_CtrlPos);
}

//--------------------------------------------------------------
void ofChanelApp::onChanelTheatreEvent(string& e)
{
	if(e == NAME_MGR::T_DISABLE_CURSOR)
	{
		setCursor(false);
	}
	else if(e == NAME_MGR::T_ENABLE_CURSOR)
	{
		setCursor(true);
	}
	else if(e == NAME_MGR::T_ENABLE_BGM)
	{
		setBGM(true);
	}
	else if(e == NAME_MGR::T_DISABLE_BGM)
	{
		setBGM(false);
	}
	else if(e == NAME_MGR::T_RESET_IDLE)
	{
		if(!_HaveUser)
		{
			_IdleTimer = cIDLE_TIME_DURATION;
			_IdleTrigger1 = false;
			_IdleTrigger2 = false;
		}
	}
	else if(e == NAME_MGR::T_RESET)
	{
		setCursor(false);
		_HaveUser = false;
	}
}

#pragma endregion

#pragma region Leap Motion
//------------------------------------------
//LeapMotion
//------------------------------------------
void ofChanelApp::updateLeap()
{
	bool bHaveUser_ = _LeapListener.GetCtrlFingerPos(_CtrlPos);
	
	if(bHaveUser_ && !_HaveUser)
	{
		//player in
		_IdleTimer = -1;
	}
	else if(!bHaveUser_ && _HaveUser)
	{
		//player out
		_IdleTimer = cIDLE_TIME_DURATION;
		_IdleTrigger1 = false;
		_IdleTrigger2 = false;
	}

	if(bHaveUser_)
	{
		_Theatre.displayIntro();
	}
	_HaveUser = bHaveUser_;
}

//--------------------------------------------------------------
void ofChanelApp::drawLeap()
{
#ifdef _DEBUG
	if(_HaveUser)
	{
		ofPushStyle();
		{
			ofSetColor(255);
			ofCircle(_CtrlPos, 10);
		}
		ofPopStyle();
	}
#endif //_DEBUG	
}
#pragma endregion

#pragma region BGM
//--------------------------------------------------------------
void ofChanelApp::setupBGM()
{
	_bgm.loadSound("audios/bgm.mp3");
	_bgm.setLoop(true);
	_bgm.play();
	_bgm.setVolume(1.0);

	_animVol.setDuration(1.0);
	_animVol.reset(1.0);
}

//--------------------------------------------------------------
void ofChanelApp::updateBGM(float fDelta)
{
	_animVol.update(fDelta);

	if(_animVol.isAnimating())
	{
		_bgm.setVolume(_animVol.getCurrentValue());
	}
	
}

//--------------------------------------------------------------
void ofChanelApp::setBGM(bool val)
{
	if(val)
	{
		_animVol.animateFromTo(0.0, 1.0);
	}
	else
	{
		_animVol.animateFromTo(1.0, 0.0);
	}	
}

#pragma endregion

#pragma region Cursor
void ofChanelApp::setupCursor()
{
	if(!_cursor.loadImage("images/cursor.png"))
	{
		ofLog(OF_LOG_ERROR, "[Cursor]Load cursor image failed");
	}
	_drawCursor = false;
}

//-------------------------------------------------
void ofChanelApp::drawCursor(ofVec2f pos)
{
	if(_HaveUser &&  _drawCursor && _cursor.isAllocated())
	{
		ofPushStyle();
		ofSetColor(255);
		{
			_cursor.draw(pos);
		}
		ofPopStyle();
	}
}

//-------------------------------------------------
void ofChanelApp::setCursor(bool val)
{
	_drawCursor = val;
}
#pragma endregion
