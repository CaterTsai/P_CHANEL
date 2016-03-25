#ifndef P_CHANEL_CONSTPARAMETER
#define P_CHANEL_CONSTPARAMETER

#include "ofMain.h"
#include "NameManager.h"

//Idle Timer
static const float cIDLE_TIME_DURATION = 30.0;
static const float cIDLE_TIME_TRIGGER_1 = 15.0;
static const float cIDLE_TIME_TRIGGER_2 = 0.0;

//Theatre 
static const ofRectangle	cSTART_BUTTON_RECT = ofRectangle(830, 624, 260, 260);
static const ofRectangle	cPLANT_BUTTON_RECT_1 = ofRectangle(326, 562, 200, 165);
static const ofRectangle	cPLANT_BUTTON_RECT_2 = ofRectangle(817, 799, 200, 165);
static const ofRectangle	cPLANT_BUTTON_RECT_3 = ofRectangle(1430, 660, 200, 165);
static const ofRectangle	cPOLLINATION_BUTTON_RECT = ofRectangle(975, 628, 200, 165);
static const ofRectangle	cHARVEST_BUTTON_RECT = ofRectangle(821, 481, 200, 165);
static const ofVec2f	cINTERATIVE_SELECTOR_POS = ofVec2f(1390, 599);
static const ofRectangle	cINTERATIVE_BUTTON_RECT = ofRectangle(1669, 860, 200, 165);

//Sun light
static const float cSUN_LIGHT_FADE_DURATION = 1.0f;

//flower
static const int cFLOWER_MAX_NUM = 10;
static const float cFLOWER_DURATION = 3.9f;
static const pair<float, float> cFLOWER_FELLINGSPEED = make_pair(5.0f, 8.0f);
static const float cFLOWER_TRIGGER_DIST = 40.0f;
static const ofRectangle	cFLOWER_RECT = ofRectangle(0, 0, 1200, 1200);

//Interative
static const ofVec2f cINTERATIVE_STORY_POS = ofVec2f(1514, 244);
static const ofVec2f cINTERATIVE_MASSAGE_POS = ofVec2f(420, 244);
static const ofVec2f cINTERATIVE_LUXURIOUS_POS = ofVec2f(1240, 734);
static const ofVec2f cINTERATIVE_FOOD_POS = ofVec2f(969, 244);
static const ofVec2f cINTERATIVE_FLOWER_POS = ofVec2f(644, 734);
static const ofRectangle cINTERATIVE_STORY_CLOSE = ofRectangle(1784, 82, 80, 80);
static const float cINTERATIVE_TRIGGER_DISTANCE = 170;

#endif // !P_CHANEL_CONSTPARAMETER