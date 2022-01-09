#ifndef EXPORTDIALOG_H
#define EXPORTDIALOG_H

#include <QDialog>

namespace Ui {
class exportdialog;
}

class exportdialog : public QDialog
{
    Q_OBJECT

public:
    explicit exportdialog(QWidget *parent = nullptr);
    ~exportdialog();
    QString get_path();

private slots:
    void on_pushButton_clicked();

private:
    Ui::exportdialog *ui;
    QString path;
};

#endif // EXPORTDIALOG_H
