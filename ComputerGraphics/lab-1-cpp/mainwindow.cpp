#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *e)
{
    double k = 1.5;
    QPainter painter(this);
    QPen pen;

    QBrush brush;
    pen.setWidth(1);

    auto drawArrow = [&painter, &pen, &k](int endX, int endY)
    {
        QPointF start(233 * k, 303 * k);
        QPointF end(endX * k, endY * k);
        painter.drawLine(start, end);

    };

    auto drawPoli = [&painter, &pen, &k](bool useBrush)
    {
      QPointF figure[4] =
      {
          QPointF(145 * k, 333 * k),
          QPointF(121 * k, 286 * k),
          QPointF(312 * k, 152 * k),
          QPointF(312 * k, 390 * k)
      };

      painter.setPen(pen);

      if (useBrush)
      {
          painter.setBrush(QColor(189, 187, 188));
      }
      else
      {
          painter.setBrush(Qt::NoBrush);
      }
      painter.drawPolygon(figure, 4);
    };

    drawPoli(1);

    painter.setBrush(QColor(165, 255, 122));
    painter.setPen(pen);
    painter.drawRect(263 * k, 80 * k, 28 * k, 200 * k);

    QPointF rotatedSquare[4] =
    {
        QPointF(121 * k, 287 * k),
        QPointF(145 * k, 333 * k),
        QPointF(193 * k, 311 * k),
        QPointF(168 * k, 263 * k)
    };

    painter.setBrush(QColor(255, 206, 168));
    painter.drawPolygon(rotatedSquare, 4);

    drawPoli(0);

    painter.setBrush(QColor(0, 0, 0));
    double radius = 5 * k;
    painter.drawEllipse(230 * k, 300 * k, radius, radius);
    painter.drawEllipse(146 * k, 265 * k, radius, radius);
    painter.drawEllipse(310 * k, 212 * k, radius, radius);
    painter.drawEllipse(275 * k, 175 * k, radius, radius);

    drawArrow(120, 256);
    QPointF arrowHead[3] =
    {
        QPointF(120 * k, 256 * k),
        QPointF(124 * k, 260 * k),
        QPointF(125 * k, 256 * k)
    };
    painter.drawPolygon(arrowHead, 3);

    drawArrow(345, 280);
    QPointF arrowHead2[3] =
    {
       QPointF(228 * k, 153 * k),
       QPointF(226 * k, 159 * k),
       QPointF(231 * k, 159 * k)
    };
    painter.drawPolygon(arrowHead2, 3);

    drawArrow(326, 200);
    QPointF arrowHead3[3] =
    {
       QPointF(277 * k, 50 * k),
       QPointF(273 * k, 58 * k),
       QPointF(277 * k, 58 * k)
    };
    painter.drawPolygon(arrowHead3, 3);

    drawArrow(314, 78);
    QPointF arrowHead4[3] =
    {
       QPointF(320 * k, 203 * k),
       QPointF(326 * k, 200 * k),
       QPointF(324 * k, 205 * k)
    };
    painter.drawPolygon(arrowHead4, 3);

    drawArrow(228, 153);
    QPointF arrowHead5[3] =
    {
       QPointF(314 * k, 78 * k),
       QPointF(309 * k, 83 * k),
       QPointF(314 * k, 84 * k)
    };
    painter.drawPolygon(arrowHead5, 3);

    drawArrow(277, 50);
    QPointF arrowHead6[3] =
    {
       QPointF(345 * k, 280 * k),
       QPointF(338 * k, 283 * k),
       QPointF(337 * k, 280 * k)
    };
    painter.drawPolygon(arrowHead6, 3);

    painter.drawText(QPointF(230 * k, 315 * k), "C");
    painter.drawText(QPointF(145 * k, 260 * k), "+1");
    painter.drawText(QPointF(226 * k, 150 * k), "0");
    painter.drawText(QPointF(275 * k, 48  * k), "0");
    painter.drawText(QPointF(312 * k, 76  * k), "1");
    painter.drawText(QPointF(346 * k, 280 * k), "0");
    painter.drawText(QPointF(326 * k, 200 * k), "1");
    painter.drawText(QPointF(276 * k, 187 * k), "+1");
    painter.drawText(QPointF(316 * k, 218 * k), "+1");
}

