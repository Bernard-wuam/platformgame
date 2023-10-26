import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5

Window {
    width: 400
    height: 200
    visible: true
    title: qsTr("Hello World")
    x:970
    y:30

    Loader{
        id:loader
        focus: true
        anchors.fill: parent
        source: "./MainWindow.qml"

        function reload(){
            loader.source = "";
            QQmlEngine.clearCache();
            loader.source = "./MainWindow.qml"
        }

        Connections{
            target: QQmlEngine
            function onReloadUI(){
                loader.reload()
            }
        }
    }
}
