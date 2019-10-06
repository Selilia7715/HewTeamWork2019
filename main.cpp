#include "main.h"
#include <Windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//*****************************************************************************
// マクロ定義//DirectX相关
//*****************************************************************************
#define	CLASS_NAME		"サンプル"					// ウインドウクラスの名前
#define WINDOW_NAME		"ゲーム名:Wolf Escape  操作説明:移動--WASD,ジャンプ--Space,確認--Enter"	// ウィンドウの名前
#define PI (3.1415926)
#define FVF_VERTEX_2D (D3DFVF_XYZRHW|D3DFVF_DIFFUSE|D3DFVF_TEX1)
HWND hWnd;
#define FPS (60)									//刷新率
//FPS管理用
int g_nCountFPS = 0;
float g_dispFPS = 0;

//*****************************************************************************
// グローバル変数
//*****************************************************************************
//SceenManager用的Flag
int SceenFlag = 1;//Sceen1TPTeam ,Sceen2Title,Sceen3Select,Sceen4Game,Sceen5Result
bool DebugTest = false;
int SaveSceenMessage = 0;//用于储存关卡信息

//Sceen1TPTeam
int Sceen1TPTeamPosX = SCREEN_WIDTH / 2;
int Sceen1TPTeamPosY = SCREEN_HEIGHT / 2;
int Sceen1TPTeamSizeX = 1000;
int Sceen1TPTeamSizeY = 540;
int Sceen1DisplayTime = 120;					//Sceen1显示时间
int Sceen1Timer = 0;						//内部计算时间用

//Sceen2Title
//Sceen2BgPic
int Sceen2BgPicPosX = SCREEN_WIDTH / 2;
int Sceen2BgPicPosY = SCREEN_HEIGHT / 2;
int Sceen2BgPicSizeX = SCREEN_WIDTH;
int Sceen2BgPicSizeY = SCREEN_HEIGHT;
//Sceen2Sun
int Sceen2SunPosX = 1700;
int Sceen2SunPosY = 120;
int Sceen2SunSizeX = 300;
int Sceen2SunSizeY = 300;
int SunTimer = 0;
//Sceen2Seagull1
int Sceen2Seagull1PosX = 700;
int Sceen2Seagull1PosY = 420;
int Sceen2Seagull1SizeX = 200;
int Sceen2Seagull1SizeY = 200;
int Sceen2Seagull1Timer = 0;
//Sceen2Seagull2
int Sceen2Seagull2PosX = 1200;
int Sceen2Seagull2PosY = 400;
int Sceen2Seagull2SizeX = 100;
int Sceen2Seagull2SizeY = 100;
int Sceen2Seagull2Timer = 0;
//Sceen2Title图片
int Sceen2TitlePosX = SCREEN_WIDTH / 2;
int Sceen2TitlePosY = 200;
int Sceen2TitleSizeX = 1200;
int Sceen2TitleSizeY = 300;
//Sceen2OnePlayerHighlight
int Sceen2OnePlayerHighlightPosX = SCREEN_WIDTH / 2;
int Sceen2OnePlayerHighlightPosY = 650;
int Sceen2OnePlayerHighlightSizeX = 720;
int Sceen2OnePlayerHighlightSizeY = 180;
//Sceen2OnePlayerLowlight
int Sceen2OnePlayerLowlightPosX = Sceen2OnePlayerHighlightPosX;
int Sceen2OnePlayerLowlightPosY = Sceen2OnePlayerHighlightPosY;
int Sceen2OnePlayerLowlightSizeX = 600;
int Sceen2OnePlayerLowlightSizeY = 150;
//Sceen2TwoPlayerHighLight
int Sceen2TwoPlayerHighlightPosX = SCREEN_WIDTH / 2;
int Sceen2TwoPlayerHighlightPosY = 900;
int Sceen2TwoPlayerHighlightSizeX = 720;
int Sceen2TwoPlayerHighlightSizeY = 180;
//Sceen2TwoPlayerLowlight
int Sceen2TwoPlayerLowlightPosX = Sceen2TwoPlayerHighlightPosX;
int Sceen2TwoPlayerLowlightPosY = Sceen2TwoPlayerHighlightPosY;
int Sceen2TwoPlayerLowlightSizeX = 600;
int Sceen2TwoPlayerLowlightSizeY = 150;
//Sceen2SelectArrow
int Sceen2SelectArrowPosX = SCREEN_WIDTH / 2;
int Sceen2SelectArrowPosY = Sceen2OnePlayerHighlightPosY;
int Sceen2SelectArrowSizeX = 800;
int Sceen2SelectArrowSizeY = 200;
int ArrowTimer = 0;
bool ButtonState = true;

//Sceen3SelectSceen
int StageSelectState = 1;//Stage 1 Stage 2 Stage 3 Stage 4
//Sceen3BgPic
int Sceen3BgPicPosX = SCREEN_WIDTH / 2;
int Sceen3BgPicPosY = SCREEN_HEIGHT / 2;
int Sceen3BgPicSizeX = SCREEN_WIDTH;
int Sceen3BgPicSizeY = SCREEN_HEIGHT;
//Sceen3SelectBox
int Sceen3SelectBoxPosX = 360;
int Sceen3SelectBoxPosY = 700;
int Sceen3SelectBoxSizeX = 400;
int Sceen3SelectBoxSizeY = 400;
int BoxTimer = 0;
//Sceen3Stage1
int Sceen3Stage1PosX = 640;
int Sceen3Stage1PosY = 570;
int Sceen3Stage1SizeX = 120;
int Sceen3Stage1SizeY = 50;
//Sceen3Stage2
int Sceen3Stage2PosX = 1280;
int Sceen3Stage2PosY = Sceen3Stage1PosY;
int Sceen3Stage2SizeX = Sceen3Stage1SizeX;
int Sceen3Stage2SizeY = Sceen3Stage1SizeY;
//Sceen3Stage3
int Sceen3Stage3PosX = 1160;
int Sceen3Stage3PosY = Sceen3Stage1PosY;
int Sceen3Stage3SizeX = Sceen3Stage1SizeX;
int Sceen3Stage3SizeY = Sceen3Stage1SizeY;
//Sceen3Stage4
int Sceen3Stage4PosX = 1560;
int Sceen3Stage4PosY = Sceen3Stage1PosY;
int Sceen3Stage4SizeX = Sceen3Stage1SizeX;
int Sceen3Stage4SizeY = Sceen3Stage1SizeY;
//CharacterA
int CharacterADefPosX = 200;
int CharacterADefPosY = 600;
int CharacterAPosX = CharacterADefPosX;
int CharacterAPosY = CharacterADefPosY;
int CharacterASizeX = 100;
int CharacterASizeY = 200;
//Sceen3SelectTile
int Sceen3SelectTilePosX = SCREEN_WIDTH / 2;
int Sceen3SelectTilePosY = SCREEN_HEIGHT / 2;
int Sceen3SelectTileSizeX = SCREEN_WIDTH;
int Sceen3SelectTileSizeY = SCREEN_HEIGHT;
//GroundBox
int GroundBoxSizeX = 20;
int GroundBoxSizeY = 10;
int GroundBoxPosX = CharacterAPosX;
int GroundBoxPosY = CharacterAPosY + CharacterASizeY / 2 - GroundBoxSizeY / 2 + 10;//Box要比玩家稍微下一点点
//HeadBox
int HeadBoxSizeX = 20;
int HeadBoxSizeY = 10;
int HeadBoxPosX = CharacterAPosX;
int HeadBoxPosY = CharacterAPosY - CharacterASizeY / 2 - HeadBoxSizeY / 2 + 50;
//CharacterBox
int CharacterBoxSizeX = 80;
int DefaultCharacterBoxSizeY = 120;
int SmallCharacterBoxSizeY = 60;
int CharacterBoxSizeY = DefaultCharacterBoxSizeY;
int CharacterBoxPosX = CharacterAPosX;
int DefaultCharacterBoxPosY = CharacterAPosY + 20;
int CharacterBoxPosY = DefaultCharacterBoxPosY;
//Sceen3House
int Sceen3HousePosX = SCREEN_WIDTH / 2;
int Sceen3HousePosY = 150;
int Sceen3HouseSizeX = 800;
int Sceen3HouseSizeY = 200;
//DebugTestTimer
int DebugTestTimer = 0;
//Gem
int GemPosX[GEMMAX];
int GemPosY[GEMMAX];
int GemSizeX[GEMMAX];
int GemSizeY[GEMMAX];
//ItemFeedback
int ItemFeedbackPosX[ITEMFEEDBACKMAX];
int ItemFeedbackPosY[ITEMFEEDBACKMAX];
int ItemFeedbackSizeX[ITEMFEEDBACKMAX];
int ItemFeedbackSizeY[ITEMFEEDBACKMAX];
bool TouchState[ITEMFEEDBACKMAX];
//Arrow
int ArrowPosX = 200;
int ArrowPosY = SCREEN_HEIGHT / 2;
int ArrowSizeX = 400;
int ArrowSizeY = 200;
int ArrowDispTimer = 0;
//过场特效BlackPic
int BlackPicPosX = -SCREEN_WIDTH / 2;
int BlackPicPosY = SCREEN_HEIGHT / 2;
int BlackPicSizeX = SCREEN_WIDTH;
int BlackPicSizeY = SCREEN_HEIGHT;
int BlackPicMoveSpeed = 20;
//Door
#define DOORMAX (100)
int DoorPosX[DOORMAX];
int DoorPosY[DOORMAX];
int DoorSizeX[DOORMAX];
int DoorSizeY[DOORMAX];
bool DoorCollisionState[DOORMAX];
//DoorAnimation
int DoorAnimationPosX[DOORMAX];
int DoorAnimationPosY[DOORMAX];
int DoorAnimationSizeX[DOORMAX];
int DoorAnimationSizeY[DOORMAX];
bool DoorAniState[DOORMAX];
int DoorAnimationTimer = 0;
//Key
int KeyPosX[KEYMAX];
int KeyPosY[KEYMAX];
int KeySizeX[KEYMAX];
int KeySizeY[KEYMAX];
//Translucent
int TranslucentPosX[KEYMAX];
int TranslucentPosY[KEYMAX];
int TranslucentSizeX[KEYMAX];
int TranslucentSizeY[KEYMAX];
//W
int WPosX = KeyPosX[0];
int WPosY = KeyPosY[0];
int WSizeX = 80;
int WSizeY = 80;
//A
int APosX = KeyPosX[1];
int APosY = KeyPosY[1];
int ASizeX = WSizeX;
int ASizeY = WSizeY;
//S
int SPosX = KeyPosX[2];
int SPosY = KeyPosY[2];
int SSizeX = WSizeX;
int SSizeY = WSizeY;
//D
int DPosX = KeyPosX[3];
int DPosY = KeyPosY[3];
int DSizeX = WSizeX;
int DSizeY = WSizeY;
//Space
int SpacePosX = KeyPosX[4];
int SpacePosY = KeyPosY[4];
int SpaceSizeX = KeySizeX[4];
int SpaceSizeY = WSizeY;

//Sceen4Stage1
//Sceen4Stage1Sky
int Sceen4Stage1SkyPosX = SCREEN_WIDTH / 2;
int Sceen4Stage1SkyPosY = SCREEN_HEIGHT / 2;
int Sceen4Stage1SkySizeX = SCREEN_WIDTH;
int Sceen4Stage1SkySizeY = SCREEN_HEIGHT;
//Sceen4Stage1Tile
int Sceen4Stage1TilePosX = SCREEN_WIDTH / 2;
int Sceen4Stage1TilePosY = SCREEN_HEIGHT / 2;
int Sceen4Stage1TileSizeX = SCREEN_WIDTH;
int Sceen4Stage1TileSizeY = SCREEN_HEIGHT;
//Cloud
int CloudPosX[CLOUDMAX];
int CloudPosY[CLOUDMAX];
int CloudSizeX[CLOUDMAX];
int CloudSizeY[CLOUDMAX];

//Sceen5Stage1_1
//Sceen5Tile
int Sceen5TilePosX = SCREEN_WIDTH / 2;
int Sceen5TilePosY = SCREEN_HEIGHT / 2;
int Sceen5TileSizeX = SCREEN_WIDTH;
int Sceen5TileSizeY = SCREEN_HEIGHT;
//Sceen5Arrow
int Sceen5ArrowPosX = -1000;
int Sceen5ArrowPosY = -1000;
int Sceen5ArrowSizeX = 80;
int Sceen5ArrowSizeY = 80;
//Spike
int SpikePosX[SPIKEMAX];
int SpikePosY[SPIKEMAX];
int SpikeSizeX[SPIKEMAX];
int SpikeSizeY[SPIKEMAX];
int SpikeTimer = 0;
int SpikeDefTime = 8;
int SpikeTime = SpikeDefTime;//每隔 帧 从第一根尖刺开始下落尖刺
int SpikeSpeed = 10;
int SpikeCnt = 0;
bool SpikeMoveState[SPIKEMAX];

//Sceen6Stage1_2
//Sceen6Tile
int Sceen6TilePosX = SCREEN_WIDTH / 2;
int Sceen6TilePosY = SCREEN_HEIGHT / 2;
int Sceen6TileSizeX = SCREEN_WIDTH;
int Sceen6TileSizeY = SCREEN_HEIGHT;
//Laser
int LaserDefPosX = -100;
int LaserPosX = LaserDefPosX;
int LaserPosY = SCREEN_HEIGHT / 2;
int LaserSizeX = 20;
int LaserSizeY = SCREEN_HEIGHT;
int LaserSpeed = 3;

//Sceen7Stage1_3
//Sceen7Tile
int Sceen7TilePosX = SCREEN_WIDTH / 2;
int Sceen7TilePosY = SCREEN_HEIGHT / 2;
int Sceen7TileSizeX = SCREEN_WIDTH;
int Sceen7TileSizeY = SCREEN_HEIGHT;
//Bullet
int BulletDefPosX = 1480;
int BulletPosX = 640;
int BulletPosY = 560;
int BulletSizeX = 80;
int BulletSizeY = 20;
int BulletSpeed = 10;

//Sceen8Stage2_1
//Sceen8Tile
int Sceen8TilePosX = SCREEN_WIDTH / 2;
int Sceen8TilePosY = SCREEN_HEIGHT / 2;
int Sceen8TileSizeX = SCREEN_WIDTH;
int Sceen8TileSizeY = SCREEN_HEIGHT;
//横板过关游戏的世界坐标的设定
int WorldMovePosX = 0;//一开始的时候为0


//Loading
int SaveSceenFlag = 0;
int LoadingTimer = 0;
int LoadingDisTime = 60;
//LoadingTitle
int LoadingTitlePosX = SCREEN_WIDTH / 2;
int LoadingTitlePosY = SCREEN_HEIGHT / 6;
int LoadingTitleSizeX = SCREEN_WIDTH - 400;
int LoadingTitleSizeY = SCREEN_HEIGHT / 4;
//Stage1Title
int Stage1TitlePosX = SCREEN_WIDTH / 2;
int Stage1TitlePosY = SCREEN_HEIGHT / 6;
int Stage1TitleSizeX = SCREEN_WIDTH - 400;
int Stage1TitleSizeY = SCREEN_HEIGHT / 4;
//Stage2Title
int Stage2TitlePosX = SCREEN_WIDTH / 2;
int Stage2TitlePosY = SCREEN_HEIGHT / 6;
int Stage2TitleSizeX = SCREEN_WIDTH - 400;
int Stage2TitleSizeY = SCREEN_HEIGHT / 4;
//LoadingIcon
int LoadingIconPosX = SCREEN_WIDTH / 2;
int LoadingIconPosY = 540;
int LoadingIconSizeX = 300;
int LoadingIconSizeY = 300;
//NowLoading
int NowLoadingPosX = SCREEN_WIDTH / 2;
int NowLoadingPosY = 960;
int NowLoadingSizeX = 600;
int NowLoadingSizeY = 100;

//Sceen81GameOver
bool GameOverButtonState = true;
int DeathTimer = 0;
int DeathTime = 60;
//GameOverTitle
int GameOverTitlePosX = SCREEN_WIDTH / 2;
int GameOverTitlePosY = 200;
int GameOverTitleSizeX = 1200;
int GameOverTitleSizeY = 300;
//RetryHighlight
int RetryHighlightPosX = Sceen2OnePlayerHighlightPosX;
int RetryHighlightPosY = Sceen2OnePlayerHighlightPosY;
int RetryHighlightSizeX = 720;
int RetryHighlightSizeY = 180;
//RetryLowlight
int RetryLowlightPosX = RetryHighlightPosX;
int RetryLowlightPosY = RetryHighlightPosY;
int RetryLowlightSizeX = 600;
int RetryLowlightSizeY = 150;
//StageSelectPlayerHighLight
int StageSelectHighlightPosX = Sceen2TwoPlayerHighlightPosX;
int StageSelectHighlightPosY = Sceen2TwoPlayerHighlightPosY;
int StageSelectHighlightSizeX = 720;
int StageSelectHighlightSizeY = 180;
//StageSelectLowlight
int StageSelectLowlightPosX = StageSelectHighlightPosX;
int StageSelectLowlightPosY = StageSelectHighlightPosY;
int StageSelectLowlightSizeX = 600;
int StageSelectLowlightSizeY = 150;
//Sceen81BgPic
int Sceen81BgPicPosX = SCREEN_WIDTH / 2;
int Sceen81BgPicPosY = SCREEN_HEIGHT / 2;
int Sceen81BgPicSizeX = SCREEN_WIDTH;
int Sceen81BgPicSizeY = SCREEN_HEIGHT;

