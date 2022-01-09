#include "importdialog.h"
#include "ui_importdialog.h"
#include <QFileDialog>
#include <QProcess>
#include <QDebug>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <QString>

ImportDialog::ImportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImportDialog)
{
    ui->setupUi(this);
}

ImportDialog::~ImportDialog()
{
    delete ui;
}

QString ImportDialog::get_path() {
    return path;
}

QString ImportDialog::get_topic() {
    return ui->comboBox->currentText();
}

void ImportDialog::on_pushButton_clicked()
{
    QString filter = "All File (*.*) ;; Bag File (*.bag)";
    QString file_path = QFileDialog::getOpenFileName(this, "open file", QDir::homePath(), filter);
    path = file_path;
    QString file_name = (file_path.toStdString().substr(file_path.toStdString().find_last_of("/\\") + 1)).c_str();
    ui->lineEdit_3->setText(file_name);
    QProcess *p = new QProcess();
    QStringList topic_params;
    topic_params << "../CameraDataAnnotationInterface/topic_extraction.py" << file_path;
    //for release
    //topic_params << "topic_extraction.py" << file_path;
    p->execute("python", topic_params);

    std::vector<QString> topiclist; // topiclist stores the list of avaliable topics
    std::string line;
    std::ifstream myfile ("topiclist.txt");
    if (myfile.is_open())
    {
      while ( getline (myfile, line) )
      {
        topiclist.push_back(QString::fromStdString(line));
      }
      myfile.close();
    }
    else{ qDebug() << "toplic list file can't be opened"; }

    ui->comboBox->clear();
    for(QString topic : topiclist) {
        ui->comboBox->addItem(topic.toStdString().c_str());
    }
}

void ImportDialog::on_buttonBox_accepted()
{
    this->close();
}

void ImportDialog::on_buttonBox_rejected()
{
    this->close();
}

QString ImportDialog::get_box_path() {
    return box_path;
}

void ImportDialog::on_pushButton_2_clicked()
{
    QString filter = "All File (*.*) ;; Txt File (*.txt)";
    QString file_path = QFileDialog::getOpenFileName(this, "open file", QDir::homePath(), filter);
    box_path = file_path;
    QString file_name = (file_path.toStdString().substr(file_path.toStdString().find_last_of("/\\") + 1)).c_str();
    ui->lineEdit->setText(file_name);
}
