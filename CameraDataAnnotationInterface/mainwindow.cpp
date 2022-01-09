#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "importdialog.h"
#include "settingsdialog.h"
#include "exportdialog.h"
#include "annotation.h"
#include "clickablelabel.h"
#include "labelarea.h"
#include "timelineview.h"
#include "resizablerectitem.h"
#include <QFileDialog>
#include <QPixmap>
#include <QProcess>
#include <QList>
#include <QDebug>
#include <QLocale>
#include <QSignalMapper>
#include <QScrollBar>
#include <QRubberBand>
#include <QMouseEvent>
#include <QtGlobal>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <QMessageBox>
#include <QGraphicsItem>
#include <QDesktopServices>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Annotation *Car = new Annotation("Car",QColor(255,0,0,255/3));
    Annotation *Person = new Annotation("Person",QColor(0,255,0,255/3));
    Annotation *TrafficLight = new Annotation("TrafficLight",QColor(0,0,255,255/3));
    class_list.push_back(Car);
    class_list.push_back(Person);
    class_list.push_back(TrafficLight);
    readClassList();
    selectedClass = ui->classTreeWidget->topLevelItem(0);
    prevClass = nullptr;
    ui->classTreeWidget->setCurrentItem(selectedClass);
    QString stringLabel = "Current Label: " + selectedClass->text(0);
    ui->classSelectedLabel->setText(stringLabel);

    selectedBox = nullptr;

    ui->nextimgButton->setEnabled(false);
    ui->previmgButton->setEnabled(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//just used for testing
void MainWindow::readClassList(){
    qDebug() << "Class List:";
    for(int i = 0; i < class_list.size(); i++){
        qDebug() << class_list.at(i)->getClassName();
    }
}

//this can be used in exportation to gather all the meta data for the annotations
QString MainWindow::printAnnotations(){

    for(int i = 0; i < class_list.size(); i++){
        for(int j = 0; j < class_list.at(i)->getList().size(); j++){
            //get stuff from each rubberBand
            QGraphicsItem *temp = class_list.at(i)->getList().at(j);
        }
    }
    return "Out";
}

// function goal: update timeline to selected frame
// moves timeline based on distance between prev_label frame and selected frame
// call draw_picture to update main image to selected image
void MainWindow::update_timeline(QWidget *label) {
    timelineView *cur_label = qobject_cast<timelineView *>(label);
    prev_label->setStyleSheet("");
    cur_label->setStyleSheet("border: 3px solid blue;");

    if(cur_label->getFrameNum() - prev_label->getFrameNum() == 1 && box_transfer) {
        copyBoxes(cur_label->getFrameNum());
    }

    if(cur_label->getFrameNum() > prev_label->getFrameNum()) {
        if(cur_label->getFrameNum() > 2) {
            ui->scrollArea->horizontalScrollBar()->setValue(171 * (cur_label->getFrameNum()-2));
        }
    }
    else {
        if(cur_label->getFrameNum() < num_images-3) {
            ui->scrollArea->horizontalScrollBar()->setValue(171 * (cur_label->getFrameNum()-2));
        }
    }

    draw_picture(cur_label->getImagePath(), cur_label->getFrameNum());
    prev_label = cur_label;

}

void MainWindow::copyBoxes(int scene_num){
    timelineView *view;
    QGraphicsScene *scene;
    switch( QMessageBox::question(
                this,
                tr("Camera Data Annotation Interface"),
                tr("Would you like to copy the boxes to this scene?"),

                QMessageBox::Yes |
                QMessageBox::No ) )
    {
      case QMessageBox::Yes:
        qDebug( "yes" );
        for(QGraphicsItem *item : scenes.at(scene_num-1)->items()) {
            ResizableRectItem *test = dynamic_cast<ResizableRectItem*>(item);
            if(test != nullptr){
                QRectF newr(test->sceneBoundingRect().topLeft(), test->sceneBoundingRect().bottomRight());
                ResizableRectItemSettings *settings = new ResizableRectItemSettings(
                            15, QSizeF(30, 30), QSizeF(2048, 2048),
                            Qt::DashLine, getAnnotationFromClass(test->getClass())->getColor());
                ResizableRectItem *item = new ResizableRectItem(newr,settings);
                item->setClass(test->getClass());
                item->setBrush(getAnnotationFromClass(test->getClass())->getColor());
                item->setFlag(QGraphicsItem::ItemIsMovable);
                item->setFlag(QGraphicsItem::ItemIsSelectable);
                scenes.at(scene_num)->addItem(item);
                import_box_made(item,getAnnotationFromClass(test->getClass()),scene_num);
            }
        }
        break;

      case QMessageBox::No:
        qDebug( "no" );
        break;
      default:
        qDebug( "close" );
        break;
    }
}

// function goal: create timeline using every image within ros bag topic
// get number of images within /images directory and stores it in num_images
// signalmapper to create dynamic signal/slot connection, allowing to pass widget to slot function
// boxlayout on top of widget for scaling purposes
// loop finds each image path, sets clickable label's pixmap to it, and then creates connection to slot function
void MainWindow::timeline(QString directory) {
    get_num_images(directory);
    setupGraphicScenes();

    QSignalMapper * mapper = new QSignalMapper(this);
    connect(mapper,SIGNAL(mapped(QWidget *)),this,SLOT(update_timeline(QWidget *)));

    QWidget *window = new QWidget(this);
    Hlayout = new QHBoxLayout(window);

    for(int i = 0; i < num_images; i ++) {
        timelineView *view = new timelineView();

        char s[32];
        int len = sprintf(s, "%d", i);
        QString frame_num = "";
        for(int x = 0; x < 6-len; x++){
            frame_num.append("0");
        }
        frame_num.append(QString::number(i));
        QString image_path = QDir::currentPath() + "/" + directory;
        QString frame_path = image_path + "/frame" + frame_num + ".png";
        qDebug() << frame_path.toStdString().c_str();

        //load in image and scale it
        QImage *image = new QImage();
        image->load(frame_path);
        *image = image->scaled(165, 165);

        //setup scene and view
        QGraphicsScene* scene = new QGraphicsScene(this);
        view->setScene(scene);
        view->item = new QGraphicsPixmapItem(QPixmap::fromImage(*image));
        scene->addItem(view->item);
        view->setFixedSize(165,165);
        view->setSceneRect(0,0,165,165);
        view->fitInView(0,0,165,165,Qt::KeepAspectRatio);

        //connect view to slot function and set indexing functions
        connect(view,SIGNAL(clicked()),mapper,SLOT(map()));
        mapper->setMapping(view, view);
        view->setFrameNum(i);
        view->setImagePath(frame_path);

        Hlayout->addWidget(view);

        ui->labelarea->displayImg(QImage(frame_path.toStdString().c_str()), scenes.at(i));
    }

    ui->scrollArea->setWidget(window);
    Hlayout->itemAt(0)->widget()->setStyleSheet("border: 3px solid blue;");
    prev_label = qobject_cast<timelineView *>(Hlayout->itemAt(0)->widget());
    ui->nextimgButton->setEnabled(true);
    ui->previmgButton->setEnabled(true);
}

void MainWindow::setupGraphicScenes() {
    for(int i = 0; i < num_images; i++) {
        scenes.push_back(ui->labelarea->setupScene());
    }
}

// function goal: get number of images within directory
// uses dirent.h and while loop to count number of files (including hidden files)
// currently only checks /images directory
void MainWindow::get_num_images(QString directory) {
    int total_num_imgs = 0;
    QString images_path = QDir::currentPath() + "/" + directory;
    QDir dir(images_path);
    dir.setFilter( QDir::AllEntries | QDir::NoDotAndDotDot );
    total_num_imgs = dir.count();
    num_images = total_num_imgs;
    qDebug() << "num imgs: " << num_images;
}

//funciton goal: correctly display list for the made boxes of the current image
//should be called everytime the image is changed
void MainWindow::updateTreeList(){
    //clear tree here
    for(int i = 0; i < ui->classTreeWidget->topLevelItemCount(); i++){
        QTreeWidgetItem* parent = ui->classTreeWidget->topLevelItem(i);
        QList<QTreeWidgetItem*> childList = parent->takeChildren();
        while(!childList.isEmpty()){
            delete childList.takeFirst();
        }
    }

    QGraphicsScene* currentScene = ui->labelarea->scene();
    QList<QGraphicsItem*> boxList = currentScene->items();

    qDebug() << "boxList:";
    for(int i = 0; i < boxList.size(); i++){
        qDebug() << boxList.at(i);
    }

    //re-add boxes back into the list
    for(int i = 0; i < boxList.size(); i++){
        QString className;
        for(int j = 0; j < class_list.size(); j++){
            className = class_list.at(j)->whoAmI(boxList.at(i));
            if( className != ""){
                //add to tree
                QTreeWidgetItem* parent = ui->classTreeWidget->findItems(className,Qt::MatchExactly,0).first();
                QString shapeName = "_";
                QTreeWidgetItem *child = new QTreeWidgetItem();

                shapeName = "Rectangle" + QString::number(parent->childCount());

                child->setText(0, shapeName);
                parent->addChild(child);
                ui->classTreeWidget->setCurrentItem(child);
            }
        }
    }

}

// function goal: draw image to screen
// Creates Pixmap of passed in frame located in images directory
// set picture label pixmap
void MainWindow::draw_picture(QString source, int loc){
    //used promoted widget label area of type LabelArea
    //draw image on labelarea
    ui->labelarea->setScene(scenes.at(loc));

    LabelArea* l = ui->labelarea;
    connect(l,SIGNAL(boxMade(QGraphicsItem*)),this,SLOT(on_labelarea_boxMade(QGraphicsItem*)),Qt::UniqueConnection);

    //signal to class tree that a box in the label area has been selected
    //currently disconnected
    //connect(l->getScene(),SIGNAL(selectionChanged()),this,SLOT(on_labelarea_selectionChanged()),Qt::UniqueConnection);

    connect(l,SIGNAL(boxMoved()),this,SLOT(on_labelarea_boxMoved()),Qt::UniqueConnection);
    updateTreeList();
    qDebug() << "Current Scene " << ui->labelarea->scene();
}

// function goal: import functionality
// calls import dialog gui
// calls import dialog's getters to obtain file path and params
// calls extract.py, passing in bag location and image destination
// calls draw_picture to display images to screen
void MainWindow::on_actionImport_triggered()
{
    ImportDialog importDialog;
    importDialog.setModal(true);
    importDialog.exec();
    if(importDialog.get_path() == "")
        return;

    QString file_path = importDialog.get_path();

    // execute topic_extraction.py to retrive the list of topics

    localDir = importDialog.get_topic();
    std::replace( localDir.begin(), localDir.end(), '/', '_'); // replace all '/' to '_' for the name of directory
    qDebug() << localDir.toStdString().c_str();

    QProcess *p = new QProcess();
    QString image_path = QDir::currentPath() + "/"+ localDir;
    qDebug() << image_path.toStdString().c_str();
    QStringList image_params;

    image_params << "../CameraDataAnnotationInterface/image_extraction.py" << file_path << importDialog.get_topic().toStdString().c_str();
    //for release
    //image_params << "image_extraction.py" << file_path << importDialog.get_topic().toStdString().c_str();
    qDebug() << image_params;
    setCursor(Qt::WaitCursor);
    p->execute("python", image_params);

    timeline(localDir);
    draw_picture(localDir + "/frame000000.png",0);
    setCursor(Qt::ArrowCursor);

    // WAITING FOR CLASS TO BE ADDED TO EXPORT
    if(importDialog.get_box_path() == ""){
        return;
    }
    p->waitForFinished();
    QFile file(importDialog.get_box_path());
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(nullptr, "error", file.errorString());
    }
    QTextStream in(&file);

    //code for adding boxes back into the interface after importation
    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if(fields.at(0).contains("image")){
            int pic_num = fields.at(0).split(" ")[1].toInt()-1;
            QString annotation = fields.at(0).split(" ")[6];
            qDebug() << pic_num;
            qDebug() << annotation;
            if(!class_list.contains(getAnnotationFromClass(annotation))){
                qDebug() << "create new class on import";
                QString className = annotation;
                srand(time(NULL));
                int r = rand() % 256;
                int g = rand() % 256;
                int b = rand() % 256;
                Annotation *newClass = new Annotation(className,QColor(r,g,b,255/3));
                class_list.push_back(newClass);

                QTreeWidgetItem *newItem = new QTreeWidgetItem();
                newItem->setText(0, className);
                auto currentFlags = newItem->flags();
                newItem->setFlags(currentFlags | Qt::ItemIsEditable);
                ui->classTreeWidget->addTopLevelItem(newItem);
                qDebug() << "top level item count " << ui->classTreeWidget->topLevelItemCount();

                readClassList();

            }

            qDebug() << "annotation name: " << annotation;
            double width = in.readLine().split(" ").at(3).toDouble();
            double height = in.readLine().split(" ").at(3).toDouble();
            double x = in.readLine().split(" ").at(3).toDouble();
            double y = in.readLine().split(" ").at(3).toDouble();
            ResizableRectItemSettings *settings = new ResizableRectItemSettings(
                        15, QSizeF(30, 30), QSizeF(2048, 2048),
                        Qt::DashLine, getAnnotationFromClass(annotation)->getColor());
            QRectF rect(x,y,width,height);
            qDebug() << rect;
            ResizableRectItem *item = new ResizableRectItem(rect,settings);
            item->setClass(annotation);
            item->setBrush(getAnnotationFromClass(annotation)->getColor());
            item->setFlag(QGraphicsItem::ItemIsMovable);
            item->setFlag(QGraphicsItem::ItemIsSelectable);
            scenes.at(pic_num)->addItem(item);
            import_box_made(item,getAnnotationFromClass(annotation),pic_num);
        }
    }
    file.close();
    updateTreeList();
    setCursor(Qt::ArrowCursor);
}

