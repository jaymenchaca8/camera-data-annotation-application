<div>

<span class="c3"></span>

</div>

# <span>Camera Data Annotation Interface:</span> <span class="c14">Documentation</span>

* * *

<span class="c3"></span>

<span class="c3"></span>

## <span class="c16">Table of Contents</span>

### <span class="c6">Views</span>

- #### <span class="c11">[Main Window](#mainwindowhmainwindowcpp)</span>

- #### <span class="c11">[Timeline View](#timelineviewhtimelineviewcpp)</span>

### <span class="c6">Annotating & Labeling</span>

- #### <span class="c11">[Annotations](#annotationhannotationcpp)</span>

- #### <span class="c11">[Clickable Label](#clickablelabelhclickablelabelcpp)</span>

- #### <span class="c11">[Label Area](#labelareahlabelareacpp)</span>

### <span class="c6">Dialog Boxes</span>

- #### <span class="c11">[Import Dialog Box](#importdialoghimportdialogcpp)</span>

- #### <span class="c11">[Export Dialog Box](#exportdialoghexportdialogcpp)</span>

- #### <span class="c11">[Settings Dialog Box](#settingsdialoghsettingsdialogcpp)</span>

### <span class="c6">Resizing</span>

- #### <span class="c11">[Resizable Rectangle Item](#resizablerectitemhresizablerectitemcpp)</span>

- #### <span class="c11">[Resizable Rectangle Item Settings](#resizablerectitemsettingshresizablerectitemsettingscpp)</span>

- #### <span class="c11">[Resize Directions](#resizedirectionsh)</span>

* * *

## <span class="c9">annotation.h/annotation.cpp</span>

- ### <span class="c6">void setClassName(QString _class_name);</span>

  - <span class="c3">Changes name of annotation labels</span>

- ### <span class="c6">QString getClassName();</span>

  - <span class="c3">Returns label name</span>

- ### <span class="c6">void setColor(QColor _color);</span>

  - <span class="c3">Changes color of annotation boxes</span>

- ### <span class="c6">QColor getColor();</span>

  - <span class="c3">Returns color</span>

- ### <span>void printList();</span> <span class="c12">Not used</span>

  - <span class="c3">Prints to the console the addresses of the stored QGraphicItems under this specific annotation class</span>

- ### <span class="c6">void addBand(QGraphicsItem* box);</span>

  - <span>Appends</span> <span class="c18">box</span><span class="c3"> to the stored QGraphicsItem list</span>

- ### <span class="c6">void removeBand(QGraphicsItem* box);</span>

  - <span>Removes</span> <span class="c18">box</span> <span class="c3">from the stored QGraphicsItem list</span>

- ### <span class="c6">QGraphicsItem* removeBandAt(int i);</span>

  - <span>Removes QGraphicsItem</span><span class="c18"> </span><span>from the stored list at index</span> <span class="c18">i</span>

- ### <span class="c6">QGraphicsItem* getBandAt(int i);</span>

  - <span>Returns QGraphicsItem</span><span class="c18"> </span><span>from the stored list at index</span> <span class="c18">i</span>

- ### <span class="c6">QList<QGraphicsItem*> getList();</span>

  - <span class="c3">Returns the QGraphicsItem list</span>

- ### <span class="c6">QString whoAmI(QGraphicsItem* box);</span>

  - <span>Checks and returns the class_name if</span> <span class="c18">box</span> <span>is found within the QGraphicsItem list. Returns an empty QString if it is not found</span>

## <span class="c9">clickablelabel.h/clickablelabel.cpp</span>

- ### <span class="c6">void setFrameNum(int _frame_num);</span>

  - <span class="c3">Changes frame number</span>

- ### <span class="c6">int getFrameNum();</span>

  - <span class="c3">Returns frame number</span>

- ### <span class="c6">void setImagePath(QString _image_path);</span>

  - <span class="c3">Changes system path to image</span>

- ### <span class="c6">QString getImagePath();</span>

  - <span class="c3">Returns system path to image</span>

- ### <span class="c6">void clicked();</span>

  - <span class="c3">clicked() signal</span>

