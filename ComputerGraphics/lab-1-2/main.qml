import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


            Repeater
            {
                model: 24
                       Rectangle
                       {
                           width: 70;
                           height: 200
                           color: "lightgreen"
                       }
            }

        Rectangle
        {
            x : 10
            y : 400
            width: 400;
            height: 100;
            color: "black"
        }

}
