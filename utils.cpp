#include "utils.h"

Utils::Utils()
{

}

int Utils::gridCell(int c)
{
    return 16 * c;
}

int Utils::calcDistance(QPoint p1, QPoint p2)
{
    auto c = p2 - p1;
    return std::sqrt( (c.x())^2 +(c.y())^2 );
}

QPoint Utils::normalVec(const QPoint & point1, const QPoint &point2)
{
    auto dis = calcDistance (point1,point2);
    auto newPoint = point2 - point1;
    return QPoint(newPoint.x ()/dis, newPoint.y ()/dis);
}


