#pragma once

#include "constParameter.h"
#include "ofxCTLeapMotion.h"
#include "ChanelTheatre.h"

class ofChanelApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
		
private:
	float _fMainTimer, _IdleTimer;
	bool  _IdleTrigger1, _IdleTrigger2;
	bool _useLeap, _showMouse;
#pragma region Theatre
public:
	void drawBeforeTheatre();
	void drawAfterTheatre();
	void onChanelTheatreEvent(string& e);
private:
	ChanelTheatre		_Theatre;
#pragma endregion

#pragma region Leap Motion
//------------------------------------------
//LeapMotion
//------------------------------------------
public:
	void updateLeap();
	void drawLeap();

private:
	bool								_HaveUser;
	ofPoint							_CtrlPos;
	LeapMotionListener	_LeapListener;
	Leap::Controller			_LeapController;
#pragma endregion

#pragma region BGM
public:
	void setupBGM();
	void updateBGM(float fDelta);
	void setBGM(bool val);

private:
	ofxAnimatableFloat	_animVol;
	ofSoundPlayer	_bgm;
#pragma endregion

#pragma region Cursor
private:
	void setupCursor();
	void drawCursor(ofVec2f pos);
	void setCursor(bool val);
private:
	bool _drawCursor;
	ofImage _cursor;
#pragma endregion

};
