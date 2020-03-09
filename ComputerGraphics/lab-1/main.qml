import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 600
    title: qsTr("Hello World")

    Canvas
    {
        anchors.fill:parent

        onPaint:
        {
            var context = getContext("2d");

            // the triangle
            context.beginPath();
            context.moveTo(128, 400);
            context.lineTo(88, 310);
            context.lineTo(500, 500);
           // context.lineTo(500, 50);
            context.closePath();

            // the fill color
            context.fillStyle = "gainsboro";
            context.fill();
        }


    }

    Canvas
    {
        anchors.fill:parent

        onPaint:
        {
            var context = getContext("2d");

            // the triangle
            context.beginPath();
            context.moveTo();
            context.lineTo(88, 310);
            context.lineTo(500, 500);
            context.lineTo(500, 50);
            context.closePath();

            // the fill color
            context.fillStyle = "gainsboro";
            context.fill();
        }
    }

    Rectangle
    {
        x: 30
        y: 300
        width: 100
        height: 100
        color: "blanchedalmond"
        border.color: "black"
        //border.width: 5
        //radius: 10

        transform: Rotation
        {
            origin.x: 100;
            origin.y: 100;
            axis { x: 0; y: 0; z: 1 } angle: 65
        }
    }

    Rectangle
    {
        x: 400
        y: 10
        width: 40
        height:  280
        border.color: "black"
        color: "lightgreen"
    }
}
