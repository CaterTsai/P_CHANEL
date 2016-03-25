#include "ofxCTLeapMotion.h"

LeapMotionListener::LeapMotionListener():
	_bHaveHand(false),
	_CtrlFingerPos(0)
{}

//--------------------------------------------------------------
void LeapMotionListener::onInit(const Controller& controller)
{
	ofLog(OF_LOG_NOTICE, "Leap Motion Initialzied");
}

//--------------------------------------------------------------
void LeapMotionListener::onConnect(const Controller& controller)
{
	ofLog(OF_LOG_NOTICE, "Leap Motion Connected");
}

//--------------------------------------------------------------
void LeapMotionListener::onDisconnect(const Controller& controller)
{
	ofLog(OF_LOG_NOTICE, "Leap Motion Disconnected");
}

//--------------------------------------------------------------
void LeapMotionListener::onFrame(const Controller& controller)
{
	const Frame LeapFrame_ = controller.frame();
	if(LeapFrame_.hands().count() > 0)
	{
		_bHaveHand = true;
		
		const FingerList FingersList_ = LeapFrame_.fingers();
		for(auto Iter_ = FingersList_.begin(); Iter_ != FingersList_.end(); ++Iter_)
		{
			if((*Iter_).type() != cCTRL_FINGER_ID)
			{
				continue;
			}

			Vector Vec_ = (*Iter_).tipPosition();
			_CtrlFingerPos.x = ofMap(Vec_.x, -200, 200, 0, ofGetWindowWidth());
			_CtrlFingerPos.y = ofGetHeight() - ofMap(Vec_.y, 100, 400, 0, ofGetWindowHeight());
		}
	}
	else
	{
		_bHaveHand = false;
	}
}

//--------------------------------------------------------------
bool LeapMotionListener::GetCtrlFingerPos(ofPoint &CtrlFingerPos)
{
	CtrlFingerPos.set(0);
	if(_bHaveHand)
	{
		CtrlFingerPos = _CtrlFingerPos;
	}
	return _bHaveHand;
}