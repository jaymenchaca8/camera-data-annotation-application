#include "exportdialog.h"
#include "ui_exportdialog.h"
#include <QFileDialog>

exportdialog::exportdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::exportdialog)
{
    ui->setupUi(this);
}

exportdialog::~exportdialog()
{
    delete ui;
}

QString exportdialog::get_path() {
    return path;
}

void exportdialog::on_pushButton_clicked()
{
     QString filter = "All File (*.*)";
     QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                  QDir::currentPath(),
                                                  QFileDialog::ShowDirsOnly
                                                  | QFileDialog::DontResolveSymlinks);
     path = dir;
     ui->lineEdit->setText(dir);
}


