#include "Character.h"
#include "main.h"
#include "input.h"
#include "Animation.h"
huhuhuh
vttgy
//Gem
int GemAniCnt = 0;
int GemAniNum = 0;
int GemAnimationSpeed = 10;
#define GEMANM_MAX (5)
float GemAnimationTbl[GEMANM_MAX] = { 0.0f / 75.0f,15.0f / 75.0f, 30.0f / 75.0f, 45.0f / 75.0f, 60.0f / 75.0f };
//ItemFeedback
int ItemAniCnt = 0;
int ItemAniNum = 0;
int ItemFeedbackAnimationSpeed = 10;
int ItemFeedbackTimer = 0;
#define ITEMFEEDBACKANM_MAX (5)
bool ItemDisState[1000];
float ItemFeedbackAnimationTbl[ITEMFEEDBACKANM_MAX] = { 0.0f / 160.0f,32.0f / 160.0f, 64.0f / 160.0f, 96.0f / 160.0f, 128.0f / 160.0f };
//DoorAnimation
int DoorAniCnt = 0;
int DoorAniNum = 0;
int DoorAnimationSpeed = 10;
int DoorTimer = 0;
#define DOORANM_MAX (3)
bool DoorDisState[1000];
float DoorAnimationTbl[DOORANM_MAX] = { 0.0f / 240.0f,80.0f / 240.0f, 160.0f / 240.0f};
//Cloud
int CloudAniCnt = 0;
int CloudAniNum = 0;
int CloudAnimationSpeed = 10;
#define CLOUDANM_MAX (2)
float CloudAnimationTbl[CLOUDANM_MAX] = { 0.0f / 512.0f,256.0f / 512.0f};
//LoadingIcon
int LoadingIconAniCnt = 0;
int LoadingIconAniNum = 0;
int LoadingIconAnimationSpeed = 10;
#define LOADINGICONANM_MAX (4)
float LoadingIconAnimationTbl[LOADINGICONANM_MAX] = { 0.0f / 140.0f,35.0f / 140.0f,70.0f / 140.0f,105.0f / 140.0f };

//原型函数定义
void GemAnimation();
void ItemFeedbackAnimation();
void CloudAnimation();
void LoadingIconAnimation();


