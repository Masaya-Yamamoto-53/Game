#include "DxLib.h"
#include "InputDeviceHub.h"

InputDeviceHub& InputDeviceHub::instance() {
    static InputDeviceHub instance;
    return instance;
}

InputDeviceHub::InputDeviceHub()
    : m_keyboard()  // KeyboardInput‚Ì‰Šú‰»
    , m_mouse()     // MouseInput‚Ì‰Šú‰»
{
}

void InputDeviceHub::update() {
    m_keyboard.update();
    m_mouse.update();
}

bool InputDeviceHub::isKeyTriggered(int keyIndex) const {
    return m_keyboard.isTriggered(keyIndex);
}

int InputDeviceHub::getKeyHoldFrames(int keyIndex) const {
    return m_keyboard.getHoldFrames(keyIndex);
}

bool InputDeviceHub::isMouseTriggered(int button) const {
    return m_mouse.isTriggered(button);
}

bool InputDeviceHub::isMousePressed(int button) const {
    return m_mouse.isPressed(button);
}

int InputDeviceHub::getMouseHoldFrames(int button) const {
    return m_mouse.getHoldFrames(button);
}

int InputDeviceHub::getMouseX() const {
    return m_mouse.getX();
}

int InputDeviceHub::getMouseY() const {
    return m_mouse.getY();
}

int InputDeviceHub::getMouseWheelRot() const {
    return m_mouse.getWheelRot();
}
