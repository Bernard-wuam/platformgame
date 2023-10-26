#ifndef TESTINGVEC_H
#define TESTINGVEC_H
#include <QObject>
#include <QDebug>
#include <QVector2D>
#include <QQmlEngine>

class TestingVec : public QObject
{
    QML_ELEMENT
    QML_SINGLETON
    Q_OBJECT
public:
    TestingVec(QObject* parent = nullptr);
    Q_INVOKABLE float distanceTo(const QVector2D& inp) const;
    Q_INVOKABLE QVector2D normalize(const QVector2D& point1,const QVector2D& point2) const;
    Q_INVOKABLE float distanceToLine(QVector2D point1,QVector2D point2,QVector2D dir) const;
};

#endif // TESTINGVEC_H
