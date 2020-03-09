#include "logo.h"

#include <QPainter>

static const double pi {3.14159265358979323846264338327950288419717};
static const double twoPi{2 * pi};

Logo::Logo(int movementType) :
    angle(0), speed(2),
    color((qrand()) % 256, (qrand()) % 256, (qrand()) % 256),
    direction(1),directionX(1),directionY(1),x(0), y(0),boundingRectPosX(0), boundingRectPosY(0), boundingRectWidth(70), boundingRectHeight(85),changeAngle(0), movementType{movementType}
{
    radius = 100 + qrand() % 100;
    bool sign = qrand() % 1;

    if (sign)
    {
        x = qrand() % sceneWidth;
        y = qrand() % sceneHeight;
    }
    else
    {
        x = -qrand()%(sceneWidth - boundingRectWidth);
        y = -qrand()%(sceneHeight - boundingRectWidth);
    }
    setPos(x, y);
}

QRectF Logo::boundingRect() const
{
    return QRect(boundingRectPosX, boundingRectPosY, boundingRectWidth, boundingRectHeight);
}

QPainterPath Logo::shape() const
{

}

void Logo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(color);

    QPainterPath apple(QPointF(34, 25));
    apple.cubicTo(29, 24, 29, 24, 25, 22);
    apple.cubicTo(19, 21, 19, 21, 15, 22);
    apple.cubicTo(9, 25, 9, 25, 6, 29);
    apple.cubicTo(2, 36, 2, 36, 1, 41);
    apple.cubicTo(1, 44, 1, 44, 1, 48);
    apple.cubicTo(7, 68, 7, 68, 17, 82);
    apple.cubicTo(21, 83, 21, 83, 24, 83);
    apple.cubicTo(21, 83, 21, 83, 24, 83);
    apple.cubicTo(32, 80, 32, 80, 38, 80);
    apple.cubicTo(48, 84, 48, 84, 55, 80);
    apple.cubicTo(61, 73, 61, 73, 67, 62);
    //
    apple.cubicTo(60, 58, 60, 58, 56, 50);
    apple.cubicTo(55, 45, 55, 45, 56, 40);

    apple.cubicTo(58, 35, 58, 35, 64, 30);
    apple.cubicTo(59, 25, 59, 25, 56, 23);
    apple.cubicTo(50, 20, 50, 20, 34, 25);
    painter->drawPath(apple);

    QPainterPath leaf(QPointF(50, 2));
    leaf.cubicTo(42, 5, 42, 5 ,38, 8);
    leaf.cubicTo(45, 4, 45, 4 ,43, 4);
    leaf.cubicTo(35, 12, 35, 12, 34, 20);

    leaf.cubicTo(41, 20, 41, 20 ,45, 15);
    leaf.cubicTo(47, 12, 47, 12, 48, 10);
    leaf.cubicTo(48, 10, 48, 10, 50, 2);
    painter->drawPath(leaf);
}

void Logo::advance(int phase)
{
    if (phase)
    {
        QLineF lineToCenter(QPointF(0, 0), mapFromScene(0, 0));
        QPointF mapCoordinates = mapFromScene(0, 0);

        if (mapCoordinates.rx() >= sceneWidth  || mapCoordinates.rx() - boundingRectWidth <= -sceneWidth)
        {
            if (directionX <= -1)
            {
                directionX = 1 * qrand() % 2 + 1;
                direction = 1;
                x+=3;
            }
            else if(directionX >= 1)
            {
                directionX = -1 * qrand() % 2 - 1;
                direction = -1;
                x-=3;
            }

        }
        if (mapCoordinates.ry() >= sceneHeight || mapCoordinates.ry() - boundingRectHeight <= -sceneHeight)
        {
            if (directionY <= -1)
            {
                directionY = 1 * qrand() % 2 + 1;
                y += 3;
            }
            else if(directionY >= 1)
            {
                directionY = -1 * qrand() % 2 - 1;
                y-= 3;
            }
        }

        switch(movementType)
        {
        case 0:
        {
            // синусоїда
            x += direction * speed;
            angle = pi / 2;

            setPos(x, 100 * sin(0.025 * x));
        }
            break;

        case 1:
        {
            // по-прямі
            x += directionX * speed;
            y += directionY * speed;
            setPos(x, y);
        }
            break;
        case 2:
        {
            //x += qrand() % 3 + 1;
            x++;
            setPos(radius*cosf(0.1*abs(x)), radius*sinf(0.1*abs(x)));
        }
            break;
        case 3:
        {
            y += directionY * speed;
            setPos(x, y);
        }
            break;
        case 4:
        {
            x += directionX * speed;
            setPos(x, y);
        }
            break;
        case 5:
        {
            x++;
            setPos(radius*cosf(0.1*abs(x)), radius*cosf(0.1*abs(x)) + y);
        }
             break;
        }

    }

}

