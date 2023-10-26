#include "componentcreatorengine.h"

ComponentCreatorEngine::ComponentCreatorEngine(QObject *parent)
  : QQmlApplicationEngine{parent}
{
 m_filemonitoringclass = new  FileMonitoringClass("C:/Users/USER/source/QtRepos/","keepMe",this);
 QObject::connect (m_filemonitoringclass,&FileMonitoringClass::reloadUI,this,&ComponentCreatorEngine::reloadUI);
}

void ComponentCreatorEngine::clearCache()
{
  this->clearComponentCache ();
}