//Sceen82StageClear
bool StageClearButtonState = true;
//Sceen82BgPic
int Sceen82BgPicPosX = SCREEN_WIDTH / 2;
int Sceen82BgPicPosY = SCREEN_HEIGHT / 2;
int Sceen82BgPicSizeX = SCREEN_WIDTH;
int Sceen82BgPicSizeY = SCREEN_HEIGHT;
//StageClearTitle
int StageClearTitlePosX = SCREEN_WIDTH / 2;
int StageClearTitlePosY = 200;
int StageClearTitleSizeX = 1200;
int StageClearTitleSizeY = 300;





//碰撞体相关
//与CharacterBox发生的碰撞
bool WallCollision[WALLMAX];
int WallPosX[WALLMAX];
int WallPosY[WALLMAX];
int WallSizeX[WALLMAX];
int WallSizeY[WALLMAX];
//与HeadBox发生的碰撞
bool RoofCollision[ROOFMAX];
int RoofPosX[ROOFMAX];
int RoofPosY[ROOFMAX];
int RoofSizeX[ROOFMAX];
int RoofSizeY[ROOFMAX];
//与GroundBox发生的碰撞
bool TileCollision[TILEMAX];
int TilePosX[TILEMAX];
int TilePosY[TILEMAX];
int TileSizeX[TILEMAX];
int TileSizeY[TILEMAX];
//攀爬藤蔓相关
bool VineCollision[VINE_MAX];
int VinePosX[VINE_MAX];
int VinePosY[VINE_MAX];
int VineSizeX[VINE_MAX];
int VineSizeY[VINE_MAX];
bool VineState = false;

//无敌时间
bool InvincibleState = false;



//Sound
//GameOverSceen
bool CurrentGameOverSoundState = false;
bool OldGameOverSoundState = false;
//StageClearSceen
bool CurrentStageClearSoundState = false;
bool OldStageClearSoundState = false;


//图片显示相关
//*****************************************************************************
// 多边形構造体定義
//*****************************************************************************
//typedef struct VERTEX_2D {
//	float X, Y, Z;		//顶点坐标
//	float rhw;
//	D3DCOLOR col;
//	float u, v;			//材质坐标
//}VERTEX_2D;

//构造体原型定义
//Sceen1TPTeam场景
//Sceen1TPTeam
VERTEX_2D Sceen1TPTeamVertex[4];

//Sceen2Title场景
//Sceen2BgPic
VERTEX_2D Sceen2BgPicVertex[4];
//Sceen2Sun
VERTEX_2D Sceen2SunVertex[4];
//Sceen2Seagull1
VERTEX_2D Sceen2Seagull1Vertex[4];
//Sceen2Seagull2
VERTEX_2D Sceen2Seagull2Vertex[4];
//Sceen2Title
VERTEX_2D Sceen2TitleVertex[4];
//Sceen2OnePlayerHighlight
VERTEX_2D Sceen2OnePlayerHighlightVertex[4];
//Sceen2OnePlayerLowlight
VERTEX_2D Sceen2OnePlayerLowlightVertex[4];
//Sceen2TwoPlayerHighlight
VERTEX_2D Sceen2TwoPlayerHighlightVertex[4];
//Sceen2TwoPlayerLowlight
VERTEX_2D Sceen2TwoPlayerLowlightVertex[4];
//Sceen2SelectArrow
VERTEX_2D Sceen2SelectArrowVertex[4];

//Sceen3Select
//Sceen3BgPic
VERTEX_2D Sceen3BgPicVertex[4];
//Sceen3SelectBox
VERTEX_2D Sceen3SelectBoxVertex[4];
//Sceen3Stage1
VERTEX_2D Sceen3Stage1Vertex[4];
//Sceen3Stage2
VERTEX_2D Sceen3Stage2Vertex[4];
//Sceen3Stage3
VERTEX_2D Sceen3Stage3Vertex[4];
//Sceen3Stage4
VERTEX_2D Sceen3Stage4Vertex[4];
//CharacterA
VERTEX_2D CharacterAVertex[4];
//Sceen3SelectTile
VERTEX_2D Sceen3SelectTileVertex[4];
//GroundBox
VERTEX_2D GroundBoxVertex[4];
//HeadBox
VERTEX_2D HeadBoxVertex[4];
//CharacterBox
VERTEX_2D CharacterBoxVertex[4];
//Sceen3House
VERTEX_2D Sceen3HouseVertex[4];
//Gem
VERTEX_2D GemVertex[GEMMAX][4];
//ItemFeedback
VERTEX_2D ItemFeedbackVertex[ITEMFEEDBACKMAX][4];
//Arrow
VERTEX_2D ArrowVertex[4];
//过场特效BlackPic
VERTEX_2D BlackPicVertex[4];
//Door
VERTEX_2D DoorVertex[DOORMAX][4];
//DoorAnimation
VERTEX_2D DoorAnimationVertex[DOORMAX][4];
//Key
VERTEX_2D KeyVertex[KEYMAX][4];
//Translucent
VERTEX_2D TranslucentVertex[KEYMAX][4];
//W
VERTEX_2D WVertex[4];
//A
VERTEX_2D AVertex[4];
//S
VERTEX_2D SVertex[4];
//D
VERTEX_2D DVertex[4];
//Space
VERTEX_2D SpaceVertex[4];

//Sceen4Stage1
//Sceen4Stage1Sky
VERTEX_2D Sceen4Stage1SkyVertex[4];
//Sceen4Stage1Tile
VERTEX_2D Sceen4Stage1TileVertex[4];
//Cloud
VERTEX_2D CloudVertex[CLOUDMAX][4];

//Sceen5Tile
VERTEX_2D Sceen5TileVertex[4];
//Sceen5Arrow
VERTEX_2D Sceen5ArrowVertex[4];
//Spike
VERTEX_2D SpikeVertex[SPIKEMAX][4];

//Sceen6Tile
VERTEX_2D Sceen6TileVertex[4];
//Laser
VERTEX_2D LaserVertex[4];

//Sceen7
//Sceen7Tile
VERTEX_2D Sceen7TileVertex[4];
//Bullet
VERTEX_2D BulletVertex[4];

//Sceen8
//Sceen8Tile
VERTEX_2D Sceen8TileVertex[4];


//Loading
//LoadingTitle
VERTEX_2D LoadingTitleVertex[4];
//Stage1Title
VERTEX_2D Stage1TitleVertex[4];
//Stage2Title
VERTEX_2D Stage2TitleVertex[4];
//LoadingIcon
VERTEX_2D LoadingIconVertex[4];
//Nowloading
VERTEX_2D NowLoadingVertex[4];

//Sceen81GameOverTitle
VERTEX_2D GameOverTitleVertex[4];
//RetryHighlight
VERTEX_2D RetryHighlightVertex[4];
//RetryLowlight
VERTEX_2D RetryLowlightVertex[4];
//StageSelectHighlight
VERTEX_2D StageSelectHighlightVertex[4];
//StageSelectLowlight
VERTEX_2D StageSelectLowlightVertex[4];
//Sceen81BgPic
VERTEX_2D Sceen81BgPicVertex[4];

//Sceen82StageClear
//Sceen82BgPic
VERTEX_2D Sceen82BgPicVertex[4];
//StageClearTitle
VERTEX_2D StageClearTitleVertex[4];


//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);		//窗口程序相关处理
HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);							//初始化
void Uninit(void);																	//后处理
void Update(void);																	//更新处理																//背景移动
//场景管理
void SceenManagement();																//场景管理
void Sceen1TPTeamDraw();															//场景1 TP Team场景
void Sceen2TitleDraw();																//场景2 Title场景
void Sceen3SelectDraw();															//场景3 Select场景
void Sceen4Stage1Draw();															//场景4 Stage1场景
void Sceen5Stage1_1Draw();
void Sceen6Stage1_2Draw();
void Sceen7Stage1_3Draw();
void Sceen8Stage2_1Draw();
//void Sceen9Stage1_5Draw();
//void Sceen10Stage1_6Draw();
//void Sceen11Stage1_7Draw();

void LoadingSceenDraw();															//Loading场景 SceenFlag = 80
void Sceen81GameOverDraw();
void InitData();//用于初始化左右数据
void Sceen82StageClearDraw();

//*****************************************************************************
// DirectX设备相关
//*****************************************************************************
LPDIRECT3D9			g_pD3D = NULL;			// Direct3Dオブジェクト
LPDIRECT3DDEVICE9	g_pD3DDevice = NULL;	// Deviceオブジェクト(描画に必要)
LPDIRECT3DTEXTURE9  g_pD3DTexture[100];		// Direct3D材质

//=============================================================================
// メイン関数
//  (WINAPI : Win32API関数を呼び出す時の規約)
//  hInstance     : このアプリケーションのインスタンスハンドル(識別子)			//程序的初始化处理
//  hPrevInstance : 常にNULL(16bit時代の名残り)									//预初始化处理
//  lpCmdLine     : コマンドラインから受け取った引数へのポインタ				//从命令行过来的指针
//  nCmdShow      : アプリケーションの初期ウインドウ表示方法の指定				//指定了应用的初期窗口的表示方式
//=============================================================================
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wcex =
	{
		sizeof(WNDCLASSEX),				// WNDCLASSEXのメモリサイズを指定										//指定内存大小
		CS_CLASSDC,						// 表示するウインドウのスタイルを設定									//表示窗口的风格
		WndProc,						// ウィンドウプロシージャのアドレス(関数名)を指定						//指定窗口程序的地址
		0,								// 通常は使用しないので"0"を指定
		0,								// 通常は使用しないので"0"を指定
		hInstance,						// WinMainのパラメータのインスタンスハンドルを設定						//WinMain参数的初始化设定
		NULL,							// 使用するアイコンを指定(Windowsがもっているアイコンを使うならNULL)	//使用的图标，如果没有的话，就是空的
		LoadCursor(NULL, IDC_ARROW),	// マウスカーソルを指定													//鼠标光标的指定
		(HBRUSH)(COLOR_WINDOW + 1),		// ウインドウのクライアント領域の背景色を設定							//窗口客户领域的背景颜色的设定
		NULL,							// Windowにつけるメニューを設定											//窗口相关的菜单设置
		CLASS_NAME,						// ウインドウクラスの名前												//窗口class的名字
		NULL							// 小さいアイコンが設定された場合の情報を記述							//设定小图标时候的情报
	};
	//HWND hWnd;
	MSG msg;
	//FPS管理用变数
	DWORD dwExecLastTime;
	DWORD dwCurrentTime;
	DWORD dwFrameCount;
	// ウィンドウクラスの登録														//窗口类的登录
	RegisterClassEx(&wcex);															//寄存器Class
	// ウィンドウの作成//生成窗口
	hWnd = CreateWindowEx(0,	// 拡張ウィンドウスタイル							//扩张窗口风格
		CLASS_NAME,				// ウィンドウクラスの名前							//窗口类的名字
		WINDOW_NAME,			// ウィンドウの名前									//窗口的名字
		WS_OVERLAPPEDWINDOW,	// ウィンドウスタイル								//窗口的风格为重叠
		CW_USEDEFAULT,			// ウィンドウの左上Ｘ座標							//窗口的左上X坐标
		CW_USEDEFAULT,			// ウィンドウの左上Ｙ座標							//窗口右上的Y坐标
		(SCREEN_WIDTH + GetSystemMetrics(SM_CXDLGFRAME) * 2), // ウィンドウの幅		//窗口的横向
		(SCREEN_HEIGHT + GetSystemMetrics(SM_CXDLGFRAME) * 2 +
			GetSystemMetrics(SM_CYCAPTION)), // ウィンドウの高さ					//窗口的纵向
		NULL,					// 親ウィンドウのハンドル							//父窗口的处理
		NULL,					// メニューハンドルまたは子ウィンドウID				//菜单窗口的处理，或者是子窗口的ID
		hInstance,				// インスタンスハンドル								//初始化
		NULL);					// ウィンドウ作成データ								//窗口生成的数据
	// 初期化処理(ウィンドウを作成してから行う)										//初始化处理，生成了窗口
	if (FAILED(Init(hInstance, hWnd, TRUE)))
	{
		return -1;
	}
	// ウインドウの表示(初期化処理の後に行う)										//窗口的表示
	ShowWindow(hWnd, nCmdShow);														//显示窗口
	UpdateWindow(hWnd);																//更新窗口
	//FPS帧率的初期化
	timeBeginPeriod(1);																//为了把系统时间分解为1ms
	dwExecLastTime = timeGetTime();													//取得系统时间
	dwCurrentTime = dwFrameCount = 0;

	// メッセージループ																//信息循环
	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0)	// メッセージを取得しなかった場合"0"を返す
		{// Windowsの処理															//窗口处理
			if (msg.message == WM_QUIT)												//如果信息= 退出
			{// PostQuitMessage()が呼ばれて、WM_QUITメッセージが来たらループ終了	//退出信息来的时候循环终了
				break;
			}
			else
			{
				// メッセージの翻訳と送出
				TranslateMessage(&msg);												//传送信息
				DispatchMessage(&msg);												//调度信息
			}
		}
		else
		{// DirectXの処理
			dwCurrentTime = timeGetTime();
			if ((dwCurrentTime - dwExecLastTime) >= (1000.0f / FPS))
			{
				g_dispFPS = (1000.0f / (dwCurrentTime - dwExecLastTime));
				dwExecLastTime = dwCurrentTime;
				// 更新処理															//目前需要关注的重点，游戏相关的所有东西都在这里描述
				Update();															//负责用户输入相关的更新
			}
		}
	}
	// ウィンドウクラスの登録を解除													//窗口类的登录和解除
	//  第１引数：メクラス名														//MainClass？
	//  第２引数：アプリケーションインスタンスのハンドル							//应用的初始化处理
	UnregisterClass(CLASS_NAME, wcex.hInstance);									//非寄存器类 类名
	// 終了処理
	Uninit();
	return (int)msg.wParam;
}

//=============================================================================
// ウインドウプロシージャ															//窗口程序
//=============================================================================
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	int nID;																		//定义了一个ID

	switch (uMsg)																	//UserMessage
	{
	case WM_DESTROY:
		PostQuitMessage(0);															//退出信息
		break;

	case WM_KEYDOWN:																//按下按键
		switch (wParam)
		{
		case VK_ESCAPE:																//Esc按键
			nID = MessageBox(hWnd, "終了しますか？", "終了", MB_YESNO);				//是否关闭程序
			if (nID == IDYES)
			{
				DestroyWindow(hWnd);												//消除窗口
			}
			break;
		}
		break;
	case WM_CLOSE:
		nID = MessageBox(hWnd, "終了しますか？", "終了", MB_YESNO);
		if (nID = IDYES)
		{
			DestroyWindow(hWnd);
		}
		else
		{
			return 0;
		}
		break;
	default:																		//默认跳出该switch
		break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);								//回到默认的窗口更新程序
}

