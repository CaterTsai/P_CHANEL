#ifndef _CT_LEAP_MOTION_
#define _CT_LEAP_MOTION_

#include "ofMain.h"
#include "Leap.h"

using namespace Leap;

const Finger::Type cCTRL_FINGER_ID = Finger::Type::TYPE_INDEX;

//struct stFINGER_POINT
//{
//	ofPoint		Position;
//	bool		bIsTap;
//
//	stFINGER_POINT():bIsTap(false), Position(0){};
//};

class LeapMotionListener : public Listener
{
public:
	LeapMotionListener();

public:
	//Basic function
	virtual void onInit(const Controller& controller);
	virtual void onConnect(const Controller& controller);
    virtual void onDisconnect(const Controller& controller);
	virtual void onFrame(const Controller& controller);

public:
	bool GetCtrlFingerPos(ofPoint &CtrlFingerPos);

private:
	bool	_bHaveHand;
	ofPoint	_CtrlFingerPos;
};


#endif //_CT_LEAP_MOTION_