void AnimationManagement()
{
	//GemAnimation管理
	GemAnimation();
	//ItemFeedbackAnimation
	ItemFeedbackAnimation();
	//DoorAnimation
	DoorAnimation();
	//CloudAnimation
	CloudAnimation();
	//LoadingIconAnimation();
	LoadingIconAnimation();
}
void GemAnimation()
{
	//Gem0
	//Animation位置的更新
	++GemAniCnt;
	if (GemAniCnt % GemAnimationSpeed == 0)
	{
		++GemAniNum;
		if (GemAniNum >= GEMANM_MAX)
		{
			GemAniNum = 0;
		}
		GemVertex[0][0].u = GemAnimationTbl[GemAniNum];
		GemVertex[0][1].u = GemAnimationTbl[GemAniNum] + 15.0f / 75.0f;
		GemVertex[0][2].u = GemVertex[0][0].u;
		GemVertex[0][3].u = GemVertex[0][1].u;
		GemVertex[1][0].u = GemAnimationTbl[GemAniNum];
		GemVertex[1][1].u = GemAnimationTbl[GemAniNum] + 15.0f / 75.0f;
		GemVertex[1][2].u = GemVertex[0][0].u;
		GemVertex[1][3].u = GemVertex[0][1].u;
		GemVertex[2][0].u = GemAnimationTbl[GemAniNum];
		GemVertex[2][1].u = GemAnimationTbl[GemAniNum] + 15.0f / 75.0f;
		GemVertex[2][2].u = GemVertex[0][0].u;
		GemVertex[2][3].u = GemVertex[0][1].u;
	}
	GemVertex[0][0].v = 0.0f;
	GemVertex[0][1].v = GemVertex[0][0].v;
	GemVertex[0][2].v = 75.0f / 75.0f;
	GemVertex[0][3].v = GemVertex[0][2].v;
	GemVertex[1][0].v = 0.0f;
	GemVertex[1][1].v = GemVertex[0][0].v;
	GemVertex[1][2].v = 75.0f / 75.0f;
	GemVertex[1][3].v = GemVertex[0][2].v;
	GemVertex[2][0].v = 0.0f;
	GemVertex[2][1].v = GemVertex[0][0].v;
	GemVertex[2][2].v = 75.0f / 75.0f;
	GemVertex[2][3].v = GemVertex[0][2].v;

}
void ItemFeedbackAnimation()
{
	//Gem0
	//Animation位置的更新
	++ItemAniCnt;
	if (ItemAniCnt % ItemFeedbackAnimationSpeed == 0)
	{
		++ItemAniNum;
		if (ItemAniNum >= ITEMFEEDBACKANM_MAX)
		{
			ItemAniNum = 0;
		}
		ItemFeedbackVertex[0][0].u =ItemFeedbackAnimationTbl[ItemAniNum];
		ItemFeedbackVertex[0][1].u =ItemFeedbackAnimationTbl[ItemAniNum] + 32.0f / 160.0f;
		ItemFeedbackVertex[0][2].u =ItemFeedbackVertex[0][0].u;
		ItemFeedbackVertex[0][3].u =ItemFeedbackVertex[0][1].u;
		ItemFeedbackVertex[1][0].u = ItemFeedbackAnimationTbl[ItemAniNum];
		ItemFeedbackVertex[1][1].u = ItemFeedbackAnimationTbl[ItemAniNum] + 32.0f / 160.0f;
		ItemFeedbackVertex[1][2].u = ItemFeedbackVertex[0][0].u;
		ItemFeedbackVertex[1][3].u = ItemFeedbackVertex[0][1].u;
		ItemFeedbackVertex[2][0].u = ItemFeedbackAnimationTbl[ItemAniNum];
		ItemFeedbackVertex[2][1].u = ItemFeedbackAnimationTbl[ItemAniNum] + 32.0f / 160.0f;
		ItemFeedbackVertex[2][2].u = ItemFeedbackVertex[0][0].u;
		ItemFeedbackVertex[2][3].u = ItemFeedbackVertex[0][1].u;
	}
	ItemFeedbackVertex[0][0].v = 0.0f;
	ItemFeedbackVertex[0][1].v = ItemFeedbackVertex[0][0].v;
	ItemFeedbackVertex[0][2].v = 128.0f / 128.0f;
	ItemFeedbackVertex[0][3].v = ItemFeedbackVertex[0][2].v;
	ItemFeedbackVertex[1][0].v = 0.0f;
	ItemFeedbackVertex[1][1].v = ItemFeedbackVertex[0][0].v;
	ItemFeedbackVertex[1][2].v = 128.0f / 128.0f;
	ItemFeedbackVertex[1][3].v = ItemFeedbackVertex[0][2].v;
	ItemFeedbackVertex[2][0].v = 0.0f;
	ItemFeedbackVertex[2][1].v = ItemFeedbackVertex[0][0].v;
	ItemFeedbackVertex[2][2].v = 128.0f / 128.0f;
	ItemFeedbackVertex[2][3].v = ItemFeedbackVertex[0][2].v;
}
void DoorAnimation()
{
	//Door 0 1 2 
	//Animation位置的更新
	++DoorAniCnt;
	if (DoorAniCnt % DoorAnimationSpeed == 0)
	{
		++DoorAniNum;
		if (DoorAniNum >= DOORANM_MAX)
		{
			DoorAniNum = 0;
		}
		DoorAnimationVertex[0][0].u = DoorAnimationTbl[DoorAniNum];
		DoorAnimationVertex[0][1].u = DoorAnimationTbl[DoorAniNum] + 80.0f / 240.0f;
		DoorAnimationVertex[0][2].u = DoorAnimationVertex[0][0].u;
		DoorAnimationVertex[0][3].u = DoorAnimationVertex[0][1].u;
		DoorAnimationVertex[1][0].u = DoorAnimationTbl[DoorAniNum];
		DoorAnimationVertex[1][1].u = DoorAnimationTbl[DoorAniNum] + 80.0f / 240.0f;
		DoorAnimationVertex[1][2].u = DoorAnimationVertex[0][0].u;
		DoorAnimationVertex[1][3].u = DoorAnimationVertex[0][1].u;
		DoorAnimationVertex[2][0].u = DoorAnimationTbl[DoorAniNum];
		DoorAnimationVertex[2][1].u = DoorAnimationTbl[DoorAniNum] + 80.0f / 240.0f;
		DoorAnimationVertex[2][2].u = DoorAnimationVertex[0][0].u;
		DoorAnimationVertex[2][3].u = DoorAnimationVertex[0][1].u;
	}
	DoorAnimationVertex[0][0].v = 0.0f;
	DoorAnimationVertex[0][1].v = DoorVertex[0][0].v;
	DoorAnimationVertex[0][2].v = 160.0f / 160.0f;
	DoorAnimationVertex[0][3].v = DoorVertex[0][2].v;
	DoorAnimationVertex[1][0].v = 0.0f;
	DoorAnimationVertex[1][1].v = DoorVertex[0][0].v;
	DoorAnimationVertex[1][2].v = 160.0f / 160.0f;
	DoorAnimationVertex[1][3].v = DoorVertex[0][2].v;
	DoorAnimationVertex[2][0].v = 0.0f;
	DoorAnimationVertex[2][1].v = DoorVertex[0][0].v;
	DoorAnimationVertex[2][2].v = 160.0f / 160.0f;
	DoorAnimationVertex[2][3].v = DoorVertex[0][2].v;
}

