#include "movingupstate.h"
#include "walkable.h"

template<typename Entity>
MovingUpState<Entity>::MovingUpState()
{

}

template<typename Entity>
void MovingUpState<Entity>::execute(Entity *actor)
{
    if(actor->hasArrived() > 0){
        qInfo() << actor->currentDirectionVector() ;
        auto newPos = actor->position() + actor->currentDirectionVector() * 4;
        if(!IsFree::getInstance ()->contains(newPos)){
            actor->setPosition(newPos);
        }

        actor->setFrame(m_animationFrames[State<Entity>::m_animationframeIndex]);

        State<Entity>::m_animationframeIndex++;
        int hasArrived = actor->hasArrived() - 4;
        actor->setHasArrived(hasArrived);
        if(State<Entity>::m_animationframeIndex > m_animationFrames.length() - 1) State<Entity>::m_animationframeIndex = 0;
    }

}

template<typename Entity>
void MovingUpState<Entity>::enter(Entity *actor)
{

}

template<typename Entity>
void MovingUpState<Entity>::exit(Entity *actor)
{

}














