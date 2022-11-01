#ifndef APPMANAGER_H
#define APPMANAGER_H

#include "data/employeemodel.h"

class AppManager
{
private:
    AppManager();

public:
    static AppManager* getInstance();

public:
    bool initApp(int argc, char *argv[]);
    bool initView(int argc, char *argv[]);
    bool initData();

private:
    EmployeeModel m_appModel;
};

#endif // APPMANAGER_H
