#ifndef _NAME_MANAGER_
#define _NAME_MANAGER_

#include <string>
using namespace std;

#define CREATE_VALUE(NAME) static const string NAME = #NAME;
#define CREATE_VALUE_WITH_VALUE(NAME, VALUE) static const string NAME = VALUE;

namespace NAME_MGR
{
//-------------------------------------------------
//Theatre
//-------------------------------------------------

///////////////////////////////////////
// Scenes
//////////////////////////////////////
	CREATE_VALUE(S_Start);
	CREATE_VALUE(S_Plant);
	CREATE_VALUE(S_Pollination);
	CREATE_VALUE(S_Harvest)
	CREATE_VALUE(S_Product);
	CREATE_VALUE(S_Interative);

/////////////////////////////////////////
//// Actor
////////////////////////////////////////

	//Start
	CREATE_VALUE(A_StartBG);
	CREATE_VALUE(A_Title);
	CREATE_VALUE(A_IntroText);
	CREATE_VALUE(A_TitleBtn);
	CREATE_VALUE(A_TitleLight);
	
	//Plant
	CREATE_VALUE(A_PlantBG);
	CREATE_VALUE(A_PlantItem1);
	CREATE_VALUE(A_PlantItem2);
	CREATE_VALUE(A_PlantItem3);
	CREATE_VALUE(A_PlantText);
	CREATE_VALUE(A_PlantTips);
	
	//Pollination
	CREATE_VALUE(A_PollinationBG);
	CREATE_VALUE(A_PollinationItem);
	CREATE_VALUE(A_PollinationText);
	CREATE_VALUE(A_PollinationTips);

	//Harvest
	CREATE_VALUE(A_HarvestBG);
	CREATE_VALUE(A_HarvestItem);
	CREATE_VALUE(A_HarvestText);
	CREATE_VALUE(A_HarvestTips);
	
	//Product
	CREATE_VALUE(A_ProductBG);

	//Interative
	CREATE_VALUE(A_InterativeBG);
	CREATE_VALUE(A_FlowerDark);
	CREATE_VALUE(A_FoodDark);
	CREATE_VALUE(A_LuxuriousDark);
	CREATE_VALUE(A_MassageDark);
	CREATE_VALUE(A_StoryDark);
	CREATE_VALUE(A_BackText);
	
	//Common
	CREATE_VALUE(A_ItemSelect);
	CREATE_VALUE(A_ItemBtn);
	

/////////////////////////////////////////
//// Plane
////////////////////////////////////////

	CREATE_VALUE(P_Start);
	CREATE_VALUE(P_Plant);
	CREATE_VALUE(P_Pollination);
	CREATE_VALUE(P_Harvest)
	CREATE_VALUE(P_Product);
	CREATE_VALUE(P_Interative);

/////////////////////////////////////////
//// Element
////////////////////////////////////////

	//Start
	CREATE_VALUE(E_StartBG);
	CREATE_VALUE(E_Title);
	CREATE_VALUE(E_TitleLight);
	CREATE_VALUE(E_IntroText);
	CREATE_VALUE(E_TitleBtn);

	//Plant
	CREATE_VALUE(E_PlantBG);
	CREATE_VALUE(E_PlantItem_1);
	CREATE_VALUE(E_PlantItem_2);
	CREATE_VALUE(E_PlantItem_3);	
	CREATE_VALUE(E_PlantItemBtn_1);
	CREATE_VALUE(E_PlantItemBtn_2);
	CREATE_VALUE(E_PlantItemBtn_3);
	CREATE_VALUE(E_PlantText);
	CREATE_VALUE(E_PlantTips);
	
	//Pollination
	CREATE_VALUE(E_PollinationBG);
	CREATE_VALUE(E_PollinationItem);
	CREATE_VALUE(E_PollinationBtn);
	CREATE_VALUE(E_PollinationText);
	CREATE_VALUE(E_PollinationTips);

	//Harvest
	CREATE_VALUE(E_HarvestBG);
	CREATE_VALUE(E_HarvestItem);
	CREATE_VALUE(E_HarvestBtn);
	CREATE_VALUE(E_HarvestText);
	CREATE_VALUE(E_HarvestTips);

	//Product
	CREATE_VALUE(E_ProductBG);

	//Interative
	CREATE_VALUE(E_InterativeBG);
	CREATE_VALUE(E_FlowerDark);
	CREATE_VALUE(E_FoodDark);
	CREATE_VALUE(E_LuxuriousDark);
	CREATE_VALUE(E_MassageDark);	
	CREATE_VALUE(E_StoryDark);

	CREATE_VALUE(E_BackBtn);
	CREATE_VALUE(E_BackText);

/////////////////////////////////////////
//// Transition Video
////////////////////////////////////////
	CREATE_VALUE(TV_Start2Plant);
	CREATE_VALUE(TV_Plant2Pollination);
	CREATE_VALUE(TV_Pollination2Harvest);
	CREATE_VALUE(TV_Harvest2Product);
	CREATE_VALUE(TV_Product2Interative);

/////////////////////////////////////////
//// Animation Init
////////////////////////////////////////
	CREATE_VALUE(INIT_EnteStart);
	CREATE_VALUE(INIT_ShowIntro);
	CREATE_VALUE(INIT_IntroExit);
	CREATE_VALUE(INIT_BackToStart);

