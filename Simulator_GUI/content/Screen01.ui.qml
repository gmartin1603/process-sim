

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick 6.5
import QtQuick.Controls 6.5
import Simulator_GUI

Rectangle {
    id: rectangle
    width: Constants.width
    height: Constants.height
    color: "#3f51aa"

    Button {
        id: button
        width: 182
        height: 40
        text: qsTr("Start Simulation")
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 300
        bottomInset: 0
        topInset: 0
        font.weight: Font.DemiBold
        font.bold: false
        font.pointSize: 12
        font.family: "Tahoma"
        checkable: true
        anchors.horizontalCenter: parent.horizontalCenter

        Connections {
            target: button
            onClicked: animation.start()
        }
    }

    Text {
        id: label
        text: qsTr("Process Stats")
        anchors.top: button.bottom
        font.family: Constants.font.family
        anchors.topMargin: -523
        anchors.horizontalCenterOffset: 408
        font.capitalization: Font.AllUppercase
        font.pointSize: 14
        font.weight: Font.Bold
        anchors.horizontalCenter: parent.horizontalCenter

        SequentialAnimation {
            id: animation

            ColorAnimation {
                id: colorAnimation1
                target: rectangle
                property: "color"
                to: "#2294c6"
                from: Constants.backgroundColor
            }

            ColorAnimation {
                id: colorAnimation2
                target: rectangle
                property: "color"
                to: Constants.backgroundColor
                from: "#2294c6"
            }
        }
    }

    Button {
        id: button1
        text: qsTr("Decrease")
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 300
        anchors.horizontalCenterOffset: -600
        bottomInset: 0
        topInset: 0
        font.weight: Font.DemiBold
        font.bold: false
        font.pointSize: 12
        font.family: "Tahoma"
        checkable: true
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Button {
        id: button2
        text: qsTr("Increase")
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 300
        anchors.horizontalCenterOffset: -400
        bottomInset: 0
        topInset: 0
        font.weight: Font.DemiBold
        font.bold: false
        font.pointSize: 12
        font.family: "Tahoma"
        checkable: true
        anchors.horizontalCenter: parent.horizontalCenter
    }
    states: [
        State {
            name: "clicked"
            when: button.checked

            PropertyChanges {
                target: label
                text: qsTr("Simulation Started")
            }
        }
    ]
}