//=============================================================================
// 初期化処理
// hInstance : インスタンスのハンドル												//初始化处理
// hWnd      : ウインドウのハンドル													//窗口处理
// bWindow   : ウインドウモードにするかどうか										//是否 窗口模式
//=============================================================================
HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	D3DPRESENT_PARAMETERS d3dpp;													//当前 参数
	D3DDISPLAYMODE d3ddm;															//显示模式
	// Direct3Dオブジェクトの生成
	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (g_pD3D == NULL)
	{
		return E_FAIL;
	}
	// 現在のディスプレイモードを取得												//取得现在的显示器模式
	if (FAILED(g_pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm)))			//适配器显示模式 适配器默认
	{
		return E_FAIL;
	}
	// デバイスのプレゼンテーションパラメータの設定									//设备的介绍参数
	ZeroMemory(&d3dpp, sizeof(d3dpp));			// ワークをゼロクリア				//工作的零清零
	d3dpp.BackBufferWidth = SCREEN_WIDTH;		// ゲーム画面サイズ(幅)
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;		// ゲーム画面サイズ(高さ)
	d3dpp.BackBufferFormat = d3ddm.Format;		// カラーモードの指定				//颜色模式指定
	d3dpp.BackBufferCount = 1;					// バックバッファの数				//Back缓存的数量
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;	// 映像信号に同期してフリップする	//图像信号的切换 切换特效 丢失
	d3dpp.Windowed = bWindow;					// ウィンドウモード					//窗口模式
	d3dpp.EnableAutoDepthStencil = TRUE;		// デプスバッファ(Ｚバッファ)とステンシルバッファを作成//打开自动的深度模板
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;	// デプスバッファとして16bitを使う	//自动深度模板格式

	if (bWindow)
	{// ウィンドウモード															//窗口模式
		d3dpp.FullScreen_RefreshRateInHz = 0;										// リフレッシュレート(指定できないので0固定)
		d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;					//介绍  间隔
		// インターバル(VSyncを待たずに描画)										//间隔
	}
	else
	{// フルスクリーンモード														//全屏幕模式
		d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
		// リフレッシュレート(現在の速度に合わせる)									//刷新率
		d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;
		// インターバル(VSyncを待って描画)											//间隔
	}

	// デバイスオブジェクトの生成													//设备目标生成
	// [デバイス作成制御]<描画>と<頂点処理>をハードウェアで行なう
	if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT,	// ディスプレイアダプタ		//显示器适配器
		D3DDEVTYPE_HAL,									// デバイスタイプ			//设备类型
		hWnd,											// フォーカスするウインドウへのハンドル
		D3DCREATE_HARDWARE_VERTEXPROCESSING,			// デバイス作成制御の組み合わせ		//创造硬件顶点处理
		&d3dpp,											// デバイスのプレゼンテーションパラメータ//设备的介绍参数
		&g_pD3DDevice)))								// デバイスインターフェースへのポインタ//设备接口的指针
	{
		// 上記の設定が失敗したら													//如果上面的设定失败了的话
		// [デバイス作成制御]<描画>をハードウェアで行い、<頂点処理>はCPUで行なう
		if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL,															//设备类型
			hWnd,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING,									//创造软件顶点处理
			&d3dpp,																	//设备的介绍参数
			&g_pD3DDevice)))
		{
			// 上記の設定が失敗したら
			// [デバイス作成制御]<描画>と<頂点処理>をCPUで行なう
			if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
				D3DDEVTYPE_REF,//设备类型
				hWnd,
				D3DCREATE_SOFTWARE_VERTEXPROCESSING,
				&d3dpp,
				&g_pD3DDevice)))
			{
				// 初期化失敗
				return E_FAIL;
			}
		}
	}

	//=============================================================================
	// Texture初期化
	//=============================================================================
	//Sceen1中的Texuture
	//Texture【1】Sceen1TPTeam
	InitTexture1();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen1/Sceen1TPTeam.tga", &g_pD3DTexture[1]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Sceen2中的Texuture
	//Texture【2】Sceen2Title
	InitTexture2();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen2/Sceen2Title.tga", &g_pD3DTexture[2]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【3】Sceen2OnePlayerHighlight
	InitTexture3();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen2/OnePlayerHighlight.tga", &g_pD3DTexture[3]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【4】Sceen2OnePlayerLowlight
	InitTexture4();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen2/OnePlayerLowlight.tga", &g_pD3DTexture[4]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【5】Sceen2TwoPlayerHighlight
	InitTexture5();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen2/TwoPlayerHighlight.tga", &g_pD3DTexture[5]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【6】Sceen2TwoPlayerLowlight
	InitTexture6();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen2/TwoPlayerLowlight.tga", &g_pD3DTexture[6]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【7】Sceen2Arrow
	InitTexture7();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen2/Sceen2SelectArrow.tga", &g_pD3DTexture[7]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【8】Sceen2BgPic
	InitTexture8();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen2/Sceen2BgPic.tga", &g_pD3DTexture[8]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【9】Sceen2Sun
	InitTexture9();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen2/Sceen2Sun.tga", &g_pD3DTexture[9]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【10】Sceen2Seagull1
	InitTexture10();
	Sceen2Seagull1Vertex[3].v = 1.0f;
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen2/Sceen2Seagull1.tga", &g_pD3DTexture[10]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【11】Sceen2Seagull2
	InitTexture11();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen2/Sceen2Seagull2.tga", &g_pD3DTexture[11]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Sceen3Select场景
	//Texture【12】Sceen3BgPic
	InitTexture12();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen3/Sceen3BgPic.tga", &g_pD3DTexture[12]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Sceen3Select场景
	//Texture【13】Sceen3SelectBox
	InitTexture13();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen3/Sceen3SelectBox.tga", &g_pD3DTexture[13]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【14】Wall
	InitTexture14();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen3/Sceen3Stage1.tga", &g_pD3DTexture[14]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【15】Sceen3Stage2
	InitTexture15();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen3/Sceen3Stage2.tga", &g_pD3DTexture[15]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【16】Sceen3Stage3
	InitTexture16();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen3/Sceen3Stage3.tga", &g_pD3DTexture[16]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【17】Sceen3Stage4
	InitTexture17();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen3/Sceen3Stage4.tga", &g_pD3DTexture[17]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【18】CharacterA
	InitTexture18();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Character/CharacterA.tga", &g_pD3DTexture[18]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【19】Sceen3SelectTile
	InitTexture19();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen3/Sceen3SelectTile.tga", &g_pD3DTexture[19]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【20】GroundBox
	InitTexture20();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Character/GroundBox.tga", &g_pD3DTexture[20]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}

	//Texture【21】Sceen3House
	InitTexture21();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen3/StageSelect.tga", &g_pD3DTexture[21]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【22】Gem
	InitTexture22();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen3/Gem.tga", &g_pD3DTexture[22]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【23】ItemFeedback
	InitTexture23();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen3/ItemFeedback2.tga", &g_pD3DTexture[23]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【24】Arrow
	InitTexture24();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen3/Arrow.tga", &g_pD3DTexture[24]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【25】BlackPic
	InitTexture25();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen3/BlackPic.tga", &g_pD3DTexture[25]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【26】Sceen4Stage1Sky
	InitTexture26();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen4/Sceen4Stage1Sky.tga", &g_pD3DTexture[26]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【27】Sceen4Stage1Tile
	InitTexture27();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen4/Sceen4Stage1Tile.tga", &g_pD3DTexture[27]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【28】CharacterBox
	InitTexture28();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Character/GroundBox.tga", &g_pD3DTexture[28]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【29】Door
	InitTexture29();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen3/Door.tga", &g_pD3DTexture[29]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【30】DoorAnimation
	for (int i = 0; i < DOORMAX; i++)
	{
		DoorAniState[i]= false;
	}
	InitTexture30();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen3/DoorAnimation.tga", &g_pD3DTexture[30]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【31】Key
	//数组初始化
	for (int i = 0; i < KEYMAX; i++)
	{

	}
	InitTexture31();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen3/Key.tga", &g_pD3DTexture[31]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}

	//Texture【32】Translucent
		//数组初始化
	for (int i = 0; i < KEYMAX; i++)
	{

	}
	InitTexture32();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen3/Translucent.tga", &g_pD3DTexture[32]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【33】W
	InitTexture33();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen3/W.tga", &g_pD3DTexture[33]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【34】A
	InitTexture34();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen3/A.tga", &g_pD3DTexture[34]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【35】S
	InitTexture35();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen3/S.tga", &g_pD3DTexture[35]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【36】D
	InitTexture36();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen3/D.tga", &g_pD3DTexture[36]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【37】Space
	InitTexture37();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen3/Space.tga", &g_pD3DTexture[37]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【38】LoadingTitle
	InitTexture38();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Loading/LoadingTitle.tga", &g_pD3DTexture[38]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【39】Stage1Title
	InitTexture39();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Loading/Stage1Title.tga", &g_pD3DTexture[39]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【40】TwiceJump
	InitTexture40();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Character/TwiceJump.tga", &g_pD3DTexture[40]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【41】Cloud
	InitTexture41();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen4/Cloud.tga", &g_pD3DTexture[41]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【42】Nowloading
	InitTexture42();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Loading/NowLoading.tga", &g_pD3DTexture[42]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【43】GameOverTitle
	InitTexture43();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen81/GameOverTitle.tga", &g_pD3DTexture[43]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【44】RetryHighlight
	InitTexture44();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen81/RetryHighlight.tga", &g_pD3DTexture[44]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【45】RetryLowlight
	InitTexture45();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen81/RetryLowlight.tga", &g_pD3DTexture[45]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【46】StageSelectHighlight
	InitTexture46();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen81/StageSelectHighlight.tga", &g_pD3DTexture[46]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【47】StageSelectLowlight
	InitTexture47();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen81/StageSelectLowlight.tga", &g_pD3DTexture[47]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【48】Sceen81BgPic
	InitTexture48();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen81/Sceen81BgPic.tga", &g_pD3DTexture[48]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【49】LoadingIcon
	InitTexture49();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Loading/LoadingIcon.tga", &g_pD3DTexture[49]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}

	//Texture【50】Sceen5Tile
	InitTexture50();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen5/Sceen5Tile.tga", &g_pD3DTexture[50]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}

	//Texture【51】Sceen5Arrow
	InitTexture51();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen5/Sceen5Arrow.tga", &g_pD3DTexture[51]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}

	//Texture【52】Spike
	InitTexture52();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen5/Spike.tga", &g_pD3DTexture[52]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Spike初始位置设定
	for (int i = 0; i < 22; i++)
	{
		SpikeMoveState[i] = false;//初始化状态
		SpikePosX[i] = 120 + 80 * i;
		SpikePosY[i] = 200;
		//顶点位置更新
		SpikeVertex[i][0].X = SpikePosX[i] - SpikeSizeX[i] / 2;
		SpikeVertex[i][0].Y = SpikePosY[i] - SpikeSizeY[i] / 2;
		SpikeVertex[i][1].X = SpikePosX[i] + SpikeSizeX[i] / 2;
		SpikeVertex[i][1].Y = SpikePosY[i] - SpikeSizeY[i] / 2;
		SpikeVertex[i][2].X = SpikePosX[i] - SpikeSizeX[i] / 2;
		SpikeVertex[i][2].Y = SpikePosY[i] + SpikeSizeY[i] / 2;
		SpikeVertex[i][3].X = SpikePosX[i] + SpikeSizeX[i] / 2;
		SpikeVertex[i][3].Y = SpikePosY[i] + SpikeSizeY[i] / 2;
	}

	//Texture【53】Sceen6Tile
	InitTexture53();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen6/Sceen6Tile.tga", &g_pD3DTexture[53]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}

	//Texture【54】Laser
	InitTexture54();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen6/Laser.tga", &g_pD3DTexture[54]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}

	//Texture【55】Sceen7Tile
	InitTexture55();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen7/Sceen7Tile.tga", &g_pD3DTexture[55]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}

	//Texture【56】Bullet
	InitTexture56();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen7/Bullet.tga", &g_pD3DTexture[56]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}

	//Texture【57】Sceen82BgPic
	InitTexture57();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen82/Sceen82BgPic.tga", &g_pD3DTexture[57]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【58】StageClearTitle
	InitTexture58();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen82/StageClearTitle.tga", &g_pD3DTexture[58]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}
	//Texture【59】HeadBox
	InitTexture59();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Character/GroundBox.tga", &g_pD3DTexture[59]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}

	//Texture【60】Sceen8Tile
	InitTexture60();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Sceen8/Sceen8Tile.tga", &g_pD3DTexture[60]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}

	//对于藤蔓碰撞进行初始化
	for (int i = 0; i < VINE_MAX; i++)
	{
		VineCollision[i] = false;
	}

	//Texture【61】Stage2Title
	InitTexture61();
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, "data/Texture/Loading/Stage2Title.tga", &g_pD3DTexture[61]))) {
		MessageBox(hWnd, "TextureLoad", "ReadFailed", MB_ICONWARNING);
	}

	//Input初始化
	InitInput(hInstance,hWnd);
	//Sound初始化
	InitSound();

	return S_OK;
}
void InitData()
{
	//初始化材质
	InitTexture1();
	InitTexture2();
	InitTexture3();
	InitTexture4();
	InitTexture5();
	InitTexture6();
	InitTexture7();
	InitTexture8();
	InitTexture9();
	InitTexture10();
	InitTexture11();
	InitTexture12();
	InitTexture13();
	InitTexture14();
	InitTexture15();
	InitTexture16();
	InitTexture17();
	InitTexture18();
	InitTexture19();
	InitTexture20();
	InitTexture21();
	InitTexture22();
	InitTexture23();
	InitTexture24();
	InitTexture25();
	InitTexture26();
	InitTexture27();
	InitTexture28();
	InitTexture29();
	InitTexture30();
	InitTexture31();
	InitTexture32();
	InitTexture33();
	InitTexture34();
	InitTexture35();
	InitTexture36();
	InitTexture37();
	InitTexture38();
	InitTexture39();
	InitTexture40();
	InitTexture41();
	InitTexture42();
	InitTexture43();
	InitTexture44();
	InitTexture45();
	InitTexture46();
	InitTexture47();
	InitTexture48();
	InitTexture49();
	InitTexture50();
	InitTexture51();
	InitTexture52();
	InitTexture53();
	InitTexture54();
	InitTexture55();
	InitTexture56();
	InitTexture57();
	InitTexture58();
	InitTexture59();
	InitTexture60();
	InitTexture61();
	//对于藤蔓碰撞进行初始化
	for (int i = 0; i < VINE_MAX; i++)
	{
		VineCollision[i] = false;
	}
	//初始化玩家位置和朝向
	CharacterAPosX = CharacterADefPosX;
	CharacterAPosY = CharacterADefPosY;
	GroundBoxPosX = CharacterAPosX;
	GroundBoxPosY = CharacterAPosY + CharacterASizeY / 2 - GroundBoxSizeY / 2 + 10;//Box要比玩家稍微下一点点
	CharacterBoxPosX = CharacterAPosX;
	CharacterBoxPosY = DefaultCharacterBoxPosY;//Box要比玩家稍微下一点点;
	LookAtState = true;
	JumpPosState = false;
	CharacterAMoveState = true;
	AnimationState = 1;//Idle
	//初始化Timer和Cnt
	DoorAnimationTimer = 0;
	SpikeTime = SpikeDefTime;//每隔8帧 从第一根尖刺开始下落尖刺
	SpikeCnt = 0;
	DeathTimer = 0;
	//相关状态
	GameOverButtonState = true;
	GroundState = false;
	JumpUpState = false;
	DeathState = false;//玩家复活
	//限制行动相关
	RightMoveState = true;
	LeftMoveState = true;
	UpMoveState = true;
	//碰撞相关初始化
	LaserPosX = LaserDefPosX;
	BulletPosX = BulletDefPosX;
	//WallCollision初始化
	for (int i = 0; i < WALLMAX; i++)
	{
		WallCollision[i] = false;
	}
	//RoofCollision初始化
	for (int i = 0; i < ROOFMAX; i++)
	{
		RoofCollision[i] = false;
	}
	//Spike初始位置设定
	for (int i = 0; i < 22; i++)
	{
		SpikeMoveState[i] = false;//初始化状态
		SpikePosX[i] = 120 + 80 * i;
		SpikePosY[i] = 200;
		//顶点位置更新
		SpikeVertex[i][0].X = SpikePosX[i] - SpikeSizeX[i] / 2;
		SpikeVertex[i][0].Y = SpikePosY[i] - SpikeSizeY[i] / 2;
		SpikeVertex[i][1].X = SpikePosX[i] + SpikeSizeX[i] / 2;
		SpikeVertex[i][1].Y = SpikePosY[i] - SpikeSizeY[i] / 2;
		SpikeVertex[i][2].X = SpikePosX[i] - SpikeSizeX[i] / 2;
		SpikeVertex[i][2].Y = SpikePosY[i] + SpikeSizeY[i] / 2;
		SpikeVertex[i][3].X = SpikePosX[i] + SpikeSizeX[i] / 2;
		SpikeVertex[i][3].Y = SpikePosY[i] + SpikeSizeY[i] / 2;
	}
	//Sound
	CurrentGameOverSoundState = false;
	OldGameOverSoundState = CurrentGameOverSoundState;
	CurrentStageClearSoundState = false;
	OldStageClearSoundState = CurrentStageClearSoundState;
	StopSound(SOUND_LABEL_BGM000);//BGM000
	StopSound(SOUND_LABEL_BGM001);//BGM001
	//不无敌
	InvincibleState = false;
}