- ### <span class="c6">void mousePressEvent(QMouseEvent* event);</span>

  - <span class="c3">Emits clicked() signal on mouse press</span>

## <span class="c9">exportdialog.h/exportdialog.cpp</span>

- ### <span class="c6">QString get_path();</span>

  - <span class="c3">Returns path to user selected directory</span>

- ### <span class="c6">void on_pushButton_clicked();</span>

  - <span class="c3">When pushButton is clicked a QFileDialog will pop up allowing the user to browse their system’s file system and select a directory to export to. Selected directory will be set to path.</span>

## <span class="c9">importdialog.h/importdialog.cpp</span>

- ### <span class="c6">QString get_path();</span>

  - <span class="c3">Returns system path to user selected ros bag file</span>

- ### <span class="c6">QString get_topic();</span>

  - <span class="c3">Returns the currently selected topic from the ui’s comboBox</span>

- ### <span class="c6">void on_pushButton_clicked();</span>

  - <span class="c3">When pushButton is clicked a QFileDialog will pop up allowing the user to browse their system’s file system and select a file to import from. The file name will then be displayed to the ui and the system path stored to path. A QProcess then runs on the script “topic_extraction.py” using parameters path to extract the topic parameters to a file.This file is then read and the topics are added to the ui’s comboBox.</span>

- ### <span class="c6">void on_buttonBox_accepted();</span>

  - <span class="c3">Closes the import ui</span>

- ### <span class="c6">void on_buttonBox_rejected();</span>

  - <span class="c3">Closes the import ui</span>

- ### <span class="c6">QString get_box_path();</span>

  - <span class="c3">Returns system path to user selected file containing bounding box data</span>

- ### <span class="c6">void on_pushButton_2_clicked();</span>

  - <span class="c3">When pushButton is clicked a QFileDialog will pop up allowing the user to browse their system’s file system and select a file to pull bounding box data from. The selected file’s system path is stored in box_path and the file name is displayed to the ui.</span>

## <span class="c9">labelarea.h/labelarea.cpp</span>

- ### <span class="c6">QGraphicsScene* setupScene();</span>

  - <span class="c3">Used for setting a QGraphicScene’s initial settings. Sets default size to 600x800 and adds the class’s eventfilter. Finally a cross patterned black grid is added to the back of the scene.</span>

- ### <span>void</span> <span>displayImg</span><span class="c6">(const QImage &image, QGraphicsScene* _scene);</span>

  - <span class="c3">Takes in QImage and scene. Creates a QGraphicsPixmapItem from the QImage and adds it to the scene. The scene is then scaled to the image’s size and its view is centered on the image.</span>

- ### <span class="c6">bool eventFilter(QObject *watched, QEvent *event);</span>

  - <span>Used for tracking mouse events. Starts by setting the flags of all ResizableRectItems to false if in draw mode or true if not. This prevents selecting a box while in draw mode. Then checks if the mouse is pressed, and if so, stores the point where clicked relative to the scene position. Next it checks for a mouse release event, and if so draws a box. This is done by first checking if it is in draw mode, and If not, emits a boxMoved() signal. Next it calculates the bounding rect of the drawn rectangle using the point stored on mouse click and the point on mouse release. Finally the ResizableRectItemSettings and passed in to a new</span> <span>ResizeableRectItem</span><span class="c3"> along with the drawn rectangle coordinates and is added to the current scene along with a boxMade(item) signal.</span>

- ### <span class="c6">QGraphicsScene* getScene();</span>

  - <span class="c3">Returns widget’s scene</span>

- ### <span class="c6">void setColor(QColor _color);</span>

  - <span class="c3">Changes color to _color</span>

- ### <span class="c6">QColor getColor();</span>

  - <span class="c3">Returns color</span>

- ### <span class="c6">void unselectAll();</span>

  - <span class="c3">Clears the scene’s selection</span>

- ### <span class="c6">void setCurrentClass(QString _class);</span>

  - <span class="c3">Changes currentClass to _class</span>

