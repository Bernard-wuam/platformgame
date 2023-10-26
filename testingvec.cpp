#include "testingvec.h"


TestingVec::TestingVec(QObject *parent):QObject(parent)
{

}

float TestingVec::distanceTo(const QVector2D &inp) const
{
    QVector2D origin(0,0);
    return origin.distanceToPoint (inp);

}

QVector2D TestingVec::normalize(const QVector2D &point1, const QVector2D &point2) const
{
    auto newPoint = point2 - point1;
    return newPoint.normalized ();
}

float TestingVec::distanceToLine(QVector2D point1, QVector2D point2, QVector2D dir) const
{
    qInfo() << point2.distanceToLine (point1,dir);
    return point2.distanceToLine (point1,dir);
}


