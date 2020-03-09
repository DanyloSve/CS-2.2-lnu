#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      cConvolutionMatrixWidth{3},
      cConvolutionMatrixHeight{3}
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    QString openImgDir = QFileDialog::getOpenFileName(this, "Open a file", "~/Temporary");
    mEditingImg = new QImage(openImgDir);
    ui->label->setPixmap(QPixmap::fromImage(*mEditingImg));
}

void MainWindow::on_action_remove_blue_triggered()
{
    for (int i{0}; i < mEditingImg->width(); i++)
    {
        for (int j{0}; j < mEditingImg->height(); j++)
        {
            mEditingImg->pixel(i,j);
            QColor pixColor = mEditingImg->pixelColor(i, j);
            pixColor.setBlue(0);
            mEditingImg->setPixelColor(i, j, pixColor);
        }
    }
    ui->label_2->setPixmap(QPixmap::fromImage(*mEditingImg));

}

void MainWindow::on_action_sharpen_triggered()
{
    const int height {3};
    const int width {3};

    int laplace[width][height]
    {
        { 0,  -1,  0},
        {-1,   5, -1},
        { 0,  -1,  0}
    };
    mpConvolutionMatrix = &laplace[0][0];

    imageProcessing(0);
}

void MainWindow::on_action_Save_triggered()
{
    QString saveImgDir = QFileDialog::getSaveFileName(this, tr("Open File"),
                                                      "/home",
                                                      tr("Images (*.png *.xpm *.jpg)"));
    mEditingImg->save(saveImgDir, ".png");
}

void MainWindow::imageProcessing(int state = 0)
{

    auto pixCorrector = [](int pix)
    {
        if (pix > 255)
        {
            return 255;
        }
        else if (pix < 0)
        {
            return 0;
        }
        else
        {
            return pix;
        }
    };


    for (int i{0}; i < mEditingImg->width() - 2; i++)
    {
        for (int j{0}; j < mEditingImg->height() - 2; j++)
        {
            int red {0};
            int green {0};
            int blue {0};

            for (int k{0}; k < cConvolutionMatrixWidth ; k++)
            {
                for (int l{0}; l < cConvolutionMatrixHeight ; l++)
                {
                    if (k + i < 0 || k + i > mEditingImg->width()
                            || j + l < 0 || j + l > mEditingImg->height())
                    {
                        continue;
                    }

                    red += mEditingImg->pixelColor(k + i, j + l).red() *
                            (*(mpConvolutionMatrix+(k*cConvolutionMatrixHeight) + l));
                    green += mEditingImg->pixelColor(k + i, j + l).green() *
                            (*(mpConvolutionMatrix+(k*cConvolutionMatrixHeight) + l));
                    blue += mEditingImg->pixelColor(k + i, j + l).blue() *
                            (*(mpConvolutionMatrix+(k*cConvolutionMatrixHeight) + l));

                }
            }

            if (state == 1)
            {
                 QColor pixColor(pixCorrector(red / 9), pixCorrector(green / 9),
                                 pixCorrector(blue / 9));
                 mEditingImg->setPixelColor(i, j, pixColor);
            }
            else
            {
                QColor pixColor(pixCorrector(red), pixCorrector(green), pixCorrector(blue));
                mEditingImg->setPixelColor(i, j, pixColor);
            }
        }
    }
    ui->label_2->setPixmap(QPixmap::fromImage(*mEditingImg));
}

void MainWindow::on_action_edge_detection_triggered()
{
    const int width {3};
    const int height {3};

    int edgeDetect[width][height]
    {
        {-1,  -1, -1},
        {-1,   8, -1},
        {-1   -1, -1}
    };
    mpConvolutionMatrix = &edgeDetect[0][0];
    imageProcessing(0);
}

void MainWindow::on_action_gaussian_blur_triggered()
{
    const int width {3};
    const int height {3};

    int gaussBlur[width][height]
    {
        {1,  1, 1},
        {1,  1, 1},
        {1,  1, 1}
    };
    mpConvolutionMatrix = &gaussBlur[0][0];
    imageProcessing(1);

}

void MainWindow::on_action_crop_triggered()
{
    QImage *cropedImg = new QImage(mEditingImg->width(),
                                   mEditingImg->height() / 2,
                                   QImage::Format_RGB32);

    int y {0};
    for (int i{0}; i < mEditingImg->width() - 2; i++)
    {
        for (int j{0}; j < mEditingImg->height() - 2; j++)
        {
            if (j > mEditingImg->height() / 4 && j < mEditingImg->height() * 3 / 4)
            {
                continue;
            }
            else
            {
                cropedImg->setPixel(i, y, mEditingImg->pixel(i,j));
                y++;
            }
        }
        y = 0;
    }
    ui->label_2->setPixmap(QPixmap::fromImage(*cropedImg));
}
