#ifndef _PHYSICS_H_
#define _PHYSICS_H_

extern bool GroundState;//默认是没有踩到地面的
extern int GravitySpeed;
extern bool UpMove;
extern bool DownMove;
extern bool LeftMove;
extern bool RightMove;


//GameOver相关
extern bool DeathState;
//重力
void Gravity(void);
//碰撞
void Collision(void);

#endif