- ### <span class="c6">void wheelEvent(QWheelEvent *event);</span>

  - <span class="c3">Adds scroll functionality. When the user scrolls using the mouse’s scroll wheel, the scene is scaled relative to the scroll event.</span>

- ### <span class="c6">void boxMade(QGraphicsItem* band);</span>

  - <span class="c3">BoxMade(QGraphicsItem* band) signal</span>

- ### <span class="c6">Void boxMoved()</span>

  - <span class="c3">boxMoved() signal</span>

## <span class="c9">mainwindow.h/mainwindow.cpp</span>

- ### <span class="c6">void on_actionImport_triggered();</span>

  - <span class="c3">Calls import dialog gui, it’s getters to obtain file path and parameters</span>

  - <span class="c3">Calls extraction script to get .bag location and image destination</span>

  - <span class="c3">Sets up annotation tree for inclusion of a formatted .txt file</span>

  - <span class="c3">Draws images to the scenes in the frame viewer and timeline</span>

  - <span class="c3">Readds bounding boxes specified in .txt file to the scenes</span>

- ### <span class="c6">void on_actionExport_triggered();</span>

  - <span class="c3">Calls export gui</span>

  - <span class="c3">Creates a file at specified location that includes image number and the specifics for each of its boxes, including its class label, its position, and dimensions</span>

  - <span class="c3">Changes to the export format can be done here</span>

- ### <span class="c6">void on_newclassButton_clicked();</span>

  - <span class="c3">Creates and adds a new Annotation object and appends it to the class_list</span>

  - <span class="c3">New Annotations have a “New_” name and are assigned a random color</span>

  - <span class="c3">Class list is updated to show the new class under already created ones</span>

  - <span class="c3">Current label is changed to the newly created class</span>

- ### <span class="c6">void on_nextimgButton_clicked();</span>

  - <span class="c3">Find next timelineView and pass it to update_timeline()</span>

- ### <span class="c6">void on_previmgButton_clicked();</span>

  - <span class="c3">Find previous timelineView and pass it to update_timeline()</span>

- ### <span class="c6">void processExit(int , QProcess::ExitStatus);</span>

  - <span class="c3">No longer in use.</span>

  - <span class="c3">Acts as a slot function that detects ExitStatus from a QProcess to allow for asynchronous script running.</span>

- ### <span class="c6">void update_timeline(QWidget*);</span>

  - <span class="c3">Cast passed in Widget to timelineView</span>

  - <span class="c3">Change stylesheet to highlight newly selected scene on the timeline</span>

  - <span class="c3">Check if the newly selected scene is 1 after the previous scene, in which case copyBoxes() is called.</span>

  - <span class="c3">See in the newly selected scene is after or before the previous scene</span>

  - <span class="c3">Make sure newly selected scene is not one of the first 2 or last 3 scenes, then scale the scrollbar by 171 * newly selected scene’s frame number-2</span>

  - <span class="c3">(171 is used as it scales well with the size of the timeline)</span>

- ### <span class="c6">void on_classTreeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);</span>

  - <span class="c3">Called when when another item other than the one currently selected on the class tree is selected</span>

  - <span class="c3">If the item is a class then the current label is changed and drawing color is updated to reflect the current class</span>

  - <span class="c3">If the item refers to a box, the QGraphicsItem is highlighted on the current scene</span>

- ### <span class="c6">void on_classTreeWidget_itemChanged(QTreeWidgetItem *item, int column);</span>

  - <span class="c3">Called when the currently selected item is edited</span>

  - <span class="c3">Updates the associated annotation class based on the changes made to the item</span>

- ### <span class="c6">void on_classTreeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);</span>

  - <span class="c3">Unused</span>

  - <span class="c3">Console debug</span>

- ### <span class="c6">void on_labelarea_boxMade(QGraphicsItem* band);</span>

  - <span class="c3">Called when a QGraphicsItem is added to the current scene</span>

  - <span class="c3">Attaches the item to the current label by appending the item to the annotation list</span>

  - <span class="c3">Class tree is updated to include the item underneath its associated label</span>

  - <span class="c3">Creates a ResizableRectItem associated with the GraphicsItem and sets its parameters with the annotation’s assigned color</span>

