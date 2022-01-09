#ifndef TIMELINEVIEW_H
#define TIMELINEVIEW_H

#include <QGraphicsView>

class timelineView : public QGraphicsView
{
    Q_OBJECT
public:
    timelineView(QWidget *parent=nullptr);
    void resizeEvent(QResizeEvent *event);
    void setFrameNum(int _frame_num);
    int getFrameNum();
    void setImagePath(QString _image_path);

    QString getImagePath();
    QGraphicsPixmapItem *item;

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);

private:
    int frame_num;
    QString image_path;

};

#endif // TIMELINEVIEW_H
