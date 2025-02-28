import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello QML")

    MyRectangle {
        width: 200
        height: 200
        color: "lightblue"
    }
}