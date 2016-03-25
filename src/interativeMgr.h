#ifndef P_CHANEL_INTERATIVE_MGR
#define P_CHANEL_INTERATIVE_MGR

#include "constParameter.h"
#include "ofxAnimatableFloat.h"
#include "ofxHapPlayer.h"

enum eInterativeType
{
	eType_Massage = 0
	,eType_Flower
	,eType_Food
	,eType_Luxurious
	,eType_Story
};

class interativeMgr
{

#pragma region Interative Element
private:

	class interativeElement
	{
	public:
		interativeElement();
		bool setup(string name);
		void update(float fDelta);
		void draw();

		void reset();
		void start();		
		bool showText();
		void BacktoLooping();
		bool getIsLoop();

		void setPos(ofVec2f loopPos, ofVec2f textPos, ofVec2f imgPos);
		void setTextFadeDuration(float fduration);
	private:
		enum eState
		{	
			eState_Wait = 0
			,eState_Looping
			,eState_CrossFade
			,eState_ShowText
			,eState_BacktoLooping
		}_eState;

		bool _isSetup;
		ofxAnimatableFloat _animLoopAlpha, _animTextAlpha;
		ofVideoPlayer	_loopText, _textVideo;
		ofImage	_lightImg;
		ofVec2f _textPos, _loopPos, _imgPos;

	public:
		static ofEvent<void>	_showTextFinish;
	};
#pragma endregion

public:
	interativeMgr()
		:_isSetup(false)
		,_isStoryPlay(false)
		,_canTrigger(true)
	{}
	void setup();
	void update(float delta, ofVec2f Ctrlpos);
	void draw();
	void reset();

	bool addElement(eInterativeType eType);
	void startElement(eInterativeType eType);

	void enableStoryBtn();	
	void onElementFinish();
private:
	void updateStoryBtn();	
	void triggerStoryBtn(bool bval);

private:
	bool _isSetup, _isStoryPlay, _canTrigger;
	bool _StoryBtnEnable, _StoryBtnTrigger;

	ofVideoPlayer	_StorySelect;
	map<eInterativeType, interativeElement> _elementMgr;
	ofImage	_StoryCloseBtn;

	ofSoundPlayer	_storyAudio;

public:
	ofEvent<bool>	_InterativeStoryEvent;
};

#endif // !P_CHANEL_INTERATIVE_MGR