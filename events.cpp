// #include "events.h"

// Events::Events() {

// }

// Custom_View::Custom_View(QWidget *parent) : QGraphicsView(parent)
// {
//     setAcceptDrops(true);
//     scene = new QGraphicsScene(this);
//     setScene(scene);
//     viewport()->installEventFilter(this);
// }

// void Custom_View::dragEnterEvent(QDragEnterEvent *event)
// {
//     QDragEnterEvent *DragEnterEvent = static_cast<QDragEnterEvent*>(event);
//     if(DragEnterEvent->mimeData()->hasUrls()){
//         DragEnterEvent->acceptProposedAction();
//     }

// }

// void Custom_View::dragLeaveEvent(QDragLeaveEvent *event)
// {
//     event->accept();
// }

// void Custom_View::dragMoveEvent(QDragMoveEvent *event)
// {
//     event->accept();
//     event->acceptProposedAction();
// }

// void Custom_View::dropEvent(QDropEvent *event)
// {
//     if(event->source() == this) return;

//     QDropEvent *DropEvent = static_cast<QDropEvent*>(event);
//     if(DropEvent->mimeData()->hasUrls()) {
//         QList<QUrl> urllist = DropEvent->mimeData()->urls();

//         foreach (QUrl url, urllist) {

//             if(url.isLocalFile()){
//                 QString FilePath = url.toLocalFile();



//                 QPixmap pixmap(FilePath);

//                 if(pixmap.isNull() == false)
//                 {
//                     // Remove the previous image to new image
//                     if(scene->items().count() > 0) scene->clear();

//                     QGraphicsPixmapItem *item = new QGraphicsPixmapItem(pixmap);

//                     scene->setSceneRect(pixmap.rect());
//                     setSceneRect(scene->sceneRect());
//                     fitInView(scene->sceneRect(), Qt::KeepAspectRatio); // Show image in QGraphicsView

//                     scene->addItem(item);
//                     DropEvent->acceptProposedAction();
//                 }
//             }
//         }
//     }
// }
