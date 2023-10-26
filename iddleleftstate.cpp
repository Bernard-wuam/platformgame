#include "iddleleftstate.h"

template<typename Entity>
IddleLeftState<Entity>::IddleLeftState()
{

}

template<typename Entity>
void IddleLeftState<Entity>::execute(Entity *actor)
{
    actor->setFrame(10);
    actor->setHasArrived(0);
}

template<typename Entity>
void IddleLeftState<Entity>::enter(Entity *actor)
{

}

template<typename Entity>
void IddleLeftState<Entity>::exit(Entity *actor)
{

}

