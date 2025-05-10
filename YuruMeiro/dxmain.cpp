#include "DxLib.h"

int WINAPI WinMain(
      HINSTANCE hInstance
    , HINSTANCE hPrevInstance
    , LPSTR lpCmdLine
    , int nCmdShow
    )
{
    // �c�w���C�u��������������
    if (DxLib_Init() == -1) return -1;

    // ����ʂɕ`�悷��
	SetDrawScreen(DX_SCREEN_BACK);

    // ���C�����[�v
    while (ProcessMessage() == 0) {
        // Escape�L�[�������ꂽ�烋�[�v�𔲂���
        if (CheckHitKey(KEY_INPUT_ESCAPE)) {
            break;
        }

		// ��ʂ��N���A����
		ClearDrawScreen();

		// ��ʂ��X�V����
		ScreenFlip();
	}

    // �c�w���C�u�����g�p�̏I������
    DxLib_End();

    return 0;
}