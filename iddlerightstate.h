#ifndef IDDLERIGHTSTATE_H
#define IDDLERIGHTSTATE_H

#include "state.h"
#include <QDebug>
#include <memory>
#include <QVector>
#include <QVector2D>

template<typename Entity>
class IddleRightState : public State<Entity>
{
public:
    IddleRightState();
    void execute (Entity*) override;
    void enter(Entity*) override;
    void exit(Entity*) override;

private:

};

#endif // IDDLERIGHTSTATE_H
