#ifndef MOVINGDOWNSTATE_H
#define MOVINGDOWNSTATE_H
#include "state.h"
#include <QDebug>
#include <memory>
#include <QVector>
#include <QVector2D>

template<typename Entity>
class MovingDownState : public State<Entity>
{
public:
    MovingDownState();
    void execute (Entity*) override;
    void enter(Entity*) override;
    void exit(Entity*) override;

private:
    QVector<int> m_animationFrames{
        1,2,1,0
    };

};

#endif // MOVINGDOWNSTATE_H
