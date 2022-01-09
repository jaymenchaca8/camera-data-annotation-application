// https://github.com/sashoalm/ResizableRectItem

#ifndef RESIZABLERECTITEM_H
#define RESIZABLERECTITEM_H

#include <QGraphicsRectItem>
#include <QPen>
#include <QBrush>

class ResizableRectItemSettings;

class ResizableRectItem : public QGraphicsRectItem
{
public:
    ResizableRectItem(QRectF rect, ResizableRectItemSettings *settings, QGraphicsItem *parent = nullptr);
    void changeColor(QColor _color);
    void setClass(QString _class_name);
    QString getClass();

private:
    ResizableRectItemSettings *settings;
    QString class_name;
    QRectF getInnerRect() const;

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void resizeRect(QGraphicsSceneMouseEvent *event);

};

#endif // RESIZABLERECTITEM_H
