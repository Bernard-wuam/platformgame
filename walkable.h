#ifndef WALKABLE_H
#define WALKABLE_H
#include <QVector2D>
#include <QVector>
#include <memory>
#include <QDebug>

class IsFree{

public:
    static std::unique_ptr<IsFree> getInstance(){
        return std::unique_ptr<IsFree>(new IsFree);
    }
    bool contains(const QVector2D& a) const{
       // qInfo() << "contains ==>" << a << " " << m_obstable.contains(a);
        return m_obstable.contains(a);
    }
private:
    QVector<QVector2D> m_obstable{
        {64,48},{64,64},
        {92,60},{96,60},{100,60},{104,60},
        {112,80},{128,80},{144,80},{160,80},
        {172,76},{176,76},{180,76},
        {184, 64},{200,64},{216,64},{232, 80},{228, 76},
        {104, 72},{120, 72},{136, 72},{152, 72},
        {152, 48},{136, 48},{120, 48},{104, 48},
        {184,44},
        {164, 60},
        {180,64},{196,64},
        {200,44},
        {72,60},{76,60},{80,60},{84,60},
        {72,64},
        {56,44},{60,44},{64,44},{68,44},{72,44},
        {68,48},{72,48},{76,48},{80,48},{84,48},{76,44},{80,44},{84,44},
        {72,68},{72,72},{56,60},{56,64},{56,68},{56,72},{72,40},{72,36},{72,32},
        /*tree*/ {56,28},{60,28},{64,28},{68,28},
        {212,76},{212,72},{212,68},{212,64},{228,72},{228,68},{228,64},
        {120,28},{124,28},{128,28},{132,28},{136,28},{140,28},{144,28},{148,28},
        {116,28},{112,28},{108,28},{120,32},{120,36},{120,40},
        {136,32},{136,36},{136,40},
        {88,108},{88,104},{88,100},{88,96},{88,92},{88,88},{88,84},{88,80}

    };

    IsFree() = default;
    IsFree(const IsFree& others) = default;
    const IsFree& operator=(const IsFree& others) = delete;
};


#endif // WALKABLE_H
