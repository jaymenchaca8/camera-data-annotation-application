#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include <QColorDialog>

settingsdialog::settingsdialog(QList<Annotation*> _class_list, bool box_transfer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settingsdialog)
{
    ui->setupUi(this);

    class_list = _class_list;
    for(Annotation* a : class_list) {
        ui->comboBox_class->addItem(a->getClassName());
    }

    //ui->comboBox_class->setCurrentText("tree");
    int index = ui->comboBox_class->currentIndex();
    ui->lineEdit_color->setText(class_list.at(index)->getColor().name());
    ui->lineEdit_alpha->setText(QString::number(class_list.at(index)->getColor().alphaF()));

    ui->checkBox->setChecked(box_transfer);
}

settingsdialog::~settingsdialog()
{
    delete ui;
}

void settingsdialog::on_pushButton_color_clicked()
{
    int index = ui->comboBox_class->currentIndex();
    QColor t = class_list.at(index)->getColor();
    QColor color = QColorDialog::getColor(t,this,"Choose Color");
    if(color.isValid()) {
        color.setAlphaF(class_list.at(index)->getColor().alphaF());
        class_list.at(index)->setColor(color);
        ui->lineEdit_color->setText(class_list.at(index)->getColor().name());
    }
}

void settingsdialog::on_comboBox_class_currentIndexChanged(int index)
{
    ui->lineEdit_color->setText(class_list.at(index)->getColor().name());
    ui->lineEdit_alpha->setText(QString::number(class_list.at(index)->getColor().alphaF()));
}

void settingsdialog::on_buttonBox_accepted()
{
    bool ok;
    int index = ui->comboBox_class->currentIndex();
    QColor new_color = class_list.at(index)->getColor();
    double d = ui->lineEdit_alpha->text().toDouble(&ok);
    new_color.setAlphaF(d);
    class_list.at(index)->setColor(new_color);
}

bool settingsdialog::get_checked(){
    if(ui->checkBox->checkState() == Qt::Unchecked)
        return false;
    else {
        return true;
    }
}
