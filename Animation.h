#ifndef _ANIMATION_H_
#define _ANIMATION_H_
//ȫ�ֱ���
extern int ItemFeedbackTimer;
extern bool ItemDisState[1000];
extern bool DoorDisState[1000];
extern int DoorAnimationSpeed;

//ԭ�ͺ���
//AnimationManagement//��E氁E�Gem��ItemFeedBack��
void AnimationManagement(void);
//DoorAnimation
void DoorAnimation();


#endif
