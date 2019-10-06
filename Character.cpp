#include "Character.h"
#include "main.h"
#include "input.h"
#include "XAudio2.h"
#include "Physics.h"

//动画总体参数
bool AnimationAnyState = false;
int AnimationState = 1;//1 Idle,2 Run,3 Crouch ,4 Jump,5 Hurt,6 Climb 默认开始状态为Idle
bool LookAtState = true;//true==Right false==Left //动画朝向问题
bool LookAtClock = false;
bool CharacterAMoveState = true;

//Animation材质变化参数相关
int AnimationCnt = 0;
int AnimationNum = 0;
//Idle
#define IDLEANM_MAX (4)
float IdleAnimationTbl[IDLEANM_MAX] = { 0.0f / 132.0f,33.0f / 132.0f, 66.0f / 132.0f, 99.0f / 132.0f };
//Run
bool RightMoveState = true;
bool LeftMoveState = true;
bool UpMoveState = true;
#define RUNANM_MAX (6)
float RunAnimationTbl[RUNANM_MAX] = { 0.0f / 132.0f,33.0f / 132.0f, 66.0f / 132.0f, 99.0f / 132.0f, 0.0f / 132.0f,33.0f / 132.0f };
//Crouch
#define CROUCHANM_MAX (2)
float CrouchAnimationTbl[CROUCHANM_MAX] = { 0.0f / 132.0f,33.0f / 132.0f};
//Jump
//TwiceJump
#define TWICEJUMP_MAX (4)
float TwiceJumpAnimationTbl[TWICEJUMP_MAX] = { 0.0f / 132.0f,33.0f / 132.0f,66.0f / 132.0f,99.0f / 132.0f };


//Hurt
#define HURTANM_MAX (2)
float HurtAnimationTbl[HURTANM_MAX] = { 0.0f / 132.0f,33.0f / 132.0f };
//Climb
#define CLIMBANM_MAX (3)
float ClimbAnimationTbl[CLIMBANM_MAX] = { 0.0f / 132.0f,33.0f / 132.0f, 66.0f / 132.0f };

//函数原型宣言
//Idle
int IdleAnimationSpeed = 10;
void IdleAnimation();
void InitIdleRight();
void InitIdleLeft();
//Run
int RunSpeed = 10;
int RunAnimationSpeed = 10;
void RunAnimation();
void InitRunRight();
void InitRunLeft();
//Crouch
int CrouchAnimationSpeed = 10;
int CrouchSpeed = 10;
void CrouchAnimation();
void InitCrouchRight();
void InitCrouchLeft();
//Jump
int JumpUpTime = 30;
int JumpUpSpeed = 12; //这样的话 跳跃的高度为360加上初始提高的高度30 跳跃高度为390
int JumpDownTime = JumpUpTime * JumpUpSpeed / GravitySpeed;
int JumpPosTimer = 0;//用于JumpPos计算用
int JumpAniTimer = 0;//用于JumpPos计算用
int TwiceJumpAniTimer = 0;//用于JumpPos计算用
int JumpCnt = 0;//TwiceJump
int TwiceJumpTimer = 0;
bool JumpChange = false;
bool TwiceJumpFlag = false;
bool JumpUpState = false;//Jump时候不受重力的影响
bool JumpPosState = false;
void JumpPos();
void JumpAnimation();
void InitJumpRight();
void InitJumpLeft();
//TwiceJump
int TwiceJumpAnimationSpeed = 10;
void TwiceJumpAnimation();
void InitTwiceJumpRight();
void InitTwiceJumpLeft();


//Hurt
bool HurtAtState = true; //true==right false==Left
bool HurtState = false;//受伤的时候玩家不能操作
int HurtAnimationSpeed = 10;
int HurtTime = 60;//Hurt期间无法操作
int HurtTimer = 0;//Hurt计时用
void HurtAnimation();
void InitHurtRight();
void InitHurtLeft();

//Climb
//Climb期间玩家也无法操作，相当于进门动作
int ClimbAnimationSpeed = 10;
int ClimbTime = 60;//Climb期间无法操作
int ClimbTimer = 0;//Climb计时用
void ClimbAnimation();
void InitClimb();


