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

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    //painter.setBrush(Qt::blue);
    QTransform t;
    t.rotate(45); // у градусаx
    painter.setTransform(t);


    QPolygon triangle;
    triangle << QPoint(this->width() * 1 / 4, 0)
             <<QPoint(this->width() * 3 / 4, 0)
             <<QPoint(this->width() * 1 / 2, this->width() * 1 / 4);

    painter.setBrush(Qt::blue);
    painter.drawPolygon(triangle);

    QRectF rect(this->width() * 1 / 4, 0, this->width() * 1 / 8, -(this->height() * 1 / 8));
    painter.setBrush(Qt::red);
    painter.drawRect(rect);

}

void MainWindow::move()
{

}

