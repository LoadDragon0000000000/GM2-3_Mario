#include "DxLib.h"
#include <stdlib.h>


/***********************************************
 * �񋓑̂̐錾
 ***********************************************/
typedef enum GAME_MODE{
 GAME_TITLE = 0,
 GAME_INIT,
 GAME_MAIN,
 GAME_OVER,
 GAME_CLEAR,
 GAME_END,
 GAME_HELP,
};
/***********************************************
 * �ϐ��̐錾
 ***********************************************/
int	g_OldKey;				// �O��̓��̓L�[
int	g_NowKey;				// ����̓��̓L�[
int	g_KeyFlg;				// ���̓L�[���


int g_Title;                //�^�C�g����ʂ̉摜

int g_GameState = GAME_TITLE; // �Q�[�����[�h
/***********************************************
 * �֐��̃v���g�^�C�v�錾
 ***********************************************/
void GameInit(void);		//�Q�[������������
void GameMain(void);		//�Q�[�����C������


void DrawGameTitle(void);	//�Q�[���^�C�g������
void DrawHelp(void);        //�Q�[���w���v����
void DrawEnd(void);			//�Q�[���G���h����
void DrawGameClear(void); //�Q�[���N���A����
void DrawGameOver(void); //�Q�[���I�[�o�[����
/***********************************************
 * �v���O�����̊J�n
 ***********************************************/
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, 
LPSTR lpCmdLine, int nCmdShow )
{
	SetMainWindowText( "�}���I�I�f�b�Z�C" ); // �^�C�g����ݒ�

	ChangeWindowMode(TRUE); // �E�B���h�E���[�h�ŋN��
	if ( DxLib_Init() == -1 ) return -1; // DX ���C�u�����̏���������

		SetDrawScreen( DX_SCREEN_BACK ); // �`����ʂ𗠂ɂ���

	
		// �Q�[�����[�v
	while ( ProcessMessage() == 0 && g_GameState != 99 && !(g_KeyFlg & PAD_INPUT_START)){
			 // ���̓L�[�擾
			 g_OldKey = g_NowKey;
			 g_NowKey = GetJoypadInputState( DX_INPUT_KEY_PAD1 );
			 g_KeyFlg = g_NowKey & ~g_OldKey;

			 ClearDrawScreen(); // ��ʂ̏�����

	 switch (g_GameState){

		 case 0:
			 DrawGameTitle(); //�Q�[���^�C�g���`�揈��
			 break;
		case 1:
			 GameInit(); //�Q�[����������
			 break;
		 case 2:
			 GameMain(); //�Q�[�����C���`�揈��
			 break;
		 case 3:
			 DrawGameOver(); //�Q�[���I�[�o�[�`�揈��
			 break;
		 case 4:
			 DrawGameClear(); //�Q�[��CLEAR����
			 break;
		 case 5:
			 DrawEnd(); //�Q�[���G���h�`�揈
			 break;
		 case 6:
			 DrawHelp();//�Q�[���w���v
			 break;
			 }
	 ScreenFlip(); // ����ʂ̓��e��\��ʂɔ��f
			 }
	 DxLib_End(); // DX ���C�u�����g�p�̏I������

	 return 0; // �\�t�g�̏I��
	}

/***********************************************
 * �Q�[���^�C�g���\���i���j���[��ʁj
 ***********************************************/
void DrawGameTitle(void)
{

}
/***********************************************
 * �Q�[����������
 ***********************************************/
void GameInit(void)
{

}
/***********************************************
 * �Q�[���w���v�`�揈��
 ***********************************************/
void DrawHelp(void)
{

}
/***********************************************
 * �Q�[���G���h�`�揈��
 ***********************************************/
void DrawEnd(void)
{

}
/***********************************************
 * �Q�[�����C��
 ***********************************************/
void GameMain(void)
{

}
/************************************************
*�Q�[���N���A�����@
**********************************************/
void DrawGameClear(void)
{

}
/***********************************************
 * �Q�[���I�[�o�[��ʏ���
 ***********************************************/
void DrawGameOver(void)
{

}