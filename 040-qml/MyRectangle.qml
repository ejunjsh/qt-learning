import QtQuick 2.15

Rectangle {
    property alias color: rect.color

    Rectangle {
        id: rect
        anchors.fill: parent
        border.color: "black"
        border.width: 2
    }
}