#include "ChanelTheatre.h"

#pragma region Basic Method
//-------------------------------------------------
void ChanelTheatre::setup()
{
	_Director.SetStageSize(ofGetWindowWidth(), ofGetWindowHeight());

#pragma region Scenes
	//-------------------------------------------------
	//Scenes
	//-------------------------------------------------
	_Director.AddScenes(NAME_MGR::S_Start);
	_Director.AddScenes(NAME_MGR::S_Plant);
	_Director.AddScenes(NAME_MGR::S_Pollination);
	_Director.AddScenes(NAME_MGR::S_Harvest);
	_Director.AddScenes(NAME_MGR::S_Product);
	_Director.AddScenes(NAME_MGR::S_Interative);
#pragma endregion

#pragma region Actor
	//-------------------------------------------------
	//Actor
	//-------------------------------------------------
	//S_Start
	_Director.AddActor(new ofxImageActor(NAME_MGR::A_StartBG, "images/start_bg.jpg"));
	_Director.AddActor(new ofxImageActor(NAME_MGR::A_Title, "images/title.png", eBLEND_ALPHA));
	_Director.AddActor(new ofxImageActor(NAME_MGR::A_IntroText, "images/IntroText.png", eBLEND_ALPHA));
	_Director.AddActor(new ofxImageActor(NAME_MGR::A_TitleBtn, "images/titleBtn.png", eBLEND_ALPHA));
	_Director.AddActor(new ofxVideoActor(NAME_MGR::A_TitleLight, "videos/titalLight.mov", ofPtr<ofxHapPlayer>(new ofxHapPlayer), eBLEND_ALPHA));

	//S_Plant
	_Director.AddActor(new ofxImageActor(NAME_MGR::A_PlantBG, "images/plant_bg.jpg"));
	_Director.AddActor(new ofxVideoActor(NAME_MGR::A_PlantItem1, "videos/plant_mark.mov", ofPtr<ofxHapPlayer>(new ofxHapPlayer), eBLEND_ALPHA));
	_Director.AddActor(new ofxVideoActor(NAME_MGR::A_PlantItem2, "videos/plant_mark.mov", ofPtr<ofxHapPlayer>(new ofxHapPlayer), eBLEND_ALPHA));
	_Director.AddActor(new ofxVideoActor(NAME_MGR::A_PlantItem3, "videos/plant_mark.mov", ofPtr<ofxHapPlayer>(new ofxHapPlayer), eBLEND_ALPHA));
	_Director.AddActor(new ofxVideoActor(NAME_MGR::A_PlantText, "videos/plant_text.mov", ofPtr<ofxHapPlayer>(new ofxHapPlayer), eBLEND_ALPHA));
	
	//S_Pollination
	_Director.AddActor(new ofxImageActor(NAME_MGR::A_PollinationBG, "images/pollination_bg.jpg"));
	_Director.AddActor(new ofxVideoActor(NAME_MGR::A_PollinationItem, "videos/pollination_mark.mov", ofPtr<ofxHapPlayer>(new ofxHapPlayer), eBLEND_ALPHA));
	_Director.AddActor(new ofxVideoActor(NAME_MGR::A_PollinationText, "videos/pollination_text.mov", ofPtr<ofxHapPlayer>(new ofxHapPlayer), eBLEND_ALPHA));
	
	//S_Harvest
	_Director.AddActor(new ofxImageActor(NAME_MGR::A_HarvestBG, "images/harvest_bg.jpg"));
	_Director.AddActor(new ofxVideoActor(NAME_MGR::A_HarvestItem, "videos/harvest_mark.mov", ofPtr<ofxHapPlayer>(new ofxHapPlayer), eBLEND_ALPHA));
	_Director.AddActor(new ofxVideoActor(NAME_MGR::A_HarvestText, "videos/harvest_text.mov", ofPtr<ofxHapPlayer>(new ofxHapPlayer), eBLEND_ALPHA));
	
	//S_Product
	_Director.AddActor(new ofxImageActor(NAME_MGR::A_ProductBG, "images/product_bg.jpg"));

	//S_Interative
	_Director.AddActor(new ofxImageActor(NAME_MGR::A_InterativeBG, "images/interative_bg.jpg"));
	_Director.AddActor(new ofxImageActor(NAME_MGR::A_FlowerDark, "images/flower_dark.png", eBLEND_ALPHA));
	_Director.AddActor(new ofxImageActor(NAME_MGR::A_FoodDark, "images/food_dark.png", eBLEND_ALPHA));
	_Director.AddActor(new ofxImageActor(NAME_MGR::A_LuxuriousDark, "images/luxurious_dark.png", eBLEND_ALPHA));
	_Director.AddActor(new ofxImageActor(NAME_MGR::A_MassageDark, "images/massage_dark.png", eBLEND_ALPHA));
	_Director.AddActor(new ofxImageActor(NAME_MGR::A_StoryDark, "images/story_dark.png", eBLEND_ALPHA));

	_Director.AddActor(new ofxImageActor(NAME_MGR::A_BackText, "images/backText.png", eBLEND_ALPHA));
	
	//Common
	_Director.AddActor(new ofxImageActor(NAME_MGR::A_ItemBtn, "images/selectBtn.png", eBLEND_ADD));
	_Director.AddActor(new ofxVideoActor(NAME_MGR::A_ItemSelect, "videos/btnlightItem.mov", ofPtr<ofxHapPlayer>(new ofxHapPlayer), eBLEND_ALPHA));
	
#pragma endregion

#pragma region Plane
	//-------------------------------------------------
	//Plane
	//-------------------------------------------------
	_Director.AddPlane(NAME_MGR::S_Start, NAME_MGR::P_Start, 0);
	_Director.AddPlane(NAME_MGR::S_Plant, NAME_MGR::P_Plant, 0);
	_Director.AddPlane(NAME_MGR::S_Pollination, NAME_MGR::P_Pollination, 0);
	_Director.AddPlane(NAME_MGR::S_Harvest, NAME_MGR::P_Harvest, 0);
	_Director.AddPlane(NAME_MGR::S_Product, NAME_MGR::P_Product, 0);
	_Director.AddPlane(NAME_MGR::S_Interative, NAME_MGR::P_Interative, 0);
#pragma endregion

#pragma region Element
	//-------------------------------------------------
	//Element
	//-------------------------------------------------
	//S_Start
	_Director.AddElement(NAME_MGR::E_StartBG, NAME_MGR::P_Start, NAME_MGR::A_StartBG);
	_Director.AddElement(NAME_MGR::E_Title, NAME_MGR::P_Start, NAME_MGR::A_Title, 9, ofVec2f(0), false);
	_Director.AddElement(NAME_MGR::E_TitleLight, NAME_MGR::P_Start, NAME_MGR::A_TitleLight, 8, ofVec2f(0));
	_Director.AddElement(NAME_MGR::E_IntroText, NAME_MGR::P_Start, NAME_MGR::A_IntroText, 5, ofVec2f(512, 337), false);
	_Director.AddElement(NAME_MGR::E_TitleBtn, NAME_MGR::P_Start, NAME_MGR::A_TitleBtn, 4, ofVec2f(0), false);
	
	//S_Plant
	_Director.AddElement(NAME_MGR::E_PlantBG, NAME_MGR::P_Plant, NAME_MGR::A_PlantBG);
	_Director.AddElement(NAME_MGR::E_PlantItem_1, NAME_MGR::P_Plant, NAME_MGR::A_PlantItem1, 4, ofVec2f(42, 303), false );
	_Director.AddElement(NAME_MGR::E_PlantItem_2, NAME_MGR::P_Plant, NAME_MGR::A_PlantItem2, 5, ofVec2f(540, 539), false);
	_Director.AddElement(NAME_MGR::E_PlantItem_3, NAME_MGR::P_Plant, NAME_MGR::A_PlantItem3, 6, ofVec2f(1205, 400), false);
	_Director.AddElement(NAME_MGR::E_PlantItemBtn_1, NAME_MGR::P_Plant, NAME_MGR::A_ItemBtn, 1, ofVec2f(42, 303), false);
	_Director.AddElement(NAME_MGR::E_PlantItemBtn_2, NAME_MGR::P_Plant, NAME_MGR::A_ItemBtn, 2, ofVec2f(540, 539), false);
	_Director.AddElement(NAME_MGR::E_PlantItemBtn_3, NAME_MGR::P_Plant, NAME_MGR::A_ItemBtn, 3, ofVec2f(1205, 400), false);
	_Director.AddElement(NAME_MGR::E_PlantText, NAME_MGR::P_Plant, NAME_MGR::A_PlantText, 7, ofVec2f(0), false);

	//S_Pollination
	_Director.AddElement(NAME_MGR::E_PollinationBG, NAME_MGR::P_Pollination, NAME_MGR::A_PollinationBG);
	_Director.AddElement(NAME_MGR::E_PollinationItem, NAME_MGR::P_Pollination, NAME_MGR::A_PollinationItem, 2, ofVec2f(696, 367), false);
	_Director.AddElement(NAME_MGR::E_PollinationBtn, NAME_MGR::P_Pollination, NAME_MGR::A_ItemBtn, 1, ofVec2f(696, 367), false);	
	_Director.AddElement(NAME_MGR::E_PollinationText, NAME_MGR::P_Pollination, NAME_MGR::A_PollinationText, 3, ofVec2f(0), false);

	//S_Harvest
	_Director.AddElement(NAME_MGR::E_HarvestBG, NAME_MGR::P_Harvest, NAME_MGR::A_HarvestBG);
	_Director.AddElement(NAME_MGR::E_HarvestItem, NAME_MGR::P_Harvest, NAME_MGR::A_HarvestItem, 2, ofVec2f(542, 220), false);
	_Director.AddElement(NAME_MGR::E_HarvestBtn, NAME_MGR::P_Harvest, NAME_MGR::A_ItemBtn, 1, ofVec2f(542, 220), false);	
	_Director.AddElement(NAME_MGR::E_HarvestText, NAME_MGR::P_Harvest, NAME_MGR::A_HarvestText, 3, ofVec2f(0), false);
		
	//S_Product
	_Director.AddElement(NAME_MGR::E_ProductBG, NAME_MGR::P_Product, NAME_MGR::A_ProductBG);

	//S_Interative
	_Director.AddElement(NAME_MGR::E_InterativeBG, NAME_MGR::P_Interative, NAME_MGR::A_InterativeBG);	
	
	_Director.AddElement(NAME_MGR::E_FlowerDark, NAME_MGR::P_Interative, NAME_MGR::A_FlowerDark, 1, ofVec2f(485, 555), false);
	_Director.AddElement(NAME_MGR::E_FoodDark, NAME_MGR::P_Interative, NAME_MGR::A_FoodDark, 1, ofVec2f(790, 65), false);
	_Director.AddElement(NAME_MGR::E_LuxuriousDark, NAME_MGR::P_Interative, NAME_MGR::A_LuxuriousDark, 1, ofVec2f(1061, 555), false);
	_Director.AddElement(NAME_MGR::E_MassageDark, NAME_MGR::P_Interative, NAME_MGR::A_MassageDark, 1, ofVec2f(241, 65), false);
	_Director.AddElement(NAME_MGR::E_StoryDark, NAME_MGR::P_Interative, NAME_MGR::A_StoryDark, 1, ofVec2f(1333, 65), false);

	_Director.AddElement(NAME_MGR::E_BackBtn, NAME_MGR::P_Interative, NAME_MGR::A_ItemBtn, 1, ofVec2f(1390, 597), false);
	_Director.AddElement(NAME_MGR::E_BackText, NAME_MGR::P_Interative, NAME_MGR::A_BackText, 2, ofVec2f(1720, 935), false);

#pragma endregion

#pragma region Translate Element
	_Director.AddTransititonVideo(NAME_MGR::TV_Start2Plant, "videos/translate/t_start2plant.mov", ofPtr<ofxHapPlayer>(new ofxHapPlayer), 1.0f);
	_Director.AddTransititonVideo(NAME_MGR::TV_Plant2Pollination, "videos/translate/t_plant2pollination.mov", ofPtr<ofxHapPlayer>(new ofxHapPlayer), 1.0f);
	_Director.AddTransititonVideo(NAME_MGR::TV_Pollination2Harvest, "videos/translate/t_pollination2harvest.mov", ofPtr<ofxHapPlayer>(new ofxHapPlayer), 1.0f);
	_Director.AddTransititonVideo(NAME_MGR::TV_Harvest2Product, "videos/translate/t_harvest2product.mov", ofPtr<ofxHapPlayer>(new ofxHapPlayer), 1.0f);
	_Director.AddTransititonVideo(NAME_MGR::TV_Product2Interative, "videos/translate/t_product2interative.mov", ofPtr<ofxHapPlayer>(new ofxHapPlayer), 1.0f);
#pragma endregion

#pragma region Element Setting
	//-------------------------------------------------
	//Element Setting
	//-------------------------------------------------	
	//Video
	ofxVideoElement* pVideoElement = nullptr;
	_Director.GetElementPtr(NAME_MGR::E_TitleLight, pVideoElement);
	pVideoElement->SetVideoLoop(true);
	pVideoElement->SetVideoAutoPlay(true);

	_Director.GetElementPtr(NAME_MGR::E_PlantItem_1, pVideoElement);
	pVideoElement->SetVideoAutoPlay(true);
	pVideoElement->SetVideoLoop(true);

	_Director.GetElementPtr(NAME_MGR::E_PlantItem_2, pVideoElement);
	pVideoElement->SetVideoAutoPlay(true);
	pVideoElement->SetVideoLoop(true);

	_Director.GetElementPtr(NAME_MGR::E_PlantItem_3, pVideoElement);
	pVideoElement->SetVideoAutoPlay(true);
	pVideoElement->SetVideoLoop(true);

	_Director.GetElementPtr(NAME_MGR::E_PlantText, pVideoElement);
	pVideoElement->StartEvent();
	pVideoElement->SetVideoAutoPlay(false);

	_Director.GetElementPtr(NAME_MGR::E_PollinationItem, pVideoElement);
	pVideoElement->SetVideoAutoPlay(true);
	pVideoElement->SetVideoLoop(true);

	_Director.GetElementPtr(NAME_MGR::E_PollinationText, pVideoElement);
	pVideoElement->StartEvent();
	pVideoElement->SetVideoAutoPlay(false);

	_Director.GetElementPtr(NAME_MGR::E_HarvestItem, pVideoElement);
	pVideoElement->SetVideoAutoPlay(true);
	pVideoElement->SetVideoLoop(true);

	_Director.GetElementPtr(NAME_MGR::E_HarvestText, pVideoElement);
	pVideoElement->StartEvent();
	pVideoElement->SetVideoAutoPlay(false);

#pragma endregion

#pragma region Others
	initSunlight();
	initStart();
	_CanDisplayIntro = false;
	_DisplayIntro = false;
	setSunlight(true);
	_itemSelector.setup();
	_flowerMgr.setup();
	_interativeMgr.setup();

#pragma endregion

	ofAddListener(_interativeMgr._InterativeStoryEvent, this, &ChanelTheatre::onInteratvieStory);
	ofAddListener(ofxTheatreEventArgs::TheatreEvent, this, &ChanelTheatre::onTheatreEvent);
	_Director.Play();

	AnimInit(NAME_MGR::INIT_EnteStart);
}

