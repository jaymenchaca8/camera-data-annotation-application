#include "labelarea.h"

#include <QEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QPainter>
#include <QPen>


LabelArea::LabelArea(QWidget *parent):
    QGraphicsView(parent)
{
    //setup scene
    QGraphicsScene* _1scene = setupScene();
    setScene(_1scene);
}

QGraphicsScene* LabelArea::setupScene() {
    //scene creation
    QGraphicsScene* _scene = new QGraphicsScene(this);
    _scene->setSceneRect(0,0,600,800);
    _scene->installEventFilter(this);

    //draw grid
    QGraphicsRectItem *rect = new QGraphicsRectItem(-400,-400,1200,1200);//also needs proper scaling
    rect->setFlag(QGraphicsItem::ItemIgnoresTransformations);
    QPen pen;
    pen.setColor(Qt::black);
    rect->setBrush(Qt::CrossPattern);
    rect->setPen(pen);
    rect->setOpacity(0.5);
    rect->setZValue(-1); //sends to back (probably not proper)
    _scene->addItem(rect);
    return _scene;
}

void LabelArea::displayImg(const QImage &image, QGraphicsScene* _scene){
    pixmap=QPixmap::fromImage(image);
    pixmapItem=new QGraphicsPixmapItem(pixmap);
    _scene->addItem(pixmapItem);
    setSceneRect(image.rect());
    fitInView(pixmapItem, Qt::KeepAspectRatio);
    centerOn(pixmapItem);
}

bool LabelArea::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == scene()){

        // prevents selecting box while in draw mode
        for(QGraphicsItem *item : scene()->items()) {
            ResizableRectItem *test = dynamic_cast<ResizableRectItem*>(item);
            if(test != nullptr){
                if(this->dragMode() == QGraphicsView::RubberBandDrag){
                    test->setFlag(QGraphicsItem::ItemIsMovable,false);
                    test->setFlag(QGraphicsItem::ItemIsSelectable,false);
                }
                else{
                    test->setFlag(QGraphicsItem::ItemIsMovable,true);
                    test->setFlag(QGraphicsItem::ItemIsSelectable,true);
                }
            }
        }

        // press event
        QGraphicsSceneMouseEvent *mouseSceneEvent;
        if(event->type() == QEvent::GraphicsSceneMousePress){
            mouseSceneEvent = static_cast<QGraphicsSceneMouseEvent *>(event);
            clickedPoint = new QPointF(mouseSceneEvent->scenePos());
            qDebug() << *clickedPoint;
        }

        // move event
        else if (event->type() == QEvent::GraphicsSceneMouseMove) {
            mouseSceneEvent = static_cast<QGraphicsSceneMouseEvent *>(event);
        }

        // release event
        else if (event->type() == QEvent::GraphicsSceneMouseRelease) {
            if(this->dragMode() != QGraphicsView::RubberBandDrag){
                emit boxMoved();
                return false;
            }

            mouseSceneEvent = static_cast<QGraphicsSceneMouseEvent *>(event);
            QPointF test(*clickedPoint);
            QRectF rect;
            //get correct top left and bottom right points (necessary for resiablerectitem class)
            double topleftx = qMin(mouseSceneEvent->scenePos().x(), test.x());
            double toplefty = qMin(mouseSceneEvent->scenePos().y(), test.y());
            double botrightx = qMax(mouseSceneEvent->scenePos().x(), test.x());
            double botrighty = qMax(mouseSceneEvent->scenePos().y(), test.y());
            rect = QRectF(QPointF(topleftx,toplefty),QPointF(botrightx,botrighty));
            qDebug() << rect;

            //setup rect background
            QBrush brush(color);
            ResizableRectItemSettings *settings = new ResizableRectItemSettings(
                        15, QSizeF(30, 30), QSizeF(2048, 2048),
                        Qt::DashLine, brush);
            ResizableRectItem *item = new ResizableRectItem(rect, settings);
            item->changeColor(color);
            item->setBrush(brush);
            item->setFlag(QGraphicsItem::ItemIsMovable);
            item->setFlag(QGraphicsItem::ItemIsSelectable);
            item->setClass(currentClass);
            scene()->addItem(item);

            emit boxMade(item);
        }
    }
    return QGraphicsView::eventFilter(watched, event);
}

QGraphicsScene* LabelArea::getScene(){
    return scene();
}

void LabelArea::unselectAll(){
    scene()->clearSelection();
    qDebug() << "all boxes unselected";
}

void LabelArea::setColor(QColor _color){
    color = _color;
}

void LabelArea::setCurrentClass(QString _class) {
    currentClass = _class;
}
