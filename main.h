//=============================================================================
//
// DX21
// DirectX雛型処理 [main.h]
//
//=============================================================================
#ifndef _MAIN_H_
#define _MAIN_H_

//*****************************************************************************
// インクルードファイル
//*****************************************************************************
#include <windows.h>
#include "d3dx9.h"						// 描画処理に必要
#include "input.h"						//键盘输入相关的操作 来自老师
#include "XAudio2.h"					//声音相关操作 来自老师
#include "Character.h"					//玩家相关操作
#include "Texture.h"					//材质宣言相关
#include "Physics.h"					//物理碰撞相关的处理
#include "Animation.h"					//动画相关的处理
#include "Camera.h"						//相机相关的处理  目前没有用上 3D相关
#include "Tool.h"						//工具相关的处理 目前是Null的

//*****************************************************************************
// ライブラリのリンク
//*****************************************************************************
#if 1	// [ここを"0"にした場合、"構成プロパティ" -> "リンカ" -> "入力" -> "追加の依存ファイル"に
// 対象ライブラリを設定する]
#pragma comment (lib, "d3d9.lib")		// 描画処理に必要
#pragma comment (lib, "d3dx9.lib")		// [d3d9.lib]の拡張ライブラリ
#pragma comment (lib, "dxguid.lib")		// DirectXコンポーネント使用に必要
#pragma comment (lib, "winmm.lib")		// 现在时间使用に必要
#endif

//*****************************************************************************
// マクロ定義//宏定义
//*****************************************************************************
#define SCREEN_WIDTH	(1920)			// ウインドウの幅
#define SCREEN_HEIGHT	(1080)			// ウインドウの高さ

//*****************************************************************************
// グローバル変数
//*****************************************************************************
//SceenManager用的Flag
extern int SceenFlag;
extern bool DebugTest;
extern int SaveSceenMessage;//用于储存关卡信息

//Sceen1TPTeam
extern int Sceen1TPTeamPosX;
extern int Sceen1TPTeamPosY;
extern int Sceen1TPTeamSizeX;
extern int Sceen1TPTeamSizeY;
extern int Sceen1DisplayTime;					//Sceen1显示时间
extern int Sceen1Timer;						//内部计算时间用

//Sceen2Title
//Sceen2BgPic
extern int Sceen2BgPicPosX;
extern int Sceen2BgPicPosY;
extern int Sceen2BgPicSizeX;
extern int Sceen2BgPicSizeY;
//Sceen2Sun
extern int Sceen2SunPosX;
extern int Sceen2SunPosY;
extern int Sceen2SunSizeX;
extern int Sceen2SunSizeY;
extern int SunTimer;
//Sceen2Seagull1
extern int Sceen2Seagull1PosX;
extern int Sceen2Seagull1PosY;
extern int Sceen2Seagull1SizeX;
extern int Sceen2Seagull1SizeY;
extern int Sceen2Seagull1Timer;
//Sceen2Seagull2
extern int Sceen2Seagull2PosX;
extern int Sceen2Seagull2PosY;
extern int Sceen2Seagull2SizeX;
extern int Sceen2Seagull2SizeY;
extern int Sceen2Seagull2Timer;
//Sceen2Title图片
extern int Sceen2TitlePosX;
extern int Sceen2TitlePosY;
extern int Sceen2TitleSizeX;
extern int Sceen2TitleSizeY;
//Sceen2OnePlayerHighlight
extern int Sceen2OnePlayerHighlightPosX;
extern int Sceen2OnePlayerHighlightPosY;
extern int Sceen2OnePlayerHighlightSizeX;
extern int Sceen2OnePlayerHighlightSizeY;
//Sceen2OnePlayerLowlight
extern int Sceen2OnePlayerLowlightPosX;
extern int Sceen2OnePlayerLowlightPosY;
extern int Sceen2OnePlayerLowlightSizeX;
extern int Sceen2OnePlayerLowlightSizeY;
//Sceen2TwoPlayerHighLight
extern int Sceen2TwoPlayerHighlightPosX;
extern int Sceen2TwoPlayerHighlightPosY;
extern int Sceen2TwoPlayerHighlightSizeX;
extern int Sceen2TwoPlayerHighlightSizeY;
//Sceen2TwoPlayerLowlight
extern int Sceen2TwoPlayerLowlightPosX;
extern int Sceen2TwoPlayerLowlightPosY;
extern int Sceen2TwoPlayerLowlightSizeX;
extern int Sceen2TwoPlayerLowlightSizeY;
//Sceen2SelectArrow
extern int Sceen2SelectArrowPosX;
extern int Sceen2SelectArrowPosY;
extern int Sceen2SelectArrowSizeX;
extern int Sceen2SelectArrowSizeY;
extern int ArrowTimer;
extern bool ButtonState;