void MainWindow::import_box_made(QGraphicsItem *band, Annotation* annon, int scene_num) {
    qDebug() << "box made decieved in mainwindow";

    annon->addBand(band);

    QString shapeName = "_";
    QTreeWidgetItem *child = new QTreeWidgetItem();

    shapeName = "Rectangle" + QString::number(selectedClass->childCount());

    child->setText(0, shapeName);
    selectedClass->addChild(child);
    ui->classTreeWidget->setCurrentItem(child);


    // update timeline
    timelineView *view = dynamic_cast<timelineView*>(Hlayout->itemAt(scene_num)->widget());
    QGraphicsScene *scene = view->scene();

    // remove items from timeline scene
    for(QGraphicsItem *item : scene->items()) {
        ResizableRectItem *test = dynamic_cast<ResizableRectItem*>(item);
        if(test != nullptr){
            delete item;
        }
    }

    //add updated items to timelinescene
    for(QGraphicsItem *item : scenes.at(scene_num)->items()) {
        ResizableRectItem *test = dynamic_cast<ResizableRectItem*>(item);
        if(test != nullptr){
            QRectF newr;
            newr.setRect(test->sceneBoundingRect().x()*(165.0/2048),
                          test->sceneBoundingRect().y()*(165.0/2048),
                          test->sceneBoundingRect().width()*(165.0/2048),
                          test->sceneBoundingRect().height()*(165.0/2048));
            ResizableRectItemSettings *settings = new ResizableRectItemSettings(
                        1, QSizeF(10, 10), QSizeF(2048, 2048),
                        Qt::DashLine, getAnnotationFromClass(test->getClass())->getColor());
            ResizableRectItem *newItem = new ResizableRectItem(newr,settings);
            newItem->setBrush(getAnnotationFromClass(test->getClass())->getColor());
            newItem->setClass(test->getClass());
            scene->addItem(newItem);
        }
    }
}


