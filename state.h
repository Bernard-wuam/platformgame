#ifndef STATE_H
#define STATE_H

template<typename Entity>
class State{
protected:
    int m_animationframeIndex = 0;
public:
    virtual void execute(Entity*) = 0;
    virtual void enter(Entity*) = 0;
    virtual void exit(Entity*) = 0;
};

#endif // STATE_H