//=============================================================================
// 終了処理
//=============================================================================
void Uninit(void)
{
	if (g_pD3DDevice != NULL)
	{// デバイスの開放
		g_pD3DDevice->Release();//释放设备
		g_pD3DDevice = NULL;
	}
	if (g_pD3D != NULL)
	{// Direct3Dオブジェクトの開放//释放目标
		g_pD3D->Release();
		g_pD3D = NULL;
	}
	//材质使用完之后，要对材质进行释放
	if (g_pD3DTexture[0] != NULL)
	{
		g_pD3DTexture[0]->Release();
	}
	if (g_pD3DTexture[1] != NULL)
	{
		g_pD3DTexture[1]->Release();
	}
	if (g_pD3DTexture[2] != NULL)
	{
		g_pD3DTexture[2]->Release();
	}

	//Input终了处理
	UninitInput();
	//Sound终了处理
	UninitSound();
}
//=============================================================================
// 更新処理
//=============================================================================
void Update(void)
{
	//场景管理
	SceenManagement();
	//Input更新
	UpdateInput();
	//重力相关影响
	Gravity();
	//碰撞相关
	Collision();
	//AnimationManagement
	AnimationManagement();
}
//=============================================================================
// 场景管理
//=============================================================================
void SceenManagement()
{
	switch (SceenFlag) 
	{
		case 1:
			Sceen1TPTeamDraw();
			break;
		case 2:			
			Sceen2TitleDraw();
			break;
		case 3:
			Sceen3SelectDraw();
			break;
		case 4:
			Sceen4Stage1Draw();
			break;
		case 5:
			Sceen5Stage1_1Draw();
			break;
		case 6:
			Sceen6Stage1_2Draw();
			break;
		case 7:
			Sceen7Stage1_3Draw();
			break;
		case 8:
			Sceen8Stage2_1Draw();
			break;
		//case 9:
		//	Sceen9Stage1_5Draw();
		//	break;
		//case 10:
		//	Sceen10Stage1_6Draw();
		//	break;
		//case 11:
		//	Sceen11Stage1_7Draw();
		//	break;
		case 80:
			LoadingSceenDraw();
			break;
		case 81:
			Sceen81GameOverDraw();
			break;
		case 82:
			Sceen82StageClearDraw();
			break;
		default:
			break;
	}
	if (SceenFlag == 1)
	{
		Sceen1Timer++;
		if (Sceen1Timer >= Sceen1DisplayTime)
		{
			//开始播放Title界面的音乐
			PlaySound(SOUND_LABEL_BGM000);//BGM000
			SceenFlag = 2;
			Sceen1Timer = 0;
		}
	}
	if (SceenFlag == 2)//Title场景
	{
		//GameOver
		if (ButtonState == true && GetKeyboardTrigger(DIK_RETURN))
		{
			//停止Title界面的音乐
			StopSound(SOUND_LABEL_BGM000);//BGM000
			//开始游戏中的音乐
			PlaySound(SOUND_LABEL_BGM002);//BGM002
			SceenFlag = 3;
			//初始化玩家位置
			CharacterAPosX = CharacterADefPosX;
			CharacterAPosY = CharacterADefPosY;
		}
		//GameExit
		if (ButtonState == false && GetKeyboardTrigger(DIK_RETURN))
		{
			DestroyWindow(hWnd);												//消除窗口
		}
	}

	if (SceenFlag == 81)//GameOver场景
	{
		//Retry
		if (GameOverButtonState == true && GetKeyboardTrigger(DIK_RETURN))
		{
			DeathState = false;//玩家复活
			//根据不同的情况选择不同的关卡
			SceenFlag = 80;//LoadingSceen
			//初始化所有相关数据
			InitData();
			//播放游戏中的音乐
			PlaySound(SOUND_LABEL_BGM002);//BGM002 Game BGM
		}
		//StageSelect
		if (GameOverButtonState == false && GetKeyboardTrigger(DIK_RETURN))
		{
			DeathState = false;//玩家复活
			SceenFlag = 3;//回到选择关卡界面
			//初始化所有相关数据
			InitData();
			//播放游戏中的音乐
			PlaySound(SOUND_LABEL_BGM002);//BGM002 Game BGM
		}
	}
	if (SceenFlag == 82)//StageClear场景
	{
		//StageSelect
		if (StageClearButtonState == true && GetKeyboardTrigger(DIK_RETURN))
		{
			
			DeathState = false;//玩家复活
			SaveSceenMessage = 3;
			SceenFlag = SaveSceenMessage;//回到选择关卡界面
			//初始化所有相关数据
			InitData();
			//StopStageClear的音乐
			StopSound(SOUND_LABEL_BGM003);//BGM003 StageClear
			//播放游戏中的音乐
			PlaySound(SOUND_LABEL_BGM002);//BGM002 Game BGM
		}
		//Exit
		if (StageClearButtonState == false && GetKeyboardTrigger(DIK_RETURN))
		{
			DestroyWindow(hWnd);												//消除窗口
		}
	}

	//当玩家死亡的时候跳转到GameOver场景
	if (DeathState == true)
	{
		//只播放一遍Se
		CurrentGameOverSoundState = true;
		if (OldGameOverSoundState != CurrentGameOverSoundState)
		{
			//播放死亡se
			PlaySound(SOUND_LABEL_SE002);//SE GameOver
			//停止游戏中的音乐
			StopSound(SOUND_LABEL_BGM002);//BGM002
			//播放GameOver的音乐
			PlaySound(SOUND_LABEL_BGM001);//BGM001
			OldGameOverSoundState = CurrentGameOverSoundState;
		}
		//播放死亡动画 玩家Animation为受伤 向上移动一下向下坠落
		//Animation
		AnimationState = 5;		
		CharacterAMoveState = false;
		//Move
		DeathTimer++;
		if (DeathTimer < DeathTime/4)
		{
			CharacterAPosY -= 10;
			//UpdateVertex
			CharacterAVertex[0].Y =CharacterAPosY - CharacterASizeY / 2;
			CharacterAVertex[1].Y =CharacterAPosY - CharacterASizeY / 2;
			CharacterAVertex[2].Y =CharacterAPosY + CharacterASizeY / 2;
			CharacterAVertex[3].Y =CharacterAPosY + CharacterASizeY / 2;
		}
		else if (DeathTimer > DeathTime / 4 && DeathTimer < DeathTime / 2)
		{
			CharacterAPosY += 10;
			//UpdateVertex
			CharacterAVertex[0].Y = CharacterAPosY - CharacterASizeY / 2;
			CharacterAVertex[1].Y = CharacterAPosY - CharacterASizeY / 2;
			CharacterAVertex[2].Y = CharacterAPosY + CharacterASizeY / 2;
			CharacterAVertex[3].Y = CharacterAPosY + CharacterASizeY / 2;
		}
		if (DeathTimer > DeathTime)
		{
			//进入GameOver场景
			SceenFlag = 81;//Sceen81GameOver
		}	
		
	}
}

//Sceen1TPTeam
void Sceen1TPTeamDraw()
{
	// バックバッファ＆Ｚバッファのクリア
	// Count   : pRects配列にある矩形の数
	// pRects  : クリアする矩形の配列(NULL指定でビューポート矩形全体をクリア)
	// Flags   : クリアするサーフェスを示すフラグ(少なくとも１つを使用しなければならない)
	//         : [D3DCLEAR_TARGET - レンダリングターゲットをクリアしてColorパラメータの値にする]
	//         : [D3DCLEAR_ZBUFFER - 深度(Ｚ)バッファをクリアしてZパラメータの値にする]
	//         : [D3DCLEAR_STENCIL - ステンシルバッファをクリアしてStencilパラメータの値にする]
	// Color   : サーフェスをクリアする色
	// Z       : デプスバッファに保存する値
	// Stencil : ステンシルバッファに保存する値(整数)
	g_pD3DDevice->Clear(0, NULL, (D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER),
		D3DCOLOR_RGBA(0, 0, 0, 0), 1.0f, 0);
	// Direct3Dによる描画の開始
	if (SUCCEEDED(g_pD3DDevice->BeginScene()))
	{
		//具体的な描画処理をココに記述していく
		g_pD3DDevice->SetFVF(FVF_VERTEX_2D);
		//从这里开始描画

		//Texture[1] Sceen1BgPic
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[1]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen1TPTeamVertex, sizeof(VERTEX_2D));

		//从这里结束描画
		g_pD3DDevice->EndScene();
	}
	// バックバッファとフロントバッファの入れ替え
	// pSourceRect         : 転送元矩形
	// pDestRect           : 転送先矩形
	// hDestWindowOverride : 転送先ウインドウへのポインタ
	// pDirtyRegion        : 通常はNULLで
	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

//Sceen2Title
void Sceen2TitleDraw()
{

	g_pD3DDevice->Clear(0, NULL, (D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER),
		D3DCOLOR_RGBA(0, 0, 0, 0), 1.0f, 0);
	// Direct3Dによる描画の開始
	if (SUCCEEDED(g_pD3DDevice->BeginScene()))
	{
		//具体的な描画処理をココに記述していく
		g_pD3DDevice->SetFVF(FVF_VERTEX_2D);
		//从这里开始描画

		//Texture[8] Sceen2BgPic
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[8]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen2BgPicVertex, sizeof(VERTEX_2D));
		//Texture[9] Sceen2Sun
		//太阳的闪烁
		SunTimer++;
		if (0 < SunTimer && SunTimer <= 40)
		{
			Sceen2SunVertex[0].u = 0.0f;
			Sceen2SunVertex[0].v = 0.0f;
			Sceen2SunVertex[1].u = 0.5f;
			Sceen2SunVertex[1].v = 0.0f;
			Sceen2SunVertex[2].u = 0.0f;
			Sceen2SunVertex[2].v = 1.0f;
			Sceen2SunVertex[3].u = 0.5f;
			Sceen2SunVertex[3].v = 1.0f;
		}
		else if (40 < SunTimer && SunTimer <= 80)
		{
			Sceen2SunVertex[0].u = 0.5f;
			Sceen2SunVertex[0].v = 0.0f;
			Sceen2SunVertex[1].u = 1.0f;
			Sceen2SunVertex[1].v = 0.0f;
			Sceen2SunVertex[2].u = 0.5f;
			Sceen2SunVertex[2].v = 1.0f;
			Sceen2SunVertex[3].u = 1.0f;
			Sceen2SunVertex[3].v = 1.0f;
		}
		else if (SunTimer > 80)
		{
			SunTimer = 0;
		}
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[9]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen2SunVertex, sizeof(VERTEX_2D));

		//Texture[10] Sceen2Seagull1
		//海鸥1的闪烁
		Sceen2Seagull1Timer++;
		if (0 < Sceen2Seagull1Timer && Sceen2Seagull1Timer <= 60)
		{
			Sceen2Seagull1Vertex[0].u = 0.0f;
			Sceen2Seagull1Vertex[0].v = 0.0f;
			Sceen2Seagull1Vertex[1].u = 0.5f;
			Sceen2Seagull1Vertex[1].v = 0.0f;
			Sceen2Seagull1Vertex[2].u = 0.0f;
			Sceen2Seagull1Vertex[2].v = 1.0f;
			Sceen2Seagull1Vertex[3].u = 0.5f;
			Sceen2Seagull1Vertex[3].v = 1.0f;
		}
		else if (60 < Sceen2Seagull1Timer && Sceen2Seagull1Timer <= 120)
		{
			Sceen2Seagull1Vertex[0].u = 0.5f;
			Sceen2Seagull1Vertex[0].v = 0.0f;
			Sceen2Seagull1Vertex[1].u = 1.0f;
			Sceen2Seagull1Vertex[1].v = 0.0f;
			Sceen2Seagull1Vertex[2].u = 0.5f;
			Sceen2Seagull1Vertex[2].v = 1.0f;
			Sceen2Seagull1Vertex[3].u = 1.0f;
			Sceen2Seagull1Vertex[3].v = 1.0f;
		}
		else if (Sceen2Seagull1Timer > 120)
		{
			Sceen2Seagull1Timer = 0;
		}
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[10]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen2Seagull1Vertex, sizeof(VERTEX_2D));

		//Texture[11] Sceen2Seagull2
		//海鸥2的闪烁
		Sceen2Seagull2Timer++;
		if (0 < Sceen2Seagull2Timer && Sceen2Seagull2Timer <= 80)
		{
			Sceen2Seagull2Vertex[0].u = 0.0f;
			Sceen2Seagull2Vertex[0].v = 0.0f;
			Sceen2Seagull2Vertex[1].u = 0.5f;
			Sceen2Seagull2Vertex[1].v = 0.0f;
			Sceen2Seagull2Vertex[2].u = 0.0f;
			Sceen2Seagull2Vertex[2].v = 1.0f;
			Sceen2Seagull2Vertex[3].u = 0.5f;
			Sceen2Seagull2Vertex[3].v = 1.0f;
		}
		else if (80 < Sceen2Seagull2Timer && Sceen2Seagull2Timer <= 160)
		{
			Sceen2Seagull2Vertex[0].u = 0.5f;
			Sceen2Seagull2Vertex[0].v = 0.0f;
			Sceen2Seagull2Vertex[1].u = 1.0f;
			Sceen2Seagull2Vertex[1].v = 0.0f;
			Sceen2Seagull2Vertex[2].u = 0.5f;
			Sceen2Seagull2Vertex[2].v = 1.0f;
			Sceen2Seagull2Vertex[3].u = 1.0f;
			Sceen2Seagull2Vertex[3].v = 1.0f;
		}
		else if (Sceen2Seagull2Timer > 160)
		{
			Sceen2Seagull2Timer = 0;
		}
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[11]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen2Seagull2Vertex, sizeof(VERTEX_2D));

		//Texture[2] Sceen2Title WhatIsCalledFriendship
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[2]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen2TitleVertex, sizeof(VERTEX_2D));

		//Texture[7] Sceen2SelectArrow
		//箭头位置的移动
		if (GetKeyboardRepeat(DIK_DOWN) || GetKeyboardRepeat(DIK_S))//按钮切换
		{
			ButtonState = false;
		}
		if (GetKeyboardRepeat(DIK_UP) || GetKeyboardRepeat(DIK_W))//按钮切换
		{
			ButtonState = true;		
		}
		if (ButtonState == true)
		{
			//调整箭头位置
			Sceen2SelectArrowPosY = Sceen2OnePlayerHighlightPosY;
			//显示正确的Button
			//Texture[3] Sceen2OnePlayerHighlight
			g_pD3DDevice->SetTexture(0, g_pD3DTexture[3]);
			g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen2OnePlayerHighlightVertex, sizeof(VERTEX_2D));
			//Texture[6] Sceen2TwoPlayerLowlight
			g_pD3DDevice->SetTexture(0, g_pD3DTexture[6]);
			g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen2TwoPlayerLowlightVertex, sizeof(VERTEX_2D));
		}
		else if (ButtonState == false)
		{
			//调整箭头位置
			Sceen2SelectArrowPosY = Sceen2TwoPlayerHighlightPosY;
			//显示正确的Button
			//Texture[4] Sceen2OnePlayerLowlight
			g_pD3DDevice->SetTexture(0, g_pD3DTexture[4]);
			g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen2OnePlayerLowlightVertex, sizeof(VERTEX_2D));
			//Texture[5] Sceen2TwoPlayerHighlight
			g_pD3DDevice->SetTexture(0, g_pD3DTexture[5]);
			g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen2TwoPlayerHighlightVertex, sizeof(VERTEX_2D));
		}
		Sceen2SelectArrowVertex[0].Y = Sceen2SelectArrowPosY - Sceen2SelectArrowSizeY / 2;
		Sceen2SelectArrowVertex[1].Y = Sceen2SelectArrowPosY - Sceen2SelectArrowSizeY / 2;
		Sceen2SelectArrowVertex[2].Y = Sceen2SelectArrowPosY + Sceen2SelectArrowSizeY / 2;
		Sceen2SelectArrowVertex[3].Y = Sceen2SelectArrowPosY + Sceen2SelectArrowSizeY / 2;
		//箭头的闪烁
		ArrowTimer++;
		if (0 < ArrowTimer && ArrowTimer <= 15)
		{
			Sceen2SelectArrowVertex[0].u = 0.0f;
			Sceen2SelectArrowVertex[0].v = 0.0f;
			Sceen2SelectArrowVertex[1].u = 0.25f;
			Sceen2SelectArrowVertex[1].v = 0.0f;
			Sceen2SelectArrowVertex[2].u = 0.0f;
			Sceen2SelectArrowVertex[2].v = 1.0f;
			Sceen2SelectArrowVertex[3].u = 0.25f;
			Sceen2SelectArrowVertex[3].v = 1.0f;
		}
		else if (15 < ArrowTimer && ArrowTimer <= 30)
		{
			Sceen2SelectArrowVertex[0].u = 0.25f;
			Sceen2SelectArrowVertex[0].v = 0.0f;
			Sceen2SelectArrowVertex[1].u = 0.5f;
			Sceen2SelectArrowVertex[1].v = 0.0f;
			Sceen2SelectArrowVertex[2].u = 0.25f;
			Sceen2SelectArrowVertex[2].v = 1.0f;
			Sceen2SelectArrowVertex[3].u = 0.5f;
			Sceen2SelectArrowVertex[3].v = 1.0f;
		}
		else if (30 < ArrowTimer && ArrowTimer <= 45)
		{
			Sceen2SelectArrowVertex[0].u = 0.5f;
			Sceen2SelectArrowVertex[0].v = 0.0f;
			Sceen2SelectArrowVertex[1].u = 0.75f;
			Sceen2SelectArrowVertex[1].v = 0.0f;
			Sceen2SelectArrowVertex[2].u = 0.5f;
			Sceen2SelectArrowVertex[2].v = 1.0f;
			Sceen2SelectArrowVertex[3].u = 0.75f;
			Sceen2SelectArrowVertex[3].v = 1.0f;
		}
		else if (45 < ArrowTimer && ArrowTimer <= 60)
		{
			Sceen2SelectArrowVertex[0].u = 0.75f;
			Sceen2SelectArrowVertex[0].v = 0.0f;
			Sceen2SelectArrowVertex[1].u = 1.0f;
			Sceen2SelectArrowVertex[1].v = 0.0f;
			Sceen2SelectArrowVertex[2].u = 0.75f;
			Sceen2SelectArrowVertex[2].v = 1.0f;
			Sceen2SelectArrowVertex[3].u = 1.0f;
			Sceen2SelectArrowVertex[3].v = 1.0f;
		}
		else if (ArrowTimer > 60)
		{
		ArrowTimer = 0;
		}
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[7]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen2SelectArrowVertex, sizeof(VERTEX_2D));

		//从这里结束描画
		g_pD3DDevice->EndScene();
	}
	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

