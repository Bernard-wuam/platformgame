#ifndef IDDLEUPSTATE_H
#define IDDLEUPSTATE_H

#include "state.h"
#include <QDebug>
#include <memory>
#include <QVector>
#include <QVector2D>

template<typename Entity>
class IddleUpState : public State<Entity>
{
public:
    IddleUpState();
    void execute (Entity*) override;
    void enter(Entity*) override;
    void exit(Entity*) override;

private:

};

#endif // IDDLEUPSTATE_H
