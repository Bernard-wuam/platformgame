#ifndef UTILS_H
#define UTILS_H

#include <QPoint>

class Utils
{
public:
    Utils();
    static int gridCell(int);

    static int calcDistance(QPoint,QPoint);
    static QPoint normalVec(const QPoint&,const QPoint&);
};

#endif // UTILS_H
