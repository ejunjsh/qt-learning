import QtQuick 2.9

Rectangle {
    //visible: true
    //width: 150
    //height: 150
    //anchors.fill: parent
    //anchors.centerIn: parent
    
    border.color: "#00ffd5"
    border.width: 10
    radius : 10
    
    Text {
        id : text
        anchors.centerIn: parent
        text: qsTr("QML Text")
        antialiasing: true  //抗锯齿
    }

    // 旋转动画
    NumberAnimation {
        id : numberAnimation
        target: text
        property: "rotation"
        from: 0
        to: 360
        duration: 3000
        
        running: true
        loops: Animation.Infinite
        
    }
}