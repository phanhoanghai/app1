#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>

class Employee
{
public:
    Employee(const QString& name, const QString& graduate);

public:
    QString name() const;
    QString graduate() const;

private:
    QString m_name;
    QString m_graduate;
};

#endif // EMPLOYEE_H
