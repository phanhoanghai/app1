#include "employee.h"

Employee::Employee(const QString& name, const QString& average)
    :m_name(name), m_average(average) {

}

QString Employee::name() const {
    return m_name;
}

QString Employee::average() const {
    return m_average;
}
