import QtQuick 2.15
import Qt5Compat.GraphicalEffects
import QtQuick.Controls
import QtQuick.Layouts
import keepMe

Item {
    id:main
    focus: true

    Keys.onReleased: (event)=> {
                         if (event.key === Qt.Key_Left) {
                             event.accepted = true;
                             Input.removeKey(Input.LeftKey)
                         }

                         if (event.key === Qt.Key_Right) {
                            event.accepted = true;
                            Input.removeKey(Input.RightKey)
                         }

                         if (event.key === Qt.Key_Up) {
                             event.accepted = true;
                             Input.removeKey(Input.UpKey)
                         }

                         if (event.key === Qt.Key_Down) {
                             event.accepted = true;
                             Input.removeKey(Input.DownKey)
                         }
                     }
    Keys.onPressed: (event)=>{
                        if(event.key === Qt.Key_Up){
                            Input.addKey(Input.UpKey)
                        }
                        if(event.key === Qt.Key_Down){
                            Input.addKey(Input.DownKey)
                        }
                        if(event.key === Qt.Key_Right){
                            Input.addKey(Input.RightKey)
                        }
                        if(event.key === Qt.Key_Left){
                            Input.addKey(Input.LeftKey)
                        }
                    }
    Rectangle{
        anchors.horizontalCenter: parent.horizontalCenter
        id:backgroundImage
        width: 320
        height: 180
        color: "gray"

        Canvas{
            id:canvas
            anchors.fill: parent
            property  var ctx
            property real accumulatedTime: 0
            property real lastTime: 0
            property real timeStep: 10/60
            property Sprite gameworld: Sprite{}

            Sprite{
                id:hero
                resource: "assets/sprites/hero-sheet.png"
                frameSize: 32
                frame:1
                hframe:3
                vframe: 8
                position:Qt.vector2d(88,60)
                // position:Qt.vector2d(200,44)
                Component.onCompleted: {
                      hero.frameMap()
                }
            }
            Sprite{
                id:hero_shadow
                resource: "assets/sprites/shadow.png"
                frameSize: 32
                position:hero.position
            }


            onAvailableChanged: if(available) ctx = getContext('2d')

            function drawImage(image,frameh,framev,width,height,x,y,widthx,heighty){
                ctx.drawImage(image,frameh,framev,width,height,x,y,widthx,heighty)
                ctx.save();
            }

            function daint(timestamp){
                ctx.clearRect(0,0,270,500)
                ctx.drawImage("assets/sprites/sky.png",0,0,320,180,0,0,320,180)
                ctx.drawImage("assets/sprites/ground.png",0,0)
            }


            function mainLoop(){

                let deltaTime = GameLoop.deltaTime();
                accumulatedTime += deltaTime
                //console.log("accumulatedTime = ",accumulatedTime)

                while(accumulatedTime >= timeStep){
                    daint() //mainly to draw the environment of the game....
                    hero.update(Input.getDirection(),deltaTime)
                    hero_shadow.update(Input.getDirection(),deltaTime)
                    hero.drawImage(drawImage)

                    hero_shadow.drawImage(drawImage)
//                    hero.frame = (hero.frame + 1)
//                    if(hero.frame > 24) hero.frame = 0

                    accumulatedTime -= timeStep
                }
                GameLoop.ticks();
                requestAnimationFrame(mainLoop)
            }

            //keys InputMethod

            onPaint: {
                mainLoop()
            }
        }
    }
}

