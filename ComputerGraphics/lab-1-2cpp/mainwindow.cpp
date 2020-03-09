#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cmath>

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
    QPainter painter(this);
    QBrush brush;
    QPen   pen;
    pen.setWidth(2);
    brush.setColor(QColor(0 , 0, 0));

    int count = 0;

    auto drawPen = [&painter, &pen, &count](int pencilTipX, int pencilTipY,
            bool isPen)
    {
        painter.setPen(Qt::NoPen);
        int pencilBodyHeight {200};
        int leadHeight {12};

        double sharpness {0.523598};

        QPointF lead[3] =
        {
            QPointF(pencilTipX, pencilTipY),
            QPointF(pencilTipX - tan(sharpness / 2) * leadHeight, pencilTipY + leadHeight),
            QPointF(pencilTipX + tanf(sharpness / 2) * leadHeight, pencilTipY + leadHeight)
        };
        //painter.setPen(pen);
        painter.setPen(Qt::NoPen);
        painter.setBrush(QColor(pencilTipX - 35, pencilTipY - 20, 123));

        painter.drawPolygon(lead, 3);

        int woodenTopHeight = leadHeight * 3;
        QPointF woodenTop[4] =
        {
            QPointF(pencilTipX - tan(sharpness / 2) * leadHeight, pencilTipY + leadHeight),
            QPointF(pencilTipX + tanf(sharpness / 2) * leadHeight, pencilTipY + leadHeight),

            QPointF(pencilTipX + tan(sharpness / 2) * (leadHeight + woodenTopHeight) ,
            pencilTipY + leadHeight +  woodenTopHeight),

            QPointF(pencilTipX - tan(sharpness / 2) * (leadHeight + woodenTopHeight) ,
            pencilTipY + leadHeight +  woodenTopHeight),
        };
        //painter.setPen(pen);


        if (isPen)
        {
            painter.setBrush(QColor(242, 225, 172));
        }
        else
        {
            painter.setBrush(QColor(153, 51, 0));
        }


        painter.drawPolygon(woodenTop, 4);

        QRectF pencilsBody(
                    pencilTipX - tan(sharpness / 2) * (leadHeight + woodenTopHeight) ,
                    pencilTipY + leadHeight +  woodenTopHeight,
                    pencilTipX + tan(sharpness / 2) * (leadHeight + woodenTopHeight)
                    - (pencilTipX - tan(sharpness / 2) * (leadHeight + woodenTopHeight)) ,
                    pencilBodyHeight);

        if (count % 3 == 0)
        {
            pen.setColor(Qt::blue);
            painter.setPen(pen);
        }

        count++;

        painter.setBrush(QColor(pencilTipX - 45, pencilTipY - 20, 123));
        painter.drawRect(pencilsBody);
    };

    bool isStroke{0};

    for (int i{90}; i <= 320; i += 40)
    {
        for (int j{30}; j != 180; j += 30)
        {
            if (isStroke)
            {
                drawPen(i, j, 0);
                isStroke = 0;
            }
            else
            {
                drawPen(i, j, 1);
                isStroke = 1;
            }
        }
    }

    // box
    QRectF();
    painter.setBrush(QColor(156, 189, 123));
    painter.drawRect(70, 300, 250, 100);
}

