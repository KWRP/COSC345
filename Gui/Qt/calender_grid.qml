import QtQuick 2.0

Item {
    GridLayout {
        id: gridLayout
        columns: 7
        rows: 5
        anchors.fill: parent

        TextArea {
            id: textArea
            width: 81
            height: 59
            text: qsTr("Text Area")
        }
    }
}