//-------------------------------------------------
void ChanelTheatre::update(float fDelta, ofVec2f CtrlPos)
{
	updateSunlight(fDelta);
	
	string strScence_ = _Director.GetNowScenes()->GetScenesName();

	if(strScence_ == NAME_MGR::S_Start)
	{
		updateStart(CtrlPos);
		_flowerMgr.update(fDelta, CtrlPos);
	}
	else if(strScence_ == NAME_MGR::S_Plant)
	{
		updatePlant(CtrlPos);
	}
	else if(strScence_ == NAME_MGR::S_Pollination)
	{
		updatePollination(CtrlPos);
	}
	else if(strScence_ == NAME_MGR::S_Harvest)
	{
		updateHarvest(CtrlPos);
	}
	else if(strScence_ == NAME_MGR::S_Interative)
	{
		updateInterative(CtrlPos);
		_interativeMgr.update(fDelta, CtrlPos);
	}		

	_itemSelector.update();
	_Director.update();
}

//-------------------------------------------------
void ChanelTheatre::draw()
{
	string strScence_ = _Director.GetNowScenes()->GetScenesName();

	ofPushStyle();
	{
		_Director.draw();
		drawSunlight();

		if(strScence_ == NAME_MGR::S_Start)
		{
			drawStart();
			_flowerMgr.draw();
		}
		else if(strScence_ == NAME_MGR::S_Interative)
		{
			_interativeMgr.draw();
		}


		_itemSelector.draw();
	}
	ofPopStyle();
}