//角色输入相关
void CharacterInput()
{
	////由于存在过多bug暂时放弃
	////当抓住藤蔓的时候 玩家变成可以向上爬行
	//if (VineState == true)
	//{
	//	
	//	//运动相关
	//	//1.不受重力
	//	GroundState = true;
	//	//2.向上向下爬行
	//	if (GetKeyboardPress(DIK_W))
	//	{
	//		//Animation相关
	//		AnimationState = 6;		//攀爬相关动作
	//		CharacterAPosY -= CrouchSpeed;
	//	}
	//	if (GetKeyboardPress(DIK_S))
	//	{
	//		//Animation相关
	//		AnimationState = 6;		//攀爬相关动作
	//		CharacterAPosY += CrouchSpeed;
	//	}
	//}
	//else
	//{
	//	//一旦没有抓住藤蔓范围，受到重力的影响
	//	GroundState = false;
	//}


	//跟随CharacterA移动的事物们
	//CharacterBox随玩家移动
	CharacterBoxPosX = CharacterAPosX;
	DefaultCharacterBoxPosY = CharacterAPosY + 20;
	CharacterBoxPosY = DefaultCharacterBoxPosY;
	CharacterBoxVertex[0].X = CharacterBoxPosX - CharacterBoxSizeX / 2;
	CharacterBoxVertex[0].Y = CharacterBoxPosY - CharacterBoxSizeY / 2;
	CharacterBoxVertex[1].X = CharacterBoxPosX + CharacterBoxSizeX / 2;
	CharacterBoxVertex[1].Y = CharacterBoxPosY - CharacterBoxSizeY / 2;
	CharacterBoxVertex[2].X = CharacterBoxPosX - CharacterBoxSizeX / 2;
	CharacterBoxVertex[2].Y = CharacterBoxPosY + CharacterBoxSizeY / 2;
	CharacterBoxVertex[3].X = CharacterBoxPosX + CharacterBoxSizeX / 2;
	CharacterBoxVertex[3].Y = CharacterBoxPosY + CharacterBoxSizeY / 2;
	//GroundBox随玩家移动
	GroundBoxPosX = CharacterAPosX;
	GroundBoxPosY = CharacterAPosY + CharacterASizeY / 2 - GroundBoxSizeY / 2 + 10;
	GroundBoxVertex[0].X = GroundBoxPosX - GroundBoxSizeX / 2;
	GroundBoxVertex[0].Y = GroundBoxPosY - GroundBoxSizeY / 2;
	GroundBoxVertex[1].X = GroundBoxPosX + GroundBoxSizeX / 2;
	GroundBoxVertex[1].Y = GroundBoxPosY - GroundBoxSizeY / 2;
	GroundBoxVertex[2].X = GroundBoxPosX - GroundBoxSizeX / 2;
	GroundBoxVertex[2].Y = GroundBoxPosY + GroundBoxSizeY / 2;
	GroundBoxVertex[3].X = GroundBoxPosX + GroundBoxSizeX / 2;
	GroundBoxVertex[3].Y = GroundBoxPosY + GroundBoxSizeY / 2;
	//HeadBox随玩家移动
	HeadBoxPosX = CharacterAPosX;
	HeadBoxPosY = CharacterAPosY - CharacterASizeY / 2 - HeadBoxSizeY / 2 + 50;
	HeadBoxVertex[0].X = HeadBoxPosX - HeadBoxSizeX / 2;
	HeadBoxVertex[0].Y = HeadBoxPosY - HeadBoxSizeY / 2;
	HeadBoxVertex[1].X = HeadBoxPosX + HeadBoxSizeX / 2;
	HeadBoxVertex[1].Y = HeadBoxPosY - HeadBoxSizeY / 2;
	HeadBoxVertex[2].X = HeadBoxPosX - HeadBoxSizeX / 2;
	HeadBoxVertex[2].Y = HeadBoxPosY + HeadBoxSizeY / 2;
	HeadBoxVertex[3].X = HeadBoxPosX + HeadBoxSizeX / 2;
	HeadBoxVertex[3].Y = HeadBoxPosY + HeadBoxSizeY / 2;
	//111111111111111111111111111111111111111111111111
	//CharacterA顶点更新
	//1111111111111111111111111111111111111
	CharacterAVertex[0].X = CharacterAPosX - CharacterASizeX / 2;
	CharacterAVertex[0].Y = CharacterAPosY - CharacterASizeY / 2;
	CharacterAVertex[1].X = CharacterAPosX + CharacterASizeX / 2;
	CharacterAVertex[1].Y = CharacterAPosY - CharacterASizeY / 2;
	CharacterAVertex[2].X = CharacterAPosX - CharacterASizeX / 2;
	CharacterAVertex[2].Y = CharacterAPosY + CharacterASizeY / 2;
	CharacterAVertex[3].X = CharacterAPosX + CharacterASizeX / 2;
	CharacterAVertex[3].Y = CharacterAPosY + CharacterASizeY / 2;


	//特定条件下才能移动
	if (CharacterAMoveState == true )
	{
		//左右边框限制
		if ((CharacterBoxPosX - CharacterBoxSizeX / 2) <= 0)
		{
			CharacterAPosX = CharacterBoxSizeX / 2;
		}
		if ((CharacterBoxPosX + CharacterBoxSizeX / 2) >= 1920)
		{
			CharacterAPosX = 1920 - CharacterBoxSizeX / 2;
		}
		//上下边框限制
		if ((CharacterBoxPosY - CharacterBoxSizeY / 2) <= 0)
		{
			//玩家撞到天花板
			CharacterAPosY = CharacterBoxSizeY / 2;
			AnimationState = 1;
			//停止跳跃动作
			JumpUpState = false;
			JumpPosState = false;
			//开始施加重力
			GroundState = false;
		}

		if (HurtState == false)//非受伤状态才能够操作
		{
			//当玩家撞到天花板的时候恢复到待机状态
			if (UpMoveState == false)
			{
				AnimationState = 1;//Idle
			}

			//普通状态的AD按键
			//按键AD Trigger
			if (GetKeyboardTrigger(DIK_D) && LookAtClock == false && SceenFlag != 8)
			{
				LookAtState = true;
			}
			else if (GetKeyboardTrigger(DIK_A) && LookAtClock == false && SceenFlag != 8)
			{
				LookAtState = false;
			}

			if (AnimationState != 3 && GetKeyboardTrigger(DIK_D) && LookAtClock == false && SceenFlag != 8)
			{
				if (RightMoveState == true)
				{
					CharacterAPosX = CharacterAPosX + 1;
				}
				//RunAnimation初始化
				InitRunRight();
			}
			else if (AnimationState != 3 && GetKeyboardTrigger(DIK_A) && LookAtClock == false && SceenFlag != 8)
			{
				if (LeftMoveState == true)
				{
					CharacterAPosX = CharacterAPosX - 1;
				}
				//RunAnimation初始化
				InitRunLeft();
			}

			//按键AD Press	
			if (AnimationState != 3 && GetKeyboardPress(DIK_A) && SceenFlag != 8)
			{
				LookAtState = false;
				LookAtClock = true;//锁住朝向
				if (LeftMove == true)
				{
					if (LeftMoveState == true)
					{
						//改变CharacterA的Pos
						CharacterAPosX = CharacterAPosX - RunSpeed;
					}
				}

			}
			if (AnimationState != 3 && AnimationState != 4 && GetKeyboardPress(DIK_A) && SceenFlag != 8)
			{
				AnimationState = 2;//Run
			}
			if (AnimationState != 3 && AnimationState != 4 && GetKeyboardPress(DIK_D) && SceenFlag != 8)
			{
				AnimationState = 2;//Run
			}
			if (AnimationState != 3 && GetKeyboardPress(DIK_D) && SceenFlag != 8)
			{
				LookAtState = true;
				LookAtClock = true;//锁住朝向
				if (RightMove == true)
				{
					if (RightMoveState == true)
					{
						//改变CharacterA的Pos
						CharacterAPosX = CharacterAPosX + RunSpeed;
					}
				}
			}

			//更新CharacterA的位置
			CharacterAVertex[0].X = CharacterAPosX - CharacterASizeX / 2;
			CharacterAVertex[1].X = CharacterAPosX + CharacterASizeX / 2;
			CharacterAVertex[2].X = CharacterAPosX - CharacterASizeX / 2;
			CharacterAVertex[3].X = CharacterAPosX + CharacterASizeX / 2;
			//按键AD Release
			if (AnimationState == 2 && (GetKeyboardRelease(DIK_A) || GetKeyboardRelease(DIK_D)) && SceenFlag != 8)
			{
				AnimationState = 1;
				//IdleAnimation初始化
				if (LookAtState == true)
				{
					InitIdleRight();

				}
				if (LookAtState == false)
				{
					InitIdleLeft();
				}
			}
			if (GetKeyboardRelease(DIK_A) || GetKeyboardRelease(DIK_D) && SceenFlag != 8)
			{
				LookAtClock = false;//解锁朝向
			}

			//横板过关状态的AD按键
			//按键AD Trigger
			if (GetKeyboardTrigger(DIK_D) && LookAtClock == false)
			{
				LookAtState = true;
			}
			else if (GetKeyboardTrigger(DIK_A) && LookAtClock == false)
			{
				LookAtState = false;
			}

			if (AnimationState != 3 && GetKeyboardTrigger(DIK_D) && LookAtClock == false && SceenFlag == 8)
			{
				if (RightMoveState == true)
				{
					WorldMovePosX = WorldMovePosX - 1;
				}
				//RunAnimation初始化
				InitRunRight();
			}
			else if (AnimationState != 3 && GetKeyboardTrigger(DIK_A) && LookAtClock == false && SceenFlag == 8)
			{
				if (LeftMoveState == true)
				{
					WorldMovePosX = WorldMovePosX + 1;
				}
				//RunAnimation初始化
				InitRunLeft();
			}

			//按键AD Press	
			if (AnimationState != 3 && GetKeyboardPress(DIK_A) && SceenFlag == 8)
			{
				LookAtState = false;
				LookAtClock = true;//锁住朝向
				if (LeftMove == true)
				{
					if (LeftMoveState == true)
					{
						//改变CharacterA的Pos
						WorldMovePosX = WorldMovePosX + RunSpeed;
					}
				}

			}
			if (AnimationState != 3 && AnimationState != 4 && GetKeyboardPress(DIK_A))
			{
				AnimationState = 2;//Run
			}
			if (AnimationState != 3 && AnimationState != 4 && GetKeyboardPress(DIK_D))
			{
				AnimationState = 2;//Run
			}
			if (AnimationState != 3 && GetKeyboardPress(DIK_D) && SceenFlag == 8)
			{
				LookAtState = true;
				LookAtClock = true;//锁住朝向
				if (RightMove == true)
				{
					if (RightMoveState == true)
					{
						//改变CharacterA的Pos
						WorldMovePosX = WorldMovePosX - RunSpeed;
					}
				}
			}

			////更新CharacterA的位置
			//CharacterAVertex[0].X = CharacterAPosX - CharacterASizeX / 2;
			//CharacterAVertex[1].X = CharacterAPosX + CharacterASizeX / 2;
			//CharacterAVertex[2].X = CharacterAPosX - CharacterASizeX / 2;
			//CharacterAVertex[3].X = CharacterAPosX + CharacterASizeX / 2;

			//按键AD Release
			if (AnimationState == 2 && (GetKeyboardRelease(DIK_A) || GetKeyboardRelease(DIK_D)))
			{
				AnimationState = 1;
				//IdleAnimation初始化
				if (LookAtState == true)
				{
					InitIdleRight();

				}
				if (LookAtState == false)
				{
					InitIdleLeft();
				}
			}
			if (GetKeyboardRelease(DIK_A) || GetKeyboardRelease(DIK_D))
			{
				LookAtClock = false;//解锁朝向
			}

			//按键S Trigger
			if (GetKeyboardTrigger(DIK_S))
			{
				//CrouchAnimation初始化
				if (LookAtState == true)
				{
					InitCrouchRight();
				}
				if (LookAtState == false)
				{
					InitCrouchLeft();
				}
			}
			//特殊情况处理当Jump的时候按下下蹲S按键 Jump上升停止 ，同时快速下降
			if (AnimationState == 4 && GetKeyboardTrigger(DIK_S))
			{

				//结束跳跃向上的位移
				JumpPosTimer = JumpUpTime + JumpDownTime;
				//结束跳跃动作
				JumpAniTimer = JumpUpTime + JumpDownTime;
				//启动重力
				JumpUpState = false;

				//CrouchAnimation初始化
				if (LookAtState == true)
				{
					InitCrouchRight();
				}
				if (LookAtState == false)
				{
					InitCrouchLeft();
				}
			}

			//按键S Press
			else if (GetKeyboardPress(DIK_S))
			{
				CharacterBoxSizeY = SmallCharacterBoxSizeY;//此时把判定范围变小
				AnimationState = 3;
				
			}
			//按键S Release
			else if (GetKeyboardRelease(DIK_S))
			{
				CharacterBoxSizeY = DefaultCharacterBoxSizeY;//判定范围恢复
				AnimationState = 1;
				//IdleAnimation初始化
				if (LookAtState == true)
				{
					InitIdleRight();

				}
				if (LookAtState == false)
				{
					InitIdleLeft();
				}
			}

			//按键Space Trigger
			//一段跳
			if (JumpCnt == 0 && AnimationState != 3 && GroundState == true && GetKeyboardTrigger(DIK_SPACE) && UpMoveState == true)
			{
				//JumpSound
				PlaySound(SOUND_LABEL_SE004);//SE Jump
				JumpChange = true;

				//Pos相关
				JumpPosState = true;
				CharacterAPosY -= JumpUpSpeed * 3;//先位移一段 好让GroundState = false

				//Animation相关
				AnimationState = 4;
				//JumpAnimation初始化
				if (LookAtState == true)
				{
					InitJumpRight();

				}
				if (LookAtState == false)
				{
					InitJumpLeft();
				}
			}
			//需要起跳一段时间之后才能进行二段跳
			if (JumpChange == true)
			{
				TwiceJumpTimer++;
				if (TwiceJumpTimer > 10)
				{
					JumpCnt = 1;//此时JumpCnt= 1
					TwiceJumpTimer = 0;
				}
			}
			////二段跳
			//if (JumpCnt == 1 && GetKeyboardTrigger(DIK_SPACE))
			//{
			//	AnimationCnt = 0;
			//	AnimationNum = 0;
			//	JumpChange = false;
			//	TwiceJumpFlag = true;
			//	JumpCnt = 2;//此时JumpCnt= 2
			//	//重新计算内部时间
			//	JumpPosTimer = 0;
			//	JumpAniTimer = 0;
			//	//Pos相关
			//	JumpPosState = true;
			//	GroundState = false;
			//	CharacterAPosY -= JumpUpSpeed * 3;//先位移一段 好让GroundState = false

			//	//Animation相关
			//	AnimationState = 7;
			//	//JumpAnimation初始化
			//	if (LookAtState == true)
			//	{
			//		InitTwiceJumpRight();

			//	}
			//	if (LookAtState == false)
			//	{
			//		InitTwiceJumpLeft();
			//	}
			//}
			//按键W
			for (int i = 0; i < DOORMAX; i++)
			{
				if (DoorCollisionState[i] == true && GetKeyboardTrigger(DIK_W))
				{
					InvincibleState = true;//进入门之后就无敌了
					//门打开
					DoorAniState[i] = true;
					//玩家位置等于门的位置
					CharacterAPosX = DoorPosX[i];
					//更新玩家位置
					CharacterAVertex[0].X = CharacterAPosX - CharacterASizeX / 2;
					CharacterAVertex[1].X = CharacterAPosX + CharacterASizeX / 2;
					CharacterAVertex[2].X = CharacterAPosX - CharacterASizeX / 2;
					CharacterAVertex[3].X = CharacterAPosX + CharacterASizeX / 2;
					//此时进入门中 使用
					HurtState = true;//相当于玩家受伤了 无法操作
					AnimationState = 6;//Climb
					InitClimb();
				}
			}
		}

		//按键UI Trigger
		if (GetKeyboardTrigger(DIK_U))
		{
			HurtState = true;//此时玩家受伤了 无法操作
			HurtAtState = false;
			AnimationState = 5;
			InitHurtLeft();
		}
		else if (GetKeyboardTrigger(DIK_I))
		{
			HurtState = true;//此时玩家受伤了 无法操作
			HurtAtState = true;
			AnimationState = 5;
			InitHurtRight();
		}
		//Jump相关参数处理
		if (JumpPosState == true && GroundState == false)
		{
			JumpPos();
		}
	}
	

}
void JumpPos()
{
	JumpPosTimer++;
	if (JumpPosTimer <= JumpUpTime&&UpMoveState == true)
	{
		JumpUpState = true;
		CharacterAPosY -= JumpUpSpeed;
		if (GroundState == true)
		{
			JumpUpState = false;
			JumpPosState = false;
			JumpChange = false;
			JumpPosTimer = JumpUpTime + 10;
		}
	}
	else
	{
		JumpUpState = false;
		JumpPosState = false;
	}
	CharacterAVertex[0].Y = CharacterAPosY - CharacterASizeY / 2;
	CharacterAVertex[1].Y = CharacterAPosY - CharacterASizeY / 2;
	CharacterAVertex[2].Y = CharacterAPosY + CharacterASizeY / 2;
	CharacterAVertex[3].Y = CharacterAPosY + CharacterASizeY / 2;
}