// function goal: move to next img
// finds next label from prevLabel
// calls update_timeline with new label
void MainWindow::on_nextimgButton_clicked()
{
    QWidget *clicked_label = Hlayout->itemAt(qMin(num_images-1,prev_label->getFrameNum() + 1))->widget();
    update_timeline(clicked_label);
}

// function goal: move to prev img
// finds prev label from prevLabel
// calls update_timeline with new label
void MainWindow::on_previmgButton_clicked()
{
    QWidget *clicked_label = Hlayout->itemAt(qMax(0,prev_label->getFrameNum() - 1))->widget();
    update_timeline(clicked_label);
}

//export specifics can be modified here
void MainWindow::on_actionExport_triggered()
{
    QString out = printAnnotations();

    exportdialog exportdialog;
    exportdialog.setModal(true);
    exportdialog.exec();


    if(exportdialog.get_path() == "")
        return;
    QString dir_path = exportdialog.get_path();

    std::ofstream myfile;
    myfile.open (dir_path .toStdString()+ "/export.txt");

    for( int i=0; i<scenes.count(); ++i )
    {   QGraphicsScene *scene = scenes[i];
        int box_count = 1;
        for(QGraphicsItem *item : scene->items()) {
            ResizableRectItem *test = dynamic_cast<ResizableRectItem*>(item);

            if(test != nullptr){
                qDebug() << "image: " << i+1 <<" bounding box: " << box_count<< " topic: "<< test->getClass() << endl;
                qDebug() << " box width: " << test->sceneBoundingRect().width() << endl;
                qDebug() << " box height: "<< test->sceneBoundingRect().height() << endl;
                qDebug() << " x coordinates: "<< test->sceneBoundingRect().x() << endl;
                qDebug() << " y coordinates: "<< test->sceneBoundingRect().y() << endl;

                myfile << "image: " << i+1 <<" bounding box: " << box_count<<  " topic: " << test->getClass().toStdString() << "\n";
                myfile << " box width: " << test->sceneBoundingRect().width() << "\n";
                myfile << " box height: "<< test->sceneBoundingRect().height() << "\n";
                myfile << " x coordinates: "<< test->sceneBoundingRect().x() << "\n";
                myfile << " y coordinates: "<< test->sceneBoundingRect().y() << "\n";
            }
            box_count++;
        }
        myfile << "\n";

    }
    myfile.close();

}