//-------------------------------------------------
void ChanelTheatre::nextScence()
{
	auto strScenceName_ = _Director.GetNowScenes()->GetScenesName();

	if(strScenceName_ == NAME_MGR::S_Start)
	{
		_Director.TransitByVideo(NAME_MGR::S_Plant, NAME_MGR::TV_Start2Plant);
		
	}
	else if(strScenceName_ == NAME_MGR::S_Plant)
	{
		_Director.TransitByVideo(NAME_MGR::S_Pollination, NAME_MGR::TV_Plant2Pollination);
	}
	else if(strScenceName_ == NAME_MGR::S_Pollination)
	{
		_Director.TransitByVideo(NAME_MGR::S_Harvest, NAME_MGR::TV_Pollination2Harvest);
	}
	else if(strScenceName_ == NAME_MGR::S_Harvest)
	{
		_Director.TransitByVideo(NAME_MGR::S_Product, NAME_MGR::TV_Harvest2Product);
	}
	else if(strScenceName_ == NAME_MGR::S_Product)
	{
		_Director.TransitByVideo(NAME_MGR::S_Interative, NAME_MGR::TV_Product2Interative);
	}
	else if(strScenceName_ == NAME_MGR::S_Interative)
	{
		resetTheatre();
	}
	
}

//-------------------------------------------------
void ChanelTheatre::resetTheatre()
{
	//Start
	_StartBtnTrigger = false;
	_StartBtnEnable = false;
	_CanDisplayIntro = false;
	_DisplayIntro = false;

	setSunlight(true);
	_flowerMgr.clear();
	_interativeMgr.reset();

	_Director.TransitTo(NAME_MGR::S_Start);

	string strEvent_ = NAME_MGR::T_RESET;
	ofNotifyEvent(_TheatreEvent, strEvent_);
}