//Sceen3SelectSceen
extern int StageSelectState;//Stage 1 Stage 2 Stage 3 Stage 4
//Sceen3BgPic
extern int Sceen3BgPicPosX;
extern int Sceen3BgPicPosY;
extern int Sceen3BgPicSizeX;
extern int Sceen3BgPicSizeY;
//Sceen3SelectBox
extern int Sceen3SelectBoxPosX;
extern int Sceen3SelectBoxPosY;
extern int Sceen3SelectBoxSizeX;
extern int Sceen3SelectBoxSizeY;
extern int BoxTimer;
//Sceen3Stage1
extern int Sceen3Stage1PosX;
extern int Sceen3Stage1PosY;
extern int Sceen3Stage1SizeX;
extern int Sceen3Stage1SizeY;
//Sceen3Stage2
extern int Sceen3Stage2PosX;
extern int Sceen3Stage2PosY;
extern int Sceen3Stage2SizeX;
extern int Sceen3Stage2SizeY;
//Sceen3Stage3
extern int Sceen3Stage3PosX;
extern int Sceen3Stage3PosY;
extern int Sceen3Stage3SizeX;
extern int Sceen3Stage3SizeY;
//Sceen3Stage4
extern int Sceen3Stage4PosX;
extern int Sceen3Stage4PosY;
extern int Sceen3Stage4SizeX;
extern int Sceen3Stage4SizeY;
//CharacterA
extern int CharacterADefPosX;
extern int CharacterADefPosY;
extern int CharacterAPosX;
extern int CharacterAPosY;
extern int CharacterASizeX;
extern int CharacterASizeY;
//Sceen3SelectTile
extern int Sceen3SelectTilePosX;
extern int Sceen3SelectTilePosY;
extern int Sceen3SelectTileSizeX;
extern int Sceen3SelectTileSizeY;
//GroundBox
extern int GroundBoxPosX;
extern int GroundBoxPosY;
extern int GroundBoxSizeX;
extern int GroundBoxSizeY;

//HeadBox
extern int HeadBoxPosX;
extern int HeadBoxPosY;
extern int HeadBoxSizeX;
extern int HeadBoxSizeY;
//CharacterBox
extern int CharacterBoxPosX;
extern int DefaultCharacterBoxPosY;
extern int CharacterBoxPosY;
extern int CharacterBoxSizeX;
extern int DefaultCharacterBoxSizeY;
extern int SmallCharacterBoxSizeY;
extern int CharacterBoxSizeY;
//Sceen3House
extern int Sceen3HousePosX;
extern int Sceen3HousePosY;
extern int Sceen3HouseSizeX;
extern int Sceen3HouseSizeY;
//Gem
#define GEMMAX (1000)
extern int GemPosX[GEMMAX];
extern int GemPosY[GEMMAX];
extern int GemSizeX[GEMMAX];
extern int GemSizeY[GEMMAX];
//ItemFeedback
#define ITEMFEEDBACKMAX (1000)
extern int ItemFeedbackPosX[ITEMFEEDBACKMAX];
extern int ItemFeedbackPosY[ITEMFEEDBACKMAX];
extern int ItemFeedbackSizeX[ITEMFEEDBACKMAX];
extern int ItemFeedbackSizeY[ITEMFEEDBACKMAX];
extern bool TouchState[ITEMFEEDBACKMAX];
//Arrow
extern int ArrowPosX;
extern int ArrowPosY;
extern int ArrowSizeX;
extern int ArrowSizeY;
//过场特效BlackPic
extern int BlackPicPosX;
extern int BlackPicPosY;
extern int BlackPicSizeX;
extern int BlackPicSizeY;
extern int BlackPicMoveSpeed;
//Door
#define DOORMAX (100)
extern int DoorPosX[DOORMAX];
extern int DoorPosY[DOORMAX];
extern int DoorSizeX[DOORMAX];
extern int DoorSizeY[DOORMAX];
extern bool DoorCollisionState[DOORMAX];
//DoorAnimation
extern int DoorAnimationPosX[DOORMAX];
extern int DoorAnimationPosY[DOORMAX];
extern int DoorAnimationSizeX[DOORMAX];
extern int DoorAnimationSizeY[DOORMAX];
extern bool DoorAniState[DOORMAX];
extern int DoorAnimationTimer;
//Key
#define KEYMAX (100)
extern int KeyPosX[KEYMAX];
extern int KeyPosY[KEYMAX];
extern int KeySizeX[KEYMAX];
extern int KeySizeY[KEYMAX];
//Translucent
extern int TranslucentSizeX[KEYMAX];
extern int TranslucentSizeY[KEYMAX];
extern int TranslucentPosX[KEYMAX];
extern int TranslucentPosY[KEYMAX];
//W
extern int WPosX;
extern int WPosY;
extern int WSizeX;
extern int WSizeY;
//A
extern int ASizeX;
extern int ASizeY;
extern int APosX;
extern int APosY;
//S
extern int SSizeX;
extern int SSizeY;
extern int SPosX;
extern int SPosY;
//D
extern int DSizeX;
extern int DSizeY;
extern int DPosX;
extern int DPosY;
//Space
extern int SpaceSizeX;
extern int SpaceSizeY;
extern int SpacePosX;
extern int SpacePosY;



