#include "gameloop.h"

GameLoop::GameLoop(QObject *parent)
    : QObject{parent}
{
    m_previousTime = std::chrono::steady_clock::now ();
}

void GameLoop::ticks()
{
    m_previousTime = m_currentTime;
}

double GameLoop::deltaTime()
{
    m_currentTime = std::chrono::steady_clock::now ();
    return (m_currentTime - m_previousTime).count();
}