//Sceen3Select
void Sceen3SelectDraw()
{
	g_pD3DDevice->Clear(0, NULL, (D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER),
		D3DCOLOR_RGBA(0, 0, 0, 0), 1.0f, 0);
	// Direct3Dによる描画の開始
	if (SUCCEEDED(g_pD3DDevice->BeginScene()))
	{
		//具体的な描画処理をココに記述していく
		g_pD3DDevice->SetFVF(FVF_VERTEX_2D);
		//从这里开始描画

		//Texture[12] Sceen3BgPic
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[12]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen3BgPicVertex, sizeof(VERTEX_2D));
	
		//Texture[29] Door Texture[30] DoorAnimation
		//Door具体位置设定
		DoorPosX[0] = 640;		//通往Stage1的门
		DoorPosY[0] = 680;
		DoorPosX[1] = 1280;		//通往Stage2的门
		DoorPosY[1] = 680;

		for (int i = 0; i < DOORMAX; i++)
		{
			//Door顶点更新
			DoorVertex[i][0].X = DoorPosX[i] - DoorSizeX[i] / 2;
			DoorVertex[i][0].Y = DoorPosY[i] - DoorSizeY[i] / 2;
			DoorVertex[i][0].Z = 0;
			DoorVertex[i][1].X = DoorPosX[i] + DoorSizeX[i] / 2;
			DoorVertex[i][1].Y = DoorPosY[i] - DoorSizeY[i] / 2;
			DoorVertex[i][1].Z = 0;
			DoorVertex[i][2].X = DoorPosX[i] - DoorSizeX[i] / 2;
			DoorVertex[i][2].Y = DoorPosY[i] + DoorSizeY[i] / 2;
			DoorVertex[i][2].Z = 0;
			DoorVertex[i][3].X = DoorPosX[i] + DoorSizeX[i] / 2;
			DoorVertex[i][3].Y = DoorPosY[i] + DoorSizeY[i] / 2;
			//DoorAnimation顶点更新
			DoorAnimationPosX[i] = DoorPosX[i];
			DoorAnimationPosY[i] = DoorPosY[i];
			DoorAnimationSizeX[i] = DoorSizeX[i];
			DoorAnimationSizeY[i] = DoorSizeY[i];
			DoorAnimationVertex[i][0].X = DoorAnimationPosX[i] - DoorAnimationSizeX[i] / 2;
			DoorAnimationVertex[i][0].Y = DoorAnimationPosY[i] - DoorAnimationSizeY[i] / 2;
			DoorAnimationVertex[i][0].Z = 0;
			DoorAnimationVertex[i][1].X = DoorAnimationPosX[i] + DoorAnimationSizeX[i] / 2;
			DoorAnimationVertex[i][1].Y = DoorAnimationPosY[i] - DoorAnimationSizeY[i] / 2;
			DoorAnimationVertex[i][1].Z = 0;
			DoorAnimationVertex[i][2].X = DoorAnimationPosX[i] - DoorAnimationSizeX[i] / 2;
			DoorAnimationVertex[i][2].Y = DoorAnimationPosY[i] + DoorAnimationSizeY[i] / 2;
			DoorAnimationVertex[i][2].Z = 0;
			DoorAnimationVertex[i][3].X = DoorAnimationPosX[i] + DoorAnimationSizeX[i] / 2;
			DoorAnimationVertex[i][3].Y = DoorAnimationPosY[i] + DoorAnimationSizeY[i] / 2;
			if (DoorAniState[i] == false)
			{
				//设置材质29 Door
				g_pD3DDevice->SetTexture(0, g_pD3DTexture[29]);
				g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, DoorVertex[i], sizeof(VERTEX_2D));
			}
			else if (DoorAniState[i] == true)
			{
				DoorAnimationTimer++;
				if(DoorAnimationTimer < 40)
				{
					DoorAnimation();
					//设置材质30 DoorAnimation
					g_pD3DDevice->SetTexture(0, g_pD3DTexture[30]);
					g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, DoorAnimationVertex[i], sizeof(VERTEX_2D));
				}
				else
				{
					//跳转场景了Sceen4Stage1
					if (DoorAniState[0] == true)
					{
						InitData();
						DoorAniState[0] = false;
						HurtState = false;//此时玩家受伤了 无法操作
						InvincibleState = false;
						SaveSceenMessage = 4;//Sceen4Stage1
						SaveSceenFlag = SaveSceenMessage;//Sceen4Stage1
						SceenFlag = 80;//LoadingSceen
						//初始化玩家位置
						CharacterAPosX = CharacterADefPosX;
						CharacterAPosY = CharacterADefPosY;
						DoorAnimationTimer = 0;//Timer归零
						LookAtState = true;//true==Right false==Left //动画朝向问题
						AnimationState = 1;//Character回到Idle状态
					}

					//跳转场景了Sceen8Stage2
					if (DoorAniState[1] == true)
					{
						InitData();
						DoorAniState[1] = false;
						HurtState = false;//此时玩家受伤了 无法操作
						InvincibleState = false;
						SaveSceenMessage = 8;//Sceen4Stage1
						SaveSceenFlag = SaveSceenMessage;//Sceen4Stage1
						SceenFlag = 80;//LoadingSceen
						//初始化玩家位置
						CharacterAPosX = 960;
						CharacterAPosY = CharacterADefPosY;
						DoorAnimationTimer = 0;//Timer归零
						LookAtState = true;//true==Right false==Left //动画朝向问题
						AnimationState = 1;//Character回到Idle状态
					}				
				}						
			}
		}
		//Texture[19] Sceen3SelectTile
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[19]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen3SelectTileVertex, sizeof(VERTEX_2D));

		//Texture[18] CharacterA
		CharacterInput();
		CharacterAnimation();
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[18]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, CharacterAVertex, sizeof(VERTEX_2D));

		////跟随CharacterA的事物们
		////Texture[28] CharacterBox
		////显示材质
		//g_pD3DDevice->SetTexture(0, g_pD3DTexture[28]);
		//g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, CharacterBoxVertex, sizeof(VERTEX_2D));

		////Texture[20] GroundBox
		//g_pD3DDevice->SetTexture(0, g_pD3DTexture[20]);
		//g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, GroundBoxVertex, sizeof(VERTEX_2D));

		////HeadBox
		//g_pD3DDevice->SetTexture(0, g_pD3DTexture[59]);
		//g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, HeadBoxVertex, sizeof(VERTEX_2D));

		//Texture[22] Gem
		//位置定义
		//Gem0
		GemPosX[0] = 200;
		GemPosY[0] = 200;
		ItemFeedbackPosX[0] = GemPosX[0];
		ItemFeedbackPosY[0] = GemPosY[0];
		//Gem1
		GemPosX[1] = 960;
		GemPosY[1] = 400;
		ItemFeedbackPosX[1] = GemPosX[1];
		ItemFeedbackPosY[1] = GemPosY[1];
		//Gem2
		GemPosX[2] = 1720;
		GemPosY[2] = 200;
		ItemFeedbackPosX[2] = GemPosX[2];
		ItemFeedbackPosY[2] = GemPosY[2];
		for (int i = 0; i < GEMMAX; i++)
		{
			//Gem位置更新
			GemVertex[i][0].X = GemPosX[i] - GemSizeX[i] / 2;
			GemVertex[i][0].Y = GemPosY[i] - GemSizeY[i] / 2;
			GemVertex[i][1].X = GemPosX[i] + GemSizeX[i] / 2;
			GemVertex[i][1].Y = GemPosY[i] - GemSizeY[i] / 2;
			GemVertex[i][2].X = GemPosX[i] - GemSizeX[i] / 2;
			GemVertex[i][2].Y = GemPosY[i] + GemSizeY[i] / 2;;
			GemVertex[i][3].X = GemPosX[i] + GemSizeX[i] / 2;
			GemVertex[i][3].Y = GemPosY[i] + GemSizeY[i] / 2;
			//ItemFeedback位置更新
			ItemFeedbackVertex[i][0].X = ItemFeedbackPosX[i] - ItemFeedbackSizeX[i] / 2;
			ItemFeedbackVertex[i][0].Y = ItemFeedbackPosY[i] - ItemFeedbackSizeY[i] / 2;
			ItemFeedbackVertex[i][1].X = ItemFeedbackPosX[i] + ItemFeedbackSizeX[i] / 2;
			ItemFeedbackVertex[i][1].Y = ItemFeedbackPosY[i] - ItemFeedbackSizeY[i] / 2;
			ItemFeedbackVertex[i][2].X = ItemFeedbackPosX[i] - ItemFeedbackSizeX[i] / 2;
			ItemFeedbackVertex[i][2].Y = ItemFeedbackPosY[i] + ItemFeedbackSizeY[i] / 2;;
			ItemFeedbackVertex[i][3].X = ItemFeedbackPosX[i] + ItemFeedbackSizeX[i] / 2;
			ItemFeedbackVertex[i][3].Y = ItemFeedbackPosY[i] + ItemFeedbackSizeY[i] / 2;
			if (ItemDisState[i] == true&&TouchState[i] == false)
			{
				//Texture[22] Gem
				g_pD3DDevice->SetTexture(0, g_pD3DTexture[22]);
				g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, GemVertex[i], sizeof(VERTEX_2D));
			}
			else if (ItemDisState[i] == true && TouchState[i] == true)
			{
				ItemFeedbackTimer++;
				if (ItemFeedbackTimer < 40)
				{
					//Texture[23] ItemFeedback
					g_pD3DDevice->SetTexture(0, g_pD3DTexture[23]);
					g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, ItemFeedbackVertex[i], sizeof(VERTEX_2D));
				}
				else
				{
					ItemFeedbackTimer = 0;
					ItemDisState[i] = false;
				}
				
			}
			
		}
			


		//UI部分最后面描画
		//Texture[31] Key 
		//Key具体位置设定
		KeyPosX[0] = 200;
		KeyPosY[0] = 880;
		KeySizeX[0] = 80;
		KeySizeY[0] = 80;
		KeyPosX[1] = 100;
		KeyPosY[1] = 980;
		KeySizeX[1] = KeySizeX[0];
		KeySizeY[1] = KeySizeY[0];
		KeyPosX[2] = KeyPosX[0];
		KeyPosY[2] = KeyPosY[1];
		KeySizeX[2] = KeySizeX[0];
		KeySizeY[2] = KeySizeY[0];
		KeyPosX[3] = 300;
		KeyPosY[3] = KeyPosY[1];
		KeySizeX[3] = KeySizeX[0];
		KeySizeY[3] = KeySizeY[0];
		KeyPosX[4] = 960;
		KeyPosY[4] = KeyPosY[1];
		KeySizeX[4] = KeySizeX[0] * 6;
		KeySizeY[4] = KeySizeY[0];
		//Translucent具体位置设定
		TranslucentPosX[0] = KeyPosX[0];
		TranslucentPosY[0] = KeyPosY[0];
		TranslucentSizeX[0] = KeySizeX[0];
		TranslucentSizeY[0] = KeySizeY[0];
		TranslucentPosX[1] = KeyPosX[1];
		TranslucentPosY[1] = KeyPosY[1];
		TranslucentSizeX[1] = KeySizeX[1];
		TranslucentSizeY[1] = KeySizeY[1];
		TranslucentPosX[2] = KeyPosX[2];
		TranslucentPosY[2] = KeyPosY[2];
		TranslucentSizeX[2] = KeySizeX[2];
		TranslucentSizeY[2] = KeySizeY[2];
		TranslucentPosX[3] = KeyPosX[3];
		TranslucentPosY[3] = KeyPosY[3];
		TranslucentSizeX[3] = KeySizeX[3];
		TranslucentSizeY[3] = KeySizeY[3];
		TranslucentPosX[4] = KeyPosX[4];
		TranslucentPosY[4] = KeyPosY[4];
		TranslucentSizeX[4] = KeySizeX[4];
		TranslucentSizeY[4] = KeySizeY[4];
		for (int i = 0; i < KEYMAX; i++)
		{
			//Key顶点更新
			KeyVertex[i][0].X = KeyPosX[i] - KeySizeX[i] / 2;
			KeyVertex[i][0].Y = KeyPosY[i] - KeySizeY[i] / 2;
			KeyVertex[i][0].Z = 0;
			KeyVertex[i][1].X = KeyPosX[i] + KeySizeX[i] / 2;
			KeyVertex[i][1].Y = KeyPosY[i] - KeySizeY[i] / 2;
			KeyVertex[i][1].Z = 0;
			KeyVertex[i][2].X = KeyPosX[i] - KeySizeX[i] / 2;
			KeyVertex[i][2].Y = KeyPosY[i] + KeySizeY[i] / 2;
			KeyVertex[i][2].Z = 0;
			KeyVertex[i][3].X = KeyPosX[i] + KeySizeX[i] / 2;
			KeyVertex[i][3].Y = KeyPosY[i] + KeySizeY[i] / 2;
			//Translucent顶点更新
			TranslucentVertex[i][0].X = TranslucentPosX[i] - TranslucentSizeX[i] / 2;
			TranslucentVertex[i][0].Y = TranslucentPosY[i] - TranslucentSizeY[i] / 2;
			TranslucentVertex[i][0].Z = 0;
			TranslucentVertex[i][1].X = TranslucentPosX[i] + TranslucentSizeX[i] / 2;
			TranslucentVertex[i][1].Y = TranslucentPosY[i] - TranslucentSizeY[i] / 2;
			TranslucentVertex[i][1].Z = 0;
			TranslucentVertex[i][2].X = TranslucentPosX[i] - TranslucentSizeX[i] / 2;
			TranslucentVertex[i][2].Y = TranslucentPosY[i] + TranslucentSizeY[i] / 2;
			TranslucentVertex[i][2].Z = 0;
			TranslucentVertex[i][3].X = TranslucentPosX[i] + TranslucentSizeX[i] / 2;
			TranslucentVertex[i][3].Y = TranslucentPosY[i] + TranslucentSizeY[i] / 2;
			//设置材质31 Key
			g_pD3DDevice->SetTexture(0, g_pD3DTexture[31]);
			g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, KeyVertex[i], sizeof(VERTEX_2D));
			
		}
		//Texture[32] Translucent
		if (GetKeyboardPress(DIK_W))
		{
			g_pD3DDevice->SetTexture(0, g_pD3DTexture[32]);
			g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, TranslucentVertex[0], sizeof(VERTEX_2D));
		}
		if (GetKeyboardPress(DIK_A))
		{
			g_pD3DDevice->SetTexture(0, g_pD3DTexture[32]);
			g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, TranslucentVertex[1], sizeof(VERTEX_2D));
		}
		if (GetKeyboardPress(DIK_S))
		{
			g_pD3DDevice->SetTexture(0, g_pD3DTexture[32]);
			g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, TranslucentVertex[2], sizeof(VERTEX_2D));
		}
		if (GetKeyboardPress(DIK_D))
		{
			g_pD3DDevice->SetTexture(0, g_pD3DTexture[32]);
			g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, TranslucentVertex[3], sizeof(VERTEX_2D));
		}
		if (GetKeyboardPress(DIK_SPACE))
		{
			g_pD3DDevice->SetTexture(0, g_pD3DTexture[32]);
			g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, TranslucentVertex[4], sizeof(VERTEX_2D));
		}
		

		//Texture[33] W Texture[34] A Texture[35] S Texture[36] D
		//字母位置确定	
		WPosX = KeyPosX[0];
		WPosY = KeyPosY[0];
		WSizeX = 80;
		WSizeY = 80;
		APosX = KeyPosX[1];
		APosY = KeyPosY[1];
		ASizeX = WSizeX;
		ASizeY = WSizeY;
		SPosX = KeyPosX[2];
		SPosY = KeyPosY[2];
		SSizeX = WSizeX;
		SSizeY = WSizeY;		
		DPosX = KeyPosX[3];
		DPosY = KeyPosY[3];
		DSizeX = WSizeX;
		DSizeY = WSizeY;
		SpacePosX = KeyPosX[4];
		SpacePosY = KeyPosY[4];
		SpaceSizeX = KeySizeX[4];
		SpaceSizeY = WSizeY;
		//顶点位置更新
		//W
		WVertex[0].X = WPosX - WSizeX / 2;
		WVertex[0].Y = WPosY - WSizeY / 2;
		WVertex[1].X = WPosX + WSizeX / 2;
		WVertex[1].Y = WPosY - WSizeY / 2;
		WVertex[2].X = WPosX - WSizeX / 2;
		WVertex[2].Y = WPosY + WSizeY / 2;
		WVertex[3].X = WPosX + WSizeX / 2;
		WVertex[3].Y = WPosY + WSizeY / 2;
		//A
		AVertex[0].X = APosX - ASizeX / 2;
		AVertex[0].Y = APosY - ASizeY / 2;
		AVertex[1].X = APosX + ASizeX / 2;
		AVertex[1].Y = APosY - ASizeY / 2;
		AVertex[2].X = APosX - ASizeX / 2;
		AVertex[2].Y = APosY + ASizeY / 2;
		AVertex[3].X = APosX + ASizeX / 2;
		AVertex[3].Y = APosY + ASizeY / 2;
		//S
		SVertex[0].X = SPosX - SSizeX / 2;
		SVertex[0].Y = SPosY - SSizeY / 2;
		SVertex[1].X = SPosX + SSizeX / 2;
		SVertex[1].Y = SPosY - SSizeY / 2;
		SVertex[2].X = SPosX - SSizeX / 2;
		SVertex[2].Y = SPosY + SSizeY / 2;
		SVertex[3].X = SPosX + SSizeX / 2;
		SVertex[3].Y = SPosY + SSizeY / 2;
		//D
		DVertex[0].X = DPosX - DSizeX / 2;
		DVertex[0].Y = DPosY - DSizeY / 2;
		DVertex[1].X = DPosX + DSizeX / 2;
		DVertex[1].Y = DPosY - DSizeY / 2;
		DVertex[2].X = DPosX - DSizeX / 2;
		DVertex[2].Y = DPosY + DSizeY / 2;
		DVertex[3].X = DPosX + DSizeX / 2;
		DVertex[3].Y = DPosY + DSizeY / 2;
		//Space
		SpaceVertex[0].X = SpacePosX - SpaceSizeX / 2;
		SpaceVertex[0].Y = SpacePosY - SpaceSizeY / 2;
		SpaceVertex[1].X = SpacePosX + SpaceSizeX / 2;
		SpaceVertex[1].Y = SpacePosY - SpaceSizeY / 2;
		SpaceVertex[2].X = SpacePosX - SpaceSizeX / 2;
		SpaceVertex[2].Y = SpacePosY + SpaceSizeY / 2;
		SpaceVertex[3].X = SpacePosX + SpaceSizeX / 2;
		SpaceVertex[3].Y = SpacePosY + SpaceSizeY / 2;

		//设置材质33 W
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[33]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, WVertex, sizeof(VERTEX_2D));
		//设置材质34 A
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[34]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, AVertex, sizeof(VERTEX_2D));
		//设置材质35 S
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[35]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, SVertex, sizeof(VERTEX_2D));
		//设置材质36 D
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[36]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, DVertex, sizeof(VERTEX_2D));
		//设置材质37 Space
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[37]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, SpaceVertex, sizeof(VERTEX_2D));

		//关卡标题
		//Texture【14】Sceen3Stage1
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[14]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen3Stage1Vertex, sizeof(VERTEX_2D));
		//Texture【15】Sceen3Stage2
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[15]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen3Stage2Vertex, sizeof(VERTEX_2D));
		////Texture【16】Sceen3Stage3
		//g_pD3DDevice->SetTexture(0, g_pD3DTexture[16]);
		//g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen3Stage3Vertex, sizeof(VERTEX_2D));
		////Texture【17】Sceen3Stage4
		//g_pD3DDevice->SetTexture(0, g_pD3DTexture[17]);
		//g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen3Stage4Vertex, sizeof(VERTEX_2D));
		//Texture【21】StageSelect
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[21]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen3HouseVertex, sizeof(VERTEX_2D));

		//从这里结束描画
		g_pD3DDevice->EndScene();
	}

	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}
