#include "Physics.h"
#include "main.h"
#include "input.h"
#include "Character.h"
#include<stdio.h>

bool GroundState = false;//默认是没有踩到地面的
bool UpMove = true;
bool DownMove = true;
bool LeftMove = true;
bool RightMove = true;

int GravitySpeed = 10;
//GameOver相关
bool DeathState = false;



//重力目前为全场景生效
void Gravity(void)
{
	if (CharacterAMoveState == true)
	{
		if (SceenFlag != 1 && SceenFlag != 2 && SceenFlag != 80 && SceenFlag != 81 && SceenFlag != 82)
		{
			if (GroundState == true)
			{
				JumpPosTimer = 0;
				JumpAniTimer = 0;
				JumpCnt = 0;
				TwiceJumpFlag = false;
				//Bug问题 当GroundStage ==true 但是没有和Tile碰撞的时候
				if (TileCollision[0] == false && TileCollision[1] == false && TileCollision[2] == false)
				{
					JumpUpState = false;
					GroundState = false;
				}
			}
			else if (GroundState == false && JumpUpState == false)//离开地面同时不处于跳跃上升阶段时候 重力生效
			{
				CharacterAPosY += GravitySpeed;
				CharacterAVertex[0].Y = CharacterAPosY - CharacterASizeY / 2;
				CharacterAVertex[1].Y = CharacterAPosY - CharacterASizeY / 2;
				CharacterAVertex[2].Y = CharacterAPosY + CharacterASizeY / 2;
				CharacterAVertex[3].Y = CharacterAPosY + CharacterASizeY / 2;
			}
		}
	}	
}

