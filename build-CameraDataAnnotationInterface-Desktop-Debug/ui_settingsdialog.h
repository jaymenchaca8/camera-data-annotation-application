/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settingsdialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_3;
    QComboBox *comboBox_class;
    QLineEdit *lineEdit_alpha;
    QPushButton *pushButton_color;
    QLabel *label_2;
    QLineEdit *lineEdit_color;
    QCheckBox *checkBox;
    QLabel *label_4;

    void setupUi(QDialog *settingsdialog)
    {
        if (settingsdialog->objectName().isEmpty())
            settingsdialog->setObjectName(QStringLiteral("settingsdialog"));
        settingsdialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(settingsdialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(230, 270, 166, 24));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(settingsdialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 381, 251));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        comboBox_class = new QComboBox(layoutWidget);
        comboBox_class->setObjectName(QStringLiteral("comboBox_class"));

        gridLayout->addWidget(comboBox_class, 1, 1, 1, 1);

        lineEdit_alpha = new QLineEdit(layoutWidget);
        lineEdit_alpha->setObjectName(QStringLiteral("lineEdit_alpha"));

        gridLayout->addWidget(lineEdit_alpha, 3, 1, 1, 1);

        pushButton_color = new QPushButton(layoutWidget);
        pushButton_color->setObjectName(QStringLiteral("pushButton_color"));

        gridLayout->addWidget(pushButton_color, 2, 2, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        lineEdit_color = new QLineEdit(layoutWidget);
        lineEdit_color->setObjectName(QStringLiteral("lineEdit_color"));

        gridLayout->addWidget(lineEdit_color, 2, 1, 1, 1);

        checkBox = new QCheckBox(layoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 0, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);


        retranslateUi(settingsdialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), settingsdialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), settingsdialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(settingsdialog);
    } // setupUi

    void retranslateUi(QDialog *settingsdialog)
    {
        settingsdialog->setWindowTitle(QApplication::translate("settingsdialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("settingsdialog", "color", Q_NULLPTR));
        label_3->setText(QApplication::translate("settingsdialog", "class", Q_NULLPTR));
        pushButton_color->setText(QApplication::translate("settingsdialog", "select", Q_NULLPTR));
        label_2->setText(QApplication::translate("settingsdialog", "alpha", Q_NULLPTR));
        checkBox->setText(QString());
        label_4->setText(QApplication::translate("settingsdialog", "Prompt\n"
"Box Copy", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class settingsdialog: public Ui_settingsdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
