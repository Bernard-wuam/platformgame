#include "movingleftstate.h"
#include "movingrightstate.h"

template<typename Entity>
MovingLeftState<Entity>::MovingLeftState()
{

}

template<typename Entity>
void MovingLeftState<Entity>::execute(Entity *actor)
{

    if(actor->hasArrived() > 0){
        auto newPos = actor->position() + actor->currentDirectionVector() * 4;
        if(!IsFree::getInstance ()->contains(newPos)){
            actor->setPosition(newPos);
        }
        actor->setFrame(m_animationFrames[State<Entity>::m_animationframeIndex]);
        qInfo() << State<Entity>::m_animationframeIndex << "==> this is the animation frame index";
        State<Entity>::m_animationframeIndex++;
        int hasArrived = actor->hasArrived() - 4;
        actor->setHasArrived(hasArrived);
        if(State<Entity>::m_animationframeIndex > m_animationFrames.length() - 1) State<Entity>::m_animationframeIndex = 0;
    }

}

template<typename Entity>
void MovingLeftState<Entity>::enter(Entity *actor)
{

}

template<typename Entity>
void MovingLeftState<Entity>::exit(Entity *actor)
{

}

