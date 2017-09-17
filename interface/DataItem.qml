import QtQuick 2.8
import QtQuick.Window 2.2

Rectangle {

    property string name: "Data:"
    property string value: "0"
    property QtObject controller: null
    signal errorStringTriggered(string message)

    border.color: "grey"
    border.width: 2

    height: Window.height * 5 / 100
    width: Window.width * 45 / 100

    Text {
        text: parent.name
        font.pointSize: Window.height * 1.5 / 100

        anchors.leftMargin: 5
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
    }

    Text {
        text: parent.value
        font.pointSize: Window.height * 1.5 / 100

        anchors.leftMargin: Window.width * 17.5 / 100
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
    }

    MouseArea {
        onClicked: {
            controller.build();
            parent.errorStringTriggered(controller.errorString);
        }

        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right

        height: parent.height
        width: Window.width * 12 / 100

        Rectangle {
            anchors.fill: parent

            border.color: (controller.canBuild) ? "black" : "red"
            border.width: 2

            radius: 5
        }

        Text {
            text: "Build"

            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            padding: 5
            font.pointSize: Window.height * 1.5 / 100

            color: (controller.canBuild) ? "black" : "red"
        }
    }
}
