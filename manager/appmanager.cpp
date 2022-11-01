#include "appmanager.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "data/employeemodel.h"
#include <mqueue.h>
#include <serverlistenner/readsharemem.h>
#include "util/AppDefine.h"
#include "manager/datamanager.h"
#include <QString>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>

using namespace std;
static AppManager* m_instance;

AppManager::AppManager()
{

}

AppManager *AppManager::getInstance()
{
    if (m_instance == nullptr) {
        m_instance = new AppManager();
    }
    return m_instance;
}

bool AppManager::initApp(int argc, char *argv[])
{
    initData();
    initView(argc, argv);
}

bool AppManager::initView(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQmlContext* ctxt = engine.rootContext();
    ctxt->setContextProperty("myModel", &m_appModel);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

bool AppManager::initData()
{
    QString textData = QString::fromStdString(ReadShareMem::getInstance()->getSharemem());
    QJsonArray jsonData = DataManager::getInstance()->convertTextToJson(textData);
    DataManager::getInstance()->convertDataToModel(jsonData, m_appModel);
    return true;
}
