#include "employeemodel.h"

EmployeeModel::EmployeeModel(QObject* parent)
    : QAbstractListModel(parent) {

}

void EmployeeModel::addEmployee(const Employee& employee) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_employees << employee;
    endInsertRows();
}

int EmployeeModel::rowCount(const QModelIndex& parent) const {
    Q_UNUSED(parent);
    return m_employees.count();
}

QVariant EmployeeModel::data(const QModelIndex & index, int role) const {
    if (index.row() < 0 || index.row() >= m_employees.count())
        return QVariant();

    const Employee &employee = m_employees[index.row()];
    if (role == NameRole)
        return employee.name();
    else if (role == GraduateRole)
        return employee.graduate();
    return QVariant();
}

QHash<int, QByteArray> EmployeeModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[GraduateRole] = "graduate";
    return roles;
}
