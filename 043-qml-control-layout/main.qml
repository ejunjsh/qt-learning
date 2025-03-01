import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    visible: true
    width: 720
    height: 480
    title: "QML Widgets Example"

    RowLayout {
        anchors.fill: parent
        spacing: 10

        Label {
            text: "Hello, World!"
            font.pointSize: 24
            horizontalAlignment: Text.AlignHCenter
            Layout.alignment: Qt.AlignHCenter
        }

        Button {
            text: "Click Me"
            onClicked: {
                console.log("Button clicked")
            }
        }

        Slider {
            from: 0
            to: 100
            value: 50
        }

        TextField {
            placeholderText: "Enter text here"
        }

        ProgressBar {
            value: 0.5
        }

        ColumnLayout {
        spacing: 10

            Label {
                text: "Hello, World!"
                font.pointSize: 24
                horizontalAlignment: Text.AlignHCenter
                Layout.alignment: Qt.AlignHCenter
            }

            Button {
                text: "Click Me"
                onClicked: {
                    console.log("Button clicked")
                }
            }

            Slider {
                from: 0
                to: 100
                value: 50
            }

            TextField {
                placeholderText: "Enter text here"
            }

            ProgressBar {
                value: 0.5
            }
        }
    }
}