//Sceen4Stage1Draw
void Sceen4Stage1Draw()
{
	g_pD3DDevice->Clear(0, NULL, (D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER),
		D3DCOLOR_RGBA(0, 0, 0, 0), 1.0f, 0);
	// Direct3Dによる描画の開始
	if (SUCCEEDED(g_pD3DDevice->BeginScene()))
	{
		//具体的な描画処理をココに記述していく
		g_pD3DDevice->SetFVF(FVF_VERTEX_2D);
		//从这里开始描画

		//Texture[26] Sceen4Stage1Sky
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[26]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen4Stage1SkyVertex, sizeof(VERTEX_2D));

		//Texture[9] Sceen2Sun
		//太阳的闪烁
		SunTimer++;
		if (0 < SunTimer && SunTimer <= 40)
		{
			Sceen2SunVertex[0].u = 0.0f;
			Sceen2SunVertex[0].v = 0.0f;
			Sceen2SunVertex[1].u = 0.5f;
			Sceen2SunVertex[1].v = 0.0f;
			Sceen2SunVertex[2].u = 0.0f;
			Sceen2SunVertex[2].v = 1.0f;
			Sceen2SunVertex[3].u = 0.5f;
			Sceen2SunVertex[3].v = 1.0f;
		}
		else if (40 < SunTimer && SunTimer <= 80)
		{
			Sceen2SunVertex[0].u = 0.5f;
			Sceen2SunVertex[0].v = 0.0f;
			Sceen2SunVertex[1].u = 1.0f;
			Sceen2SunVertex[1].v = 0.0f;
			Sceen2SunVertex[2].u = 0.5f;
			Sceen2SunVertex[2].v = 1.0f;
			Sceen2SunVertex[3].u = 1.0f;
			Sceen2SunVertex[3].v = 1.0f;
		}
		else if (SunTimer > 80)
		{
			SunTimer = 0;
		}
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[9]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen2SunVertex, sizeof(VERTEX_2D));

		//Texture[41] Cloud
		//位置定义
		//Cloud0
		CloudPosX[0] = 200;
		CloudPosY[0] = 200;
		CloudSizeX[0] = 300;
		CloudSizeY[0] = 300;
		//Cloud1
		CloudPosX[1] = 1200;
		CloudPosY[1] = 300;
		CloudSizeX[1] = 200;
		CloudSizeY[1] = 200;
		for (int i = 0; i < CLOUDMAX; i++)
		{
			//Cloud位置更新
			CloudVertex[i][0].X = CloudPosX[i] - CloudSizeX[i] / 2;
			CloudVertex[i][0].Y = CloudPosY[i] - CloudSizeY[i] / 2;
			CloudVertex[i][1].X = CloudPosX[i] + CloudSizeX[i] / 2;
			CloudVertex[i][1].Y = CloudPosY[i] - CloudSizeY[i] / 2;
			CloudVertex[i][2].X = CloudPosX[i] - CloudSizeX[i] / 2;
			CloudVertex[i][2].Y = CloudPosY[i] + CloudSizeY[i] / 2;;
			CloudVertex[i][3].X = CloudPosX[i] + CloudSizeX[i] / 2;
			CloudVertex[i][3].Y = CloudPosY[i] + CloudSizeY[i] / 2;		
		}
		//设置材质
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[41]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, CloudVertex[0], sizeof(VERTEX_2D));
		//设置材质
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[41]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, CloudVertex[1], sizeof(VERTEX_2D));

		//Texture[29] Door Texture[30] DoorAnimation
		//Door具体位置设定
		DoorPosX[4] = 1000;
		DoorPosY[4] = 840;
		for (int i = 0; i < DOORMAX; i++)
		{
			//Door顶点更新
			DoorVertex[i][0].X = DoorPosX[i] - DoorSizeX[i] / 2;
			DoorVertex[i][0].Y = DoorPosY[i] - DoorSizeY[i] / 2;
			DoorVertex[i][0].Z = 0;
			DoorVertex[i][1].X = DoorPosX[i] + DoorSizeX[i] / 2;
			DoorVertex[i][1].Y = DoorPosY[i] - DoorSizeY[i] / 2;
			DoorVertex[i][1].Z = 0;
			DoorVertex[i][2].X = DoorPosX[i] - DoorSizeX[i] / 2;
			DoorVertex[i][2].Y = DoorPosY[i] + DoorSizeY[i] / 2;
			DoorVertex[i][2].Z = 0;
			DoorVertex[i][3].X = DoorPosX[i] + DoorSizeX[i] / 2;
			DoorVertex[i][3].Y = DoorPosY[i] + DoorSizeY[i] / 2;
			//DoorAnimation顶点更新
			DoorAnimationPosX[i] = DoorPosX[i];
			DoorAnimationPosY[i] = DoorPosY[i];
			DoorAnimationSizeX[i] = DoorSizeX[i];
			DoorAnimationSizeY[i] = DoorSizeY[i];
			DoorAnimationVertex[i][0].X = DoorAnimationPosX[i] - DoorAnimationSizeX[i] / 2;
			DoorAnimationVertex[i][0].Y = DoorAnimationPosY[i] - DoorAnimationSizeY[i] / 2;
			DoorAnimationVertex[i][0].Z = 0;
			DoorAnimationVertex[i][1].X = DoorAnimationPosX[i] + DoorAnimationSizeX[i] / 2;
			DoorAnimationVertex[i][1].Y = DoorAnimationPosY[i] - DoorAnimationSizeY[i] / 2;
			DoorAnimationVertex[i][1].Z = 0;
			DoorAnimationVertex[i][2].X = DoorAnimationPosX[i] - DoorAnimationSizeX[i] / 2;
			DoorAnimationVertex[i][2].Y = DoorAnimationPosY[i] + DoorAnimationSizeY[i] / 2;
			DoorAnimationVertex[i][2].Z = 0;
			DoorAnimationVertex[i][3].X = DoorAnimationPosX[i] + DoorAnimationSizeX[i] / 2;
			DoorAnimationVertex[i][3].Y = DoorAnimationPosY[i] + DoorAnimationSizeY[i] / 2;
			if (DoorAniState[4] == false)
			{
				//设置材质29 Door
				g_pD3DDevice->SetTexture(0, g_pD3DTexture[29]);
				g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, DoorVertex[4], sizeof(VERTEX_2D));
			}
			else if (DoorAniState[4] == true)
			{
				DoorAnimationTimer++;
				if (DoorAnimationTimer < 40)
				{
					DoorAnimation();
					//设置材质30 DoorAnimation
					g_pD3DDevice->SetTexture(0, g_pD3DTexture[30]);
					g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, DoorAnimationVertex[4], sizeof(VERTEX_2D));
				}
				else
				{
					//跳转场景了Stage1
					if (DoorAniState[4] == true)
					{
						DoorAniState[4] = false;
						HurtState = false;//此时玩家受伤了 无法操作
						//SaveSceenFlag = 5;//Sceen5Stage1_1
						SceenFlag = 5;//直接跳转到场景Sceen5Stage1_1
						//初始化玩家位置
						//DoorPosX[6] = 240;
						//DoorPosY[6] = 860;
						InitData();
						CharacterAPosX = 400;
						CharacterAPosY = 800;
						DoorAnimationTimer = 0;//Timer归零
						LookAtState = true;//true==Right false==Left //动画朝向问题
						AnimationState = 1;//Character回到Idle状态
					}

				}

			}
		}
		//Texture[27] Sceen4Stage1Tile
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[27]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen4Stage1TileVertex, sizeof(VERTEX_2D));
		//Texture[18] CharacterA
		CharacterInput();
		CharacterAnimation();
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[18]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, CharacterAVertex, sizeof(VERTEX_2D));

	//	//跟随CharacterA的事物们
	////Texture[28] CharacterBox
	////显示材质
	//	g_pD3DDevice->SetTexture(0, g_pD3DTexture[28]);
	//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, CharacterBoxVertex, sizeof(VERTEX_2D));

	//	//Texture[20] GroundBox
	//	g_pD3DDevice->SetTexture(0, g_pD3DTexture[20]);
	//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, GroundBoxVertex, sizeof(VERTEX_2D));

	//	//HeadBox
	//	g_pD3DDevice->SetTexture(0, g_pD3DTexture[59]);
	//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, HeadBoxVertex, sizeof(VERTEX_2D));

		//UI部分
		////Texture[24] Arrow
		//ArrowDispTimer++;
		//if (0 < ArrowDispTimer&&ArrowDispTimer < 30)
		//{
		//	g_pD3DDevice->SetTexture(0, g_pD3DTexture[24]);
		//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, ArrowVertex, sizeof(VERTEX_2D));
		//}
		//if (ArrowDispTimer > 60)
		//{
		//	ArrowDispTimer = 0;
		//}
		////Texture[25] BlackPic
		//if (CharacterAPosX > 1920)//跳转场景的条件
		//{
		//	BlackPicPosX += BlackPicMoveSpeed;
		//	BlackPicVertex[0].X = BlackPicPosX - BlackPicSizeX / 2;
		//	BlackPicVertex[1].X = BlackPicPosX + BlackPicSizeX / 2;
		//	BlackPicVertex[2].X = BlackPicPosX - BlackPicSizeX / 2;
		//	BlackPicVertex[3].X = BlackPicPosX + BlackPicSizeX / 2;
		//	g_pD3DDevice->SetTexture(0, g_pD3DTexture[25]);
		//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, BlackPicVertex, sizeof(VERTEX_2D));
		//}
		//if (BlackPicPosX >= SCREEN_WIDTH / 2)
		//{
		//	SceenFlag = 4;//Sceen4Stage1Sky
		//	//初始化玩家位置
		//	CharacterAPosX = CharacterADefPosX;
		//	CharacterAPosY = CharacterADefPosY;
		//}
		//UI部分
		//Texture[51] Sceen5Arrow
		Sceen5ArrowPosX = DoorPosX[4];
		Sceen5ArrowPosY = DoorPosY[4] - 120;
		Sceen5ArrowVertex[0].X = Sceen5ArrowPosX - Sceen5ArrowSizeX / 2;
		Sceen5ArrowVertex[0].Y = Sceen5ArrowPosY - Sceen5ArrowSizeY / 2;
		Sceen5ArrowVertex[1].X = Sceen5ArrowPosX + Sceen5ArrowSizeX / 2;
		Sceen5ArrowVertex[1].Y = Sceen5ArrowPosY - Sceen5ArrowSizeY / 2;
		Sceen5ArrowVertex[2].X = Sceen5ArrowPosX - Sceen5ArrowSizeX / 2;
		Sceen5ArrowVertex[2].Y = Sceen5ArrowPosY + Sceen5ArrowSizeY / 2;
		Sceen5ArrowVertex[3].X = Sceen5ArrowPosX + Sceen5ArrowSizeX / 2;
		Sceen5ArrowVertex[3].Y = Sceen5ArrowPosY + Sceen5ArrowSizeY / 2;
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[51]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen5ArrowVertex, sizeof(VERTEX_2D));
		//从这里结束描画
		g_pD3DDevice->EndScene();
	}

	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}
