#ifndef SPRITE_H
#define SPRITE_H

#include <QObject>
#include <QQmlEngine>
#include <QPoint>
#include <QHash>
#include <QMap>
#include <QDebug>
#include <QJSValue>
#include <QJSValueList>
#include <memory>
#include <QVector2D>
#include "input.h"
#include "utils.h"
#include "state.h"
#include "movingrightstate.h"
#include "movingrightstate.cpp"
#include "iddlerightstate.h"
#include "iddlerightstate.cpp"
#include "movingleftstate.h"
#include "movingleftstate.cpp"
#include "iddleleftstate.h"
#include "iddleleftstate.cpp"
#include "movingupstate.h"
#include "movingupstate.cpp"
#include "iddleupstate.h"
#include "iddleupstate.cpp"
#include "movingdownstate.h"
#include "movingdownstate.cpp"
#include "iddledownstate.h"
#include "iddledownstate.cpp"



class Sprite : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString resource READ resource WRITE setResource NOTIFY resourceChanged FINAL)
    Q_PROPERTY(int frameSize READ frameSize WRITE setFrameSize NOTIFY frameSizeChanged FINAL)
    Q_PROPERTY(int hframe READ hframe WRITE setHframe NOTIFY hframeChanged FINAL)
    Q_PROPERTY(int vframe READ vframe WRITE setVframe NOTIFY vframeChanged FINAL)
    Q_PROPERTY(QVector2D position READ position WRITE setPosition NOTIFY positionChanged FINAL)
    Q_PROPERTY(int frame READ frame WRITE setFrame NOTIFY frameChanged FINAL)
public:
    explicit Sprite(QObject *parent = nullptr);
    Sprite(QString resource,int frameSize,int hframe,int vframe,
           int frame,int scale,QVector2D position,QObject *parent = nullptr);

    enum  class StateName{
        RightState,
        IddleRightState,
        LeftState,
        IddleLeftState,
        UpState,
        IddleUpState,
        DownState,
        IddleDownState
    };

    QString resource() const;
    void setResource(const QString &newResource);

    int frameSize() const;
    void setFrameSize(int newFrameSize);

    int hframe() const;
    void setHframe(int newHframe);

    int vframe() const;
    void setVframe(int newVframe);

    Q_INVOKABLE QHash<int, QPoint> frameMap();
    Q_INVOKABLE void drawImage(QJSValue ctx);
    Q_INVOKABLE void update(const Input::InputKeys&,double);

    QVector2D position() const;
    void setPosition(QVector2D newPosition);

    int frame() const;
    void setFrame(int newFrame);

    QVector2D setCurrentDirectionVector(Input::InputKeys newCurrentDirectionVector);

    QVector2D currentDirectionVector() const;

    int hasArrived() const;
    void setHasArrived(int newHasArrived);

signals:

    void resourceChanged();

    void frameSizeChanged();

    void hframeChanged();

    void vframeChanged();

    void positionChanged();

    void frameChanged();

private:
    QString m_resource{};   
    int m_frameSize{32};
    int m_hframe{1};
    int m_vframe{1};
    int m_frame{1};
    QHash<int,QPoint> m_frameMap;
    int m_scale{1};
    QVector2D m_position{Utils::gridCell(0),Utils::gridCell(0)};
    std::unique_ptr<State<Sprite>> m_state{new IddleDownState<Sprite>{}};

    //the player's input...
    StateName m_stateName = Sprite::StateName::IddleDownState;
    int m_hasArrived = 0;
    int m_gridLength = 16;
    QVector2D m_currentDirectionVector{QVector2D(1,0)};
    //function that generates the frameMaps
    void generateFrameMap();

};

#endif // SPRITE_H