//-------------------------------------------------
void ChanelTheatre::AnimInit(string strName)
{
	ofxBaseElement* ptr_ = nullptr;
	//Start
	if(strName == NAME_MGR::INIT_EnteStart)
	{
		_Director.GetElementPtr(NAME_MGR::E_Title, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Start, 0, new ofxFadeInAnimation(NAME_MGR::ANIM_TITLE_FADEIN, ptr_));
	}
	else if(strName == NAME_MGR::INIT_ShowIntro)
	{
		_Director.GetElementPtr(NAME_MGR::E_Title, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Start, 0, new ofxFadeOutAnimation(NAME_MGR::ANIM_TITLE_FADEOUT, ptr_));
		
		_Director.GetElementPtr(NAME_MGR::E_TitleLight, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Start, 1, new ofxFadeOutAnimation(NAME_MGR::ANIM_TITLE_LIGHT_FADEOUT, ptr_));
		
		_Director.GetElementPtr(NAME_MGR::E_IntroText, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Start, 0, new ofxFadeInAnimation(NAME_MGR::ANIM_INTRO_FADEIN, ptr_));

		_Director.GetElementPtr(NAME_MGR::E_TitleBtn, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Start, 1, new ofxFadeInAnimation(NAME_MGR::ANIM_TITLE_BUTTON_FADEIN, ptr_));
	}
	else if(strName == NAME_MGR::INIT_IntroExit)
	{
		_Director.GetElementPtr(NAME_MGR::E_TitleBtn, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Start, 0, new ofxFadeOutAnimation(NAME_MGR::ANIM_TITLE_BUTTON_FADEOUT, ptr_));

		_Director.GetElementPtr(NAME_MGR::E_IntroText, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Start, 0, new ofxFadeOutAnimation(NAME_MGR::ANIM_INTRO_FADEOUT, ptr_));
		_Director.AddAnimation(NAME_MGR::S_Start, 0, new ofxEmptyAnimation(NAME_MGR::ANIM_TO_PLANE, ptr_, 0.0f));
	}
	else if(strName == NAME_MGR::INIT_BackToStart)
	{
		_Director.GetElementPtr(NAME_MGR::E_TitleBtn, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Start, 0, new ofxFadeOutAnimation(NAME_MGR::ANIM_TITLE_BUTTON_FADEOUT, ptr_));

		_Director.GetElementPtr(NAME_MGR::E_IntroText, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Start, 0, new ofxFadeOutAnimation(NAME_MGR::ANIM_INTRO_FADEOUT, ptr_));

		_Director.GetElementPtr(NAME_MGR::E_Title, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Start, 0, new ofxFadeInAnimation(NAME_MGR::ANIM_TITLE_FADEIN, ptr_));

		_Director.GetElementPtr(NAME_MGR::E_TitleLight, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Start, 0, new ofxFadeInAnimation(NAME_MGR::ANIM_TITLE_LIGHT_FADEIN, ptr_));
	}
	//Plant
	else if(strName == NAME_MGR::INIT_PlantItemIn)
	{
		_Director.GetElementPtr(NAME_MGR::E_PlantItem_1, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Plant, 0, new ofxFadeInAnimation(NAME_MGR::ANIM_PLANT_ITEM_1_FADEIN, ptr_, 0.5f));

		_Director.GetElementPtr(NAME_MGR::E_PlantItem_2, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Plant, 1, new ofxFadeInAnimation(NAME_MGR::ANIM_PLANT_ITEM_2_FADEIN, ptr_, 0.5f));

		_Director.GetElementPtr(NAME_MGR::E_PlantItem_3, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Plant, 2, new ofxFadeInAnimation(NAME_MGR::ANIM_PLANT_ITEM_3_FADEIN, ptr_, 0.5f));

		_Director.GetElementPtr(NAME_MGR::E_PlantItemBtn_1, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Plant, 3, new ofxFadeInAnimation(NAME_MGR::ANIM_PLANT_BTN_1_FADEIN, ptr_, 0.2f));

		_Director.GetElementPtr(NAME_MGR::E_PlantItemBtn_2, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Plant, 4, new ofxFadeInAnimation(NAME_MGR::ANIM_PLANT_BTN_2_FADEIN, ptr_, 0.2f));

		_Director.GetElementPtr(NAME_MGR::E_PlantItemBtn_3, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Plant, 5, new ofxFadeInAnimation(NAME_MGR::ANIM_PLANT_BTN_3_FADEIN, ptr_, 0.2f));
	}
	else if(strName == NAME_MGR::INIT_PlantItemOut)
	{
		_Director.GetElementPtr(NAME_MGR::E_PlantItem_1, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Plant, 0, new ofxFadeOutAnimation(NAME_MGR::ANIM_PLANT_ITEM_1_FADEOUT, ptr_));

		_Director.GetElementPtr(NAME_MGR::E_PlantItem_2, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Plant, 1, new ofxFadeOutAnimation(NAME_MGR::ANIM_PLANT_ITEM_2_FADEOUT, ptr_));

		_Director.GetElementPtr(NAME_MGR::E_PlantItem_3, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Plant, 2, new ofxFadeOutAnimation(NAME_MGR::ANIM_PLANT_ITEM_3_FADEOUT, ptr_));

		_Director.GetElementPtr(NAME_MGR::E_PlantItemBtn_1, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Plant, 3, new ofxFadeOutAnimation(NAME_MGR::ANIM_PLANT_BTN_1_FADEOUT, ptr_, 0.0f));

		_Director.GetElementPtr(NAME_MGR::E_PlantItemBtn_2, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Plant, 4, new ofxFadeOutAnimation(NAME_MGR::ANIM_PLANT_BTN_2_FADEOUT, ptr_, 0.0f));

		_Director.GetElementPtr(NAME_MGR::E_PlantItemBtn_3, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Plant, 5, new ofxFadeOutAnimation(NAME_MGR::ANIM_PLANT_BTN_3_FADEOUT, ptr_, 0.0f));

		_Director.GetElementPtr(NAME_MGR::E_PlantText, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Plant, 6, new ofxFadeInAnimation(NAME_MGR::ANIM_PLANT_TEXT_FADEIN, ptr_));
	}
	else if(strName == NAME_MGR::INIT_PlantTextOut)
	{
		_Director.GetElementPtr(NAME_MGR::E_PlantText, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Plant, 0, new ofxFadeOutAnimation(NAME_MGR::ANIM_PLANT_TEXT_FADEOUT, ptr_));
	}
	//Pollination
	else if(strName == NAME_MGR::INIT_PollinationItemIn)
	{
		_Director.GetElementPtr(NAME_MGR::E_PollinationItem, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Pollination, 0, new ofxFadeInAnimation(NAME_MGR::ANIM_POLLINATION_ITEM_FADEIN, ptr_, 0.5f));

		_Director.GetElementPtr(NAME_MGR::E_PollinationBtn, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Pollination, 1, new ofxFadeInAnimation(NAME_MGR::ANIM_POLLINATION_BTN_FADEIN, ptr_, 0.2f));
	}
	else if(strName == NAME_MGR::INIT_PollinationItemOut)
	{
		_Director.GetElementPtr(NAME_MGR::E_PollinationItem, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Pollination, 0, new ofxFadeOutAnimation(NAME_MGR::ANIM_POLLINATION_ITEM_FADEOUT, ptr_));
		
		_Director.GetElementPtr(NAME_MGR::E_PollinationBtn, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Pollination, 1, new ofxFadeOutAnimation(NAME_MGR::ANIM_POLLINATION_BTN_FADEOUT, ptr_, 0.0f));

		_Director.GetElementPtr(NAME_MGR::E_PollinationText, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Pollination, 0, new ofxFadeInAnimation(NAME_MGR::ANIM_POLLINATION_TEXT_FADEIN, ptr_));
	}
	else if(strName == NAME_MGR::INIT_PollinationTextOut)
	{
		_Director.GetElementPtr(NAME_MGR::E_PollinationText, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Pollination, 0, new ofxFadeOutAnimation(NAME_MGR::ANIM_POLLINATION_TEXT_FADEOUT, ptr_));
	}
	//Harvest
	else if(strName == NAME_MGR::INIT_HarvestItemIn)
	{
		_Director.GetElementPtr(NAME_MGR::E_HarvestItem, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Harvest, 0, new ofxFadeInAnimation(NAME_MGR::ANIM_HARVEST_ITEM_FADEIN, ptr_, 0.5f));

		_Director.GetElementPtr(NAME_MGR::E_HarvestBtn, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Harvest, 1, new ofxFadeInAnimation(NAME_MGR::ANIM_HARVEST_BTN_FADEIN, ptr_, 0.2f));
	}
	else if(strName == NAME_MGR::INIT_HarvestItemOut)
	{
		_Director.GetElementPtr(NAME_MGR::E_HarvestItem, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Harvest, 0, new ofxFadeOutAnimation(NAME_MGR::ANIM_HARVEST_ITEM_FADEOUT, ptr_));
		
		_Director.GetElementPtr(NAME_MGR::E_HarvestBtn, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Harvest, 1, new ofxFadeOutAnimation(NAME_MGR::ANIM_HARVEST_BTN_FADEOUT, ptr_, 0.0f));

		_Director.GetElementPtr(NAME_MGR::E_HarvestText, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Harvest, 0, new ofxFadeInAnimation(NAME_MGR::ANIM_HARVEST_TEXT_FADEIN, ptr_));
	}
	else if(strName == NAME_MGR::INIT_HarvestTextOut)
	{
		_Director.GetElementPtr(NAME_MGR::E_HarvestText, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Harvest, 0, new ofxFadeOutAnimation(NAME_MGR::ANIM_HARVEST_TEXT_FADEOUT, ptr_));
	}
	//Product
	else if(strName == NAME_MGR::INIT_ProductWait)
	{
		_Director.GetElementPtr(NAME_MGR::P_Product, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Product, 0, new ofxEmptyAnimation(NAME_MGR::ANIM_PRODUCT_WAIT, ptr_, 0.0f, 0.1f));
	}
	//Interative
	else if(strName == NAME_MGR::INIT_InterativeFadeIn)
	{
		_Director.GetElementPtr(NAME_MGR::E_MassageDark, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Interative, 0, new ofxFadeInAnimation(NAME_MGR::ANIM_MASSAGE_DARK_FADEIN, ptr_));

		_Director.GetElementPtr(NAME_MGR::E_FlowerDark, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Interative, 0, new ofxFadeInAnimation(NAME_MGR::ANIM_FLOWER_DARK_FADEIN, ptr_, 0.5f, 0.5f));

		_Director.GetElementPtr(NAME_MGR::E_FoodDark, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Interative, 0, new ofxFadeInAnimation(NAME_MGR::ANIM_FOOD_DARK_FADEIN, ptr_, 0.5f, 0.5f));

		_Director.GetElementPtr(NAME_MGR::E_LuxuriousDark, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Interative, 0, new ofxFadeInAnimation(NAME_MGR::ANIM_LUXURIOUS_DARK_FADEIN, ptr_, 0.5f, 0.5f));

		_Director.GetElementPtr(NAME_MGR::E_StoryDark, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Interative, 0, new ofxFadeInAnimation(NAME_MGR::ANIM_STORY_DARK_FADEIN, ptr_, 0.5f, 0.5f));
	}
	else if(strName == NAME_MGR::INIT_InterativeTextFadeIn)
	{
		_Director.GetElementPtr(NAME_MGR::E_BackBtn, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Interative, 0, new ofxFadeInAnimation(NAME_MGR::ANIM_BACK_BTN_FADEIN, ptr_));

		_Director.GetElementPtr(NAME_MGR::E_BackText, ptr_);
		_Director.AddAnimation(NAME_MGR::S_Interative, 1, new ofxFadeInAnimation(NAME_MGR::ANIM_BACK_TEXT_FADEIN, ptr_));
	}
}