//Sceen4Stage1
//Sceen4Stage1Sky
extern int Sceen4Stage1SkyPosX;
extern int Sceen4Stage1SkyPosY;
extern int Sceen4Stage1SkySizeX;
extern int Sceen4Stage1SkySizeY;
//Sceen4Stage1Tile
extern int Sceen4Stage1TilePosX;
extern int Sceen4Stage1TilePosY;
extern int Sceen4Stage1TileSizeX;
extern int Sceen4Stage1TileSizeY;
//Cloud
#define CLOUDMAX (100)
extern int CloudPosX[CLOUDMAX];
extern int CloudPosY[CLOUDMAX];
extern int CloudSizeX[CLOUDMAX];
extern int CloudSizeY[CLOUDMAX];
//Sceen5
//Sceen5Tile
extern int Sceen5TilePosX;
extern int Sceen5TilePosY;
extern int Sceen5TileSizeX;
extern int Sceen5TileSizeY;
//Sceen5Arrow
extern int Sceen5ArrowPosX;
extern int Sceen5ArrowPosY;
extern int Sceen5ArrowSizeX;
extern int Sceen5ArrowSizeY;
//Spike
#define SPIKEMAX (1000)
extern int SpikePosX[SPIKEMAX];
extern int SpikePosY[SPIKEMAX];
extern int SpikeSizeX[SPIKEMAX];
extern int SpikeSizeY[SPIKEMAX];
extern bool SpikeMoveState[SPIKEMAX];

//Sceen6Stage1_2
//Sceen6Tile
extern int Sceen6TilePosX;
extern int Sceen6TilePosY;
extern int Sceen6TileSizeX;
extern int Sceen6TileSizeY;
//Laser
extern int LaserPosX;
extern int LaserPosY;
extern int LaserSizeX;
extern int LaserSizeY;

//Sceen7Stage1_2
//Sceen7Tile
extern int Sceen7TilePosX;
extern int Sceen7TilePosY;
extern int Sceen7TileSizeX;
extern int Sceen7TileSizeY;
//Bullet
extern int BulletPosX;
extern int BulletPosY;
extern int BulletSizeX;
extern int BulletSizeY;

//Sceen8Stage2_1
//Sceen8Tile
extern int Sceen8TilePosX;
extern int Sceen8TilePosY;
extern int Sceen8TileSizeX;
extern int Sceen8TileSizeY;
//横板过关游戏的世界坐标的设定
extern int WorldMovePosX;


//Loading
//LoadingTitle
extern int LoadingTitlePosX;
extern int LoadingTitlePosY;
extern int LoadingTitleSizeX;
extern int LoadingTitleSizeY;
//Stage1Title
extern int Stage1TitlePosX;
extern int Stage1TitlePosY;
extern int Stage1TitleSizeX;
extern int Stage1TitleSizeY;
//Stage2Title
extern int Stage2TitlePosX;
extern int Stage2TitlePosY;
extern int Stage2TitleSizeX;
extern int Stage2TitleSizeY;
//LoadingIcon
extern int LoadingIconPosX;
extern int LoadingIconPosY;
extern int LoadingIconSizeX;
extern int LoadingIconSizeY;
//NowLoading
extern int NowLoadingPosX;
extern int NowLoadingPosY;
extern int NowLoadingSizeX;
extern int NowLoadingSizeY;

