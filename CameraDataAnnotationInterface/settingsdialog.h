#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include "annotation.h"

namespace Ui {
class settingsdialog;
}

class settingsdialog : public QDialog
{
    Q_OBJECT

public:
    explicit settingsdialog(QWidget *parent = nullptr);
    explicit settingsdialog(QList<Annotation*> _class_list,bool box_transfer, QWidget *parent = nullptr);
    ~settingsdialog();
    bool get_checked();

private slots:
    void on_pushButton_color_clicked();

    void on_comboBox_class_currentIndexChanged(int index);

    void on_buttonBox_accepted();

private:
    Ui::settingsdialog *ui;
    QList<Annotation*> class_list;

};

#endif // SETTINGSDIALOG_H
