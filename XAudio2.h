//=============================================================================
//
// �T�E���h���� [XAudio2.h]
//
//=============================================================================
#ifndef _XAUDIO2_H_
#define _XAUDIO2_H_

#include <xaudio2.h>

// �T�E���h�t�@�C��
typedef enum
{
	SOUND_LABEL_BGM000,		// TitleBGM
	SOUND_LABEL_BGM001,		// GameOverBGM
	SOUND_LABEL_BGM002,		// GameBGM
	SOUND_LABEL_BGM003,		// StageClearBGM
	SOUND_LABEL_SE000,			// �T���v��SE Coin
	SOUND_LABEL_SE001,			// �T���v��SE Explosion
	SOUND_LABEL_SE002,			// �T���v��SE GameOver
	SOUND_LABEL_SE003,			// �T���v��SE Hit	
	SOUND_LABEL_SE004,			// �T���v��SE Jump		
	SOUND_LABEL_SE005,			// �T���v��SE Laser
	SOUND_LABEL_SE006,			// �T���v��SE PowerUp	
	SOUND_LABEL_SE007,			// �T���v��SE Shot	
	SOUND_LABEL_MAX,
} SOUND_LABEL;

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitSound(void);
void UninitSound(void);
void PlaySound(SOUND_LABEL label);
void StopSound(SOUND_LABEL label);
void PauseSound(SOUND_LABEL label);
#endif