//-------------------------------------------------
void ChanelTheatre::onTheatreEvent(ofxTheatreEventArgs& e)
{
	//Scens
	if(e.strMessage == NAME_MGR::S_Start)
	{	
		AnimInit(NAME_MGR::INIT_EnteStart);

		string strEvent_ = NAME_MGR::T_RESET_IDLE;
		ofNotifyEvent(_TheatreEvent, strEvent_);
	}
	else if(e.strMessage == NAME_MGR::S_Plant)
	{
		_bEnablePlantCtrl = true;
		_iBtnIndex = -1;
		AnimInit(NAME_MGR::INIT_PlantItemIn);

		setSunlight(true);

		string strEvent_ = NAME_MGR::T_RESET_IDLE;
		ofNotifyEvent(_TheatreEvent, strEvent_);
	}
	else if(e.strMessage == NAME_MGR::S_Pollination)
	{
		_bEnablePollinationCtrl = true;
		_bPollinationTrigger = false;
		AnimInit(NAME_MGR::INIT_PollinationItemIn);

		setSunlight(true);

		string strEvent_ = NAME_MGR::T_RESET_IDLE;
		ofNotifyEvent(_TheatreEvent, strEvent_);
	}
	else if(e.strMessage == NAME_MGR::S_Harvest)
	{
		_bEnableHarvestCtrl = true;
		_bHarvestTrigger = false;
		AnimInit(NAME_MGR::INIT_HarvestItemIn);

		setSunlight(true);

		string strEvent_ = NAME_MGR::T_RESET_IDLE;
		ofNotifyEvent(_TheatreEvent, strEvent_);
	}
	else if(e.strMessage == NAME_MGR::S_Product)
	{
		AnimInit(NAME_MGR::INIT_ProductWait);
	}
	else if(e.strMessage == NAME_MGR::S_Interative)
	{
		_bEnableInterativeCtrl = true;
		_bInterativeTrigger = false;

		AnimInit(NAME_MGR::INIT_InterativeFadeIn);

		setSunlight(true);

		string strEvent_ = NAME_MGR::T_ENABLE_CURSOR;
		ofNotifyEvent(_TheatreEvent, strEvent_);
	}

	//Animation
	if(e.strMessage == NAME_MGR::ANIM_TITLE_FADEIN)
	{
		_CanDisplayIntro = true;
		_flowerMgr.setTriggerCheck(false);
		_flowerMgr.start();
	}
	else if(e.strMessage == NAME_MGR::ANIM_TITLE_BUTTON_FADEIN)
	{
		string strEvent_ = NAME_MGR::T_ENABLE_CURSOR;
		ofNotifyEvent(_TheatreEvent, strEvent_);

		_flowerMgr.setTriggerCheck(true);

		enableStartBtn();

		_DisplayIntro = true;
	}
	else if(e.strMessage == NAME_MGR::ANIM_TO_PLANE)
	{
		nextScence();
	}
	else if(e.strMessage == NAME_MGR::ANIM_PLANT_BTN_1_FADEIN)
	{
		string strEvent_ = NAME_MGR::T_ENABLE_CURSOR;
		ofNotifyEvent(_TheatreEvent, strEvent_);
	}
	else if(e.strMessage == NAME_MGR::ANIM_PLANT_TEXT_FADEOUT)
	{
		setSunlight(false);
		nextScence();
	}
	else if(e.strMessage == NAME_MGR::ANIM_POLLINATION_BTN_FADEIN)
	{
		string strEvent_ = NAME_MGR::T_ENABLE_CURSOR;
		ofNotifyEvent(_TheatreEvent, strEvent_);
	}
	else if(e.strMessage == NAME_MGR::ANIM_POLLINATION_TEXT_FADEOUT)
	{
		setSunlight(false);
		nextScence();
	}
	else if(e.strMessage == NAME_MGR::ANIM_HARVEST_BTN_FADEIN)
	{
		string strEvent_ = NAME_MGR::T_ENABLE_CURSOR;
		ofNotifyEvent(_TheatreEvent, strEvent_);
	}
	else if(e.strMessage == NAME_MGR::ANIM_HARVEST_TEXT_FADEOUT)
	{
		setSunlight(false);
		nextScence();
	}
	else if(e.strMessage == NAME_MGR::ANIM_PRODUCT_WAIT)
	{
		nextScence();
	}

	//Interative
	else if(e.strMessage == NAME_MGR::ANIM_MASSAGE_DARK_FADEIN)
	{
		_interativeMgr.startElement(eInterativeType::eType_Massage);
	}
	else if(e.strMessage == NAME_MGR::ANIM_FLOWER_DARK_FADEIN)
	{
		_interativeMgr.startElement(eInterativeType::eType_Flower);
	}
	else if(e.strMessage == NAME_MGR::ANIM_FOOD_DARK_FADEIN)
	{
		_interativeMgr.startElement(eInterativeType::eType_Food);
	}
	else if(e.strMessage == NAME_MGR::ANIM_LUXURIOUS_DARK_FADEIN)
	{
		_interativeMgr.startElement(eInterativeType::eType_Luxurious);
	}
	else if(e.strMessage == NAME_MGR::ANIM_STORY_DARK_FADEIN)
	{
		_interativeMgr.startElement(eInterativeType::eType_Story);
		_interativeMgr.enableStoryBtn();
		//_interativeMgr.reset();

		AnimInit(NAME_MGR::INIT_InterativeTextFadeIn);

		
	}

	//Video
	if(e.strMessage == NAME_MGR::E_PlantText)
	{
		AnimInit(NAME_MGR::INIT_PlantTextOut);
	}
	else if(e.strMessage == NAME_MGR::E_PollinationText)
	{
		AnimInit(NAME_MGR::INIT_PollinationTextOut);
	}
	else if(e.strMessage == NAME_MGR::E_HarvestText)
	{
		AnimInit(NAME_MGR::INIT_HarvestTextOut);
	}
}
#pragma endregion

