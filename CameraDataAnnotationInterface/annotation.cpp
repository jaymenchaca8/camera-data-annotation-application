#include "annotation.h"

Annotation::Annotation() :
    class_name("New"), color(QColor(255,0,0,255/3))
{

}

Annotation::Annotation(QString _class_name, QColor _color) :
    class_name(_class_name), color(_color)
{

}

Annotation::~Annotation(){

}

void Annotation::setClassName(QString _class_name){
    this->class_name = _class_name;
}

QString Annotation::getClassName(){
    return class_name;
}

void Annotation::setColor(QColor _color){
    this->color = _color;
}

QColor Annotation::getColor(){
    return color;
}

void Annotation::printList(){
    qDebug() << "Class " << class_name;
    for (int i = 0;i < annot_list.size(); i++) {
        qDebug() << annot_list.at(i);
    }
}

void Annotation::addBand(QGraphicsItem* box){
    annot_list.push_back(box);
}

void Annotation::removeBand(QGraphicsItem* box){
    bool check = annot_list.removeOne(box);
}

//acts more like a pop function, just at a specified index
QGraphicsItem* Annotation::removeBandAt(int i){
    qDebug() << "remove band at " << i;
    QGraphicsItem* box = annot_list.at(i);
    annot_list.removeAt(i);
    return box;

}

QGraphicsItem* Annotation::getBandAt(int i){
    if(annot_list.size() > i){
        return annot_list.at(i);
    }else{
        qDebug() << "band index out of line!";
        return nullptr;
    }
}

QList<QGraphicsItem*> Annotation::getList(){
    return annot_list;
}

//if a box is found within the class's list, return the class name
//used for connecting the class to the box
QString Annotation::whoAmI(QGraphicsItem* box){
    for(int i = 0; i < annot_list.size(); i++){
        if(box == annot_list.at(i)){
            return this->class_name;
        }
    }
    return "";
}
