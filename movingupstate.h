#ifndef MOVINGUPSTATE_H
#define MOVINGUPSTATE_H

#include "state.h"
#include <QDebug>
#include <memory>
#include <QVector>
#include <QVector2D>

template<typename Entity>
class MovingUpState : public State<Entity>
{
public:
    MovingUpState();
    void execute (Entity*) override;
    void enter(Entity*) override;
    void exit(Entity*) override;

private:
    QVector<int> m_animationFrames{
        7,8,7,6
    };

};


#endif // MOVINGUPSTATE_H