#pragma region SunLight
//-------------------------------------------------
void ChanelTheatre::initSunlight()
{
	_sunLightAlpha.setDuration(cSUN_LIGHT_FADE_DURATION);
	_sunLightAlpha.reset(0.0f);
	
	_sunLight.setPlayer(ofPtr<ofxHapPlayer>(new ofxHapPlayer));
	_sunLight.setLoopState(ofLoopType::OF_LOOP_NORMAL);
	_sunLight.loadMovie("videos/sunLight.mov");
	_sunLight.play();
}

//-------------------------------------------------
void ChanelTheatre::updateSunlight(float fDelta)
{
	_sunLightAlpha.update(fDelta);

	if(_sunLight.isLoaded())
	{
		_sunLight.update();
	}
}

//-------------------------------------------------
void ChanelTheatre::drawSunlight()
{
	ofPushStyle();
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	ofSetColor(255, 255, 255, _sunLightAlpha.getCurrentValue());
	{
		_sunLight.draw(0, 0);
	}	
	ofPopStyle();
}

//-------------------------------------------------
void ChanelTheatre::setSunlight(bool val)
{
	if(val)
	{
		_sunLightAlpha.animateTo(255.0f);
	}
	else
	{
		_sunLightAlpha.animateTo(.0f);
	}
}
#pragma endregion