//Sceen81GameOver
extern bool GameOverButtonState;
//GameOverTitle
extern int GameOverTitlePosX;
extern int GameOverTitlePosY;
extern int GameOverTitleSizeX;
extern int GameOverTitleSizeY;
//RetryHighlight
extern int RetryHighlightPosX;
extern int RetryHighlightPosY;
extern int RetryHighlightSizeX;
extern int RetryHighlightSizeY;
//RetryLowlight
extern int RetryLowlightPosX;
extern int RetryLowlightPosY;
extern int RetryLowlightSizeX;
extern int RetryLowlightSizeY;
//StageSelectPlayerHighLight
extern int StageSelectHighlightPosX;
extern int StageSelectHighlightPosY;
extern int StageSelectHighlightSizeX;
extern int StageSelectHighlightSizeY;
//StageSelectLowlight
extern int StageSelectLowlightPosX;
extern int StageSelectLowlightPosY;
extern int StageSelectLowlightSizeX;
extern int StageSelectLowlightSizeY;
//Sceen81BgPic
extern int Sceen81BgPicPosX;
extern int Sceen81BgPicPosY;
extern int Sceen81BgPicSizeX;
extern int Sceen81BgPicSizeY;

//Sceen82GameClear
//Sceen82BgPic
extern int Sceen82BgPicPosX;
extern int Sceen82BgPicPosY;
extern int Sceen82BgPicSizeX;
extern int Sceen82BgPicSizeY;
//StageClearTitle
extern int StageClearTitlePosX;
extern int StageClearTitlePosY;
extern int StageClearTitleSizeX;
extern int StageClearTitleSizeY;



//碰撞体相关
//与CharacterA发生的碰撞
#define WALLMAX (100)
extern bool WallCollision[WALLMAX];
extern int WallPosX[WALLMAX];
extern int WallPosY[WALLMAX];
extern int WallSizeX[WALLMAX];
extern int WallSizeY[WALLMAX];
//与HeadBox发生的碰撞
#define ROOFMAX (100)
extern bool RoofCollision[ROOFMAX];
extern int RoofPosX[ROOFMAX];
extern int RoofPosY[ROOFMAX];
extern int RoofSizeX[ROOFMAX];
extern int RoofSizeY[ROOFMAX];
//与GroundBox发生的碰撞
#define TILEMAX (100)
extern bool TileCollision[TILEMAX];
extern int TilePosX[TILEMAX];
extern int TilePosY[TILEMAX];
extern int TileSizeX[TILEMAX];
extern int TileSizeY[TILEMAX];
//增加攀爬藤曼的代码用
#define VINE_MAX (100)
extern bool VineCollision[VINE_MAX];
extern int VinePosX[VINE_MAX];
extern int VinePosY[VINE_MAX];
extern int VineSizeX[VINE_MAX];
extern int VineSizeY[VINE_MAX];
extern bool VineState;


//无敌时间
extern bool InvincibleState;


//*****************************************************************************
// 多边形構造体定義
//*****************************************************************************
typedef struct VERTEX_2D {
	float X, Y, Z;		//顶点坐标
	float rhw;
	D3DCOLOR col;
	float u, v;			//材质坐标
}VERTEX_2D;

//构造体原型定义
//Sceen1TPTeam场景
//Sceen1TPTeam
extern VERTEX_2D Sceen1TPTeamVertex[4];

//Sceen2Title场景
//Sceen2BgPic
extern VERTEX_2D Sceen2BgPicVertex[4];
//Sceen2Sun
extern VERTEX_2D Sceen2SunVertex[4];
//Sceen2Seagull1
extern VERTEX_2D Sceen2Seagull1Vertex[4];
//Sceen2Seagull2
extern VERTEX_2D Sceen2Seagull2Vertex[4];
//Sceen2Title
extern VERTEX_2D Sceen2TitleVertex[4];
//Sceen2OnePlayerHighlight
extern VERTEX_2D Sceen2OnePlayerHighlightVertex[4];
//Sceen2OnePlayerLowlight
extern VERTEX_2D Sceen2OnePlayerLowlightVertex[4];
//Sceen2TwoPlayerHighlight
extern VERTEX_2D Sceen2TwoPlayerHighlightVertex[4];
//Sceen2TwoPlayerLowlight
extern VERTEX_2D Sceen2TwoPlayerLowlightVertex[4];
//Sceen2SelectArrow
extern VERTEX_2D Sceen2SelectArrowVertex[4];

