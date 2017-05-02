import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    visible: true
    width: 400
    height: 400
    title: qsTr("Hello World")

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1 {
            GridLayout {
                id: gridLayout
                anchors.fill: parent
                columns: 7
                rows: 6
                TextArea {
                    id: monday
                    Layout.fillWidth: true
                    horizontalAlignment: Text.AlignHCenter
                    text: "M"
                }
                TextArea {
                    text: "T"
                    id: tuesday
                    Layout.fillWidth: true
                    horizontalAlignment: Text.AlignHCenter
                }
                TextArea {
                    id: wednesday
                    Layout.fillWidth: true
                    horizontalAlignment: Text.AlignHCenter
                    text: "W"
                }
                TextArea {
                    id: thursday
                    Layout.fillWidth: true
                    horizontalAlignment: Text.AlignHCenter
                    text: "T"
                }
                TextArea {
                    id: friday
                    Layout.fillWidth: true
                    horizontalAlignment: Text.AlignHCenter
                    text: "F"
                }
                TextArea {
                    id: saturday
                    Layout.fillWidth: true
                    horizontalAlignment: Text.AlignHCenter
                    text: "S"
                }
                TextArea {
                    id: sunday
                    Layout.fillWidth: true
                    horizontalAlignment: Text.AlignHCenter
                    text: "S"
                }
                Button {
                    id: but1
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("1")
                }
                Button {
                    id: but2
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("2")
                }
                Button {
                    id: but3
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("3")
                }
                Button {
                    id: but4
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("4")
                }
                Button {
                    id: but5
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("5")
                }
                Button {
                    id: but6
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("6")
                }
                Button {
                    id: but7
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("7")
                }
                Button {
                    id: but8
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("8")
                }
                Button {
                    id: but9
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("9")
                }
                Button {
                    id: but10
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("10")
                }
                Button {
                    id: but11
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("11")
                }
                Button {
                    id: but12
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("12")
                }
                Button {
                    id: but13
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("13")
                }
                Button {
                    id: but14
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("14")
                }
                Button {
                    id: but15
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("15")
                }
                Button {
                    id: but16
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("16")
                }
                Button {
                    id: but17
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("17")
                }
                Button {
                    id: but18
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("18")
                }
                Button {
                    id: but19
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("19")
                }
                Button {
                    id: but20
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("20")
                }
                Button {
                    id: but21
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("21")
                }
                Button {
                    id: but22
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("22")
                }
                Button {
                    id: but23
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("23")
                }
                Button {
                    id: but24
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("24")
                }
                Button {
                    id: but25
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("25")
                }
                Button {
                    id: but26
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("26")
                }
                Button {
                    id: but27
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("27")
                }
                Button {
                    id: but28
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("28")
                }
                Button {
                    id: but29
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("29")
                }
                Button {
                    id: but30
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("30")
                }
                Button {
                    id: but31
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("31")
                }
            }
        }

        Page {
            Label {
                text: qsTr("Second page")
                anchors.centerIn: parent
            }
        }
    }

    header: ToolBar {
        id: menu
        RowLayout {

            ToolButton {
                Layout.fillWidth: true
                text: qsTr("Tool1")
            }
            ToolButton {
                Layout.fillWidth: true
                text: qsTr("Tool2")
            }
            ToolButton {
                Layout.fillWidth: true
                text: qsTr("Tool3")
            }
            ToolButton {
                Layout.fillWidth: true
                text: qsTr("Tool4")
            }
            ToolButton {
                Layout.fillWidth: true
                text: qsTr("Tool5")
            }
        }
    }
    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        TabButton {
            text: qsTr("Month")
        }
        TabButton {
            text: qsTr("Week")
        }
    }
}

