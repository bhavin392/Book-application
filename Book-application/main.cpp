#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "book_application.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    Book_Application bookApp;

    engine.rootContext()->setContextProperty("bookApp", &bookApp);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