//Sceen5
void Sceen5Stage1_1Draw()
{
	g_pD3DDevice->Clear(0, NULL, (D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER),
		D3DCOLOR_RGBA(0, 0, 0, 0), 1.0f, 0);
	// Direct3Dによる描画の開始
	if (SUCCEEDED(g_pD3DDevice->BeginScene()))
	{
		//具体的な描画処理をココに記述していく
		g_pD3DDevice->SetFVF(FVF_VERTEX_2D);
		//从这里开始描画


		//Texture[29] Door Texture[30] DoorAnimation
		//Door具体位置设定
		//来自上一个场景的门
		DoorPosX[6] = 400;
		DoorPosY[6] = 840;
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[29]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, DoorVertex[6], sizeof(VERTEX_2D));
		//到下一个场景的门
		DoorPosX[5] = 1520;
		DoorPosY[5] = 840;
		for (int i = 0; i < DOORMAX; i++)
		{
			//Door顶点更新
			DoorVertex[i][0].X = DoorPosX[i] - DoorSizeX[i] / 2;
			DoorVertex[i][0].Y = DoorPosY[i] - DoorSizeY[i] / 2;
			DoorVertex[i][0].Z = 0;
			DoorVertex[i][1].X = DoorPosX[i] + DoorSizeX[i] / 2;
			DoorVertex[i][1].Y = DoorPosY[i] - DoorSizeY[i] / 2;
			DoorVertex[i][1].Z = 0;
			DoorVertex[i][2].X = DoorPosX[i] - DoorSizeX[i] / 2;
			DoorVertex[i][2].Y = DoorPosY[i] + DoorSizeY[i] / 2;
			DoorVertex[i][2].Z = 0;
			DoorVertex[i][3].X = DoorPosX[i] + DoorSizeX[i] / 2;
			DoorVertex[i][3].Y = DoorPosY[i] + DoorSizeY[i] / 2;
			//DoorAnimation顶点更新
			DoorAnimationPosX[i] = DoorPosX[i];
			DoorAnimationPosY[i] = DoorPosY[i];
			DoorAnimationSizeX[i] = DoorSizeX[i];
			DoorAnimationSizeY[i] = DoorSizeY[i];
			DoorAnimationVertex[i][0].X = DoorAnimationPosX[i] - DoorAnimationSizeX[i] / 2;
			DoorAnimationVertex[i][0].Y = DoorAnimationPosY[i] - DoorAnimationSizeY[i] / 2;
			DoorAnimationVertex[i][0].Z = 0;
			DoorAnimationVertex[i][1].X = DoorAnimationPosX[i] + DoorAnimationSizeX[i] / 2;
			DoorAnimationVertex[i][1].Y = DoorAnimationPosY[i] - DoorAnimationSizeY[i] / 2;
			DoorAnimationVertex[i][1].Z = 0;
			DoorAnimationVertex[i][2].X = DoorAnimationPosX[i] - DoorAnimationSizeX[i] / 2;
			DoorAnimationVertex[i][2].Y = DoorAnimationPosY[i] + DoorAnimationSizeY[i] / 2;
			DoorAnimationVertex[i][2].Z = 0;
			DoorAnimationVertex[i][3].X = DoorAnimationPosX[i] + DoorAnimationSizeX[i] / 2;
			DoorAnimationVertex[i][3].Y = DoorAnimationPosY[i] + DoorAnimationSizeY[i] / 2;
			if (DoorAniState[5] == false)
			{
				//设置材质29 Door
				g_pD3DDevice->SetTexture(0, g_pD3DTexture[29]);
				g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, DoorVertex[5], sizeof(VERTEX_2D));
			}
			else if (DoorAniState[5] == true)
			{
				DoorAnimationTimer++;
				if (DoorAnimationTimer < 40)
				{
					DoorAnimation();
					//设置材质30 DoorAnimation
					g_pD3DDevice->SetTexture(0, g_pD3DTexture[30]);
					g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, DoorAnimationVertex[5], sizeof(VERTEX_2D));
				}
				else
				{
					//跳转场景了Sceen6Stage1_3
					if (DoorAniState[5] == true)
					{
						DoorAniState[5] = false;
						HurtState = false;//此时玩家受伤了 无法操作
						//SaveSceenFlag = 6;//Sceen5Stage1_2
						SceenFlag = 6;
						InitData();
						//初始化玩家位置和朝向
						CharacterAPosX = 840;
						CharacterAPosY = 340;
						GroundBoxPosX = CharacterAPosX;
						GroundBoxPosY = CharacterAPosY + CharacterASizeY / 2 - GroundBoxSizeY / 2 + 10;//Box要比玩家稍微下一点点
						CharacterBoxPosX = CharacterAPosX;
						CharacterBoxPosY = DefaultCharacterBoxPosY;//Box要比玩家稍微下一点点;
					}
				}
			}
		}
		//Texture[50] Sceen5Tile
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[50]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen5TileVertex, sizeof(VERTEX_2D));
		//Spike	
		//每隔30帧 从第一根尖刺开始下落尖刺
		SpikeTimer++;
		if (SpikeTimer > SpikeTime)
		{
			SpikeMoveState[SpikeCnt] = true;
			SpikeCnt++;
			SpikeTimer = 0;		
		}
		for (int i = 0; i < 22; i++)
		{
			if (SpikeMoveState[i] == true)
			{
				SpikePosY[i] += SpikeSpeed;
			}
			//顶点位置更新
			SpikeVertex[i][0].X = SpikePosX[i] - SpikeSizeX[i] / 2;
			SpikeVertex[i][0].Y = SpikePosY[i] - SpikeSizeY[i] / 2;
			SpikeVertex[i][1].X = SpikePosX[i] + SpikeSizeX[i] / 2;
			SpikeVertex[i][1].Y = SpikePosY[i] - SpikeSizeY[i] / 2;
			SpikeVertex[i][2].X = SpikePosX[i] - SpikeSizeX[i] / 2;
			SpikeVertex[i][2].Y = SpikePosY[i] + SpikeSizeY[i] / 2;
			SpikeVertex[i][3].X = SpikePosX[i] + SpikeSizeX[i] / 2;
			SpikeVertex[i][3].Y = SpikePosY[i] + SpikeSizeY[i] / 2;
			//设置材质
			g_pD3DDevice->SetTexture(0, g_pD3DTexture[52]);
			g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, SpikeVertex[i], sizeof(VERTEX_2D));
		}

		
		//Texture[18] CharacterA
		CharacterInput();
		CharacterAnimation();
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[18]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, CharacterAVertex, sizeof(VERTEX_2D));

	//	//跟随CharacterA的事物们
	////Texture[28] CharacterBox
	////显示材质
	//	g_pD3DDevice->SetTexture(0, g_pD3DTexture[28]);
	//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, CharacterBoxVertex, sizeof(VERTEX_2D));

	//	//Texture[20] GroundBox
	//	g_pD3DDevice->SetTexture(0, g_pD3DTexture[20]);
	//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, GroundBoxVertex, sizeof(VERTEX_2D));

	//	//HeadBox
	//	g_pD3DDevice->SetTexture(0, g_pD3DTexture[59]);
	//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, HeadBoxVertex, sizeof(VERTEX_2D));

		//UI部分
		//Texture[51] Sceen5Arrow
		Sceen5ArrowPosX = DoorPosX[5];
		Sceen5ArrowPosY = DoorPosY[5] - 120;
		Sceen5ArrowVertex[0].X = Sceen5ArrowPosX - Sceen5ArrowSizeX / 2;
		Sceen5ArrowVertex[0].Y = Sceen5ArrowPosY - Sceen5ArrowSizeY / 2;
		Sceen5ArrowVertex[1].X = Sceen5ArrowPosX + Sceen5ArrowSizeX / 2;
		Sceen5ArrowVertex[1].Y = Sceen5ArrowPosY - Sceen5ArrowSizeY / 2;
		Sceen5ArrowVertex[2].X = Sceen5ArrowPosX - Sceen5ArrowSizeX / 2;
		Sceen5ArrowVertex[2].Y = Sceen5ArrowPosY + Sceen5ArrowSizeY / 2;
		Sceen5ArrowVertex[3].X = Sceen5ArrowPosX + Sceen5ArrowSizeX / 2;
		Sceen5ArrowVertex[3].Y = Sceen5ArrowPosY + Sceen5ArrowSizeY / 2;
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[51]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen5ArrowVertex, sizeof(VERTEX_2D));

		//从这里结束描画
		g_pD3DDevice->EndScene();
	}
	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);

}
//Sceen6Stage1_2
void Sceen6Stage1_2Draw()
{
	g_pD3DDevice->Clear(0, NULL, (D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER),
		D3DCOLOR_RGBA(0, 0, 0, 0), 1.0f, 0);
	// Direct3Dによる描画の開始
	if (SUCCEEDED(g_pD3DDevice->BeginScene()))
	{
		//具体的な描画処理をココに記述していく
		g_pD3DDevice->SetFVF(FVF_VERTEX_2D);
		//从这里开始描画


		//Texture[29] Door Texture[30] DoorAnimation
		//Door具体位置设定
		//来自上一个场景的门7
		DoorPosX[7] = 840;
		DoorPosY[7] = 360;//这个20是为了和玩家同一水平线
		//Door顶点更新
		DoorVertex[7][0].X = DoorPosX[7] - DoorSizeX[7] / 2;
		DoorVertex[7][0].Y = DoorPosY[7] - DoorSizeY[7] / 2;
		DoorVertex[7][1].X = DoorPosX[7] + DoorSizeX[7] / 2;
		DoorVertex[7][1].Y = DoorPosY[7] - DoorSizeY[7] / 2;
		DoorVertex[7][2].X = DoorPosX[7] - DoorSizeX[7] / 2;
		DoorVertex[7][2].Y = DoorPosY[7] + DoorSizeY[7] / 2;
		DoorVertex[7][3].X = DoorPosX[7] + DoorSizeX[7] / 2;
		DoorVertex[7][3].Y = DoorPosY[7] + DoorSizeY[7] / 2;
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[29]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, DoorVertex[7], sizeof(VERTEX_2D));
		//到下一个场景的门8
		DoorPosX[8] = 1080;
		DoorPosY[8] = 360;//这个20是为了和玩家同一水平线
		//Door顶点更新
		DoorVertex[8][0].X = DoorPosX[8] - DoorSizeX[8] / 2;
		DoorVertex[8][0].Y = DoorPosY[8] - DoorSizeY[8] / 2;
		DoorVertex[8][1].X = DoorPosX[8] + DoorSizeX[8] / 2;
		DoorVertex[8][1].Y = DoorPosY[8] - DoorSizeY[8] / 2;
		DoorVertex[8][2].X = DoorPosX[8] - DoorSizeX[8] / 2;
		DoorVertex[8][2].Y = DoorPosY[8] + DoorSizeY[8] / 2;
		DoorVertex[8][3].X = DoorPosX[8] + DoorSizeX[8] / 2;
		DoorVertex[8][3].Y = DoorPosY[8] + DoorSizeY[8] / 2;
		if (DoorAniState[8] == false)
		{
			//设置材质29 Door
			g_pD3DDevice->SetTexture(0, g_pD3DTexture[29]);
			g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, DoorVertex[8], sizeof(VERTEX_2D));
		}
		else if (DoorAniState[8] == true)
		{
			DoorAnimationTimer++;
			if (DoorAnimationTimer < 40)
			{
				LaserPosX = -100;
				DoorAnimation();
				//设置材质30 DoorAnimation
				g_pD3DDevice->SetTexture(0, g_pD3DTexture[30]);
				g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, DoorAnimationVertex[8], sizeof(VERTEX_2D));
			}
			else
			{
				//跳转场景了Sceen7Stage1_3
				if (DoorAniState[8] == true)
				{

					
					DoorAniState[8] = false;
					HurtState = false;//此时玩家受伤了 无法操作
					//SaveSceenFlag = 7;//Sceen7Stage1_3
					SceenFlag = 7;
					//初始化数据
					InitData();
					//初始化玩家位置和朝向
					CharacterAPosX = 520;
					CharacterAPosY = 520;
					GroundBoxPosX = CharacterAPosX;
					GroundBoxPosY = CharacterAPosY + CharacterASizeY / 2 - GroundBoxSizeY / 2 + 10;//Box要比玩家稍微下一点点
					CharacterBoxPosX = CharacterAPosX;
					CharacterBoxPosY = DefaultCharacterBoxPosY;//Box要比玩家稍微下一点点;
				
				}
			}
		}
		
		//Texture[53] Sceen6Tile
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[53]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen6TileVertex, sizeof(VERTEX_2D));

		//Texture[18] CharacterA
		CharacterInput();
		CharacterAnimation();
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[18]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, CharacterAVertex, sizeof(VERTEX_2D));

	//	//跟随CharacterA的事物们
	////Texture[28] CharacterBox
	////显示材质
	//	g_pD3DDevice->SetTexture(0, g_pD3DTexture[28]);
	//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, CharacterBoxVertex, sizeof(VERTEX_2D));

	//	//Texture[20] GroundBox
	//	g_pD3DDevice->SetTexture(0, g_pD3DTexture[20]);
	//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, GroundBoxVertex, sizeof(VERTEX_2D));

	//	//HeadBox
	//	g_pD3DDevice->SetTexture(0, g_pD3DTexture[59]);
	//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, HeadBoxVertex, sizeof(VERTEX_2D));

		//UI部分
		//Texture[51] Sceen5Arrow
		Sceen5ArrowPosX = DoorPosX[8];
		Sceen5ArrowPosY = DoorPosY[8] - 120;
		Sceen5ArrowVertex[0].X = Sceen5ArrowPosX - Sceen5ArrowSizeX / 2;
		Sceen5ArrowVertex[0].Y = Sceen5ArrowPosY - Sceen5ArrowSizeY / 2;
		Sceen5ArrowVertex[1].X = Sceen5ArrowPosX + Sceen5ArrowSizeX / 2;
		Sceen5ArrowVertex[1].Y = Sceen5ArrowPosY - Sceen5ArrowSizeY / 2;
		Sceen5ArrowVertex[2].X = Sceen5ArrowPosX - Sceen5ArrowSizeX / 2;
		Sceen5ArrowVertex[2].Y = Sceen5ArrowPosY + Sceen5ArrowSizeY / 2;
		Sceen5ArrowVertex[3].X = Sceen5ArrowPosX + Sceen5ArrowSizeX / 2;
		Sceen5ArrowVertex[3].Y = Sceen5ArrowPosY + Sceen5ArrowSizeY / 2;
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[51]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen5ArrowVertex, sizeof(VERTEX_2D));

		//Texture[54] Laser
		LaserPosX += LaserSpeed;
		if (LaserPosX > 1920)
		{
			LaserPosX = 0;
		}
		LaserVertex[0].X = LaserPosX - LaserSizeX / 2;
		LaserVertex[0].Y = LaserPosY - LaserSizeY / 2;
		LaserVertex[1].X = LaserPosX + LaserSizeX / 2;
		LaserVertex[1].Y = LaserPosY - LaserSizeY / 2;
		LaserVertex[2].X = LaserPosX - LaserSizeX / 2;
		LaserVertex[2].Y = LaserPosY + LaserSizeY / 2;
		LaserVertex[3].X = LaserPosX + LaserSizeX / 2;
		LaserVertex[3].Y = LaserPosY + LaserSizeY / 2;
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[54]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, LaserVertex, sizeof(VERTEX_2D));

		//从这里结束描画
		g_pD3DDevice->EndScene();
	}
	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

//Sceen7Stage1_3
void Sceen7Stage1_3Draw()
{
	g_pD3DDevice->Clear(0, NULL, (D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER),
		D3DCOLOR_RGBA(0, 0, 0, 0), 1.0f, 0);
	// Direct3Dによる描画の開始
	if (SUCCEEDED(g_pD3DDevice->BeginScene()))
	{
		//具体的な描画処理をココに記述していく
		g_pD3DDevice->SetFVF(FVF_VERTEX_2D);
		//从这里开始描画


		//Texture[29] Door Texture[30] DoorAnimation
		//Door具体位置设定
		//来自上一个场景的门0
		DoorPosX[0] = 520;
		DoorPosY[0] = 600;
		//Door顶点更新
		DoorVertex[0][0].X = DoorPosX[0] - DoorSizeX[0] / 2;
		DoorVertex[0][0].Y = DoorPosY[0] - DoorSizeY[0] / 2;
		DoorVertex[0][1].X = DoorPosX[0] + DoorSizeX[0] / 2;
		DoorVertex[0][1].Y = DoorPosY[0] - DoorSizeY[0] / 2;
		DoorVertex[0][2].X = DoorPosX[0] - DoorSizeX[0] / 2;
		DoorVertex[0][2].Y = DoorPosY[0] + DoorSizeY[0] / 2;
		DoorVertex[0][3].X = DoorPosX[0] + DoorSizeX[0] / 2;
		DoorVertex[0][3].Y = DoorPosY[0] + DoorSizeY[0] / 2;
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[29]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, DoorVertex[0], sizeof(VERTEX_2D));
		//到下一个场景的门1
		DoorPosX[1] = 1920 - DoorPosX[0];
		DoorPosY[1] = DoorPosY[0];
		//Door顶点更新
		DoorVertex[1][0].X = DoorPosX[1] - DoorSizeX[1] / 2;
		DoorVertex[1][0].Y = DoorPosY[1] - DoorSizeY[1] / 2;
		DoorVertex[1][1].X = DoorPosX[1] + DoorSizeX[1] / 2;
		DoorVertex[1][1].Y = DoorPosY[1] - DoorSizeY[1] / 2;
		DoorVertex[1][2].X = DoorPosX[1] - DoorSizeX[1] / 2;
		DoorVertex[1][2].Y = DoorPosY[1] + DoorSizeY[1] / 2;
		DoorVertex[1][3].X = DoorPosX[1] + DoorSizeX[1] / 2;
		DoorVertex[1][3].Y = DoorPosY[1] + DoorSizeY[1] / 2;
		if (DoorAniState[1] == false)
		{
			//设置材质29 Door
			g_pD3DDevice->SetTexture(0, g_pD3DTexture[29]);
			g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, DoorVertex[1], sizeof(VERTEX_2D));
		}
		else if (DoorAniState[1] == true)
		{
			DoorAnimationTimer++;
			if (DoorAnimationTimer < 40)
			{
				DoorAnimation();
				//设置材质30 DoorAnimation
				g_pD3DDevice->SetTexture(0, g_pD3DTexture[30]);
				g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, DoorAnimationVertex[1], sizeof(VERTEX_2D));
			}
			else
			{
				//跳转场景了Sceen8Stage1_4
				if (DoorAniState[1] == true)
				{
					DoorAniState[1] = false;
					HurtState = false;//此时玩家受伤了 无法操作
					//SaveSceenFlag = 82;//Sceen7Stage1_3
					SceenFlag = 82;
					//初始化数据
					InitData();
					//初始化玩家位置和朝向
					CharacterAPosX = 840;
					CharacterAPosY = 320;
					GroundBoxPosX = CharacterAPosX;
					GroundBoxPosY = CharacterAPosY + CharacterASizeY / 2 - GroundBoxSizeY / 2 + 10;//Box要比玩家稍微下一点点
					CharacterBoxPosX = CharacterAPosX;
					CharacterBoxPosY = DefaultCharacterBoxPosY;//Box要比玩家稍微下一点点;

				}
			}
		}

		//Texture[55] Sceen7Tile
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[55]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen7TileVertex, sizeof(VERTEX_2D));

		//Texture[18] CharacterA
		CharacterInput();
		CharacterAnimation();
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[18]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, CharacterAVertex, sizeof(VERTEX_2D));

	//	//跟随CharacterA的事物们
	////Texture[28] CharacterBox
	////显示材质
	//	g_pD3DDevice->SetTexture(0, g_pD3DTexture[28]);
	//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, CharacterBoxVertex, sizeof(VERTEX_2D));

	//	//Texture[20] GroundBox
	//	g_pD3DDevice->SetTexture(0, g_pD3DTexture[20]);
	//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, GroundBoxVertex, sizeof(VERTEX_2D));

	//	//HeadBox
	//	g_pD3DDevice->SetTexture(0, g_pD3DTexture[59]);
	//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, HeadBoxVertex, sizeof(VERTEX_2D));

		//UI部分
		//Texture[51] Sceen5Arrow
		Sceen5ArrowPosX = DoorPosX[1];
		Sceen5ArrowPosY = DoorPosY[1] - 120;
		Sceen5ArrowVertex[0].X = Sceen5ArrowPosX - Sceen5ArrowSizeX / 2;
		Sceen5ArrowVertex[0].Y = Sceen5ArrowPosY - Sceen5ArrowSizeY / 2;
		Sceen5ArrowVertex[1].X = Sceen5ArrowPosX + Sceen5ArrowSizeX / 2;
		Sceen5ArrowVertex[1].Y = Sceen5ArrowPosY - Sceen5ArrowSizeY / 2;
		Sceen5ArrowVertex[2].X = Sceen5ArrowPosX - Sceen5ArrowSizeX / 2;
		Sceen5ArrowVertex[2].Y = Sceen5ArrowPosY + Sceen5ArrowSizeY / 2;
		Sceen5ArrowVertex[3].X = Sceen5ArrowPosX + Sceen5ArrowSizeX / 2;
		Sceen5ArrowVertex[3].Y = Sceen5ArrowPosY + Sceen5ArrowSizeY / 2;
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[51]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen5ArrowVertex, sizeof(VERTEX_2D));

		//Texture[56] Bullet
		BulletPosX -= BulletSpeed;
		if (BulletPosX < 1920 - BulletDefPosX)
		{
			BulletPosX = BulletDefPosX;
		}
		BulletVertex[0].X = BulletPosX - BulletSizeX / 2;
		BulletVertex[0].Y = BulletPosY - BulletSizeY / 2;
		BulletVertex[1].X = BulletPosX + BulletSizeX / 2;
		BulletVertex[1].Y = BulletPosY - BulletSizeY / 2;
		BulletVertex[2].X = BulletPosX - BulletSizeX / 2;
		BulletVertex[2].Y = BulletPosY + BulletSizeY / 2;
		BulletVertex[3].X = BulletPosX + BulletSizeX / 2;
		BulletVertex[3].Y = BulletPosY + BulletSizeY / 2;
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[56]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, BulletVertex, sizeof(VERTEX_2D));

		//从这里结束描画
		g_pD3DDevice->EndScene();
	}
	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

//采用横板卷轴模式
//Sceen8Stage2_1
void Sceen8Stage2_1Draw()
{
	g_pD3DDevice->Clear(0, NULL, (D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER),
		D3DCOLOR_RGBA(0, 0, 0, 0), 1.0f, 0);
	// Direct3Dによる描画の開始
	if (SUCCEEDED(g_pD3DDevice->BeginScene()))
	{
		//具体的な描画処理をココに記述していく
		g_pD3DDevice->SetFVF(FVF_VERTEX_2D);
		//从这里开始描画

		//Texture[61] 横板卷轴 test
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[61]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Stage2TitleVertex, sizeof(VERTEX_2D));

		//Texture[60] Sceen8Tile
		//更新Title的位置	
		Sceen8TileVertex[0].X = Sceen8TilePosX - Sceen8TileSizeX / 2 + WorldMovePosX;
		Sceen8TileVertex[1].X = Sceen8TilePosX + Sceen8TileSizeX / 2 + WorldMovePosX;
		Sceen8TileVertex[2].X = Sceen8TilePosX - Sceen8TileSizeX / 2 + WorldMovePosX;
		Sceen8TileVertex[3].X = Sceen8TilePosX + Sceen8TileSizeX / 2 + WorldMovePosX;
		//+WorldMovePosX;
		//描画Tile
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[60]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen8TileVertex, sizeof(VERTEX_2D));

		//Texture[18] CharacterA
		CharacterInput();
		CharacterAnimation();
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[18]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, CharacterAVertex, sizeof(VERTEX_2D));

		//跟随CharacterA的事物们
		//Texture[28] CharacterBox
		////显示材质
		//g_pD3DDevice->SetTexture(0, g_pD3DTexture[28]);
		//g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, CharacterBoxVertex, sizeof(VERTEX_2D));

		////Texture[20] GroundBox
		//g_pD3DDevice->SetTexture(0, g_pD3DTexture[20]);
		//g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, GroundBoxVertex, sizeof(VERTEX_2D));

		////HeadBox
		//g_pD3DDevice->SetTexture(0, g_pD3DTexture[59]);
		//g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, HeadBoxVertex, sizeof(VERTEX_2D));

		//从这里结束描画
		g_pD3DDevice->EndScene();
	}
	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}


