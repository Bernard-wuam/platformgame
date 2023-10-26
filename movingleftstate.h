#ifndef MOVINGLEFTSTATE_H
#define MOVINGLEFTSTATE_H

#include "state.h"
#include <QDebug>
#include <memory>
#include <QVector>
#include <QVector2D>

template<typename Entity>
class MovingLeftState : public State<Entity>
{
public:
    MovingLeftState();
    void execute (Entity*) override;
    void enter(Entity*) override;
    void exit(Entity*) override;

private:
    QVector<int> m_animationFrames{
        10,11,10,9
    };

};


#endif // MOVINGLEFTSTATE_H
