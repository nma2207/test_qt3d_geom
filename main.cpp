#include <QGuiApplication>
//#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlEngine>
#include "mygeometry.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<MyGeometry>("ModuleName", 1, 0, "MyGeometry");

    QQmlEngine engine;
    const QUrl url(u"qrc:/TestGeometry/main.qml"_qs);
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                     &app, [url](QObject *obj, const QUrl &objUrl) {
//        if (!obj && url == objUrl)
//            QCoreApplication::exit(-1);
//    }, Qt::QueuedConnection);
//    engine.load(url);
     QQuickView view{&engine, nullptr};
     view.setSource(url);
     view.show();

    return app.exec();
}
