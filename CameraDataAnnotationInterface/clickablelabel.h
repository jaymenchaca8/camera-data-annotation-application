#ifndef CLICKABLELABLE_H
#define CLICKABLELABLE_H

#include <QLabel>
#include <QWidget>
#include <Qt>
#include <QString>

class clickablelabel : public QLabel {
    Q_OBJECT

public:
    explicit clickablelabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~clickablelabel();

    void setFrameNum(int _frame_num);
    int getFrameNum();
    void setImagePath(QString _image_path);
    QString getImagePath();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);

private:
    int frame_num;
    QString image_path;

};

#endif // CLICKABLELABLE_H
