#ifndef LABELAREA_H
#define LABELAREA_H

#include "resizablerectitem.h"
#include "resizablerectitemsettings.h"
#include <QGraphicsView>
#include <QWheelEvent>


class LabelArea : public QGraphicsView
{
    Q_OBJECT
public:
    LabelArea(QWidget *parent=nullptr);
    QGraphicsScene* setupScene();
    void displayImg(const QImage &image, QGraphicsScene* _scene);
    bool eventFilter(QObject *watched, QEvent *event);
    QGraphicsScene* getScene();
    void setColor(QColor _color);
    QColor getColor();
    void unselectAll();
    void setCurrentClass(QString _class);

protected:
    void wheelEvent(QWheelEvent *event)
      {
          qreal deltaScale = 1;
          deltaScale += event->delta() > 0 ? 0.1 : -0.1;
          setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
          scale(deltaScale, deltaScale);
      }
signals:
    void boxMade(QGraphicsItem* band);
    void boxMoved();

private:
    QPixmap pixmap;
    QGraphicsPixmapItem *pixmapItem;
    QPointF* clickedPoint = new QPointF();
    QColor color;
    QString currentClass;
};

#endif // LABELAREA_H