//碰撞不同场景下碰撞的判定位置存在区别
void Collision(void)
{
	//底面边界检测
	//当Character的位置调到屏幕下方的时候 游戏结束
	if (SceenFlag != 81 && GroundBoxPosY > 1070)
	{
		DeathState = true;
	}

	//Sceen3Select
	if (SceenFlag == 3)
	{
		//GroundBox相关判定
		//1.碰撞体坐标初始化
		//碰撞体Tile0
		TilePosX[0] = 960;
		TilePosY[0] = 920;
		TileSizeX[0] = 1920;
		TileSizeY[0] = 320;
		if (TileCollision[0] == true)
		{
			GroundState = true;
		}
		else if (TileCollision[0] == false)
		{
			GroundState = false;
		}
		//CharacterBox相关判定
		//碰撞体Gem0
		WallPosX[0] = GemPosX[0];
		WallPosY[0] = GemPosY[0];
		WallSizeX[0] = GemSizeX[0];
		WallSizeY[0] = GemSizeY[0];
		//碰撞体Gem1
		WallPosX[1] = GemPosX[1];
		WallPosY[1] = GemPosY[1];
		WallSizeX[1] = GemSizeX[1];
		WallSizeY[1] = GemSizeY[1];
		//碰撞体Gem2
		WallPosX[2] = GemPosX[2];
		WallPosY[2] = GemPosY[2];
		WallSizeX[2] = GemSizeX[2];
		WallSizeY[2] = GemSizeY[2];
	}

	//Sceen4Stage1
	if (SceenFlag == 4)
	{
		//GroundBox相关判定
		//1.碰撞体坐标初始化
		//碰撞体Tile1左边地面
		TilePosX[1] = 680;
		TilePosY[1] = 1000;
		TileSizeX[1] = 1360;
		TileSizeY[1] = 160;
		//碰撞体Tile3右边地面
		TilePosX[3] = 1800;
		TilePosY[3] = 1000;
		TileSizeX[3] = 240;
		TileSizeY[3] = 160;

		if (TileCollision[1] == true || TileCollision[2] == true || TileCollision[3] == true || TileCollision[4] == true)
		{
			GroundState = true;
		}
		else
		{
			GroundState = false;
		}
		//CharacterBox相关判定
		//碰撞体Gem0
		WallPosX[0] = GemPosX[0];
		WallPosY[0] = GemPosY[0];
		WallSizeX[0] = GemSizeX[0];
		WallSizeY[0] = GemSizeY[0];
		//碰撞体Gem1
		WallPosX[1] = GemPosX[1];
		WallPosY[1] = GemPosY[1];
		WallSizeX[1] = GemSizeX[1];
		WallSizeY[1] = GemSizeY[1];
		//碰撞体Gem2
		WallPosX[2] = GemPosX[2];
		WallPosY[2] = GemPosY[2];
		WallSizeX[2] = GemSizeX[2];
		WallSizeY[2] = GemSizeY[2];

		//碰撞体空中的Bolck左边
		//左
		WallPosX[5] = 840;
		WallPosY[5] = 640;
		WallSizeX[5] = 80;
		WallSizeY[5] = 80;
		if (WallCollision[5] == true|| WallCollision[8] == true || WallCollision[12] == true)
		{
			RightMoveState = false;
		}
		else
		{
			RightMoveState = true;
		}
		//右
		WallPosX[6] = 1160;
		WallPosY[6] = 640;
		WallSizeX[6] = 80;
		WallSizeY[6] = 80;
		if (WallCollision[6] == true || WallCollision[9] == true || WallCollision[11] == true)
		{
			LeftMoveState = false;
		}
		else
		{
			LeftMoveState = true;
		}
		//下
		RoofPosX[7] = 1000;
		RoofPosY[7] = 660;
		RoofSizeX[7] = 380;
		RoofSizeY[7] = 40;
		if (RoofCollision[7] == true || RoofCollision[10] == true)
		{
			UpMoveState = false;
		}
		else
		{
			UpMoveState = true;
		}
		//上
		TilePosX[2] = 1000;
		TilePosY[2] = 620;
		TileSizeX[2] = 380;
		TileSizeY[2] = 40;
		
		//碰撞体空中的Bolck右边
		//左
		WallPosX[8] = 1780;
		WallPosY[8] = 640;
		WallSizeX[8] = 40;
		WallSizeY[8] = 80;
		//右
		WallPosX[9] = 1820;
		WallPosY[9] = 640;
		WallSizeX[9] = 40;
		WallSizeY[9] = 80;
		//下
		RoofPosX[10] = 1800;
		RoofPosY[10] = 660;
		RoofSizeX[10] = 80;
		RoofSizeY[10] = 40;

		//上
		TilePosX[4] = 1800;
		TilePosY[4] = 620;
		TileSizeX[4] = 80;
		TileSizeY[4] = 40;

		//增加两个地面的碰撞体
		//左
		WallPosX[11] = 1320;
		WallPosY[11] = 1000;
		WallSizeX[11] = 40;
		WallSizeY[11] = 80;
		//右
		WallPosX[12] = 1720;
		WallPosY[12] = 1000;
		WallSizeX[12] = 40;
		WallSizeY[12] = 80;

		////特殊情况 当玩家碰到了太阳
		//WallPosX[13] = Sceen2SunPosX;
		//WallPosY[13] = Sceen2SunPosY;
		//WallSizeX[13] = Sceen2SunSizeX;
		//WallSizeY[13] = Sceen2SunSizeY;
		//if (WallCollision[13] == true)
		//{
		//	DeathState = true;
		//}

	}
	//Sceen5Stage1_1
	if (SceenFlag == 5)
	{
		if (TileCollision[5] == true||TileCollision[6] == true || TileCollision[7] == true)
		{
			GroundState = true;
		}
		else
		{
			GroundState = false;
		}
		//GroundBox相关判定  人与地面
		//1.碰撞体坐标初始化
		//地面Tile5
		TilePosX[5] = 960;
		TilePosY[5] = 1000;
		TileSizeX[5] = 1920;
		TileSizeY[5] = 160;

		//CharacterBox相关判定 人与墙壁
		//左边边际墙壁
		WallPosX[5] = 40;
		WallPosY[5] = 540;
		WallSizeX[5] = 80;
		WallSizeY[5] = 1080;

		//右边边际墙壁
		WallPosX[6] = 1880;
		WallPosY[6] = 540;
		WallSizeX[6] = 80;
		WallSizeY[6] = 1080;
		if (WallCollision[6] == true)
		{
			RightMoveState = false;
		}
		else
		{
			RightMoveState = true;
		}

		//地面第一行箱子
		//左
		WallPosX[11] = 840;
		WallPosY[11] = 880;
		WallSizeX[11] = 80;
		WallSizeY[11] = 80;
		if (WallCollision[6] == true || WallCollision[11] == true || WallCollision[13] == true)
		{
			RightMoveState = false;
		}
		else
		{
			RightMoveState = true;
		}
		//右
		WallPosX[12] = 1080;
		WallPosY[12] = 880;
		WallSizeX[12] = 80;
		WallSizeY[12] = 80;
		if (WallCollision[5] == true || WallCollision[12] == true || WallCollision[14] == true)
		{
			LeftMoveState = false;
		}
		else
		{
			LeftMoveState = true;
		}
		//上
		TilePosX[6] = 960;
		TilePosY[6] = 880;
		TileSizeX[6] = 320;
		TileSizeY[6] = 80;

		//地面第二排箱子
		//左
		WallPosX[13] = 880;
		WallPosY[13] = 800;
		WallSizeX[13] = 80;
		WallSizeY[13] = 80;
		//右
		WallPosX[14] = 1040;
		WallPosY[14] = 800;
		WallSizeX[14] = 80;
		WallSizeY[14] = 80;
		//上
		TilePosX[7] = 960;
		TilePosY[7] = 800;
		TileSizeX[7] = 240;
		TileSizeY[7] = 80;

		//Wall从20开始是尖刺次相关碰撞
		for (int i = 0; i < 22; i++)
		{
			WallPosX[i + 20] = SpikePosX[i];
			WallPosY[i + 20] = SpikePosY[i];
			WallSizeX[i + 20] = SpikeSizeX[i];
			WallSizeY[i + 20] = SpikeSizeY[i];
		}
		for (int i = 0; i < 22; i++)
		{
			if (WallCollision[i + 20] == true && InvincibleState == false)
			{
				DeathState = true;
			}
		}
		

	}
	//Sceen6Stage1_2
	if (SceenFlag == 6)
	{
		//Tile Ground
		//最底下地面
		TilePosX[0] = 960;
		TilePosY[0] = 1000;
		TileSizeX[0] = 1920;
		TileSizeY[0] = 160;
		//高一层地面
		TilePosX[1] = 960;
		TilePosY[1] = 560;
		TileSizeX[1] = 960;
		TileSizeY[1] = 80;
		//最高的地面
		TilePosX[2] = 960;
		TilePosY[2] = 480;
		TileSizeX[2] = 480;
		TileSizeY[2] = 80;
		//左边小方块
		TilePosX[3] = 280;
		TilePosY[3] = 720;
		TileSizeX[3] = 80;
		TileSizeY[3] = 80;
		//右边小方块
		TilePosX[4] = 1640;
		TilePosY[4] = 720;
		TileSizeX[4] = 80;
		TileSizeY[4] = 80;
		if (TileCollision[0] == true || TileCollision[1] == true || TileCollision[2] == true || TileCollision[3] == true || TileCollision[4] == true)
		{
			GroundState = true;
		}
		else
		{
			GroundState = false;
		}
		
		//LeftMove
		//左边大墙壁
		WallPosX[0] = 120;
		WallPosY[0] = 540;
		WallSizeX[0] = 240;
		WallSizeY[0] = 1080;
		//左边小方块
		WallPosX[1] = 280;
		WallPosY[1] = 720;
		WallSizeX[1] = 80;
		WallSizeY[1] = 80;
		//右边门左边的墙壁
		WallPosX[2] = 1000;
		WallPosY[2] = 320;
		WallSizeX[2] = 80;
		WallSizeY[2] = 240;
		//右上角小方块
		WallPosX[3] = 1160;
		WallPosY[3] = 480;
		WallSizeX[3] = 80;
		WallSizeY[3] = 80;
		//右下角小方块
		WallPosX[4] = 1160;
		WallPosY[4] = 720;
		WallSizeX[4] = 80;
		WallSizeY[4] = 80;
		//右边小阻碍
		WallPosX[5] = 1400;
		WallPosY[5] = 600;
		WallSizeX[5] = 80;
		WallSizeY[5] = 160;
		if (WallCollision[0] == true || WallCollision[1] == true || WallCollision[2] == true || WallCollision[3] == true || WallCollision[4] == true || WallCollision[5] == true)
		{
			LeftMoveState = false;
		}
		else
		{
			LeftMoveState = true;
		}

		//RightMove
		//右边大墙壁
		WallPosX[6] = 1920 - 120;
		WallPosY[6] = 540;
		WallSizeX[6] = 240;
		WallSizeY[6] = 1080;
		//右边小方块
		WallPosX[7] = 1920 - 280;
		WallPosY[7] = 720;
		WallSizeX[7] = 80;
		WallSizeY[7] = 80;
		//左边门左边的墙壁
		WallPosX[8] = 1920 - 1000;
		WallPosY[8] = 320;
		WallSizeX[8] = 80;
		WallSizeY[8] = 240;
		//左上角小方块
		WallPosX[9] = 1920 - 1160;
		WallPosY[9] = 480;
		WallSizeX[9] = 80;
		WallSizeY[9] = 80;
		//左下角小方块
		WallPosX[10] = 1920 - 1160;
		WallPosY[10] = 720;
		WallSizeX[10] = 80;
		WallSizeY[10] = 80;
		//左边小阻碍
		WallPosX[11] = 1920 - 1400;
		WallPosY[11] = 600;
		WallSizeX[11] = 80;
		WallSizeY[11] = 160;
		if (WallCollision[6] == true || WallCollision[7] == true || WallCollision[8] == true || WallCollision[9] == true || WallCollision[10] == true || WallCollision[11] == true)
		{
			RightMoveState = false;
		}
		else
		{
			RightMoveState = true;
		}

		//UpMove
		//上边天花板
		RoofPosX[12] = 960;
		RoofPosY[12] = 160;
		RoofSizeX[12] = 1920;
		RoofSizeY[12] = 80;
		//第二层天花板
		RoofPosX[13] = 960;
		RoofPosY[13] = 640;
		RoofSizeX[13] = 960;
		RoofSizeY[13] = 80;
		//底层天花板
		RoofPosX[14] = 960;
		RoofPosY[14] = 720;
		RoofSizeX[14] = 480;
		RoofSizeY[14] = 80;
		//左边小方块
		RoofPosX[15] = 280;
		RoofPosY[15] = 720;
		RoofSizeX[15] = 80;
		RoofSizeY[15] = 80;
		//右边小方块
		RoofPosX[16] = 1920 - 280;
		RoofPosY[16] = 720;
		RoofSizeX[16] = 80;
		RoofSizeY[16] = 80;		
		if (RoofCollision[12] == true || RoofCollision[13] == true || RoofCollision[14] == true || RoofCollision[15] == true || RoofCollision[16] == true)
		{
			UpMoveState = false;
		}
		else
		{
			UpMoveState = true;
		}

		//GameOver
		//Laser
		WallPosX[17] = LaserPosX;
		WallPosY[17] = LaserPosY;
		WallSizeX[17] = LaserSizeX;
		WallSizeY[17] = LaserSizeY;
		if (WallCollision[17] == true && InvincibleState == false)
		{
			DeathState = true;
		}
	}
	//Sceen7Stage1_3
	if (SceenFlag == 7)
	{
		//Tile Ground
		//地面
		TilePosX[0] = 960;
		TilePosY[0] = 880;
		TileSizeX[0] = 1920;
		TileSizeY[0] = 400;
		if (TileCollision[0] == true)
		{
			GroundState = true;
		}
		else
		{
			GroundState = false;
		}

		//LeftMove
		//左边墙壁
		WallPosX[0] = 440;
		WallPosY[0] = 540;
		WallSizeX[0] = 80;
		WallSizeY[0] = 160;
		if (WallCollision[0] == true)
		{
			LeftMoveState = false;
		}
		else
		{
			LeftMoveState = true;
		}

		//RightMove
		//右边墙壁
		WallPosX[6] = 1920 - 440;
		WallPosY[6] = 540;
		WallSizeX[6] = 80;
		WallSizeY[6] = 160;
		if (WallCollision[6] == true)
		{
			RightMoveState = false;
		}
		else
		{
			RightMoveState = true;
		}

		//UpMove
		//上边天花板
		WallPosX[12] = 960;
		WallPosY[12] = 480;
		WallSizeX[12] = 1920;
		WallSizeY[12] = 80;
		if (WallCollision[12] == true)
		{
			UpMoveState = false;
		}
		else
		{
			UpMoveState = true;
		}

		//GameOver
		//Bullet
		WallPosX[80] = BulletPosX;
		WallPosY[80] = BulletPosY;
		WallSizeX[80] = BulletSizeX;
		WallSizeY[80] = BulletSizeY;
		if (WallCollision[80] == true && InvincibleState == false)
		{
			DeathState = true;
		}
	}

	//Sceen8Stage2_1
	if (SceenFlag == 8)
	{
		// + WorldMovePosX;
		//Tile Ground
		//地面
		TilePosX[0] = 960 + WorldMovePosX;
		TilePosY[0] = 1000;
		TileSizeX[0] = 1920;
		TileSizeY[0] = 160;
		//高台
		TilePosX[1] = 960 + WorldMovePosX;
		TilePosY[1] = 800;
		TileSizeX[1] = 320;
		TileSizeY[1] = 240;
		if (TileCollision[0] == true || TileCollision[1] == true)
		{
			GroundState = true;
		}
		else
		{
			GroundState = false;
		}

		//LeftMove
		//左边墙壁
		WallPosX[0] = 40 + WorldMovePosX;
		WallPosY[0] = 540;
		WallSizeX[0] = 80;
		WallSizeY[0] = 1080;
		//中间的砖块左边的部分
		WallPosX[1] = 1040 + WorldMovePosX;
		WallPosY[1] = 800;
		WallSizeX[1] = 160;
		WallSizeY[1] = 240;
		if (WallCollision[0] == true || WallCollision[1] == true)
		{
			LeftMoveState = false;
		}
		else
		{
			LeftMoveState = true;
		}

		//RightMove
		//右边墙壁
		WallPosX[6] = 1920 - 40 + WorldMovePosX;
		WallPosY[6] = 540;
		WallSizeX[6] = 80;
		WallSizeY[6] = 1080;
		//中间的砖块右边的部分
		WallPosX[7] = 880 + WorldMovePosX;
		WallPosY[7] = 800;
		WallSizeX[7] = 160;
		WallSizeY[7] = 240;
		if (WallCollision[6] == true || WallCollision[7] == true)
		{
			RightMoveState = false;
		}
		else
		{
			RightMoveState = true;
		}

		//UpMove
		//上边天花板
		WallPosX[12] = 960 + WorldMovePosX;
		WallPosY[12] = 0;
		WallSizeX[12] = 1920;
		WallSizeY[12] = 80;
		if (WallCollision[12] == true)
		{
			UpMoveState = false;
		}
		else
		{
			UpMoveState = true;
		}

		////Vine藤蔓相关判定
		////左边的藤蔓
		//VinePosX[0] = 760;
		//VinePosY[0] = 440;
		//VineSizeX[0] = 80;
		//VineSizeY[0] = 800;
		////右边的藤蔓
		//VinePosX[1] = 1160;
		//VinePosY[1] = 440;
		//VineSizeX[1] = 80;
		//VineSizeY[1] = 800;
		//if (VineCollision[0] == true || VineCollision[1] == true)
		//{
		//	VineState = true;
		//}
		//else
		//{
		//	VineState = false;
		//}
		////GameOver
		////Bullet
		//WallPosX[80] = BulletPosX;
		//WallPosY[80] = BulletPosY;
		//WallSizeX[80] = BulletSizeX;
		//WallSizeY[80] = BulletSizeY;
		//if (WallCollision[80] == true && InvincibleState == false)
		//{
		//	DeathState = true;
		//}
	}

	//1.WallCollision And CharacterBox
	for(int i = 0;i<WALLMAX;i++)
	{
		if (CharacterBoxPosX - CharacterBoxSizeX / 2 + CharacterBoxSizeX > WallPosX[i] - WallSizeX[i] / 2 && CharacterBoxPosX - CharacterBoxSizeX / 2 < WallPosX[i] - WallSizeX[i] / 2 + WallSizeX[i])
		{
			if (CharacterBoxPosY - CharacterBoxSizeY / 2 + CharacterBoxSizeY > WallPosY[i] - WallSizeY[i] / 2 && CharacterBoxPosY - CharacterBoxSizeY / 2 < WallPosY[i] - WallSizeY[i] / 2 + WallSizeY[i])
			{
				WallCollision[i] = true;
				TouchState[i] = true;
			}
			else
			{
				WallCollision[i] = false;
			}
		}
		else
		{
			WallCollision[i] = false;
		}
	}
	
	//2.RoofCollision And HeadBox
	for (int i = 0; i < ROOFMAX; i++)
	{
		if (HeadBoxPosX - HeadBoxSizeX / 2 + HeadBoxSizeX > RoofPosX[i] - RoofSizeX[i] / 2 && HeadBoxPosX - HeadBoxSizeX / 2 < RoofPosX[i] - RoofSizeX[i] / 2 + RoofSizeX[i])
		{
			if (HeadBoxPosY - HeadBoxSizeY / 2 + HeadBoxSizeY > RoofPosY[i] - RoofSizeY[i] / 2 && HeadBoxPosY - HeadBoxSizeY / 2 < RoofPosY[i] - RoofSizeY[i] / 2 + RoofSizeY[i])
			{
				RoofCollision[i] = true;
				TouchState[i] = true;
			}
			else
			{
				RoofCollision[i] = false;
			}
		}
		else
		{
			RoofCollision[i] = false;
		}
	}

	//3.TileCollision
	for (int i = 0; i < WALLMAX; i++)
	{
		if (GroundBoxPosX - GroundBoxSizeX / 2 + GroundBoxSizeX > TilePosX[i] - TileSizeX[i] / 2 && GroundBoxPosX - GroundBoxSizeX / 2 < TilePosX[i] - TileSizeX[i] / 2 + TileSizeX[i])
		{
			if (GroundBoxPosY - GroundBoxSizeY / 2 + GroundBoxSizeY > TilePosY[i] - TileSizeY[i] / 2 && GroundBoxPosY - GroundBoxSizeY / 2 < TilePosY[i] - TileSizeY[i] / 2 + TileSizeY[i])
			{
				TileCollision[i] = true;
			}
			else
			{
				TileCollision[i] = false;
			}
		}
		else
		{
			TileCollision[i] = false;
		}
	}
	//4.DoorCollision
	for (int i = 0; i < DOORMAX; i++)
	{
		if (abs(CharacterBoxPosX - DoorPosX[i])<30 && abs(CharacterBoxPosY - 20 - DoorPosY[i]) < 20)
		{
			DoorCollisionState[i] = true;
		}
		else
		{
			DoorCollisionState[i] = false;
		}
	}
	////5.VineCollision
	//for (int i = 0; i < VINE_MAX; i++)
	//{
	//	if (CharacterBoxPosX - CharacterBoxSizeX / 2 + CharacterBoxSizeX > VinePosX[i] - VineSizeX[i] / 2 && CharacterBoxPosX - CharacterBoxSizeX / 2 < VinePosX[i] - VineSizeX[i] / 2 + VineSizeX[i])
	//	{
	//		if (CharacterBoxPosY - CharacterBoxSizeY / 2 + CharacterBoxSizeY > VinePosY[i] - VineSizeY[i] / 2 && CharacterBoxPosY - CharacterBoxSizeY / 2 < VinePosY[i] - VineSizeY[i] / 2 + VineSizeY[i])
	//		{
	//			VineCollision[i] = true;
	//		}
	//		else
	//		{
	//			VineCollision[i] = false;
	//		}
	//	}
	//	else
	//	{
	//		VineCollision[i] = false;
	//	}
	//}
}