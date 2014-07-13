#include "mygraphicsview.h"

//Qt includes
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTextStream>
#include <QScrollBar>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QDebug>

/**
* Sets up the subclassed QGraphicsView
*/
MyGraphicsView::MyGraphicsView(QWidget* parent) : QGraphicsView(parent) {

    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    //Set-up the scene
    QGraphicsScene* Scene = new QGraphicsScene(this);
    setScene(Scene);


//  //Populate the scene
//    for(int x = 0; x < 1000; x = x + 25) {
//        for(int y = 0; y < 1000; y = y + 25) {

//            if(x % 100 == 0 && y % 100 == 0) {
//                Scene->addRect(x, y, 2, 2);

//                QString pointString;
//                QTextStream stream(&pointString);
//                stream << "(" << x << "," << y << ")";                QGraphicsTextItem* item = Scene->addText(pointString);
//                item->setPos(x, y);
//            } else {
//                Scene->addRect(x, y, 1, 1);
//            }
//        }
//    }

    //Set-up the view
    setSceneRect(0, 0, 1000, 1000);

    //Use ScrollHand Drag Mode to enable Panning
    setDragMode(ScrollHandDrag);
}

/**
  * Zoom the view in and out.
  */
void MyGraphicsView::wheelEvent(QWheelEvent* event) {

    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    // Scale the view / do the zoom
    double scaleFactor = 1.15;
    if(event->delta() > 0) {
        // Zoom in
        scale(scaleFactor, scaleFactor);
    } else {
        // Zooming out
        scale(1.0 / scaleFactor, 1.0 / scaleFactor);
    }

    // Don't call superclass handler here
    // as wheel is normally used for moving scrollbars
}
