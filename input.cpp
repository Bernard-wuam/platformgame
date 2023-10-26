#include "input.h"

Input::Input(QObject *parent)
    : QObject{parent}
{

}

void Input::addKey(const InputKeys &key)
{
    if(!m_inputList.contains(key)) {
        m_inputList.prepend (key);

        const int index = static_cast<int>(key);
        const int up = static_cast<int>(InputKeys::UpKey);
        const int down = static_cast<int>(InputKeys::DownKey);
        const int right = static_cast<int>(InputKeys::RightKey);
        const int left = static_cast<int>(InputKeys::LeftKey);

        switch (index) {
        case up: m_inputList[1] = InputKeys::IddleUp;
            break;
        case down: m_inputList[1] = InputKeys::IddleDown;
            break;
        case right: m_inputList[1] = InputKeys::IddleRight;
            break;
        case left: m_inputList[1] = InputKeys::IddleLeft;
            break;
        default:
            break;
        }
    }

}



void Input::removeKey(const InputKeys &key)
{
    if(m_inputList.contains(key)) m_inputList.removeAll(key);
}

Input::InputKeys Input::getDirection() const
{
    return m_inputList[0];
}

