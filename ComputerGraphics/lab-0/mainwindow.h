#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QtCore>
#include <QtGui>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

//private slots:
    void paintEvent(QPaintEvent *event);

private slots:
    void move();

private:
    Ui::MainWindow *ui;
    QTimer *timer;

    int x;
    int y;

};
#endif // MAINWINDOW_H
