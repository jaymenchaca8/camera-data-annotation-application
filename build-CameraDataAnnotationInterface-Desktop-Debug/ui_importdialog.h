/********************************************************************************
** Form generated from reading UI file 'importdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTDIALOG_H
#define UI_IMPORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ImportDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_2;
    QLabel *label;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QPushButton *pushButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ImportDialog)
    {
        if (ImportDialog->objectName().isEmpty())
            ImportDialog->setObjectName(QStringLiteral("ImportDialog"));
        ImportDialog->resize(532, 359);
        verticalLayout = new QVBoxLayout(ImportDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(ImportDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        lineEdit_3 = new QLineEdit(ImportDialog);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setEnabled(true);
        lineEdit_3->setMaximumSize(QSize(300, 16777215));

        gridLayout->addWidget(lineEdit_3, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(ImportDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 2, 1, 1);

        label = new QLabel(ImportDialog);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(40, 16777215));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox = new QComboBox(ImportDialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 1, 1, 1, 1);

        lineEdit = new QLineEdit(ImportDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMaximumSize(QSize(300, 16777215));

        gridLayout->addWidget(lineEdit, 2, 1, 1, 1);

        label_4 = new QLabel(ImportDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        pushButton = new QPushButton(ImportDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(ImportDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ImportDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ImportDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ImportDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ImportDialog);
    } // setupUi

    void retranslateUi(QDialog *ImportDialog)
    {
        ImportDialog->setWindowTitle(QApplication::translate("ImportDialog", "Import Options", Q_NULLPTR));
        label_3->setText(QApplication::translate("ImportDialog", "image topic", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("ImportDialog", "Browse", Q_NULLPTR));
        label->setText(QApplication::translate("ImportDialog", "File", Q_NULLPTR));
        label_4->setText(QApplication::translate("ImportDialog", "Bounding\n"
"boxes", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ImportDialog", "Browse", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ImportDialog: public Ui_ImportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTDIALOG_H