void MainWindow::on_newclassButton_clicked()
{
    qDebug() << "new class button pushed";
    QString className = "New" + QString::number(ui->classTreeWidget->topLevelItemCount());
    srand(time(NULL));
    int r = rand() % 256;
    int g = rand() % 256;
    int b = rand() % 256;
    Annotation *newClass = new Annotation(className,QColor(r,g,b,255/3));
    class_list.push_back(newClass);

    QTreeWidgetItem *newItem = new QTreeWidgetItem();
    newItem->setText(0, className);
    auto currentFlags = newItem->flags();
    newItem->setFlags(currentFlags | Qt::ItemIsEditable);
    ui->classTreeWidget->addTopLevelItem(newItem);
    qDebug() << "top level item count " << ui->classTreeWidget->topLevelItemCount();

    readClassList();
}

void MainWindow::on_labelarea_boxMoved()
{
    qDebug() << "update";
    for(QGraphicsItem *item : prev_label->scene()->items()) {
        ResizableRectItem *test = dynamic_cast<ResizableRectItem*>(item);
        if(test != nullptr){
            delete item;
        }
    }

    for(QGraphicsItem *item : ui->labelarea->scene()->items()) {
        ResizableRectItem *test = dynamic_cast<ResizableRectItem*>(item);
        if(test != nullptr){
            QRectF newr;
            newr.setRect(test->sceneBoundingRect().x()*(165.0/2048),
                          test->sceneBoundingRect().y()*(165.0/2048),
                          test->sceneBoundingRect().width()*(165.0/2048),
                          test->sceneBoundingRect().height()*(165.0/2048));
            ResizableRectItemSettings *settings = new ResizableRectItemSettings(
                        1, QSizeF(10, 10), QSizeF(2048, 2048),
                        Qt::DashLine, getAnnotationFromClass(test->getClass())->getColor());
            ResizableRectItem *newItem = new ResizableRectItem(newr,settings);
            newItem->setBrush(getAnnotationFromClass(test->getClass())->getColor());
            newItem->setClass(test->getClass());
            prev_label->scene()->addItem(newItem);
        }
    }

}

