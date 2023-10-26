#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <QObject>
#include <QQmlEngine>
#include <chrono>
class GameLoop : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
public:
    explicit GameLoop(QObject *parent = nullptr);
    Q_INVOKABLE void ticks();
    Q_INVOKABLE double deltaTime();
signals:
private:
    std::chrono::time_point<std::chrono::steady_clock,std::chrono::duration<double,std::ratio<1>>> m_previousTime{};
    std::chrono::time_point<std::chrono::steady_clock,std::chrono::duration<double,std::ratio<1>>> m_currentTime{};
};

#endif // GAMELOOP_H
