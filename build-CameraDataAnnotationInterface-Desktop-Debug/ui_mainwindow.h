/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include "labelarea.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionImport;
    QAction *actionExport;
    QAction *actionno_elp;
    QAction *actionEdit;
    QWidget *centralWidget;
    QFrame *previewFrame;
    QFrame *previewstepFrame;
    QToolButton *previmgButton;
    QToolButton *nextimgButton;
    QLabel *classSelectedLabel;
    LabelArea *labelarea;
    QPushButton *drawToolButton;
    QPushButton *selectionToolButton;
    QPushButton *moveToolButton;
    QFrame *classFrame;
    QPushButton *newclassButton;
    QPushButton *editclassButton;
    QPushButton *deleteclassButton;
    QTreeWidget *classTreeWidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 768);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setTabShape(QTabWidget::Rounded);
        actionImport = new QAction(MainWindow);
        actionImport->setObjectName(QStringLiteral("actionImport"));
        actionExport = new QAction(MainWindow);
        actionExport->setObjectName(QStringLiteral("actionExport"));
        actionno_elp = new QAction(MainWindow);
        actionno_elp->setObjectName(QStringLiteral("actionno_elp"));
        actionEdit = new QAction(MainWindow);
        actionEdit->setObjectName(QStringLiteral("actionEdit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        previewFrame = new QFrame(centralWidget);
        previewFrame->setObjectName(QStringLiteral("previewFrame"));
        previewFrame->setGeometry(QRect(210, -10, 821, 491));
        previewFrame->setFrameShape(QFrame::StyledPanel);
        previewFrame->setFrameShadow(QFrame::Raised);
        previewstepFrame = new QFrame(previewFrame);
        previewstepFrame->setObjectName(QStringLiteral("previewstepFrame"));
        previewstepFrame->setGeometry(QRect(330, 450, 151, 41));
        previewstepFrame->setFrameShape(QFrame::StyledPanel);
        previewstepFrame->setFrameShadow(QFrame::Raised);
        previmgButton = new QToolButton(previewstepFrame);
        previmgButton->setObjectName(QStringLiteral("previmgButton"));
        previmgButton->setGeometry(QRect(20, 10, 31, 22));
        nextimgButton = new QToolButton(previewstepFrame);
        nextimgButton->setObjectName(QStringLiteral("nextimgButton"));
        nextimgButton->setGeometry(QRect(100, 10, 31, 22));
        classSelectedLabel = new QLabel(previewFrame);
        classSelectedLabel->setObjectName(QStringLiteral("classSelectedLabel"));
        classSelectedLabel->setGeometry(QRect(10, 460, 311, 20));
        classSelectedLabel->setTextFormat(Qt::PlainText);
        labelarea = new LabelArea(previewFrame);
        labelarea->setObjectName(QStringLiteral("labelarea"));
        labelarea->setGeometry(QRect(0, 10, 811, 431));
        labelarea->setMouseTracking(true);
        drawToolButton = new QPushButton(previewFrame);
        drawToolButton->setObjectName(QStringLiteral("drawToolButton"));
        drawToolButton->setGeometry(QRect(500, 460, 80, 23));
        drawToolButton->setStyleSheet(QStringLiteral("background-color: rgb(255,255,255);"));
        selectionToolButton = new QPushButton(previewFrame);
        selectionToolButton->setObjectName(QStringLiteral("selectionToolButton"));
        selectionToolButton->setGeometry(QRect(610, 460, 80, 23));
        selectionToolButton->setStyleSheet(QStringLiteral("background-color: rgb(255,255,255);"));
        moveToolButton = new QPushButton(previewFrame);
        moveToolButton->setObjectName(QStringLiteral("moveToolButton"));
        moveToolButton->setGeometry(QRect(720, 460, 80, 23));
        moveToolButton->setStyleSheet(QStringLiteral("background-color: rgb(255,255,255);"));
        classFrame = new QFrame(centralWidget);
        classFrame->setObjectName(QStringLiteral("classFrame"));
        classFrame->setGeometry(QRect(-10, -10, 221, 491));
        classFrame->setFrameShape(QFrame::StyledPanel);
        classFrame->setFrameShadow(QFrame::Raised);
        newclassButton = new QPushButton(classFrame);
        newclassButton->setObjectName(QStringLiteral("newclassButton"));
        newclassButton->setGeometry(QRect(21, 400, 191, 23));
        newclassButton->setFocusPolicy(Qt::StrongFocus);
        editclassButton = new QPushButton(classFrame);
        editclassButton->setObjectName(QStringLiteral("editclassButton"));
        editclassButton->setGeometry(QRect(21, 430, 111, 23));
        editclassButton->setFocusPolicy(Qt::StrongFocus);
        deleteclassButton = new QPushButton(classFrame);
        deleteclassButton->setObjectName(QStringLiteral("deleteclassButton"));
        deleteclassButton->setGeometry(QRect(140, 430, 71, 23));
        classTreeWidget = new QTreeWidget(classFrame);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(classTreeWidget);
        __qtreewidgetitem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(classTreeWidget);
        __qtreewidgetitem1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(classTreeWidget);
        __qtreewidgetitem2->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        classTreeWidget->setObjectName(QStringLiteral("classTreeWidget"));
        classTreeWidget->setGeometry(QRect(10, 10, 211, 371));
        classTreeWidget->setContextMenuPolicy(Qt::NoContextMenu);
        classTreeWidget->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(10, 500, 981, 201));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 979, 199));
        scrollArea->setWidget(scrollAreaWidgetContents);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 1024, 20));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(menuBar->sizePolicy().hasHeightForWidth());
        menuBar->setSizePolicy(sizePolicy1);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setEnabled(true);
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionImport);
        menuFile->addAction(actionExport);
        menuEdit->addAction(actionEdit);
        menuHelp->addAction(actionno_elp);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Camera Data Annotation Interface", Q_NULLPTR));
        actionImport->setText(QApplication::translate("MainWindow", "Import", Q_NULLPTR));
        actionExport->setText(QApplication::translate("MainWindow", "Export", Q_NULLPTR));
        actionno_elp->setText(QApplication::translate("MainWindow", "Qt Documentation", Q_NULLPTR));
        actionEdit->setText(QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
        previmgButton->setText(QApplication::translate("MainWindow", "<", Q_NULLPTR));
        nextimgButton->setText(QApplication::translate("MainWindow", ">", Q_NULLPTR));
        classSelectedLabel->setText(QApplication::translate("MainWindow", "Current Label: ", Q_NULLPTR));
        classSelectedLabel->setProperty("classSelected", QVariant(QString()));
        drawToolButton->setText(QApplication::translate("MainWindow", "Draw", Q_NULLPTR));
        selectionToolButton->setText(QApplication::translate("MainWindow", "Select", Q_NULLPTR));
        moveToolButton->setText(QApplication::translate("MainWindow", "Move", Q_NULLPTR));
        newclassButton->setText(QApplication::translate("MainWindow", "New Class", Q_NULLPTR));
        editclassButton->setText(QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
        deleteclassButton->setText(QApplication::translate("MainWindow", "Delete", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = classTreeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Class", Q_NULLPTR));

        const bool __sortingEnabled = classTreeWidget->isSortingEnabled();
        classTreeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = classTreeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "Car", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem2 = classTreeWidget->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWindow", "Person", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem3 = classTreeWidget->topLevelItem(2);
        ___qtreewidgetitem3->setText(0, QApplication::translate("MainWindow", "TrafficLight", Q_NULLPTR));
        classTreeWidget->setSortingEnabled(__sortingEnabled);

        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