//角色动画相关
void CharacterAnimation()
{
	//根据AnimationState管理CharacterA的Animation
	switch (AnimationState)
	{
	case 1:
		IdleAnimation();
		break;
	case 2:
		RunAnimation();
		break;
	case 3:
		CrouchAnimation();
		break;
	case 4:
		JumpAnimation();
		break;
	case 5:
		HurtAnimation();
		break;
	case 6:
		ClimbAnimation();
		break;
	case 7:
		TwiceJumpAnimation();
		break;
	default:
		break;
	}
}


void IdleAnimation()
{
	if (LookAtState == true)
	{
		//Animation位置的更新
		++AnimationCnt;
		if (AnimationCnt % IdleAnimationSpeed == 0)
		{
			++AnimationNum;
			if (AnimationNum >= IDLEANM_MAX)
			{
				AnimationNum = 0;
			}
			CharacterAVertex[0].u = IdleAnimationTbl[AnimationNum];
			CharacterAVertex[1].u = IdleAnimationTbl[AnimationNum] + 33.0f / 132.0f;
			CharacterAVertex[2].u = IdleAnimationTbl[AnimationNum];
			CharacterAVertex[3].u = IdleAnimationTbl[AnimationNum] + 33.0f / 132.0f;
		}
		CharacterAVertex[0].v = 0.0f;
		CharacterAVertex[1].v = CharacterAVertex[0].v;
		CharacterAVertex[2].v = 32.0f / 224.0f;
		CharacterAVertex[3].v = CharacterAVertex[2].v;
	}
	else if (LookAtState == false)
	{
		//Animation位置的更新
		++AnimationCnt;
		if (AnimationCnt % IdleAnimationSpeed == 0)
		{
			++AnimationNum;
			if (AnimationNum >= IDLEANM_MAX)
			{
				AnimationNum = 0;
			}
			CharacterAVertex[1].u = IdleAnimationTbl[AnimationNum];
			CharacterAVertex[0].u = IdleAnimationTbl[AnimationNum] + 33.0f / 132.0f;
			CharacterAVertex[3].u = IdleAnimationTbl[AnimationNum];
			CharacterAVertex[2].u = IdleAnimationTbl[AnimationNum] + 33.0f / 132.0f;
		}
		CharacterAVertex[0].v = 0.0f;
		CharacterAVertex[1].v = CharacterAVertex[0].v;
		CharacterAVertex[2].v = 32.0f / 224.0f;
		CharacterAVertex[3].v = CharacterAVertex[2].v;
	}
}
void InitIdleRight()
{
	CharacterAVertex[0].u = 0.0f / 132.0f;
	CharacterAVertex[1].u = 33.0f / 132.0f;
	CharacterAVertex[2].u = CharacterAVertex[0].u;
	CharacterAVertex[3].u = CharacterAVertex[1].u;
	CharacterAVertex[0].v = 0.0f / 224.0f;
	CharacterAVertex[1].v = CharacterAVertex[0].v;
	CharacterAVertex[2].v = 32.0f / 224.0f;
	CharacterAVertex[3].v = CharacterAVertex[2].v;
}
void InitIdleLeft()
{
	CharacterAVertex[1].u = 0.0f / 132.0f;
	CharacterAVertex[0].u = 33.0f / 132.0f;
	CharacterAVertex[3].u = CharacterAVertex[1].u;
	CharacterAVertex[2].u = CharacterAVertex[0].u;
	CharacterAVertex[0].v = 0.0f / 224.0f;
	CharacterAVertex[1].v = CharacterAVertex[0].v;
	CharacterAVertex[2].v = 32.0f / 224.0f;
	CharacterAVertex[3].v = CharacterAVertex[2].v;
}

