#ifndef P_CHANEL_ITEM_SELECTOR
#define P_CHANEL_ITEM_SELECTOR

#include "constParameter.h"
#include "ofxHapPlayer.h"

class itemSelector
{
public:
	void setup();
	void update();
	void draw();

	void startCheck(std::function<void()> callback, ofVec2f pos);
	void stopCheck();

private:
	ofVideoPlayer	_itemSelector;
	ofVec2f				_pos;

	ofSoundPlayer	_clickAudio;

	bool					_startCheck;
	std::function<void()> _Callback;
};

#endif // !P_CHANEL_ITEM_SELECTOR
