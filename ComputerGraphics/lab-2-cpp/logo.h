#ifndef LOGO_H
#define LOGO_H

#include <QPainter>

#include <QGraphicsItem>
#include <QRandomGenerator>
#include <QGraphicsScene>

class Logo : public QGraphicsItem
{
public:
    Logo(int movementType);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

protected:
    void advance(int phase) override;

private:
    qreal angle;
    qreal speed;
    QColor color;
    int direction;
    int movementType;
    int x;
    int y;
    int directionX;
    int directionY;
    int boundingRectPosX;
    int boundingRectPosY;
    int boundingRectHeight;
    int boundingRectWidth;
    int radius;
    bool changeAngle;
    const int sceneWidth {300};
    const int sceneHeight {300};
};

#endif // LOGO_H
