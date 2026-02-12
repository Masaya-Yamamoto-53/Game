#pragma once
#include "KeyboardInput.h"
#include "MouseInput.h"

class InputDeviceHub {
private:
    // キーボード入力管理クラス
    KeyboardInput m_keyboard;
    // マウス入力管理クラス
    MouseInput m_mouse;

public:
    // シングルトンとして利用するための取得関数
    static InputDeviceHub& instance();
    // 毎フレーム呼び出し、全ての入力デバイスを更新する
    void update();
    // 指定したキーが押された瞬間かどうかを判定
    bool isKeyTriggered(int keyIndex) const;
    // 指定したキーの入力継続時間を取得
    int getKeyHoldFrames(int keyIndex) const;
    // 指定したマウスボタンが押された瞬間かどうかを判定
    bool isMouseTriggered(int button) const;
    // 指定したマウスボタンが押されているかどうかを判定
    bool isMousePressed(int button) const;
    //  指定したマウスボタンの入力継続時間を取得
    int getMouseHoldFrames(int button) const;
    // マウスポインタのX座標を取得
    int getMouseX() const;
    // マウスポインタのY座標を取得
    int getMouseY() const;
    // マウスホイールの回転量を取得
    int getMouseWheelRot() const;

private:
    //コンストラクタをprivateにしてシングルトン化
    InputDeviceHub();

};