//=============================================================================
//
// サウンド処理 [XAudio2.h]
//
//=============================================================================
#ifndef _XAUDIO2_H_
#define _XAUDIO2_H_

#include <xaudio2.h>

// サウンドファイル
typedef enum
{
	SOUND_LABEL_BGM000,		// TitleBGM
	SOUND_LABEL_BGM001,		// GameOverBGM
	SOUND_LABEL_BGM002,		// GameBGM
	SOUND_LABEL_BGM003,		// StageClearBGM
	SOUND_LABEL_SE000,			// サンプルSE Coin
	SOUND_LABEL_SE001,			// サンプルSE Explosion
	SOUND_LABEL_SE002,			// サンプルSE GameOver
	SOUND_LABEL_SE003,			// サンプルSE Hit	
	SOUND_LABEL_SE004,			// サンプルSE Jump		
	SOUND_LABEL_SE005,			// サンプルSE Laser
	SOUND_LABEL_SE006,			// サンプルSE PowerUp	
	SOUND_LABEL_SE007,			// サンプルSE Shot	
	SOUND_LABEL_MAX,
} SOUND_LABEL;

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT InitSound(void);
void UninitSound(void);
void PlaySound(SOUND_LABEL label);
void StopSound(SOUND_LABEL label);
void PauseSound(SOUND_LABEL label);
#endif