//Run
void RunAnimation()
{
	if (LookAtState == true)
	{
		//Animation位置的更新
		++AnimationCnt;
		if (AnimationCnt % RunAnimationSpeed == 0)
		{
			++AnimationNum;
			if (AnimationNum >= RUNANM_MAX)
			{
				AnimationNum = 0;
			}
			CharacterAVertex[0].u = RunAnimationTbl[AnimationNum];
			CharacterAVertex[1].u = RunAnimationTbl[AnimationNum] + 33.0f / 132.0f;
			CharacterAVertex[2].u = RunAnimationTbl[AnimationNum];
			CharacterAVertex[3].u = RunAnimationTbl[AnimationNum] + 33.0f / 132.0f;
		}

		CharacterAVertex[0].v = 33.0f / 224.0f;
		CharacterAVertex[1].v = CharacterAVertex[0].v;
		CharacterAVertex[2].v = 64.0f / 224.0f;
		CharacterAVertex[3].v = CharacterAVertex[2].v;
		if (AnimationNum >= 4)
		{
			CharacterAVertex[0].v = 65.0f / 224.0f;
			CharacterAVertex[1].v = CharacterAVertex[0].v;
			CharacterAVertex[2].v = 96.0f / 224.0f;
			CharacterAVertex[3].v = CharacterAVertex[2].v;
		}
	}
	else if (LookAtState == false)
	{
		//Animation位置的更新
		++AnimationCnt;
		if (AnimationCnt % RunAnimationSpeed == 0)
		{
			++AnimationNum;
			if (AnimationNum >= RUNANM_MAX)
			{
				AnimationNum = 0;
			}
			CharacterAVertex[1].u = RunAnimationTbl[AnimationNum];
			CharacterAVertex[0].u = RunAnimationTbl[AnimationNum] + 33.0f / 132.0f;
			CharacterAVertex[3].u = RunAnimationTbl[AnimationNum];
			CharacterAVertex[2].u = RunAnimationTbl[AnimationNum] + 33.0f / 132.0f;
		}

		CharacterAVertex[0].v = 33.0f / 224.0f;
		CharacterAVertex[1].v = CharacterAVertex[0].v;
		CharacterAVertex[2].v = 64.0f / 224.0f;
		CharacterAVertex[3].v = CharacterAVertex[2].v;
		if (AnimationNum >= 4)
		{
			CharacterAVertex[0].v = 65.0f / 224.0f;
			CharacterAVertex[1].v = CharacterAVertex[0].v;
			CharacterAVertex[2].v = 96.0f / 224.0f;
			CharacterAVertex[3].v = CharacterAVertex[2].v;
		}
	}
	

}
void InitRunRight()
{
	CharacterAVertex[0].u = 0.0f / 132.0f;
	CharacterAVertex[1].u = 33.0f / 132.0f;
	CharacterAVertex[2].u = CharacterAVertex[0].u;
	CharacterAVertex[3].u = CharacterAVertex[1].u;
	CharacterAVertex[0].v = 33.0f / 224.0f;
	CharacterAVertex[1].v = CharacterAVertex[0].v;
	CharacterAVertex[2].v = 64.0f / 224.0f;
	CharacterAVertex[3].v = CharacterAVertex[2].v;
}
void InitRunLeft()
{
	CharacterAVertex[1].u = 0.0f / 132.0f;
	CharacterAVertex[0].u = 33.0f / 132.0f;
	CharacterAVertex[3].u = CharacterAVertex[1].u;
	CharacterAVertex[2].u = CharacterAVertex[0].u;
	CharacterAVertex[0].v = 33.0f / 224.0f;
	CharacterAVertex[1].v = CharacterAVertex[0].v;
	CharacterAVertex[2].v = 64.0f / 224.0f;
	CharacterAVertex[3].v = CharacterAVertex[2].v;
}
//Crouch
void CrouchAnimation()
{
	if (LookAtState == true)
	{
		//Animation位置的更新
		++AnimationCnt;
		if (AnimationCnt % CrouchAnimationSpeed == 0)
		{
			++AnimationNum;
			if (AnimationNum >= CROUCHANM_MAX)
			{
				AnimationNum = 0;
			}
			CharacterAVertex[0].u = CrouchAnimationTbl[AnimationNum];
			CharacterAVertex[1].u = CrouchAnimationTbl[AnimationNum] + 33.0f / 132.0f;
			CharacterAVertex[2].u = CrouchAnimationTbl[AnimationNum];
			CharacterAVertex[3].u = CrouchAnimationTbl[AnimationNum] + 33.0f / 132.0f;
		}
		CharacterAVertex[0].v = 97.0f / 224.0f;
		CharacterAVertex[1].v = CharacterAVertex[0].v;
		CharacterAVertex[2].v = 128.0f / 224.0f;
		CharacterAVertex[3].v = CharacterAVertex[2].v;
	}
	if (LookAtState == false)
	{
		//Animation位置的更新
		++AnimationCnt;
		if (AnimationCnt % CrouchAnimationSpeed == 0)
		{
			++AnimationNum;
			if (AnimationNum >= CROUCHANM_MAX)
			{
				AnimationNum = 0;
			}
			CharacterAVertex[1].u = CrouchAnimationTbl[AnimationNum];
			CharacterAVertex[0].u = CrouchAnimationTbl[AnimationNum] + 33.0f / 132.0f;
			CharacterAVertex[3].u = CrouchAnimationTbl[AnimationNum];
			CharacterAVertex[2].u = CrouchAnimationTbl[AnimationNum] + 33.0f / 132.0f;
		}
		CharacterAVertex[0].v = 97.0f / 224.0f;
		CharacterAVertex[1].v = CharacterAVertex[0].v;
		CharacterAVertex[2].v = 128.0f / 224.0f;
		CharacterAVertex[3].v = CharacterAVertex[2].v;

	}

}
void InitCrouchRight()
{
	CharacterAVertex[0].u = 0.0f / 132.0f;
	CharacterAVertex[1].u = 32.0f / 132.0f;
	CharacterAVertex[2].u = CharacterAVertex[0].u;
	CharacterAVertex[3].u = CharacterAVertex[1].u;
	CharacterAVertex[0].v = 97.0f / 224.0f;
	CharacterAVertex[1].v = CharacterAVertex[0].v;
	CharacterAVertex[2].v = 128.0f / 224.0f;
	CharacterAVertex[3].v = CharacterAVertex[2].v;
}
void InitCrouchLeft()
{
	CharacterAVertex[1].u = 0.0f / 132.0f;
	CharacterAVertex[0].u = 32.0f / 132.0f;
	CharacterAVertex[3].u = CharacterAVertex[1].u;
	CharacterAVertex[2].u = CharacterAVertex[0].u;	
	CharacterAVertex[0].v = 97.0f / 224.0f;
	CharacterAVertex[1].v = CharacterAVertex[0].v;
	CharacterAVertex[2].v = 128.0f / 224.0f;
	CharacterAVertex[3].v = CharacterAVertex[2].v;
}

