#ifndef MOVINGRIGHTSTATE_H
#define MOVINGRIGHTSTATE_H

#include <QDebug>
#include <memory>
#include <QVector>
#include <QVector2D>
#include "state.h"
#include "walkable.h"

template<typename Entity>
class MovingRightState : public State<Entity>
{
public:
    MovingRightState();

    void execute (Entity*) override;
    void enter(Entity*) override;
    void exit(Entity*) override;   

private:
    QVector<int> m_animationFrames{
        4,5,4,3
    };

};

#endif // MOVINGRIGHTSTATE_H