//used for changing QGraphicsView mode
// ctrl -> hand scroller
// a -> selection mode
// c -> rubberband draw
void MainWindow::keyPressEvent(QKeyEvent *e) {
    if (e->key()==Qt::Key_S) {
        qDebug() << "s clicked";
        ui->labelarea->setDragMode(QGraphicsView::ScrollHandDrag);
        on_selectionToolButton_clicked();
    }
    if (e->key()==Qt::Key_A) {
        qDebug() << "a clicked";
        ui->labelarea->setDragMode(QGraphicsView::NoDrag);
        on_moveToolButton_clicked();
    }
    if (e->key()==Qt::Key_D) {
        qDebug() << "d clicked";
        ui->labelarea->setDragMode(QGraphicsView::RubberBandDrag);
        on_drawToolButton_clicked();
    }
}

void MainWindow::on_classTreeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    if(current->parent() == nullptr){
        prevClass = current->text(0);
        selectedClass = current;

        ui->classSelectedLabel->setText("Current Label: " + selectedClass->text(0));
        qDebug() << "Class seleceted "<< selectedClass->text(0);
        if(prevClass != nullptr){
            qDebug() << "Prev selected" << prevClass;
        }

        ui->labelarea->setColor(getAnnotationFromCurrentClass()->getColor());

        selectedBox = nullptr;
    }
    else{
        selectedBox = current;
        qDebug() << "Selected Box" << selectedBox;

        ui->labelarea->unselectAll();

        int index = selectedBox->parent()->indexOfChild(selectedBox);
        qDebug() << "selected box index at " << index;
        Annotation* classAnnot = getAnnotationFromClass(selectedBox->parent()->text(0));
        qDebug() << classAnnot->getClassName();
        QGraphicsItem* item = classAnnot->getBandAt(index);

        if(item != nullptr){
            item->setSelected(true);
        }else{
            qDebug() << "item could not be selected";
        }

    }
    ui->labelarea->setCurrentClass(selectedClass->text(0));
}