//LoadingSceen
void LoadingSceenDraw()
{
	g_pD3DDevice->Clear(0, NULL, (D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER),
		D3DCOLOR_RGBA(0, 0, 0, 0), 1.0f, 0);
	// Direct3Dによる描画の開始
	if (SUCCEEDED(g_pD3DDevice->BeginScene()))
	{
		//具体的な描画処理をココに記述していく
		g_pD3DDevice->SetFVF(FVF_VERTEX_2D);
		//从这里开始描画

		//Texture[38] LoadingTitle
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[38]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, LoadingTitleVertex, sizeof(VERTEX_2D));
		//Texture[49] LoadingIcon
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[49]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, LoadingIconVertex, sizeof(VERTEX_2D));
		//Texture[42] NowLoading
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[42]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, NowLoadingVertex, sizeof(VERTEX_2D));

		//根据SaveFlag的具体信息决定显示的标题
		if (SaveSceenFlag == 4)
		{
			//Texture[39] 犹豫就会败北
			g_pD3DDevice->SetTexture(0, g_pD3DTexture[39]);
			g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Stage1TitleVertex, sizeof(VERTEX_2D));
		}
		//根据SaveFlag的具体信息决定显示的标题
		if (SaveSceenFlag == 8)
		{
			//Texture[61] 横板卷轴 test
			g_pD3DDevice->SetTexture(0, g_pD3DTexture[61]);
			g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Stage2TitleVertex, sizeof(VERTEX_2D));
		}


		//跳转到下一个正式的游戏场景
		LoadingTimer++;
		if (LoadingTimer > LoadingDisTime)
		{
			//初始化玩家位置
			CharacterAPosX = CharacterADefPosX;
			CharacterAPosY = CharacterADefPosY;

			LoadingTimer = 0;
			SceenFlag = SaveSceenFlag;//跳转到下一个场景
			//SaveSceenFlag = 0;
		}





		//从这里结束描画
		g_pD3DDevice->EndScene();
	}
	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}
//Sceen81GameOver
void Sceen81GameOverDraw()
{
	DeathState = false;//玩家复活
	g_pD3DDevice->Clear(0, NULL, (D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER),
		D3DCOLOR_RGBA(0, 0, 0, 0), 1.0f, 0);
	// Direct3Dによる描画の開始
	if (SUCCEEDED(g_pD3DDevice->BeginScene()))
	{
		//具体的な描画処理をココに記述していく
		g_pD3DDevice->SetFVF(FVF_VERTEX_2D);
		//从这里开始描画

		//Texture[48] Sceen81BgPic
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[48]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen81BgPicVertex, sizeof(VERTEX_2D));

		//Texture[43] GameOverTitle
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[43]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, GameOverTitleVertex, sizeof(VERTEX_2D));

		//Texture[7] SelectArrow
		//箭头位置的移动
		if (GameOverButtonState == true && (GetKeyboardRepeat(DIK_DOWN) || GetKeyboardRepeat(DIK_S)))//按钮切换
		{
			GameOverButtonState = false;
		}
		if (GameOverButtonState == false && (GetKeyboardRepeat(DIK_UP) || GetKeyboardRepeat(DIK_W)))//按钮切换
		{
			GameOverButtonState = true;
		}
		if (GameOverButtonState == true)
		{
			//调整箭头位置
			Sceen2SelectArrowPosY = Sceen2OnePlayerHighlightPosY;

			//调整button位置
			//Texture[44] RetryHighlight
			RetryHighlightPosY = Sceen2OnePlayerHighlightPosY;
			//位置更新
			RetryHighlightVertex[0].Y = RetryHighlightPosY - RetryHighlightSizeY / 2;
			RetryHighlightVertex[1].Y = RetryHighlightPosY - RetryHighlightSizeY / 2;
			RetryHighlightVertex[2].Y = RetryHighlightPosY + RetryHighlightSizeY / 2;
			RetryHighlightVertex[3].Y = RetryHighlightPosY + RetryHighlightSizeY / 2;
			//显示正确的Button
			//Texture[44] RetryHighlight
			g_pD3DDevice->SetTexture(0, g_pD3DTexture[44]);
			g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, RetryHighlightVertex, sizeof(VERTEX_2D));

			//调整button位置
			//Texture[47] StageSelectLowlight
			StageSelectLowlightPosY = Sceen2TwoPlayerHighlightPosY;
			//位置更新
			StageSelectLowlightVertex[0].Y = StageSelectLowlightPosY - StageSelectLowlightSizeY / 2;
			StageSelectLowlightVertex[1].Y = StageSelectLowlightPosY - StageSelectLowlightSizeY / 2;
			StageSelectLowlightVertex[2].Y = StageSelectLowlightPosY + StageSelectLowlightSizeY / 2;
			StageSelectLowlightVertex[3].Y = StageSelectLowlightPosY + StageSelectLowlightSizeY / 2;
			//Texture[47] StageSelectLowlight
			g_pD3DDevice->SetTexture(0, g_pD3DTexture[47]);
			g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, StageSelectLowlightVertex, sizeof(VERTEX_2D));
		}
		else if (GameOverButtonState == false)
		{
			//调整箭头位置
			Sceen2SelectArrowPosY = Sceen2TwoPlayerHighlightPosY;
			//显示正确的Button
			//调整button位置
			//Texture[44] RetryLowlight
			RetryLowlightPosY = Sceen2OnePlayerLowlightPosY;
			//位置更新
			RetryLowlightVertex[0].Y = RetryLowlightPosY - RetryLowlightSizeY / 2;
			RetryLowlightVertex[1].Y = RetryLowlightPosY - RetryLowlightSizeY / 2;
			RetryLowlightVertex[2].Y = RetryLowlightPosY + RetryLowlightSizeY / 2;
			RetryLowlightVertex[3].Y = RetryLowlightPosY + RetryLowlightSizeY / 2;
			//Texture[4] RetryLowlight
			g_pD3DDevice->SetTexture(0, g_pD3DTexture[45]);
			g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, RetryLowlightVertex, sizeof(VERTEX_2D));

			//调整button位置
			//Texture[46] StageSelectHighlight
			StageSelectHighlightPosY = Sceen2TwoPlayerLowlightPosY;
			//位置更新
			StageSelectHighlightVertex[0].Y = StageSelectHighlightPosY - StageSelectHighlightSizeY / 2;
			StageSelectHighlightVertex[1].Y = StageSelectHighlightPosY - StageSelectHighlightSizeY / 2;
			StageSelectHighlightVertex[2].Y = StageSelectHighlightPosY + StageSelectHighlightSizeY / 2;
			StageSelectHighlightVertex[3].Y = StageSelectHighlightPosY + StageSelectHighlightSizeY / 2;
			//Texture[46] StageSelectHighlight
			g_pD3DDevice->SetTexture(0, g_pD3DTexture[46]);
			g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, StageSelectHighlightVertex, sizeof(VERTEX_2D));
		}
		Sceen2SelectArrowVertex[0].Y = Sceen2SelectArrowPosY - Sceen2SelectArrowSizeY / 2;
		Sceen2SelectArrowVertex[1].Y = Sceen2SelectArrowPosY - Sceen2SelectArrowSizeY / 2;
		Sceen2SelectArrowVertex[2].Y = Sceen2SelectArrowPosY + Sceen2SelectArrowSizeY / 2;
		Sceen2SelectArrowVertex[3].Y = Sceen2SelectArrowPosY + Sceen2SelectArrowSizeY / 2;
		//箭头的闪烁
		ArrowTimer++;
		if (0 < ArrowTimer && ArrowTimer <= 15)
		{
			Sceen2SelectArrowVertex[0].u = 0.0f;
			Sceen2SelectArrowVertex[0].v = 0.0f;
			Sceen2SelectArrowVertex[1].u = 0.25f;
			Sceen2SelectArrowVertex[1].v = 0.0f;
			Sceen2SelectArrowVertex[2].u = 0.0f;
			Sceen2SelectArrowVertex[2].v = 1.0f;
			Sceen2SelectArrowVertex[3].u = 0.25f;
			Sceen2SelectArrowVertex[3].v = 1.0f;
		}
		else if (15 < ArrowTimer && ArrowTimer <= 30)
		{
			Sceen2SelectArrowVertex[0].u = 0.25f;
			Sceen2SelectArrowVertex[0].v = 0.0f;
			Sceen2SelectArrowVertex[1].u = 0.5f;
			Sceen2SelectArrowVertex[1].v = 0.0f;
			Sceen2SelectArrowVertex[2].u = 0.25f;
			Sceen2SelectArrowVertex[2].v = 1.0f;
			Sceen2SelectArrowVertex[3].u = 0.5f;
			Sceen2SelectArrowVertex[3].v = 1.0f;
		}
		else if (30 < ArrowTimer && ArrowTimer <= 45)
		{
			Sceen2SelectArrowVertex[0].u = 0.5f;
			Sceen2SelectArrowVertex[0].v = 0.0f;
			Sceen2SelectArrowVertex[1].u = 0.75f;
			Sceen2SelectArrowVertex[1].v = 0.0f;
			Sceen2SelectArrowVertex[2].u = 0.5f;
			Sceen2SelectArrowVertex[2].v = 1.0f;
			Sceen2SelectArrowVertex[3].u = 0.75f;
			Sceen2SelectArrowVertex[3].v = 1.0f;
		}
		else if (45 < ArrowTimer && ArrowTimer <= 60)
		{
			Sceen2SelectArrowVertex[0].u = 0.75f;
			Sceen2SelectArrowVertex[0].v = 0.0f;
			Sceen2SelectArrowVertex[1].u = 1.0f;
			Sceen2SelectArrowVertex[1].v = 0.0f;
			Sceen2SelectArrowVertex[2].u = 0.75f;
			Sceen2SelectArrowVertex[2].v = 1.0f;
			Sceen2SelectArrowVertex[3].u = 1.0f;
			Sceen2SelectArrowVertex[3].v = 1.0f;
		}
		else if (ArrowTimer > 60)
		{
			ArrowTimer = 0;
		}
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[7]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen2SelectArrowVertex, sizeof(VERTEX_2D));

		//从这里结束描画
		g_pD3DDevice->EndScene();
	}
	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}
//Sceen82StageClear
void Sceen82StageClearDraw()
{
	//播放StageClear音乐
	CurrentStageClearSoundState = true;
	if (OldStageClearSoundState != CurrentStageClearSoundState)
	{
		//停止游戏中的音乐
		StopSound(SOUND_LABEL_BGM002);//BGM002 Game
		//播放StageClear的音乐
		PlaySound(SOUND_LABEL_BGM003);//BGM003 StageClear
		OldStageClearSoundState = CurrentStageClearSoundState;
	}

	g_pD3DDevice->Clear(0, NULL, (D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER),
		D3DCOLOR_RGBA(0, 0, 0, 0), 1.0f, 0);
	// Direct3Dによる描画の開始
	if (SUCCEEDED(g_pD3DDevice->BeginScene()))
	{
		//具体的な描画処理をココに記述していく
		g_pD3DDevice->SetFVF(FVF_VERTEX_2D);
		//从这里开始描画

		//Texture[57] Sceen82BgPic
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[57]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen82BgPicVertex, sizeof(VERTEX_2D));

		//Texture[58] StageClearTitle
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[58]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, StageClearTitleVertex, sizeof(VERTEX_2D));

		//Texture[7] Sceen2SelectArrow
		//箭头位置的移动
		if (GetKeyboardRepeat(DIK_DOWN) || GetKeyboardRepeat(DIK_S))//按钮切换
		{
			StageClearButtonState = false;
		}
		if (GetKeyboardRepeat(DIK_UP) || GetKeyboardRepeat(DIK_W))//按钮切换
		{
			StageClearButtonState = true;
		}
		if (StageClearButtonState == true)
		{
			//调整箭头位置
			Sceen2SelectArrowPosY = Sceen2OnePlayerHighlightPosY;
			//显示正确的Button
			//Texture[46] StageSelectHighlight
			StageSelectHighlightPosY = Sceen2OnePlayerHighlightPosY;
			//位置更新
			StageSelectHighlightVertex[0].Y = StageSelectHighlightPosY - StageSelectHighlightSizeY / 2;
			StageSelectHighlightVertex[1].Y = StageSelectHighlightPosY - StageSelectHighlightSizeY / 2;
			StageSelectHighlightVertex[2].Y = StageSelectHighlightPosY + StageSelectHighlightSizeY / 2;
			StageSelectHighlightVertex[3].Y = StageSelectHighlightPosY + StageSelectHighlightSizeY / 2;
			g_pD3DDevice->SetTexture(0, g_pD3DTexture[46]);
			g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, StageSelectHighlightVertex, sizeof(VERTEX_2D));
			//Texture[6] Sceen2TwoPlayerLowlight
			g_pD3DDevice->SetTexture(0, g_pD3DTexture[6]);
			g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen2TwoPlayerLowlightVertex, sizeof(VERTEX_2D));
		}
		else if (StageClearButtonState == false)
		{
			//调整箭头位置
			Sceen2SelectArrowPosY = Sceen2TwoPlayerHighlightPosY;
			//显示正确的Button
			//Texture[47] StageSelectLowlight
			StageSelectLowlightPosY = Sceen2OnePlayerHighlightPosY;
			//位置更新
			StageSelectLowlightVertex[0].Y = StageSelectLowlightPosY - StageSelectLowlightSizeY / 2;
			StageSelectLowlightVertex[1].Y = StageSelectLowlightPosY - StageSelectLowlightSizeY / 2;
			StageSelectLowlightVertex[2].Y = StageSelectLowlightPosY + StageSelectLowlightSizeY / 2;
			StageSelectLowlightVertex[3].Y = StageSelectLowlightPosY + StageSelectLowlightSizeY / 2;
			g_pD3DDevice->SetTexture(0, g_pD3DTexture[47]);
			g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, StageSelectLowlightVertex, sizeof(VERTEX_2D));
			//Texture[5] Sceen2TwoPlayerHighlight
			g_pD3DDevice->SetTexture(0, g_pD3DTexture[5]);
			g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen2TwoPlayerHighlightVertex, sizeof(VERTEX_2D));
		}
		Sceen2SelectArrowVertex[0].Y = Sceen2SelectArrowPosY - Sceen2SelectArrowSizeY / 2;
		Sceen2SelectArrowVertex[1].Y = Sceen2SelectArrowPosY - Sceen2SelectArrowSizeY / 2;
		Sceen2SelectArrowVertex[2].Y = Sceen2SelectArrowPosY + Sceen2SelectArrowSizeY / 2;
		Sceen2SelectArrowVertex[3].Y = Sceen2SelectArrowPosY + Sceen2SelectArrowSizeY / 2;
		//箭头的闪烁
		ArrowTimer++;
		if (0 < ArrowTimer && ArrowTimer <= 15)
		{
			Sceen2SelectArrowVertex[0].u = 0.0f;
			Sceen2SelectArrowVertex[0].v = 0.0f;
			Sceen2SelectArrowVertex[1].u = 0.25f;
			Sceen2SelectArrowVertex[1].v = 0.0f;
			Sceen2SelectArrowVertex[2].u = 0.0f;
			Sceen2SelectArrowVertex[2].v = 1.0f;
			Sceen2SelectArrowVertex[3].u = 0.25f;
			Sceen2SelectArrowVertex[3].v = 1.0f;
		}
		else if (15 < ArrowTimer && ArrowTimer <= 30)
		{
			Sceen2SelectArrowVertex[0].u = 0.25f;
			Sceen2SelectArrowVertex[0].v = 0.0f;
			Sceen2SelectArrowVertex[1].u = 0.5f;
			Sceen2SelectArrowVertex[1].v = 0.0f;
			Sceen2SelectArrowVertex[2].u = 0.25f;
			Sceen2SelectArrowVertex[2].v = 1.0f;
			Sceen2SelectArrowVertex[3].u = 0.5f;
			Sceen2SelectArrowVertex[3].v = 1.0f;
		}
		else if (30 < ArrowTimer && ArrowTimer <= 45)
		{
			Sceen2SelectArrowVertex[0].u = 0.5f;
			Sceen2SelectArrowVertex[0].v = 0.0f;
			Sceen2SelectArrowVertex[1].u = 0.75f;
			Sceen2SelectArrowVertex[1].v = 0.0f;
			Sceen2SelectArrowVertex[2].u = 0.5f;
			Sceen2SelectArrowVertex[2].v = 1.0f;
			Sceen2SelectArrowVertex[3].u = 0.75f;
			Sceen2SelectArrowVertex[3].v = 1.0f;
		}
		else if (45 < ArrowTimer && ArrowTimer <= 60)
		{
			Sceen2SelectArrowVertex[0].u = 0.75f;
			Sceen2SelectArrowVertex[0].v = 0.0f;
			Sceen2SelectArrowVertex[1].u = 1.0f;
			Sceen2SelectArrowVertex[1].v = 0.0f;
			Sceen2SelectArrowVertex[2].u = 0.75f;
			Sceen2SelectArrowVertex[2].v = 1.0f;
			Sceen2SelectArrowVertex[3].u = 1.0f;
			Sceen2SelectArrowVertex[3].v = 1.0f;
		}
		else if (ArrowTimer > 60)
		{
			ArrowTimer = 0;
		}
		g_pD3DDevice->SetTexture(0, g_pD3DTexture[7]);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Sceen2SelectArrowVertex, sizeof(VERTEX_2D));

		//从这里结束描画
		g_pD3DDevice->EndScene();
	}
	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}