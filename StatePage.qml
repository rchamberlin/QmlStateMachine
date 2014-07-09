import QtQuick 2.2
import QtQuick.Controls 1.1

Rectangle {
    id: root
    color: "#eee"
    property string titleText: "I'm a state page"
    property string pageColor: root.color

    Text {
        id: text
        anchors.centerIn: parent
        text: titleText
    }
}