void MainWindow::on_classTreeWidget_itemChanged(QTreeWidgetItem *item, int column)
{

    if(item->parent() == nullptr){
        ui->classSelectedLabel->setText("Current Label: " + selectedClass->text(0));

        //update label area current class
        ui->labelarea->setCurrentClass(selectedClass->text(0));
        //update existing rects to new class name
        for(QGraphicsItem *item : ui->labelarea->scene()->items()) {
            ResizableRectItem *test = dynamic_cast<ResizableRectItem*>(item);
            if(test != nullptr){
                if(getAnnotationFromClass(test->getClass())->getClassName() == prevClass){
                    test->setClass(selectedClass->text(0));
                }
            }
        }

        //updating class list
        for(int i = 0; i < class_list.size(); i++){
            if(class_list.at(i)->getClassName() == prevClass){
                class_list.at(i)->setClassName(item->text(column));
                qDebug()<< "what changed" <<prevClass;
                break;
            }
        }

        qDebug()<< "Changed and Selected" << selectedClass->text(0);
    }
}

//unused
void MainWindow::on_classTreeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    qDebug() << "double click" << prevClass;
}

Annotation* MainWindow::getAnnotationFromCurrentClass(){
    for(int i = 0; i < class_list.size(); i++){
        if(selectedClass->text(0) == class_list.at(i)->getClassName()){
            return class_list.at(i);
        }
    }
    return nullptr;
}