//Jump
void JumpAnimation()
{
	if (LookAtState == true)
	{

		JumpAniTimer++;
		if (JumpAniTimer <= JumpUpTime / 2)
		{
			CharacterAVertex[0].u = 0.0f / 132.0f;
			CharacterAVertex[1].u = 33.0f / 132.0f;
			CharacterAVertex[2].u = 0.0f / 132.0f;
			CharacterAVertex[3].u = 33.0f / 132.0f;
		}
		else if (JumpAniTimer > JumpUpTime / 2&&JumpAniTimer <= JumpUpTime)
		{
			if (GroundState == true)
			{
				JumpPosState = false;
				AnimationState = 1;
				InitIdleRight();
			}
			CharacterAVertex[0].u = 0.0f / 132.0f;
			CharacterAVertex[1].u = 33.0f / 132.0f;
			CharacterAVertex[2].u = 0.0f / 132.0f;
			CharacterAVertex[3].u = 33.0f / 132.0f;
		}
		else if (JumpUpTime < JumpAniTimer && JumpAniTimer < JumpUpTime + JumpDownTime)
		{
			if (GroundState == true)
			{
				JumpPosState = false;
				AnimationState = 1;
				InitIdleRight();
			}
			CharacterAVertex[0].u = 33.0f / 132.0f;
			CharacterAVertex[1].u = 66.0f / 132.0f;
			CharacterAVertex[2].u = 33.0f / 132.0f;
			CharacterAVertex[3].u = 66.0f / 132.0f;
		}
		else if (JumpAniTimer > JumpUpTime + JumpDownTime)
		{
			if (GroundState == true)
			{
				JumpAniTimer = 0;
				AnimationState = 1;
				//IdleAnimation初始化
				if (LookAtState == true)
				{
					InitIdleRight();

				}
				if (LookAtState == false)
				{
					InitIdleLeft();
				}
			}
		}
		CharacterAVertex[0].v = 129.0f / 224.0f;
		CharacterAVertex[1].v = CharacterAVertex[0].v;
		CharacterAVertex[2].v = 160.0f / 224.0f;
		CharacterAVertex[3].v = CharacterAVertex[2].v;
	}
	else if (LookAtState == false)
	{
		JumpAniTimer++;
		if (JumpAniTimer <= JumpUpTime / 2)
		{
			CharacterAVertex[1].u = 0.0f / 132.0f;
			CharacterAVertex[0].u = 33.0f / 132.0f;
			CharacterAVertex[3].u = 0.0f / 132.0f;
			CharacterAVertex[2].u = 33.0f / 132.0f;
		}
		else if (JumpAniTimer > JumpUpTime /2 && JumpAniTimer <= JumpUpTime)
		{
			if (GroundState == true)
			{
				AnimationState = 1;
				InitIdleLeft();
			}
			CharacterAVertex[1].u = 0.0f / 132.0f;
			CharacterAVertex[0].u = 33.0f / 132.0f;
			CharacterAVertex[3].u = 0.0f / 132.0f;
			CharacterAVertex[2].u = 33.0f / 132.0f;
		}
		else if (JumpUpTime < JumpAniTimer && JumpAniTimer < JumpUpTime + JumpDownTime)
		{
			if (GroundState == true)
			{
				AnimationState = 1;
				InitIdleLeft();
			}
			CharacterAVertex[1].u = 33.0f / 132.0f;
			CharacterAVertex[0].u = 66.0f / 132.0f;
			CharacterAVertex[3].u = 33.0f / 132.0f;
			CharacterAVertex[2].u = 66.0f / 132.0f;
		}
		else if (JumpAniTimer > JumpUpTime + JumpDownTime)
		{
			if (GroundState == true)
			{
				JumpAniTimer = 0;
				AnimationState = 1;
				//IdleAnimation初始化
				if (LookAtState == true)
				{
					InitIdleRight();

				}
				if (LookAtState == false)
				{
					InitIdleLeft();
				}
			}		
		}
		CharacterAVertex[0].v = 129.0f / 224.0f;
		CharacterAVertex[1].v = CharacterAVertex[0].v;
		CharacterAVertex[2].v = 160.0f / 224.0f;
		CharacterAVertex[3].v = CharacterAVertex[2].v;
	}
	
}
void InitJumpRight()
{
	CharacterAVertex[0].u = 0.0f / 132.0f;
	CharacterAVertex[1].u = 33.0f / 132.0f;
	CharacterAVertex[2].u = 0.0f / 132.0f;
	CharacterAVertex[3].u = 33.0f / 132.0f;
	CharacterAVertex[0].v = 129.0f / 224.0f;
	CharacterAVertex[1].v = CharacterAVertex[0].v;
	CharacterAVertex[2].v = 160.0f / 224.0f;
	CharacterAVertex[3].v = CharacterAVertex[2].v;
}
void InitJumpLeft()
{
	CharacterAVertex[1].u = 0.0f / 132.0f;
	CharacterAVertex[0].u = 33.0f / 132.0f;
	CharacterAVertex[3].u = 0.0f / 132.0f;
	CharacterAVertex[2].u = 33.0f / 132.0f;
	CharacterAVertex[0].v = 129.0f / 224.0f;
	CharacterAVertex[1].v = CharacterAVertex[0].v;
	CharacterAVertex[2].v = 160.0f / 224.0f;
	CharacterAVertex[3].v = CharacterAVertex[2].v;
}
//TwiceJump
void TwiceJumpAnimation()
{
	//TwiceJumpAniTimer++;
	//if (TwiceJumpAniTimer <= 10)
	//{
	//	CharacterAVertex[0].u = 0.0f / 132.0f;
	//	CharacterAVertex[1].u = 33.0f / 132.0f;
	//	CharacterAVertex[2].u = 0.0f / 132.0f;
	//	CharacterAVertex[3].u = 33.0f / 132.0f;
	//}
	//else if (TwiceJumpAniTimer > 10 && TwiceJumpAniTimer <= 20)
	//{
	//	CharacterAVertex[0].u = 34.0f / 132.0f;
	//	CharacterAVertex[1].u = 66.0f / 132.0f;
	//	CharacterAVertex[2].u = 34.0f / 132.0f;
	//	CharacterAVertex[3].u = 66.0f / 132.0f;
	//}
	//else if (TwiceJumpAniTimer > 20 && TwiceJumpAniTimer <= 30)
	//{
	//	CharacterAVertex[0].u = 67.0f / 132.0f;
	//	CharacterAVertex[1].u = 99.0f / 132.0f;
	//	CharacterAVertex[2].u = 67.0f / 132.0f;
	//	CharacterAVertex[3].u = 99.0f / 132.0f;
	//}
	//else if (TwiceJumpAniTimer > 30 && TwiceJumpAniTimer <= 40)
	//{
	//	CharacterAVertex[0].u = 100.0f / 132.0f;
	//	CharacterAVertex[1].u = 132.0f / 132.0f;
	//	CharacterAVertex[2].u = 100.0f / 132.0f;
	//	CharacterAVertex[3].u = 132.0f / 132.0f;
	//}
	//else if (TwiceJumpAniTimer > 40)
	//{
	//	TwiceJumpAniTimer = 0;
	//	TwiceJumpFlag = false;//TwiceJump结束			
	//	AnimationState = 4;//回到普通的Jump
	//	JumpAniTimer = JumpUpTime + 1;
	//	CharacterAVertex[0].u = 34.0f / 132.0f;
	//	CharacterAVertex[1].u = 66.0f / 132.0f;
	//	CharacterAVertex[2].u = 34.0f / 132.0f;
	//	CharacterAVertex[3].u = 66.0f / 132.0f;
	//	CharacterAVertex[0].v = 129.0f / 224.0f;
	//	CharacterAVertex[1].v = CharacterAVertex[0].v;
	//	CharacterAVertex[2].v = 160.0f / 224.0f;
	//	CharacterAVertex[3].v = CharacterAVertex[2].v;
	//}
	//CharacterAVertex[0].v = 0.0f / 32.0f;
	//CharacterAVertex[1].v = CharacterAVertex[0].v;
	//CharacterAVertex[2].v = 32.0f / 32.0f;
	//CharacterAVertex[3].v = CharacterAVertex[2].v;
}
void InitTwiceJumpRight()
{
	CharacterAVertex[0].u = 0.0f / 132.0f;
	CharacterAVertex[1].u = 33.0f / 132.0f;
	CharacterAVertex[2].u = CharacterAVertex[0].u;
	CharacterAVertex[3].u = CharacterAVertex[1].u;
	CharacterAVertex[0].v = 0.0f / 32.0f;
	CharacterAVertex[1].v = CharacterAVertex[0].v;
	CharacterAVertex[2].v = 32.0f / 32.0f;
	CharacterAVertex[3].v = CharacterAVertex[2].v;
}
void InitTwiceJumpLeft()
{
	CharacterAVertex[1].u = 0.0f / 132.0f;
	CharacterAVertex[0].u = 33.0f / 132.0f;
	CharacterAVertex[3].u = CharacterAVertex[1].u;
	CharacterAVertex[2].u = CharacterAVertex[0].u;
	CharacterAVertex[0].v = 0.0f / 32.0f;
	CharacterAVertex[1].v = CharacterAVertex[0].v;
	CharacterAVertex[2].v = 32.0f / 32.0f;
	CharacterAVertex[3].v = CharacterAVertex[2].v;
}

