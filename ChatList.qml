import QtQuick 2.15
import Qt5Compat.GraphicalEffects
import QtQuick.Controls
import QtQuick.Layouts

Item {
    ListView{
        id:listview
        clip: true
        model:10

        spacing: 10

        delegate: Item{
            id:delegateBackground
            width: listview.width
            height: 45


            Rectangle{
                id:delegateBackgroundColor
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                width: mouse.containsMouse ? parent.width : 0
                color: "lightblue"
                opacity: .4

                Behavior on width {
                    NumberAnimation{
                        duration: 100
                    }
                }
            }

            RowLayout{
                anchors.fill: parent
                Item{
                    id:image
                    Layout.preferredHeight: parent.height
                    Layout.preferredWidth: parent.height

                    Rectangle{
                        anchors.fill: parent
                        color: "blue"
                        radius: parent.width
                    }
                }

                Item{
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    ColumnLayout{
                        anchors.fill: parent
                        spacing: 2
                        Item{
                            Layout.preferredHeight: parent.height * .3
                            Layout.fillWidth: true
                            Text{
                                id:name
                                anchors.fill: parent
                                text: "Frank White"
                                verticalAlignment: Text.AlignVCenter
                                color: "black"
                                font.weight: Font.Bold
                                font.pixelSize: 12
                            }
                        }

                        Item{
                            Layout.fillHeight: true
                            Layout.fillWidth: true
                            Text{
                                id:message
                                anchors.fill: parent
                                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                                elide: Text.ElideRight
                                text: "maybe we took this too far, maybe i took this to far, that pain beared was too pain though"
                                verticalAlignment: Text.AlignVCenter
                                color: "black"
                                font.weight: Font.DemiBold
                                lineHeight: .9
                                font.pixelSize: 10
                            }
                        }
                    }

                    MouseArea{
                        id:mouse
                        anchors.fill: parent
                        hoverEnabled: true
                        cursorShape: containsMouse ? Qt.PointingHandCursor : Qt.ArrowCursor
                    }
                }
            }
        }
    }//end of chatList
}