Annotation* MainWindow::getAnnotationFromClass(QString className){
    for(int i = 0; i < class_list.size(); i++){
        if(className == class_list.at(i)->getClassName()){
            return class_list.at(i);
        }
    }
    return nullptr;
}

//run through the class list and its annotations to find the graphics item
QTreeWidgetItem* MainWindow::findItemInList(QGraphicsItem* item){
    for(int i = 0; i < class_list.size(); i++){
        for(int j = 0; j < class_list[i]->getList().size(); j++){
            if(item == class_list[i]->getList().at(j)){
                qDebug() << ui->classTreeWidget->itemAt(i,j);
                return ui->classTreeWidget->itemAt(i,j); //might not work
            }
        }
    }

    return nullptr;
}

void MainWindow::on_labelarea_boxMade(QGraphicsItem *band)
{
    if(scenes.size() < 1){
        qDebug() << "scene not setup yet";
        delete band;
        return;
    }

    qDebug() << "box made decieved in mainwindow";

    Annotation* annon = getAnnotationFromCurrentClass();
    annon->addBand(band);

    QString shapeName = "_";
    QTreeWidgetItem *child = new QTreeWidgetItem();

    shapeName = "Rectangle" + QString::number(selectedClass->childCount());

    child->setText(0, shapeName);
    selectedClass->addChild(child);
    ui->classTreeWidget->setCurrentItem(child);

    // update timeline
    // remove items from timeline scene
    for(QGraphicsItem *item : prev_label->scene()->items()) {
        ResizableRectItem *test = dynamic_cast<ResizableRectItem*>(item);
        if(test != nullptr){
            qDebug() << "remove item";
            delete item;
        }
    }
    //add updated items to timelinescene
    for(QGraphicsItem *item : ui->labelarea->scene()->items()) {
        ResizableRectItem *test = dynamic_cast<ResizableRectItem*>(item);
        if(test != nullptr){
            QRectF newr;
            newr.setRect(test->sceneBoundingRect().x()*(165.0/2048),
                          test->sceneBoundingRect().y()*(165.0/2048),
                          test->sceneBoundingRect().width()*(165.0/2048),
                          test->sceneBoundingRect().height()*(165.0/2048));
            ResizableRectItemSettings *settings = new ResizableRectItemSettings(
                        1, QSizeF(10, 10), QSizeF(2048, 2048),
                        Qt::DashLine, getAnnotationFromClass(test->getClass())->getColor());
            ResizableRectItem *newItem = new ResizableRectItem(newr,settings);
            newItem->setBrush(getAnnotationFromClass(test->getClass())->getColor());
            newItem->setClass(test->getClass());
            prev_label->scene()->addItem(newItem);
        }
    }
}

//currently disconnected
void MainWindow::on_labelarea_selectionChanged(){
    qDebug() << "label area selection signal";
    QGraphicsScene* tempScene = ui->labelarea->getScene();
    if(tempScene->selectedItems().size() > 0){
        QTreeWidgetItem* temp = findItemInList(tempScene->selectedItems().at(0));
        ui->classTreeWidget->setCurrentItem(temp);
    }
}

