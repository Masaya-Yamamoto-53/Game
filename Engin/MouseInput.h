#pragma once
#include "DxLib.h"

class MouseInput {
public:
    MouseInput();

    void update();

    bool isTriggered(int button) const;
    bool isPressed(int button) const;
    int  getHoldFrames(int button) const;

    int getX() const { return m_x; }
    int getY() const { return m_y; }
    int getWheelRot() const { return m_wheelRot; }

private:
    int m_prevButtons;
    int m_currButtons;
    int m_holdFrames[3];  // 左・右・中ボタン

    int m_x, m_y;
    int m_wheelRot;
};