//Sceen3Select
//Sceen3BgPic
extern VERTEX_2D Sceen3BgPicVertex[4];
//Sceen3SelectBox
extern VERTEX_2D Sceen3SelectBoxVertex[4];
//Sceen3Stage1
extern VERTEX_2D Sceen3Stage1Vertex[4];
//Sceen3Stage2
extern VERTEX_2D Sceen3Stage2Vertex[4];
//Sceen3Stage3
extern VERTEX_2D Sceen3Stage3Vertex[4];
//Sceen3Stage4
extern VERTEX_2D Sceen3Stage4Vertex[4];
//CharacterA
extern VERTEX_2D CharacterAVertex[4];
//Sceen3SelectTile
extern VERTEX_2D Sceen3SelectTileVertex[4];
//GroundBox
extern VERTEX_2D GroundBoxVertex[4];
//HeadBox
extern VERTEX_2D HeadBoxVertex[4];
//CharacterBox
extern VERTEX_2D CharacterBoxVertex[4];
//Sceen3House
extern VERTEX_2D Sceen3HouseVertex[4];
//Gem
extern VERTEX_2D GemVertex[GEMMAX][4];
//ItemFeedback
extern VERTEX_2D ItemFeedbackVertex[ITEMFEEDBACKMAX][4];
//Arrow
extern VERTEX_2D ArrowVertex[4];
//过场特效BlackPic
extern VERTEX_2D BlackPicVertex[4];
//Door
extern VERTEX_2D DoorVertex[DOORMAX][4];
//DoorAnimation
extern VERTEX_2D DoorAnimationVertex[DOORMAX][4];
//Key
extern VERTEX_2D KeyVertex[KEYMAX][4];
//Translucent
extern VERTEX_2D TranslucentVertex[KEYMAX][4];
//W
extern VERTEX_2D WVertex[4];
//A
extern VERTEX_2D AVertex[4];
//S
extern VERTEX_2D SVertex[4];
//D
extern VERTEX_2D DVertex[4];
//Space
extern VERTEX_2D SpaceVertex[4];

//Sceen4
//Sceen4Stage1Sky
extern VERTEX_2D Sceen4Stage1SkyVertex[4];
//Sceen4Stage1Tile
extern VERTEX_2D Sceen4Stage1TileVertex[4];
//Cloud
extern VERTEX_2D CloudVertex[CLOUDMAX][4];

//Sceen5
//Sceen5Tile
extern VERTEX_2D Sceen5TileVertex[4];
//Sceen5Arrow
extern VERTEX_2D Sceen5ArrowVertex[4];
//Spike
extern VERTEX_2D SpikeVertex[SPIKEMAX][4];

//Sceen6Tile
extern VERTEX_2D Sceen6TileVertex[4];
//Laser
extern VERTEX_2D LaserVertex[4];

//Sceen7Tile
extern VERTEX_2D Sceen7TileVertex[4];
//Bullet
extern VERTEX_2D BulletVertex[4];

//Sceen8Tile
extern VERTEX_2D Sceen8TileVertex[4];



//Loading
//LoadingTitle
extern VERTEX_2D LoadingTitleVertex[4];
//Stage1Title
extern VERTEX_2D Stage1TitleVertex[4];
//Stage2Title
extern VERTEX_2D Stage2TitleVertex[4];
//LoadingIcon
extern VERTEX_2D LoadingIconVertex[4];
//Nowloading
extern VERTEX_2D NowLoadingVertex[4];

//Sceen81GameOverTitle
extern VERTEX_2D GameOverTitleVertex[4];
//RetryHighlight
extern VERTEX_2D RetryHighlightVertex[4];
//RetryLowlight
extern VERTEX_2D RetryLowlightVertex[4];
//StageSelectHighlight
extern VERTEX_2D StageSelectHighlightVertex[4];
//StageSelectLowlight
extern VERTEX_2D StageSelectLowlightVertex[4];
//Sceen81BgPic
extern VERTEX_2D Sceen81BgPicVertex[4];

//Sceen82StageClear
//Sceen82BgPic
extern VERTEX_2D Sceen82BgPicVertex[4];
//StageClearTitle
extern VERTEX_2D StageClearTitleVertex[4];

#endif