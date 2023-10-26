#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "componentcreatorengine.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
  QGuiApplication app(argc, argv);
  qputenv ("MAIN_QML","../keepMe/main.qml");

  //QQmlApplicationEngine engine;
  ComponentCreatorEngine engine;

  engine.rootContext ()->setContextProperty("QQmlEngine",&engine);
  engine.addImportPath ("../keepMe/");
  const QUrl url(qgetenv("MAIN_QML"));
  QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                   &app, [url](QObject *obj, const QUrl &objUrl) {
    if (!obj && url == objUrl)
      QCoreApplication::exit(-1);
  }, Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}