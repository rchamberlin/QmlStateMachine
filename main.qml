import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Window 2.1

Window {
    id: mainWindow
    visible: true
    width: 800
    height: 600

    property string firstState: appController.firstState.objectName
    property string secondState: appController.secondState.objectName
    property string thirdState: appController.thirdState.objectName

    property Item firstStatePage: StatePage {
        objectName: firstState
        titleText: qsTr("I'm the first state")
        pageColor: "#eee"
    }
    property Item secondStatePage: StatePage {
        objectName: secondState
        titleText: qsTr("I'm the second state")
        pageColor: "#ddd"
    }
    property Item thirdStatePage: StatePage {
        objectName: thirdState
        titleText: qsTr("I'm the third state")
        pageColor: "#aaa"
    }

    function nav(item) {
        if (appController.pop) {
            stackView.pop()
        } else {
            stackView.push(item)
        }
    }

    Rectangle {
        id: navBar
        width: parent.width
        height: 60
        color: "#ccc"

        Button {
            id: prevButton
            width: 100
            height: 40
            text: qsTr("<< Previous")
            visible: stackView.state !== firstState
            anchors {
                verticalCenter: parent.verticalCenter
                left: parent.left
                leftMargin: 10
            }
            onClicked: {
                appController.navPrevious()
            }
        }

        Button {
            id: nextButton
            width: 100
            height: 40
            text: qsTr("Next >>")
            visible: stackView.state !== thirdState
            anchors {
                verticalCenter: parent.verticalCenter
                right: parent.right
                rightMargin: 10
            }
            onClicked: {
                appController.navNext()
            }
        }
    }

    StackView {
        id: stackView
        width: parent.width
        height: parent.height - navBar.height
        anchors.bottom: parent.bottom

        states: [
            State {
                name: firstState
                StateChangeScript {
                    script: nav(firstStatePage)
                }
            },
            State {
                name: secondState
                StateChangeScript {
                    script: nav(secondStatePage)
                }
            },
            State {
                name: thirdState
                StateChangeScript {
                    script: nav(thirdStatePage)
                }
            }
        ]

        Connections {
            target: appController
            onStateChanged: {
                stackView.state = objectName
                console.log("State Changed To: " + objectName)
            }
        }

        Component.onCompleted: {
            stackView.push(firstStatePage)
        }

    }

    Component.onCompleted: {
    }
}
