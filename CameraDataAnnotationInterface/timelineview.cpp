
#include "timelineview.h"

#include <QDebug>
#include <QResizeEvent>
#include <QPixmap>
#include <QGraphicsPixmapItem>

timelineView::timelineView(QWidget *parent):
    QGraphicsView(parent){}


void timelineView::mousePressEvent(QMouseEvent* event) {
    emit clicked();
}

void timelineView::resizeEvent(QResizeEvent *event){
    QWidget::resizeEvent(event);

    this->fitInView(item, Qt::KeepAspectRatio);
}

void timelineView::setFrameNum(int _frame_num) {
    this->frame_num = _frame_num;
}

int timelineView::getFrameNum() {
    return frame_num;
}

void timelineView::setImagePath(QString _image_path) {
    this->image_path = _image_path;
}

QString timelineView::getImagePath() {
    return image_path;
}


