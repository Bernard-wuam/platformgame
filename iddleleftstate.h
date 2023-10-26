#ifndef IDDLELEFTSTATE_H
#define IDDLELEFTSTATE_H

#include "state.h"
#include <QDebug>
#include <memory>
#include <QVector>
#include <QVector2D>

template<typename Entity>
class IddleLeftState : public State<Entity>
{
public:
    IddleLeftState();
    void execute (Entity*) override;
    void enter(Entity*) override;
    void exit(Entity*) override;

private:

};

#endif // IDDLELEFTSTATE_H