#pragma region Idle Trigger
//-------------------------------------------------
void ChanelTheatre::idleTriggerFirst()
{
	string sName_ = _Director.GetNowScenes()->GetScenesName();
	if(sName_ == NAME_MGR::S_Start)
	{
		if(canGoBack())
		{
			AnimInit(NAME_MGR::INIT_BackToStart);
		}
		
	}
	else if(sName_ == NAME_MGR::S_Plant)
	{
	}
	else if(sName_ == NAME_MGR::S_Pollination)
	{
	}
	else if(sName_ == NAME_MGR::S_Harvest)
	{

	}
	else if(sName_ == NAME_MGR::S_Interative)
	{
	}
}

//-------------------------------------------------
void ChanelTheatre::idleTriggerSecond()
{
	string sName_ = _Director.GetNowScenes()->GetScenesName();
	if(sName_ == NAME_MGR::S_Start)
	{	
	}
	else if(sName_ == NAME_MGR::S_Plant)
	{
		resetTheatre();
	}
	else if(sName_ == NAME_MGR::S_Pollination)
	{
		resetTheatre();
	}
	else if(sName_ == NAME_MGR::S_Harvest)
	{
		resetTheatre();
	}
	else if(sName_ == NAME_MGR::S_Interative)
	{
	}
}
#pragma endregion

#pragma region Scenes Start
//-------------------------------------------------
void ChanelTheatre::displayIntro()
{
	if(_CanDisplayIntro &&_Director.GetNowScenes()->GetScenesName() == NAME_MGR::S_Start)
	{
		AnimInit(NAME_MGR::INIT_ShowIntro);
		_CanDisplayIntro = false;
	}
}

//-------------------------------------------------
bool ChanelTheatre::canGoBack()
{
	return _DisplayIntro;
}

//-------------------------------------------------
void ChanelTheatre::initStart()
{
	_StartBtnTrigger = false;
	_StartBtnEnable = false;
	_StartBtnLight.setPlayer(ofPtr<ofxHapPlayer>(new ofxHapPlayer));
	_StartBtnLight.setLoopState(ofLoopType::OF_LOOP_NONE);
	_StartBtnLight.loadMovie("videos/btnlight.mov");

	_clickAudio.loadSound("audios/click.wav");
	_clickAudio.setLoop(false);
	_clickAudio.setMultiPlay(true);
}

//-------------------------------------------------
void ChanelTheatre::updateStart(ofVec2f ctrl)
{	
	if(!_StartBtnEnable)
	{
		return;
	}

	//Trigger Check
	if(cSTART_BUTTON_RECT.inside(ctrl))
	{
		triggerStartBtn(true);
	}
	else
	{
		triggerStartBtn(false);
	}

	if(_StartBtnTrigger)
	{
		_StartBtnLight.update();
		if(_StartBtnLight.getIsMovieDone())
		{
			_StartBtnEnable = false;
			AnimInit(NAME_MGR::INIT_IntroExit);

			_StartBtnLight.stop();
			_StartBtnLight.setFrame(0);
			_StartBtnLight.update();
			_StartBtnTrigger = false;

			_flowerMgr.setTriggerCheck(false);
			_flowerMgr.stop();

			_clickAudio.play();

			setSunlight(false);
			string strEvent_ = NAME_MGR::T_DISABLE_CURSOR;
			ofNotifyEvent(_TheatreEvent, strEvent_);
		}
	}
}

//-------------------------------------------------
void ChanelTheatre::drawStart()
{
	if(!_StartBtnEnable)
	{
		return;
	}

	ofPushStyle();
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	{
		_StartBtnLight.draw(0, 0);
	}
	ofPopStyle();
}

//-------------------------------------------------
void ChanelTheatre::enableStartBtn()
{
	_StartBtnEnable = true;
}

//-------------------------------------------------
void ChanelTheatre::triggerStartBtn(bool bval)
{
	if(!_StartBtnTrigger && bval)
	{
		_StartBtnLight.play();
		_StartBtnTrigger = true;
	}
	else if(_StartBtnTrigger && !bval)
	{
		_StartBtnLight.stop();
		_StartBtnLight.setFrame(0);
		_StartBtnLight.update();
		_StartBtnTrigger = false;
	}
}
#pragma endregion

