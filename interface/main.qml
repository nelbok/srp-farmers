import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 450
    height: 800
    minimumWidth: 450
    minimumHeight: 800
    title: qsTr("Farmers")

    Rectangle {
        anchors.top: parent.top;
        anchors.left: parent.left;
        anchors.right: parent.right;

        border.width: 1

        height: Window.height * 3 / 100

        Text {
            text: "Farmers: " + MyData.farmers

            font.pointSize: Window.height * 1.5 / 100

            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    Column {

        spacing: 2
        anchors.right: parent.right
        anchors.bottom: statusBar.top

        DataItem {
            name: "Houses:"
            value: MyData.houses
            controller: MyController.house
            onErrorStringTriggered: statusBarText.text = message
        }

        DataItem {
            name: "Fields:"
            value: MyData.fields
            controller: MyController.field
            onErrorStringTriggered: statusBarText.text = message
        }

        DataItem {
            name: "Townhall:"
            value: MyData.townhall
            controller: MyController.townhall
            onErrorStringTriggered: statusBarText.text = message
        }

    }

    MouseArea {
        anchors.left: parent.left
        anchors.bottom: statusBar.top

        onClicked: MyController.reset()

        height: 25
        width: 50

        Rectangle {
            anchors.fill: parent

            border.width: 2

            radius: 5
        }

        Text {
            text: "Reset"

            anchors.horizontalCenter: parent.horizontalCenter

            padding: 5
        }
    }

    Rectangle {
        id: statusBar

        anchors.bottom: parent.bottom;
        anchors.left: parent.left;
        anchors.right: parent.right;

        border.width: 1

        height: Window.height * 3 / 100

        Text {
            id: statusBarText

            text: ""

            font.pointSize: Window.height * 1.5 / 100

            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }
    }
}
