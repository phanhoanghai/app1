#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "data/employeemodel.h"
#include <mqueue.h>
#include <serverlistenner/readsharemem.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    ReadShareMem::getInstance()->getSharemem();

    QGuiApplication app(argc, argv);
    EmployeeModel model;
    model.addEmployee(Employee(1, "Phan Hoang Hai", "1.2", 1, 2, 3, 4, 5));
    model.addEmployee(Employee(2, "Phan Hoang Hai", "2.4", 1, 2, 3, 4, 5));
    model.addEmployee(Employee(3, "Phan Hoang Hai", "5.6", 1, 2, 3, 4, 5));
    model.addEmployee(Employee(4, "Phan Hoang Hai", "2.5", 1, 2, 3, 4, 5));

    QQmlApplicationEngine engine;
    QQmlContext* ctxt = engine.rootContext();
    ctxt->setContextProperty("myModel", &model);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;


    return app.exec();
}
