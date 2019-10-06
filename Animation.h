#ifndef _ANIMATION_H_
#define _ANIMATION_H_
//全局变量
extern int ItemFeedbackTimer;
extern bool ItemDisState[1000];
extern bool DoorDisState[1000];
extern int DoorAnimationSpeed;

//原型函数
//AnimationManagement//纴E姘丒珿em和ItemFeedBack等
void AnimationManagement(void);
//DoorAnimation
void DoorAnimation();


#endif
