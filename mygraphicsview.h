#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsRectItem>

class MyGraphicsView : public QGraphicsView
{
public:
    MyGraphicsView(QWidget* parent = NULL);

protected:

    //Take over the interaction
    virtual void wheelEvent(QWheelEvent* event);
};
#endif