#pragma region Scenes Plant
void ChanelTheatre::updatePlant(ofVec2f ctrl)
{
	if(!_bEnablePlantCtrl)
	{
		return;
	}

	if(cPLANT_BUTTON_RECT_1.inside(ctrl))
	{
		if(_iBtnIndex != 1)
		{
			ofxImageElement *ptr_ = nullptr;
			_Director.GetElementPtr(NAME_MGR::E_PlantItemBtn_1, ptr_);
			
			_iBtnIndex = 1;
			_itemSelector.stopCheck();
			_itemSelector.startCheck(
				[&](){
					ofxVideoElement* ItemPtr_ = nullptr;
					ofxVideoElement* textPtr_ = nullptr;
					_Director.GetElementPtr(NAME_MGR::E_PlantItem_1, ItemPtr_);
					_Director.GetElementPtr(NAME_MGR::E_PlantText, textPtr_);
					textPtr_->SetPos(ItemPtr_->m_stElementBase.oPos);
					textPtr_->PlayVideo();

					AnimInit(NAME_MGR::INIT_PlantItemOut);
					_bEnablePlantCtrl = false;

					string strEvent_ = NAME_MGR::T_DISABLE_CURSOR;
					ofNotifyEvent(_TheatreEvent, strEvent_);
				},
				ptr_->m_stElementBase.oPos
			);
		}
	}
	else if(cPLANT_BUTTON_RECT_2.inside(ctrl))
	{
		if(_iBtnIndex != 2)
		{
			ofxImageElement *ptr_ = nullptr;
			_Director.GetElementPtr(NAME_MGR::E_PlantItemBtn_2, ptr_);
			
			_iBtnIndex = 2;
			_itemSelector.stopCheck();
			_itemSelector.startCheck(
				[&](){
					ofxVideoElement* ItemPtr_ = nullptr;
					ofxVideoElement* textPtr_ = nullptr;
					_Director.GetElementPtr(NAME_MGR::E_PlantItem_2, ItemPtr_);
					_Director.GetElementPtr(NAME_MGR::E_PlantText, textPtr_);
					textPtr_->SetPos(ItemPtr_->m_stElementBase.oPos);
					textPtr_->PlayVideo();

					AnimInit(NAME_MGR::INIT_PlantItemOut);
					_bEnablePlantCtrl = false;

					
					string strEvent_ = NAME_MGR::T_DISABLE_CURSOR;
					ofNotifyEvent(_TheatreEvent, strEvent_);
				},
				ptr_->m_stElementBase.oPos
			);
		}
	}
	else if(cPLANT_BUTTON_RECT_3.inside(ctrl))
	{
		if(_iBtnIndex != 3)
		{
			ofxImageElement *ptr_ = nullptr;
			_Director.GetElementPtr(NAME_MGR::E_PlantItemBtn_3, ptr_);
			
			_iBtnIndex = 3;
			_itemSelector.stopCheck();
			_itemSelector.startCheck(
				[&](){
					ofxVideoElement* ItemPtr_ = nullptr;
					ofxVideoElement* textPtr_ = nullptr;
					_Director.GetElementPtr(NAME_MGR::E_PlantItem_3, ItemPtr_);
					_Director.GetElementPtr(NAME_MGR::E_PlantText, textPtr_);
					textPtr_->SetPos(ItemPtr_->m_stElementBase.oPos);
					textPtr_->PlayVideo();

					AnimInit(NAME_MGR::INIT_PlantItemOut);
					_bEnablePlantCtrl = false;

					string strEvent_ = NAME_MGR::T_DISABLE_CURSOR;
					ofNotifyEvent(_TheatreEvent, strEvent_);
				},
				ptr_->m_stElementBase.oPos
			);
		}
	}
	else
	{
		if(_iBtnIndex != -1)
		{
			_itemSelector.stopCheck();
		}
		_iBtnIndex = -1;

	}
}
#pragma endregion

#pragma region Scenes Pollination
void ChanelTheatre::updatePollination(ofVec2f ctrl)
{
	if(!_bEnablePollinationCtrl)
	{
		return;
	}

	if(cPOLLINATION_BUTTON_RECT.inside(ctrl))
	{
		if(!_bPollinationTrigger)
		{
			ofxImageElement *ptr_ = nullptr;
			_Director.GetElementPtr(NAME_MGR::E_PollinationBtn, ptr_);

			_itemSelector.stopCheck();
			_itemSelector.startCheck(
				[&](){
					ofxVideoElement* ItemPtr_ = nullptr;
					ofxVideoElement* textPtr_ = nullptr;
					_Director.GetElementPtr(NAME_MGR::E_PollinationItem, ItemPtr_);
					_Director.GetElementPtr(NAME_MGR::E_PollinationText, textPtr_);
					textPtr_->SetPos(ItemPtr_->m_stElementBase.oPos);
					textPtr_->PlayVideo();
					
					AnimInit(NAME_MGR::INIT_PollinationItemOut);
					_bEnablePollinationCtrl = false;

					string strEvent_ = NAME_MGR::T_DISABLE_CURSOR;
					ofNotifyEvent(_TheatreEvent, strEvent_);
				},
				ptr_->m_stElementBase.oPos
			);
			_bPollinationTrigger = true;
		}
		
	}
	else
	{
		_itemSelector.stopCheck();
		_bPollinationTrigger = false;
	}
}
#pragma endregion

#pragma region Scenes Harvest
void ChanelTheatre::updateHarvest(ofVec2f ctrl)
{
	if(!_bEnableHarvestCtrl)
	{
		return;
	}

	if(cHARVEST_BUTTON_RECT.inside(ctrl))
	{
		if(!_bHarvestTrigger)
		{
			ofxImageElement *ptr_ = nullptr;
			_Director.GetElementPtr(NAME_MGR::E_HarvestBtn, ptr_);

			_itemSelector.stopCheck();
			_itemSelector.startCheck(
				[&](){
					ofxVideoElement* ItemPtr_ = nullptr;
					ofxVideoElement* textPtr_ = nullptr;
					_Director.GetElementPtr(NAME_MGR::E_HarvestItem, ItemPtr_);
					_Director.GetElementPtr(NAME_MGR::E_HarvestText, textPtr_);
					textPtr_->SetPos(ItemPtr_->m_stElementBase.oPos);
					textPtr_->PlayVideo();

					AnimInit(NAME_MGR::INIT_HarvestItemOut);
					_bEnableHarvestCtrl = false;

					string strEvent_ = NAME_MGR::T_DISABLE_CURSOR;
					ofNotifyEvent(_TheatreEvent, strEvent_);
				},
				ptr_->m_stElementBase.oPos
			);
			_bHarvestTrigger = true;
		}
		
	}
	else
	{
		_itemSelector.stopCheck();
		_bHarvestTrigger = false;
	}
}
#pragma endregion

#pragma region Scenes Interative
void ChanelTheatre::updateInterative(ofVec2f ctrl)
{
	if(!_bEnableInterativeCtrl)
	{
		return;
	}

	if(cINTERATIVE_BUTTON_RECT.inside(ctrl))
	{
		if(!_bInterativeTrigger)
		{
			
			_itemSelector.stopCheck();
			_itemSelector.startCheck(
				[&](){
					_bEnableInterativeCtrl = false;
					nextScence();
				},
				cINTERATIVE_SELECTOR_POS
			);
			_bInterativeTrigger = true;
		}
	}
	else
	{
		_itemSelector.stopCheck();
		_bInterativeTrigger = false;
	}
}
#pragma endregion

#pragma region interativeMgr
void ChanelTheatre::onInteratvieStory(bool& e)
{
	if(!e)
	{
		string strEvent_ = NAME_MGR::T_ENABLE_BGM;
		ofNotifyEvent(_TheatreEvent, strEvent_);
	}
	else
	{
		string strEvent_ = NAME_MGR::T_DISABLE_BGM;
		ofNotifyEvent(_TheatreEvent, strEvent_);
	}
}
#pragma endregion
