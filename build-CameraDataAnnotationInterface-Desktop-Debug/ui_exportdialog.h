/********************************************************************************
** Form generated from reading UI file 'exportdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTDIALOG_H
#define UI_EXPORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_exportdialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *exportdialog)
    {
        if (exportdialog->objectName().isEmpty())
            exportdialog->setObjectName(QStringLiteral("exportdialog"));
        exportdialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(exportdialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(exportdialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 30, 371, 61));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);


        retranslateUi(exportdialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), exportdialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), exportdialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(exportdialog);
    } // setupUi

    void retranslateUi(QDialog *exportdialog)
    {
        exportdialog->setWindowTitle(QApplication::translate("exportdialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("exportdialog", "Destination:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("exportdialog", "Browse", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class exportdialog: public Ui_exportdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTDIALOG_H
