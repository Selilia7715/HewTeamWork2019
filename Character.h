#ifndef _CHARACTER_H_
#define _CHARACTER_H_

extern int AnimationState;//1 Idle,2 Run,3 Crouch ,4 Jump,5 Hurt,6 Climb 默认开始状态为Idle
extern bool JumpUpState;//Jump时候不受重力的影响
extern int JumpPosTimer;//用于JumpPos计算用
extern int JumpAniTimer;//用于JumpAni计算用
extern int JumpCnt;//用于实现二段跳
extern bool JumpPosState;
extern bool HurtState;
extern bool LookAtState;
extern bool JumpChange;
extern bool TwiceJumpFlag;
extern bool RightMoveState;
extern bool LeftMoveState;
extern bool UpMoveState;
extern bool CharacterAMoveState;

//角色输入相关
void CharacterInput(void);
//角色动作相关
void CharacterAnimation(void);

#endif