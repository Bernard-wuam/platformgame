#include "iddlerightstate.h"


template<typename Entity>
IddleRightState<Entity>::IddleRightState()
{

}

template<typename Entity>
void IddleRightState<Entity>::execute(Entity *actor)
{
    actor->setFrame(4);
    actor->setHasArrived(0);
}

template<typename Entity>
void IddleRightState<Entity>::enter(Entity *actor)
{

}

template<typename Entity>
void IddleRightState<Entity>::exit(Entity *actor)
{

}

