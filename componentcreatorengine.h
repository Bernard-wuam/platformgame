#ifndef COMPONENTCREATORENGINE_H
#define COMPONENTCREATORENGINE_H

#include <QObject>
#include <QQmlApplicationEngine>
#include "filemonitoringclass.h"


class ComponentCreatorEngine : public QQmlApplicationEngine
{
    Q_OBJECT

  public:
    explicit ComponentCreatorEngine(QObject *parent = nullptr);
    Q_INVOKABLE void clearCache();
  signals:
    void reloadUI();
  private:
    FileMonitoringClass* m_filemonitoringclass;
};

#endif // COMPONENTCREATORENGINE_H

