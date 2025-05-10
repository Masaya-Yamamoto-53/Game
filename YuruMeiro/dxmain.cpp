#include "DxLib.h"

int WINAPI WinMain(
      HINSTANCE hInstance
    , HINSTANCE hPrevInstance
    , LPSTR lpCmdLine
    , int nCmdShow
    )
{
    // ＤＸライブラリ初期化処理
    if (DxLib_Init() == -1) return -1;

    // 裏画面に描画する
	SetDrawScreen(DX_SCREEN_BACK);

    // メインループ
    while (ProcessMessage() == 0) {
        // Escapeキーが押されたらループを抜ける
        if (CheckHitKey(KEY_INPUT_ESCAPE)) {
            break;
        }

		// 画面をクリアする
		ClearDrawScreen();

		// 画面を更新する
		ScreenFlip();
	}

    // ＤＸライブラリ使用の終了処理
    DxLib_End();

    return 0;
}