#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "annotation.h"
#include "clickablelabel.h"
#include "timelineview.h"
#include <QMainWindow>
#include <QRubberBand>
#include <QToolTip>
#include <QHBoxLayout>

#include <QList>
#include <QTreeWidget>

#include <QProcess>
#include <QString>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionImport_triggered();

    void on_actionExport_triggered();

    void on_newclassButton_clicked();

    void on_nextimgButton_clicked();

    void on_previmgButton_clicked();

    void update_timeline(QWidget*);

    void on_classTreeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);

    void on_classTreeWidget_itemChanged(QTreeWidgetItem *item, int column);

    void on_classTreeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_labelarea_boxMade(QGraphicsItem* band);

    void on_labelarea_boxMoved();

    void on_deleteclassButton_clicked();

    void on_labelarea_selectionChanged();

    void on_drawToolButton_clicked();

    void on_selectionToolButton_clicked();

    void on_moveToolButton_clicked();

    void on_editclassButton_clicked();

    void on_actionno_elp_triggered();

    void on_actionEdit_triggered();


private:
    //variables
    Ui::MainWindow *ui;
    QList<Annotation*> class_list;
    QPoint myPoint;
    QRubberBand *rubberBand;
    QTreeWidgetItem *selectedClass;
    QTreeWidgetItem *selectedBox;
    QString prevClass;
    QHBoxLayout *Hlayout;
    timelineView* prev_label = new timelineView();
    int num_images;
    QString localDir;
    QList<QGraphicsScene*> scenes;
    bool box_transfer = true;

    //functions
    void draw_picture(QString,int);
    void timeline(QString);
    void get_num_images(QString);
    Annotation* getAnnotationFromCurrentClass();
    Annotation* getAnnotationFromClass(QString className);
    QTreeWidgetItem* findItemInList(QGraphicsItem* item);
    void readClassList();
    QString printAnnotations();
    void keyPressEvent(QKeyEvent *e);
    void setupGraphicScenes();
    void copyBoxes(int scene_num);
    void updateTreeList();
    void import_box_made(QGraphicsItem *band, Annotation* annon, int scene_num);

};

#endif // MAINWINDOW_H
