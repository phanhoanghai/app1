#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "data/employeemodel.h"
#include <mqueue.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    EmployeeModel model;
    model.addEmployee(Employee("Phan Hoang Hai", "123"));
    model.addEmployee(Employee("Phan Hoang Hai", "123"));
    model.addEmployee(Employee("Phan Hoang Hai", "123"));
    model.addEmployee(Employee("Phan Hoang Hai", "123"));

    QQmlApplicationEngine engine;
    QQmlContext* ctxt = engine.rootContext();
    ctxt->setContextProperty("myModel", &model);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