//Hurt
void HurtAnimation()
{
	HurtTimer++;
	if (HurtTimer < HurtTime)
	{
		if (HurtAtState == true)
		{
			//Animation位置的更新
			++AnimationCnt;
			if (AnimationCnt % HurtAnimationSpeed == 0)
			{
				++AnimationNum;
				if (AnimationNum >= CROUCHANM_MAX)
				{
					AnimationNum = 0;
				}
				CharacterAVertex[0].u = CrouchAnimationTbl[AnimationNum];
				CharacterAVertex[1].u = CrouchAnimationTbl[AnimationNum] + 33.0f / 132.0f;
				CharacterAVertex[2].u = CrouchAnimationTbl[AnimationNum];
				CharacterAVertex[3].u = CrouchAnimationTbl[AnimationNum] + 33.0f / 132.0f;
			}
			CharacterAVertex[0].v = 161.0f / 224.0f;
			CharacterAVertex[1].v = CharacterAVertex[0].v;
			CharacterAVertex[2].v = 192.0f / 224.0f;
			CharacterAVertex[3].v = CharacterAVertex[2].v;
		}
		if (HurtAtState == false)
		{
			//Animation位置的更新
			++AnimationCnt;
			if (AnimationCnt % HurtAnimationSpeed == 0)
			{
				++AnimationNum;
				if (AnimationNum >= CROUCHANM_MAX)
				{
					AnimationNum = 0;
				}
				CharacterAVertex[1].u = CrouchAnimationTbl[AnimationNum];
				CharacterAVertex[0].u = CrouchAnimationTbl[AnimationNum] + 33.0f / 132.0f;
				CharacterAVertex[3].u = CrouchAnimationTbl[AnimationNum];
				CharacterAVertex[2].u = CrouchAnimationTbl[AnimationNum] + 33.0f / 132.0f;
			}
			CharacterAVertex[0].v = 161.0f / 224.0f;
			CharacterAVertex[1].v = CharacterAVertex[0].v;
			CharacterAVertex[2].v = 192.0f / 224.0f;
			CharacterAVertex[3].v = CharacterAVertex[2].v;
		}
	}
	else
	{
		HurtState = false;//此时玩家受伤结束 重新可以操作
		HurtTimer = 0;//内部计时器清零
		AnimationState = 1;
		//IdleAnimation初始化
		if (LookAtState == true)
		{
			InitIdleRight();

		}
		if (LookAtState == false)
		{
			InitIdleLeft();
		}
	}
	
}
void InitHurtRight()
{
	CharacterAVertex[0].u = 0.0f / 132.0f;
	CharacterAVertex[1].u = 32.0f / 132.0f;
	CharacterAVertex[2].u = CharacterAVertex[0].u;
	CharacterAVertex[3].u = CharacterAVertex[1].u;
	CharacterAVertex[0].v = 161.0f / 224.0f;
	CharacterAVertex[1].v = CharacterAVertex[0].v;
	CharacterAVertex[2].v = 192.0f / 224.0f;
	CharacterAVertex[3].v = CharacterAVertex[2].v;
}
void InitHurtLeft()
{
	CharacterAVertex[1].u = 0.0f / 132.0f;
	CharacterAVertex[0].u = 32.0f / 132.0f;
	CharacterAVertex[3].u = CharacterAVertex[1].u;
	CharacterAVertex[2].u = CharacterAVertex[0].u;
	CharacterAVertex[0].v = 161.0f / 224.0f;
	CharacterAVertex[1].v = CharacterAVertex[0].v;
	CharacterAVertex[2].v = 192.0f / 224.0f;
	CharacterAVertex[3].v = CharacterAVertex[2].v;
}