- ### <span class="c6">void on_deleteclassButton_clicked();</span>

  - <span class="c3">Called when the delete button is pressed</span>

  - <span class="c3">Checks that the current class tree item refers to a QGraphicsItem</span>

  - <span class="c3">Deletes the item updates the class tree list</span>

  - <span class="c3">Does nothing otherwise</span>

- ### <span class="c6">void on_labelarea_selectionChanged();</span>

  - <span class="c3">Disconnected signal slot</span>

  - <span class="c3">Could be called to update the current selected class tree item based on which QGraphicsItem is selected</span>

- ### <span class="c6">void on_drawToolButton_clicked();</span>

  - <span class="c3">Changes labelarea’s DragMode to RubberBandDrag</span>

  - <span class="c3">Sets stylesheet of buttons to highlight the draw button</span>

- ### <span class="c6">void on_selectionToolButton_clicked();</span>

  - <span class="c3">Changes labelarea’s DragMode to NoDrag</span>

  - <span class="c3">Sets stylesheet of buttons to highlight the tool button</span>

- ### <span class="c6">void on_moveToolButton_clicked();</span>

  - <span class="c3">Changes labelarea’s DragMode to ScrollHandDrag</span>

  - <span class="c3">Sets stylesheet of buttons to highlight the tool button</span>

- ### <span class="c6">void on_editclassButton_clicked();</span>

  - <span class="c3">Create and initiate settingsdialog instance</span>

  - <span class="c3">Update all scene’s boxes to the new color from the settingsdialog</span>

  - <span class="c3">Update all timeline’s scene’s boxes to the new color from the settingsdialog</span>

- ### <span class="c6">void draw_picture(QString,int);</span>

  - <span class="c3">Sets the labelarea scene to selected scene</span>

  - <span class="c3">Create connection between boxMade() and on_labelarea_boxMade()</span>

  - <span class="c3">Create connection between boxMoved() and on_labelarea_boxMoved()</span>

  - <span class="c3">Call updateTreeList() to update the tree list to the new scene</span>

- ### <span class="c6">void timeline(QString directory);</span>

  - <span class="c3">Get number of images in directory</span>

  - <span class="c3">Setup all of the QGraphicScenes</span>

  - <span class="c3">Initialize QSignalMapper to create connection between slot() and update_timeline()</span>

  - <span class="c3">For each img:</span>

  - <span class="c3">Initialize new timelineView</span>

  - <span class="c3">Get next image in directory and scale in to 165x165</span>

  - <span class="c3">Initialize new QGraphicsScene</span>

  - <span class="c3">Create QGraphicsPixmapItem, add it to scene, and scale the view to the image</span>

  - <span class="c3">Create connection between clicked() signal and QSignalMapper</span>

  - <span class="c3">Set view’s frame_number and image_path</span>

  - <span class="c3">Add view to QHBoxLayout</span>

  - <span class="c3">Once all views are added, add QHBoxLayout to scrollArea on the ui</span>

- ### <span class="c6">void get_num_images(QString directory);</span>

  - <span class="c3">Return number of images located in given directory</span>

- ### <span class="c6">Annotation* getAnnotationFromCurrentClass();</span>

  - <span class="c3">Return Annotation of currently selected class</span>

- ### <span class="c6">Annotation* getAnnotationFromClass(QString className);</span>

  - <span class="c3">Return Annotation with the same name as className</span>

- ### <span>QTreeWidgetItem*</span> <span>findItemInList</span><span class="c6">(QGraphicsItem* item);</span>

  - <span>Searches the class list and the annotation lists for</span> <span class="c18">item</span> <span class="c3">and returns the associated class tree item</span>

- ### <span class="c6">void readClassList();</span>

  - <span class="c3">Puts to console the current name of all the labels</span>

- ### <span class="c6">void keyPressEvent(QKeyEvent *e);</span>

  - <span class="c3">If S clicked -> set labelarea DrawMode to ScrollHandDrag and forward to slot function</span>

  - <span>If A clicked -> set</span> <span>labelarea</span><span class="c3"> DrawMode to NoDrag and forward to slot function</span>

  - <span>If D clicked -> set</span> <span>labelarea</span><span class="c3"> DrawMode to RubberBandDrag and forward to slot function</span>

