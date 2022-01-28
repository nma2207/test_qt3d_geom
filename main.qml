import QtQuick
import QtQuick.Controls
import QtQuick3D
import QtQuick3D.Helpers
import ModuleName
import TestGeometry

Item {
    id: window
    width: 800
    height: 800
    visible: true
    //title: qsTr("Hello World")
    Button {
        id:btn1
        anchors.top: window.top
        anchors.left: window.left
        anchors.leftMargin: 10
        anchors.topMargin: 10
        text: "Add line"
        onClicked: mygm2.addLine()
    }
    MyGeomtry2{
        id: mygm2;
        anchors.fill: parent
        anchors.margins: 20

    }



//    View3D {


//        id: v3d;
//        anchors.fill: window
//        camera: camera

//        PerspectiveCamera {
//            id: camera
//            position: Qt.vector3d(0,0,600);
//        }

//        DirectionalLight {
//            position: Qt.vector3d(-500, 500, -100)
//            color: Qt.rgba(0.4, 0.2, 0.6, 1.0)
//            ambientColor: Qt.rgba(0.1, 0.1, 0.1, 1.0)
//        }

//        PointLight {
//            position: Qt.vector3d(0, 0, 100)
//            color: Qt.rgba(0.1, 1.0, 0.1, 1.0)
//            ambientColor: Qt.rgba(0.2, 0.2, 0.2, 1.0)
//        }

//        Model {

//            scale: Qt.vector3d(50, 50, 50);
//            geometry: MyGeometry {
//                id: myGeom
//            }
//            materials: [
//                DefaultMaterial {
//                    lighting: DefaultMaterial.NoLighting
//                    cullMode: DefaultMaterial.NoCulling
//                    diffuseColor: "red"
//                    pointSize: 10
//                    lineWidth: 10;
//                }
//            ]
//        }
//    }
}