//Climb
void ClimbAnimation()
{
	ClimbTimer++;
	if (ClimbTimer < ClimbTime)
	{
		//Animation位置的更新
		++AnimationCnt;
		if (AnimationCnt % ClimbAnimationSpeed == 0)
		{
			++AnimationNum;
			if (AnimationNum >= CLIMBANM_MAX)
			{
				AnimationNum = 0;
			}
			CharacterAVertex[0].u = ClimbAnimationTbl[AnimationNum];
			CharacterAVertex[1].u = ClimbAnimationTbl[AnimationNum] + 33.0f / 132.0f;
			CharacterAVertex[2].u = ClimbAnimationTbl[AnimationNum];
			CharacterAVertex[3].u = ClimbAnimationTbl[AnimationNum] + 33.0f / 132.0f;
		}
		CharacterAVertex[0].v = 193.0f / 224.0f;
		CharacterAVertex[1].v = CharacterAVertex[0].v;
		CharacterAVertex[2].v = 224.0f / 224.0f;
		CharacterAVertex[3].v = CharacterAVertex[2].v;
		
	}
	else
	{
		HurtState = false;//相当于玩家受伤结束 重新可以操作
		ClimbTimer = 0;//内部计时器清零
		AnimationState = 1;
		//IdleAnimation初始化
		if (LookAtState == true)
		{
			InitIdleRight();

		}
		if (LookAtState == false)
		{
			InitIdleLeft();
		}
	}

}
void InitClimb()
{
	CharacterAVertex[0].u = 0.0f / 132.0f;
	CharacterAVertex[1].u = 32.0f / 132.0f;
	CharacterAVertex[2].u = CharacterAVertex[0].u;
	CharacterAVertex[3].u = CharacterAVertex[1].u;
	CharacterAVertex[0].v = 193.0f / 224.0f;
	CharacterAVertex[1].v = CharacterAVertex[0].v;
	CharacterAVertex[2].v = 224.0f / 224.0f;
	CharacterAVertex[3].v = CharacterAVertex[2].v;
}

