#ifndef P_CHANEL_THEATRE
#define P_CHANEL_THEATRE

#include "constParameter.h"
#include "ofxTheatreDirector.h"
#include "ofxHapPlayer.h"
#include "ofxAnimatableFloat.h"

#include "itemSelector.h"
#include "flowerMgr.h"
#include "interativeMgr.h"

class ChanelTheatre
{
public:
	void setup();
	void update(float fDelta, ofVec2f CtrlPos = ofVec2f(0));
	void draw();

	void nextScence();
	void resetTheatre();

	void AnimInit(string strName);
	void onTheatreEvent(ofxTheatreEventArgs& e);

public:
	ofxDirector	_Director;
	float	_fTimer;
//------------------------------------
//Sun light
//------------------------------------
private:
	void initSunlight();
	void updateSunlight(float fDelta);
	void drawSunlight();

	void setSunlight(bool val);

private:
	ofxAnimatableFloat	_sunLightAlpha;
	ofVideoPlayer	_sunLight;

//------------------------------------
//Item Selector
//------------------------------------
private:
	itemSelector	_itemSelector;

//------------------------------------
//Idle Trigger
//------------------------------------
public:
	void idleTriggerFirst();
	void idleTriggerSecond();

//-------------------------------
// @Scenes : Start
//-------------------------------
public:
	void displayIntro();
	bool canGoBack();
private:
	void initStart();
	void updateStart(ofVec2f ctrl);
	void drawStart();

	void enableStartBtn();	
	void triggerStartBtn(bool bval);
	
private:
	ofVideoPlayer		_StartBtnLight;
	ofSoundPlayer	_clickAudio;
	bool					_StartBtnEnable, _StartBtnTrigger;
	bool					_CanDisplayIntro, _DisplayIntro;

//------------------------------------
//flowerMgr
private:
	flowerMgr	_flowerMgr;

//-------------------------------
// @Scenes : Plant
//-------------------------------
private:
	void updatePlant(ofVec2f ctrl);

private:
	bool _bEnablePlantCtrl;
	int _iBtnIndex;

//-------------------------------
// @Scenes : Pollination
//-------------------------------
private:
	void updatePollination(ofVec2f ctrl);

private:
	bool _bEnablePollinationCtrl;
	bool _bPollinationTrigger;

//-------------------------------
// @Scenes : Harvest
//-------------------------------
private:
	void updateHarvest(ofVec2f ctrl);

private:
	bool _bEnableHarvestCtrl;
	bool _bHarvestTrigger;

//-------------------------------
// @Scenes : Interative
//-------------------------------
private:
	void updateInterative(ofVec2f ctrl);

private:
	bool _bEnableInterativeCtrl;
	bool _bInterativeTrigger;

//------------------------------------
//interativeMgr
private:
	void onInteratvieStory(bool& e);

private:
	interativeMgr	_interativeMgr;

////////////////////////////
//EVENT
////////////////////////////
public:
	ofEvent<string>	_TheatreEvent;
};
#endif // !P_CHANEL_THEATRE