void CloudAnimation()
{
	//Cloud0
	//Animation位置的更新
	++CloudAniCnt;
	if (CloudAniCnt % CloudAnimationSpeed == 0)
	{
		++CloudAniNum;
		if (CloudAniNum >= CLOUDANM_MAX)
		{
			CloudAniNum = 0;
		}
		CloudVertex[0][0].u = CloudAnimationTbl[CloudAniNum];
		CloudVertex[0][1].u = CloudAnimationTbl[CloudAniNum] + 256.0f / 512.0f;
		CloudVertex[0][2].u = CloudVertex[0][0].u;
		CloudVertex[0][3].u = CloudVertex[0][1].u;
		CloudVertex[1][0].u = CloudAnimationTbl[CloudAniNum];
		CloudVertex[1][1].u = CloudAnimationTbl[CloudAniNum] + 256.0f / 512.0f;
		CloudVertex[1][2].u = CloudVertex[0][0].u;
		CloudVertex[1][3].u = CloudVertex[0][1].u;
	}
	CloudVertex[0][0].v = 0.0f;
	CloudVertex[0][1].v = CloudVertex[0][0].v;
	CloudVertex[0][2].v = 256.0f / 256.0f;
	CloudVertex[0][3].v = CloudVertex[0][2].v;
	CloudVertex[1][0].v = 0.0f;
	CloudVertex[1][1].v = CloudVertex[0][0].v;
	CloudVertex[1][2].v = 256.0f / 256.0f;
	CloudVertex[1][3].v = CloudVertex[0][2].v;
}
void LoadingIconAnimation()
{
	//LoadingIcon
	//Animation位置的更新
	++LoadingIconAniCnt;
	if (LoadingIconAniCnt % LoadingIconAnimationSpeed == 0)
	{
		++LoadingIconAniNum;
		if (LoadingIconAniNum >= LOADINGICONANM_MAX)
		{
			LoadingIconAniNum = 0;
		}
		LoadingIconVertex[1].u = LoadingIconAnimationTbl[LoadingIconAniNum];
		LoadingIconVertex[0].u = LoadingIconAnimationTbl[LoadingIconAniNum] + 35.0f / 140.0f;
		LoadingIconVertex[3].u = LoadingIconVertex[1].u;
		LoadingIconVertex[2].u = LoadingIconVertex[0].u;
	}
	LoadingIconVertex[0].v = 0.0f;
	LoadingIconVertex[1].v = LoadingIconVertex[0].v;
	LoadingIconVertex[2].v = 32.0f / 32.0f;
	LoadingIconVertex[3].v = LoadingIconVertex[2].v;

}
