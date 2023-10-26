#ifndef FILEMONITORINGCLASS_H
#define FILEMONITORINGCLASS_H

#include <QObject>
#include <QCoreApplication>
#include <iostream>
#include <QDir>
#include <QDebug>
#include <QFileSystemWatcher>
#include <QTimer>
#include <thread>


class FileMonitoringClass : public QObject
{
    Q_OBJECT

    QString fileRoot = "C:/Users/USER/source/QtRepos/";
    QString fileName;
    QFileSystemWatcher filewatcher;

    void beginWatchFile(const QString&);

  public:
    explicit FileMonitoringClass(const QString&, const QString& ,QObject *parent = nullptr);

  public slots:
    void onFileChanged(const QString&);
    void onDirectoryChanged(const QString&);

    signals:
    void reloadUI();
};
#endif // FILEMONITORINGCLASS_H