//functionality only works when clicking on the item in the list and clicking the delete button underneath
//still need to make it known which box is selected in the list when interacting with the graphics scene
void MainWindow::on_deleteclassButton_clicked()
{
    if(selectedBox != nullptr){
        //get graphics of the item,  this could be a funciton if needed
        int index = selectedBox->parent()->indexOfChild(selectedBox);
        Annotation* classAnnot = getAnnotationFromClass(selectedBox->parent()->text(0));

        QGraphicsItem* item = classAnnot->getBandAt(index);

        //check that the item is actually in the current scene
        if(!ui->labelarea->scene()->items().contains(item)){
            qDebug() << "Box not in scene! Stopping delete...";
            return;
        }

        //remove both from the tree and from the graphics
        ui->labelarea->scene()->removeItem(item);
        classAnnot->removeBand(item);
        delete item;
        qDebug() << "box removed from scene";
        delete selectedBox;
        qDebug() << "child deleted";
        //update to the next default box
        if(ui->classTreeWidget->currentItem()->parent() != nullptr){
            selectedBox = ui->classTreeWidget->currentItem();
        }else{
            selectedBox = nullptr;
        }
        on_labelarea_boxMoved();
    }

}

void MainWindow::on_drawToolButton_clicked()
{
    ui->labelarea->setDragMode(QGraphicsView::RubberBandDrag);
    ui->drawToolButton->setStyleSheet("background-color: rgb(0,0,255);");
    ui->selectionToolButton->setStyleSheet("background-color: rgb(255,255,255);");
    ui->moveToolButton->setStyleSheet("background-color: rgb(255,255,255);");
    qDebug() << "draw mode";
}

void MainWindow::on_selectionToolButton_clicked()
{
    ui->labelarea->setDragMode(QGraphicsView::NoDrag);
    ui->drawToolButton->setStyleSheet("background-color: rgb(255,255,255);");
    ui->selectionToolButton->setStyleSheet("background-color: rgb(0,0,255);");
    ui->moveToolButton->setStyleSheet("background-color: rgb(255,255,255);");
    qDebug() << "selection mode";
}

void MainWindow::on_moveToolButton_clicked()
{
    ui->labelarea->setDragMode(QGraphicsView::ScrollHandDrag);
    ui->drawToolButton->setStyleSheet("background-color: rgb(255,255,255);");
    ui->selectionToolButton->setStyleSheet("background-color: rgb(255,255,255);");
    ui->moveToolButton->setStyleSheet("background-color: rgb(0,0,255);");
    qDebug() << "move mode";
}

void MainWindow::on_editclassButton_clicked()
{
    settingsdialog settingsdialog(class_list, box_transfer);
    settingsdialog.setModal(true);
    settingsdialog.exec();
    box_transfer = settingsdialog.get_checked();
    ui->labelarea->setColor(getAnnotationFromCurrentClass()->getColor());
    for(QGraphicsScene *scene : scenes){
        for(QGraphicsItem *item : scene->items()) {
            ResizableRectItem *test = dynamic_cast<ResizableRectItem*>(item);
            if(test != nullptr){
                qDebug() << "Edit box";
                qDebug() << test;
                qDebug() << test->getClass();
                qDebug() << getAnnotationFromClass(test->getClass());
                qDebug()<< getAnnotationFromClass(test->getClass())->getColor();
                test->changeColor(getAnnotationFromClass(test->getClass())->getColor());
                test->setBrush(getAnnotationFromClass(test->getClass())->getColor());
            }
            scene->update();
        }
    }
    ui->labelarea->update();

    //update timeline
    for(int i = 0; i < num_images; i++){
        timelineView *view = dynamic_cast<timelineView*>(Hlayout->itemAt(i)->widget());
        QGraphicsScene *scene = view->scene();
         for(QGraphicsItem *item : scene->items()) {
             ResizableRectItem *test = dynamic_cast<ResizableRectItem*>(item);
             if(test != nullptr){
                 test->changeColor(getAnnotationFromClass(test->getClass())->getColor());
                 test->setBrush(getAnnotationFromClass(test->getClass())->getColor());
             }
         }
         scene->update();
    }

}

void MainWindow::on_actionno_elp_triggered()
{
    QString link = "https://doc.qt.io/";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_actionEdit_triggered()
{
    on_editclassButton_clicked();
}
