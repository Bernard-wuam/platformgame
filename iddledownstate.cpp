#include "iddledownstate.h"


template<typename Entity>
IddleDownState<Entity>::IddleDownState()
{

}

template<typename Entity>
void IddleDownState<Entity>::execute(Entity *actor)
{
    actor->setFrame(1);
    actor->setHasArrived(0);
}

template<typename Entity>
void IddleDownState<Entity>::enter(Entity *actor)
{

}

template<typename Entity>
void IddleDownState<Entity>::exit(Entity *actor)
{

}