	CREATE_VALUE(INIT_PlantItemIn);
	CREATE_VALUE(INIT_PlantItemOut);
	CREATE_VALUE(INIT_PlantTextOut);
	CREATE_VALUE(INIT_PlantTipsIn);

	CREATE_VALUE(INIT_PollinationItemIn);
	CREATE_VALUE(INIT_PollinationItemOut);
	CREATE_VALUE(INIT_PollinationTextOut);
	CREATE_VALUE(INIT_PollinationTipsIn);

	CREATE_VALUE(INIT_HarvestItemIn);
	CREATE_VALUE(INIT_HarvestItemOut);
	CREATE_VALUE(INIT_HarvestTextOut);
	CREATE_VALUE(INIT_HarvestTipsIn);

	CREATE_VALUE(INIT_ProductWait);

	CREATE_VALUE(INIT_InterativeFadeIn);
	CREATE_VALUE(INIT_InterativeTextFadeIn);


/////////////////////////////////////////
//// Animation
////////////////////////////////////////
	CREATE_VALUE(ANIM_TITLE_FADEIN);

	//---
	CREATE_VALUE(ANIM_TITLE_FADEOUT);
	CREATE_VALUE(ANIM_TITLE_LIGHT_FADEOUT);
	CREATE_VALUE(ANIM_INTRO_FADEIN);
	CREATE_VALUE(ANIM_TITLE_BUTTON_FADEIN);

	//---
	CREATE_VALUE(ANIM_TITLE_BUTTON_FADEOUT);
	CREATE_VALUE(ANIM_INTRO_FADEOUT);
	CREATE_VALUE(ANIM_TO_PLANE);

	//---
	CREATE_VALUE(ANIM_TITLE_LIGHT_FADEIN);

	//---
	CREATE_VALUE(ANIM_PLANT_ITEM_1_FADEIN);
	CREATE_VALUE(ANIM_PLANT_ITEM_2_FADEIN);
	CREATE_VALUE(ANIM_PLANT_ITEM_3_FADEIN);
	CREATE_VALUE(ANIM_PLANT_BTN_1_FADEIN);
	CREATE_VALUE(ANIM_PLANT_BTN_2_FADEIN);
	CREATE_VALUE(ANIM_PLANT_BTN_3_FADEIN);

	//---
	CREATE_VALUE(ANIM_PLANT_ITEM_1_FADEOUT);
	CREATE_VALUE(ANIM_PLANT_ITEM_2_FADEOUT);
	CREATE_VALUE(ANIM_PLANT_ITEM_3_FADEOUT);
	CREATE_VALUE(ANIM_PLANT_BTN_1_FADEOUT);
	CREATE_VALUE(ANIM_PLANT_BTN_2_FADEOUT);
	CREATE_VALUE(ANIM_PLANT_BTN_3_FADEOUT);
	CREATE_VALUE(ANIM_PLANT_TEXT_FADEIN);

	//---
	CREATE_VALUE(ANIM_PLANT_TEXT_FADEOUT);

	//---
	CREATE_VALUE(ANIM_PLANT_TIPS_FADEIN);

	//---
	CREATE_VALUE(ANIM_POLLINATION_ITEM_FADEIN);
	CREATE_VALUE(ANIM_POLLINATION_BTN_FADEIN);

	//---
	CREATE_VALUE(ANIM_POLLINATION_ITEM_FADEOUT);
	CREATE_VALUE(ANIM_POLLINATION_BTN_FADEOUT);
	CREATE_VALUE(ANIM_POLLINATION_TEXT_FADEIN);

	//---
	CREATE_VALUE(ANIM_POLLINATION_TEXT_FADEOUT);

	//---
	CREATE_VALUE(ANIM_POLLINATION_TIPS_FADEIN);

	//---
	CREATE_VALUE(ANIM_HARVEST_ITEM_FADEIN);
	CREATE_VALUE(ANIM_HARVEST_BTN_FADEIN);

	//---
	CREATE_VALUE(ANIM_HARVEST_ITEM_FADEOUT);
	CREATE_VALUE(ANIM_HARVEST_BTN_FADEOUT);
	CREATE_VALUE(ANIM_HARVEST_TEXT_FADEIN);

	//---
	CREATE_VALUE(ANIM_HARVEST_TEXT_FADEOUT);

	//---
	CREATE_VALUE(ANIM_HARVEST_TIPS_FADEIN);

		//---
	CREATE_VALUE(ANIM_PRODUCT_WAIT);

	//---
	CREATE_VALUE(ANIM_MASSAGE_DARK_FADEIN);
	CREATE_VALUE(ANIM_FLOWER_DARK_FADEIN);
	CREATE_VALUE(ANIM_FOOD_DARK_FADEIN);
	CREATE_VALUE(ANIM_LUXURIOUS_DARK_FADEIN);	
	CREATE_VALUE(ANIM_STORY_DARK_FADEIN);
	
	//---
	CREATE_VALUE(ANIM_BACK_BTN_FADEIN);	
	CREATE_VALUE(ANIM_BACK_TEXT_FADEIN);

/////////////////////////////////////////
//// EVENT
////////////////////////////////////////
	CREATE_VALUE(T_ENABLE_CURSOR);
	CREATE_VALUE(T_DISABLE_CURSOR);
	CREATE_VALUE(T_ENABLE_BGM);
	CREATE_VALUE(T_DISABLE_BGM);
	CREATE_VALUE(T_RESET_IDLE);


	CREATE_VALUE(T_RESET);
};



#endif //_NAME_MANAGER_