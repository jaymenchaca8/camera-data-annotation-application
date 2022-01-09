#ifndef ANNOTATION_H
#define ANNOTATION_H

#include <QString>
#include <QColor>
#include <QGraphicsView>
#include <QDebug>

class Annotation {
  public:
    Annotation();
    Annotation(QString _class_name, QColor _color);
    ~Annotation();

    void setClassName(QString _class_name);
    QString getClassName();
    void setColor(QColor _color);
    QColor getColor();
    void printList();

    void addBand(QGraphicsItem* box);
    void removeBand(QGraphicsItem* box);

    //acts more like a pop function
    QGraphicsItem* removeBandAt(int i);

    QGraphicsItem* getBandAt(int i);

    QList<QGraphicsItem*> getList();
    //used to help find which label a certain box has
    QString whoAmI(QGraphicsItem* box);

  private:
    QString class_name;
    QColor color;
    //associated graphics items should be stored here
    QList<QGraphicsItem*> annot_list;

};

#endif // ANNOTATION_H
