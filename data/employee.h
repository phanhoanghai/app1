#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>

class Employee
{
public:
    Employee(const QString& name, const QString& average);

public:
    QString name() const;
    QString average() const;

private:
    QString m_name;
    QString m_average;
};

#endif // EMPLOYEE_H
