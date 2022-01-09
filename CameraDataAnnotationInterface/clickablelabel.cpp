#include "clickablelabel.h"
#include <QDebug>

clickablelabel::clickablelabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent) {

}

clickablelabel::~clickablelabel() {}

void clickablelabel::mousePressEvent(QMouseEvent* event) {
    emit clicked();
}

void clickablelabel::setFrameNum(int _frame_num) {
    this->frame_num = _frame_num;
}

int clickablelabel::getFrameNum() {
    return frame_num;
}

void clickablelabel::setImagePath(QString _image_path) {
    this->image_path = _image_path;
}

QString clickablelabel::getImagePath() {
    return image_path;
}
