#include "mainwindow.h"

#include <QApplication>
#include <QtGui>
#include <QGraphicsView>

static const int logoCount = 6;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QGraphicsScene scene;
    // from monitor center
    scene.setSceneRect(-300, -300, 600, 600);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);
    for (int i{0}; i < logoCount; i++)
    {
        Logo *myLogo = new Logo(i % 5);
        scene.addItem(myLogo);
    }
    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setBackgroundBrush(QPixmap(":/img/download.jpeg"));
    view.setCacheMode(QGraphicsView::CacheBackground);
        view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
        view.setDragMode(QGraphicsView::ScrollHandDrag);
    view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Dice"));
        view.resize(500, 500);
        view.show();

        QTimer timer;
        QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
        timer.start(1000 / 33);

        QPen mypen = QPen(Qt::red);
        QLineF topLine(scene.sceneRect().topLeft(), scene.sceneRect().topRight());
        QLineF leftLine(scene.sceneRect().topLeft(), scene.sceneRect().bottomLeft());
        QLineF rightLine(scene.sceneRect().topRight(), scene.sceneRect().bottomRight());
        QLineF bottomLine(scene.sceneRect().bottomLeft(), scene.sceneRect().bottomRight());
        scene.addLine(topLine, mypen);
        scene.addLine(leftLine, mypen);
        scene.addLine(rightLine, mypen);
        scene.addLine(bottomLine, mypen);
        return app.exec();
}
