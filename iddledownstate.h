#ifndef IDDLEDOWNSTATE_H
#define IDDLEDOWNSTATE_H

#include "state.h"
#include <QDebug>
#include <memory>
#include <QVector>
#include <QVector2D>

template<typename Entity>
class IddleDownState : public State<Entity>
{
public:
    IddleDownState();
    void execute (Entity*) override;
    void enter(Entity*) override;
    void exit(Entity*) override;

private:

};


#endif // IDDLEDOWNSTATE_H
