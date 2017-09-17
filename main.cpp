#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "data/data.h"
#include "controller/controllermanager.h"
#include "controller/settingsmanager.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Data *data = new Data(&app);
    engine.rootContext()->setContextProperty("MyData", data);

    SettingsManager(data).load();

    ControllerManager *controller = new ControllerManager(&app);
    controller->setData(data);
    engine.rootContext()->setContextProperty("MyController", controller);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