- ### <span class="c6">void setupGraphicScenes();</span>

  - <span>Create scenes using</span> <span>labelarea’s</span><span class="c3"> setupScene()</span>

## <span class="c9">resizablerectitem.h/resizablerectitem.cpp</span>

- ### <span class="c6">void changeColor(QColor _color);</span>

  - <span class="c3">Change color to _color</span>

- ### <span class="c6">void setClass(QString _class_name);</span>

  - <span class="c3">Change class_name to _class_name</span>

- ### <span class="c6">QString getClass();</span>

  - <span class="c3">Returns class_name</span>

- ### <span class="c6">void mousePressEvent(QGraphicsSceneMouseEvent *event);</span>

  - <span class="c3">Get the resize-directions. Then, if not a resize event, pass it to base class so the move event can be implemented. ELse, resizeRect()</span>

- ### <span class="c6">void mouseMoveEvent(QGraphicsSceneMouseEvent *event);</span>

  - <span class="c3">If not a resize event, pass it to the base class so the move event can be implemented. Else, resizeRect()</span>

- ### <span class="c6">void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);</span>

  - <span class="c3">If not a resize event, pass it to the base class so the move event can be implemented. Else, resizeRect()</span>

- ### <span class="c6">void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);</span>

  - <span class="c3">Paint override to allow the inner-rect to be drawn before the outer-rect</span>

- ### <span class="c6">QRectF getInnerRect() const;</span>

  - <span class="c3">Returns rect() adjusted to settings resizableBorderSize</span>

- ### <span class="c6">void resizeRect(QGraphicsSceneMouseEvent *event);</span>

  - <span class="c3">Resize based on QGraphicsSceneMouseEvent</span>

## <span class="c9">resizablerectitemsettings.h/resizablerectitemsettings.cpp</span>

- ### <span class="c6">void validateRect(QRectF *r, const ResizeDirections &resizeDirections) const;</span>

  - <span class="c3">Enforcement of the minimum and maximum sizes</span>

## <span class="c9">resizedirections.h</span>

- ### <span class="c6">bool any();</span>

  - <span class="c3">Return either horizontal or vertical enum</span>

## <span class="c9">settingsdialog.h/settingsdialog.cpp</span>

- ### <span class="c6">void on_pushButton_color_clicked();</span>

  - <span class="c3">When pushButton_color is clicked, prompt a QColorDialog that lets the user select a color. This color is then set to the current select class along with the current set alpha. Finally, the color code is displayed to the ui.</span>

- ### <span class="c6">void on_comboBox_class_currentIndexChanged(int index);</span>

  - <span class="c3">Display newly selected class’s color and alpha to the ui.</span>

- ### <span class="c6">void on_buttonBox_accepted();</span>

  - <span class="c3">If accepted, update the selected class with the currently selected alpha value then close the ui.</span>

- ### <span class="c6">Bool get_checked();</span>

  - <span class="c3">Return the checkstate of the checkBox</span>

## <span class="c9">timelineview.h/timelineview.cpp</span>

- ### <span class="c6">void resizeEvent(QResizeEvent *event);</span>

  - <span class="c3">Override of the QGraphicsView resizeEvent to fit the view to its QGraphicPixmapItem.</span>

- ### <span class="c6">void setFrameNum(int _frame_num);</span>

  - <span class="c3">Change frame_num to _frame_num</span>

- ### <span class="c6">int getFrameNum();</span>

  - <span class="c3">Returns frame_num.</span>

- ### <span class="c6">void setImagePath(QString _image_path);</span>

  - <span class="c3">Change image_path to _image_path.</span>

- ### <span class="c6">QString getImagePath();</span>

  - <span class="c3">Returns image_path.</span>

- ### <span class="c6">void clicked();</span>

  - <span class="c3">clicked() signal</span>

- ### <span class="c6">void mousePressEvent(QMouseEvent* event);</span>

  - <span class="c3">Emit clicked() signal on mousePressEvent</span>
