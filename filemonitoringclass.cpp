#include "filemonitoringclass.h"

FileMonitoringClass::FileMonitoringClass(const QString& fileRoot,const QString& fileName ,QObject* parent):
  fileRoot{fileRoot},fileName{fileName},QObject{parent}{
  beginWatchFile (fileRoot + fileName);
//  m_time.setInterval (10);
//  m_time.setSingleShot (true);
 // m_time.start ();
  QObject::connect (&filewatcher, &QFileSystemWatcher::fileChanged,this,&FileMonitoringClass::onFileChanged);
  QObject::connect (&filewatcher, &QFileSystemWatcher::fileChanged,this,&FileMonitoringClass::reloadUI);
  QObject::connect (&filewatcher, &QFileSystemWatcher::directoryChanged,this,&FileMonitoringClass::onDirectoryChanged);
  //QObject::connect (&m_time, &QTimer::timeout,this, &FileMonitoringClass::reloadUI);

  //for testing purpose, remove after testing completed......
  QObject::connect (&filewatcher, &QFileSystemWatcher::fileChanged,this,[](const QString& fileName){ qInfo() << "file changed..." << fileName; });
}

//this function add the various file in a directory to the file watcher recurssively.
void FileMonitoringClass::beginWatchFile(const QString& fileName){

  QDir directory(fileName);

  if(!directory.exists ()){
    qInfo() << "This Directory " << directory << "does not exist";
    return;
  }

  QStringList qmlFileList = directory.entryList (QStringList() << "*.qml");
  if(qmlFileList.count () <= 0)
  {
    qInfo() << "no qml file found in this directory";
    return;
  }

  for(const auto& m: qmlFileList){
    auto u = directory.absoluteFilePath (m);
    qInfo() << u;
    filewatcher.addPath (u);
   // m_time.start ();
  }


  auto qmfileDirectory = directory.entryList (QStringList() << "*",QDir::Dirs | QDir::NoDot | QDir::NoDotAndDotDot | QDir::NoSymLinks);
  for( auto& m:  qmfileDirectory)
    beginWatchFile (directory.absolutePath () + "/" + m);

}

void FileMonitoringClass::onFileChanged(const QString& file)
{
  QFile f(file);
  std::this_thread::sleep_for(std::chrono::microseconds(1));
  if(!f.exists ())
  {
    qInfo() << "file does not exist..." << file;
   std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }
  filewatcher.addPath (file);
}
void FileMonitoringClass::onDirectoryChanged(const QString& directory)
{
  Q_UNUSED(directory);
  filewatcher.removePaths (filewatcher.files ());
  beginWatchFile (fileRoot + fileName);
}
