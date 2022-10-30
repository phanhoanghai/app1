import QtQuick 2.12
import QtQuick.Controls 2.12

TextField {
    id: textField
    width: 40
    implicitHeight: 40

    property color colorDefault: "#282c34"
    property color colorOnfocus: "#202225"
    property color colorMouseOver: "#2B2f38"
    property color colorBorderOnFocus: "#ff007f"

    placeholderText: qsTr("Search by ...")
//    color: "#ffffff"
    font.family: "Segoe UI"
    font.pointSize: 10
    clip: true
    leftPadding: 42
    rightPadding: 35
    selectByMouse: true
//    selectedTextColor: "#FFFFFF"
    selectionColor: colorBorderOnFocus
    placeholderTextColor: "#81848c"

    background: Rectangle {
        Rectangle {
            id: bgColor
            color: colorDefault
            radius: 8
            border.color: colorDefault
            border.width: 2

            Image {
                id: iconSearch
                anchors.verticalCenter: parent
                x: 7
                y: 7
                source: "../../resources/icon-search.png"
                anchors.leftMargin: 10
                fillMode: Image.PreserveAspectFit
                sourceSize.height: 20
                opacity: 0.5
                width: 25
                height: 25
            }
        }
    }

    onFocusChanged: {
        if (textField.focus) {
            textOnFocus.running = true
             textField.placeholderText = "Search by ..."
        } else {
            textLostFocus.running = true
            textField.placeholderText = ""
        }
    }

    PropertyAnimation {
        id: textOnFocus
        target: textField
        properties: "width"
        to: 300
        duration: 500
        easing.type: Easing.OutQuint
    }

    PropertyAnimation {
        id: textLostFocus
        target: textField
        properties: "width"
        to: 40
        duration: 500
        easing.type: Easing.OutQuint
    }
}
