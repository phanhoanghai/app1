import QtQuick 2.2
import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.4
import QtQuick.Layouts 1.11

ItemDelegate {
    id: root
    width: parent.width
    height: 30
    checkable: true


    RowLayout {
        id: dateColumn
        spacing: 5

        Label {
            id: timeLabel
            font.pixelSize: Qt.application.font.pixelSize
            text: model.name
            Layout.fillWidth: true
            Layout.minimumWidth: 270
            Layout.leftMargin: 50
        }

        Label {
            id: dateLabel
            font.pixelSize: Qt.application.font.pixelSize
            text: model.average
            Layout.fillWidth: true
            Layout.minimumWidth: 50
            Layout.leftMargin: 5
            color: "#3BC029"
        }
    }
    Item {
        Layout.fillWidth: true
    }


}
