#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();
    void on_action_remove_blue_triggered();
    void on_action_sharpen_triggered();
    void on_action_Save_triggered();

    void on_action_edge_detection_triggered();

    void on_action_gaussian_blur_triggered();

    void on_action_crop_triggered();

private:
    Ui::MainWindow *ui;
    QImage *mEditingImg;
    int *mpConvolutionMatrix;
    const int cConvolutionMatrixWidth;
    const int cConvolutionMatrixHeight;

    void imageProcessing(int state );
};
#endif // MAINWINDOW_H
