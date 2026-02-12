#include "MouseInput.h"

MouseInput::MouseInput()
    : m_prevButtons(0), m_currButtons(0),
      m_x(0), m_y(0), m_wheelRot(0)
{
    for (int i = 0; i < 3; i++) {
        m_holdFrames[i] = 0;
    }
}

void MouseInput::update() {
    m_prevButtons = m_currButtons;
    m_currButtons = GetMouseInput();

    GetMousePoint(&m_x, &m_y);
    m_wheelRot = GetMouseWheelRotVol();

    for (int i = 0; i < 3; i++) {
        int mask = (i == 0 ? MOUSE_INPUT_LEFT :
                   (i == 1 ? MOUSE_INPUT_RIGHT : MOUSE_INPUT_MIDDLE));

        if (m_currButtons & mask) {
            m_holdFrames[i]++;
        } else {
            m_holdFrames[i] = 0;
        }
    }
}

bool MouseInput::isTriggered(int button) const {
    return (m_currButtons & button) && !(m_prevButtons & button);
}

bool MouseInput::isPressed(int button) const {
    return (m_currButtons & button);
}

int MouseInput::getHoldFrames(int button) const {
    if (button == MOUSE_INPUT_LEFT)   return m_holdFrames[0];
    if (button == MOUSE_INPUT_RIGHT)  return m_holdFrames[1];
    if (button == MOUSE_INPUT_MIDDLE) return m_holdFrames[2];
    return 0;
}
