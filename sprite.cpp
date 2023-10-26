#include "sprite.h"

Sprite::Sprite(QObject *parent)
    : QObject{parent}
{
    generateFrameMap ();
    m_currentDirectionVector = QVector2D{1,0};
}

Sprite::Sprite(QString resource,int frameSize, int hframe,int vframe,  int frame, int scale,QVector2D position, QObject *parent):
    m_resource{resource},m_frameSize{frameSize},m_vframe{vframe},
    m_hframe{hframe},m_frame{frame},m_scale{scale},m_position{position},
    QObject{parent}
{
    generateFrameMap ();
}

QString Sprite::resource() const
{
    return m_resource;
}

void Sprite::setResource(const QString &newResource)
{
    m_resource = newResource;
    emit resourceChanged();
}

int Sprite::frameSize() const
{
    return m_frameSize;
}

void Sprite::setFrameSize(int newFrameSize)
{
    if (m_frameSize == newFrameSize)
        return;
    m_frameSize = newFrameSize;
    emit frameSizeChanged();
}

int Sprite::hframe() const
{
    return m_hframe;
}

void Sprite::setHframe(int newHframe)
{
    if (m_hframe == newHframe)
        return;
    m_hframe = newHframe;
    emit hframeChanged();
}

int Sprite::vframe() const
{
    return m_vframe;
}

void Sprite::setVframe(int newVframe)
{
    if (m_vframe == newVframe)
        return;
    m_vframe = newVframe;
    emit vframeChanged();
}

QHash<int, QPoint> Sprite::frameMap()
{
    generateFrameMap ();
    return m_frameMap;
}

void Sprite::drawImage(QJSValue ctx)
{
    if(m_frameMap.contains(m_frame)){
        qInfo() << " the current pos ==> " << m_position;
        // qInfo() << m_frame << " this is the frame from the drawImage function...";
        auto frame_h = m_frameMap.value(m_frame).x();
        auto frame_v = m_frameMap.value(m_frame).y();
        QJSValueList arg;
        arg << m_resource << frame_h << frame_v << m_frameSize <<
            m_frameSize << m_position.x() << m_position.y() <<
            m_frameSize*m_scale << m_frameSize*m_scale;
        ctx.call (arg);
    }
}

void Sprite::update(const Input::InputKeys & key,double deltaTime)
{
    if(m_hasArrived <= 0){
        setCurrentDirectionVector(key);
    }
    if(m_state){
        m_state->execute(this);
    }
}

QVector2D Sprite::position() const
{
    return m_position;
}

void Sprite::setPosition(QVector2D newPosition)
{
    m_position = newPosition;
    emit positionChanged();

}

int Sprite::frame() const
{
    return m_frame;
}

void Sprite::setFrame(int newFrame)
{
    m_frame = newFrame;
    emit frameChanged();
}

QVector2D Sprite::setCurrentDirectionVector(Input::InputKeys key)
{
    const int index = static_cast<int>(key);
    const int up = static_cast<int>(Input::InputKeys::UpKey);
    const int down = static_cast<int>(Input::InputKeys::DownKey);
    const int right = static_cast<int>(Input::InputKeys::RightKey);
    const int left = static_cast<int>(Input::InputKeys::LeftKey);
    const int iddleRight = static_cast<int>(Input::InputKeys::IddleRight);
    const int iddleLeft = static_cast<int>(Input::InputKeys::IddleLeft);
    const int iddleUp = static_cast<int>(Input::InputKeys::IddleUp);
    const int iddleDown = static_cast<int>(Input::InputKeys::IddleDown);


    switch (index) {
    case right:{
        m_hasArrived = 16;
        if(m_stateName != StateName::RightState){
            m_stateName = StateName::RightState;
            m_state.reset(new MovingRightState<Sprite>{});
        }
        m_currentDirectionVector = QVector2D(1,0);
        return QVector2D(1,0);
    }
    case left: {
        m_hasArrived = 16;
        if(m_stateName != StateName::LeftState ) {
            m_stateName = StateName::LeftState;
            m_state.reset(new MovingLeftState<Sprite>{});
        }
        m_currentDirectionVector = QVector2D(-1,0);
        return QVector2D(-1,0);
    }
    case iddleRight:{
        if(m_stateName != StateName::IddleRightState)
        {
            m_stateName = StateName::IddleRightState;
            m_state.reset(new IddleRightState<Sprite>());
        }
        return QVector2D(1,0);
    }

    case iddleLeft:{
        if(m_stateName != StateName::IddleLeftState)
        {
            m_stateName = StateName::IddleLeftState;
            m_state.reset(new IddleLeftState<Sprite>());
        }
        return QVector2D(-1,0);
    }

    case up: {
        m_hasArrived = 16;
        if(m_stateName != StateName::UpState ) {
            m_stateName = StateName::UpState;
            m_state.reset(new MovingUpState<Sprite>{});
        }
        m_currentDirectionVector = QVector2D(0,-1);
        return QVector2D(0,-1);
    }

    case iddleUp:{
        if(m_stateName != StateName::IddleUpState)
        {
            m_stateName = StateName::IddleUpState;
            m_state.reset(new IddleUpState<Sprite>());
        }
        return QVector2D(1,0);
    }

    case down: {
        m_hasArrived = 16;
        if(m_stateName != StateName::DownState) {
            m_stateName = StateName::DownState;
            m_state.reset(new MovingDownState<Sprite>{});
        }
        m_currentDirectionVector = QVector2D(0,1);
        return QVector2D(0,1);
    }

    case iddleDown:{
        if(m_stateName != StateName::IddleDownState)
        {
            m_stateName = StateName::IddleDownState;
            m_state.reset(new IddleDownState<Sprite>());
        }
        return QVector2D(1,0);
    }

    default:
        return QVector2D();
    }

}

QVector2D Sprite::currentDirectionVector() const
{
    return m_currentDirectionVector;
}

int Sprite::hasArrived() const
{
    return m_hasArrived;
}

void Sprite::setHasArrived(int newHasArrived)
{
    m_hasArrived = newHasArrived;
}

void Sprite::generateFrameMap()
{
    int frameCount = 0;
    for(int i = 0; i < m_vframe; i++){
        for(int j = 0; j < m_hframe; j++){
            m_frameMap.insert(frameCount,QPoint(j*m_frameSize,i*m_frameSize));
            frameCount++;
        }
    }
}
