#ifndef IMPORTDIALOG_H
#define IMPORTDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class ImportDialog;
}

class ImportDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ImportDialog(QWidget *parent = nullptr);
    ~ImportDialog();
    QString get_path();
    QString get_topic();
    QString get_box_path();

private slots:
    void on_pushButton_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_pushButton_2_clicked();

private:
    Ui::ImportDialog *ui;
    QString path = "";
    QString box_path = "";
};

#endif // IMPORTDIALOG_H
