#include "employee.h"

Employee::Employee(const QString& name, const QString& graduate)
    :m_name(name), m_graduate(graduate) {

}

QString Employee::name() const {
    return m_name;
}

QString Employee::graduate() const {
    return m_graduate;
}
