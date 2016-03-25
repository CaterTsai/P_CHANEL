#ifndef P_CHANEL_FLOWER_MGR
#define P_CHANEL_FLOWER_MGR

#include "constParameter.h"
#include "ofxAnimatableFloat.h"

enum eFlowerType
{
	eFlower_1	=	0
	,eFlower_2
};

class flowerMgr
{
#pragma region flower
private:
	class flower
	{
	public:
		flower(eFlowerType etype);
		void update(float fdelta);
				
		bool startAnim();

		//----
		//get
		bool getDie();
		bool getAnimStart();
		float getRotate();
		float getScale();
		float getAnimPrec();
		ofVec2f getPos();
		eFlowerType getType();

	private:
		bool _isDie, _AnimStart;
		ofVec2f _pos, _vec;
		float _degree, _rVec, _fscale;
		ofxAnimatableFloat	_animPrec;
		eFlowerType	_eType;
	};
#pragma endregion

public:
	flowerMgr()
		:_fTimer(0.0)
		,_isStart(false)
		,_isSetup(false)
		,_CanTrigger(false)
	{}

	void setup();
	void update(float fDelta, ofVec2f CtrlPos);
	void draw();

	void start();
	void stop();
	void clear();

	void setTriggerCheck(bool val);

private :
	bool loadFlowerSequence(eFlowerType eType, string strName);

private:
	bool _isSetup, _isStart, _CanTrigger;
	ofxAnimatableFloat	_animAlpha;
	float _fTimer;
	map<eFlowerType, vector<ofImage>>	_animMgr;
	list<flower>	_flowerList;

	ofSoundPlayer	_flowerAudio;
};

#endif // !P_CHANEL_FLOWER_MGR
