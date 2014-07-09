#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "appcontroller.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    AppController appController;

    engine.rootContext()->setContextProperty("appController", &appController);
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
