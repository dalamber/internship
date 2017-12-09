#include "mywidget.h"
#include <QApplication>

#include <QtWidgets>
#include <QSize>

#include "container.h"
#include "imageitem.h"
#include "item.h"

using namespace masonry;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSize myContainerSize(300, 300);
    Container mycontainer(myContainerSize);
    mycontainer.setItemMinimumWidth(200);
    if (myContainerSize.width() < mycontainer.itemMinimumWidth())
    {
        qDebug() << "Error\n";
        return a.exit();
    }
    mycontainer.setItemMaximumWidth(300);
    mycontainer.setSpacingBetweenItems(20);

    QSize sz1(5, 5);
    ImageItem item1(sz1);
    ImageItem item2(sz1);
    ImageItem item3(sz1);
    ImageItem item4(sz1);
    mycontainer.addItem(&item1);
    mycontainer.addItem(&item2);
    mycontainer.addItem(&item3);
    mycontainer.addItem(&item4);

    mycontainer.setContainerSize(QSize(500, 500));

    qDebug() << item1.geometry().topLeft().rx() << item1.geometry().topLeft().ry() << item1.geometry().width() << item1.geometry().height() << "\n";
    qDebug() << item2.geometry().topLeft().rx() << item2.geometry().topLeft().ry() << item2.geometry().width() << item2.geometry().height() << "\n";
    qDebug() << item3.geometry().topLeft().rx() << item3.geometry().topLeft().ry() << item3.geometry().width() << item3.geometry().height() << "\n";
    qDebug() << item4.geometry().topLeft().rx() << item4.geometry().topLeft().ry() << item4.geometry().width() << item4.geometry().height() << "\n";
    qDebug() << "Nice!";

    return a.exit();
}
