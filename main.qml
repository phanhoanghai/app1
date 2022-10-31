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

    Label {
        id: employeeNameLabel
        width: parent.width
        height: 30
        font.pixelSize: Qt.application.font.pixelSize * 1.2
        text: myModel.name
        anchors.horizontalCenter: parent
        font.bold: true
    }

    Item {
        id: employeeInfo
        anchors.top: employeeNameLabel.bottom
        width: parent.width
        height: 300
//        border.color: "blue"
    }

    SearchBar {
        id: searchBar
        x: 166
        anchors.top: employeeInfo.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Item {
        id: listEmployeeInfo
        height: 350
        width: 400
        anchors.top: searchBar.bottom

        Item {
            id: listLabel
            anchors.top: parent.top
            x: 50
            width: 400
            height: 30

            Label {
                id: nameLabel
                font.pixelSize: Qt.application.font.pixelSize * 1.2
                text: "Name"
                x: 50
                font.bold: true
            }

            Label {
                id: averageLabel
                font.pixelSize: Qt.application.font.pixelSize * 1.2
                text: "Average"
                x: 300
                font.bold: true
            }
        }

        ListView {
            id: listEmployee
            anchors.top: listLabel.bottom
            x: 50
            height: 320
            width: 400
            model: myModel
            delegate: EmpoyeeDelegate {}
        }
    }
}
