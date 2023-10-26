#include "iddleupstate.h"


template<typename Entity>
IddleUpState<Entity>::IddleUpState()
{

}

template<typename Entity>
void IddleUpState<Entity>::execute(Entity *actor)
{
    actor->setFrame(7);
    actor->setHasArrived(0);
}

template<typename Entity>
void IddleUpState<Entity>::enter(Entity *actor)
{

}

template<typename Entity>
void IddleUpState<Entity>::exit(Entity *actor)
{

}
