import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

TextField {
    id: textField
    width: 40
    implicitHeight: 40


    property color colorDefault: "#282c34"
    property color colorOnfocus: "#202225"
    property color colorMouseOver: "#2B2f38"
    property color colorBorderOnFocus: "#ff007f"

    placeholderText: qsTr("Search by")
    font.family: "Segoe UI"
    font.pointSize: 10
    clip: true

    style: TextFieldStyle {
        selectedTextColor: "#FFFFFF"
        selectionColor: "#ff007f"
        placeholderTextColor: "#81848c"
        Rectangle {
            id: bgColor
            color: colorDefault
            radius: 8
            border.color: colorDefault
            border.width: 2

            Image {
                id: iconSearch
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                source: "../../resources/icon-search.png"
                anchors.leftMargin: 10
                fillMode: Image.PreserveAspectFit
                sourceSize.height: 20
            }
        }
    }

    selectByMouse: true

    onFocusChanged: {
        if (textField.focus) {
            textField.width = 300
        } else {
            textField.width = 40
        }
    }


}
