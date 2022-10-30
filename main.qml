import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.4
import QtQuick.Layouts 1.11
import QtQuick.Window 2.11

ApplicationWindow {
    id: window
    width: 500
    height: 700
    visible: true

    Pane {
        anchors.fill: parent
        focusPolicy: Qt.ClickFocus
    }

    Rectangle {
        id: employeeInfo
        anchors.top: parent.top
        width: parent.width
        height: 300
        border.color: "blue"
    }

    SearchBar {
        id: searchBar
        x: 166
        anchors.top: employeeInfo.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
    }

    ListView {
        id: listEmployee
        width: parent.width
        anchors.top: searchBar.bottom
        height: 300
        model: myModel
        delegate: EmpoyeeDelegate {}
    }
}
