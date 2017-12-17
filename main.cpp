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

    QSize myContainerSize(130, 130);
    Container mycontainer(myContainerSize);
    mycontainer.setItemMinimumWidth(20);
    if (myContainerSize.width() < mycontainer.itemMinimumWidth())
    {
        qDebug() << "Error\n";
        return a.exit();
    }
    mycontainer.setItemMaximumWidth(30);
    mycontainer.setSpacingBetweenItems(10);

    ImageItem item1(QSize(24, 50)); // 24, 50
    ImageItem item2(QSize(30, 30)); //26 //30, 30
    ImageItem item3(QSize(25, 50));
    ImageItem item4(QSize(23, 70));
    ImageItem item5(QSize(27, 40)); //40
    ImageItem item6(QSize(25, 45)); //45
    ImageItem item7(QSize(25, 50));
    ImageItem item8(QSize(25, 50));
    ImageItem item9(QSize(25, 30)); //,110
    ImageItem item10(QSize(30, 80)); //25
    ImageItem item11(QSize(25, 30));


    mycontainer.addItem(&item1);
    mycontainer.addItem(&item2);
    mycontainer.addItem(&item3);
    mycontainer.addItem(&item4);
    mycontainer.addItem(&item5);
    mycontainer.addItem(&item6);
    mycontainer.addItem(&item7);
    mycontainer.addItem(&item8);
    mycontainer.addItem(&item9);
    mycontainer.addItem(&item10);
    mycontainer.addItem(&item11);

    mycontainer.setContainerSize(QSize(130, 400)); //95

    qDebug() << item1.geometry().topLeft().rx() << item1.geometry().topLeft().ry() << item1.geometry().width() << item1.geometry().height() << "\n";
    qDebug() << item2.geometry().topLeft().rx() << item2.geometry().topLeft().ry() << item2.geometry().width() << item2.geometry().height() << "\n";
    qDebug() << item3.geometry().topLeft().rx() << item3.geometry().topLeft().ry() << item3.geometry().width() << item3.geometry().height() << "\n";
    qDebug() << item4.geometry().topLeft().rx() << item4.geometry().topLeft().ry() << item4.geometry().width() << item4.geometry().height() << "\n";
    qDebug() << item5.geometry().topLeft().rx() << item5.geometry().topLeft().ry() << item5.geometry().width() << item5.geometry().height() << "\n";
    qDebug() << item6.geometry().topLeft().rx() << item6.geometry().topLeft().ry() << item6.geometry().width() << item6.geometry().height() << "\n";
    qDebug() << item7.geometry().topLeft().rx() << item7.geometry().topLeft().ry() << item7.geometry().width() << item7.geometry().height() << "\n";
    qDebug() << item8.geometry().topLeft().rx() << item8.geometry().topLeft().ry() << item8.geometry().width() << item8.geometry().height() << "\n";
    qDebug() << item9.geometry().topLeft().rx() << item9.geometry().topLeft().ry() << item9.geometry().width() << item9.geometry().height() << "\n";
    qDebug() << item10.geometry().topLeft().rx() << item10.geometry().topLeft().ry() << item10.geometry().width() << item10.geometry().height() << "\n";
    qDebug() << item11.geometry().topLeft().rx() << item11.geometry().topLeft().ry() << item11.geometry().width() << item11.geometry().height() << "\n";

    qDebug() << "Nice!";

    /*mycontainer.setContainerSize(QSize(179, 1000));

    qDebug() << item1.geometry().topLeft().rx() << item1.geometry().topLeft().ry() << item1.geometry().width() << item1.geometry().height() << "\n";
    qDebug() << item2.geometry().topLeft().rx() << item2.geometry().topLeft().ry() << item2.geometry().width() << item2.geometry().height() << "\n";
    qDebug() << item3.geometry().topLeft().rx() << item3.geometry().topLeft().ry() << item3.geometry().width() << item3.geometry().height() << "\n";
    qDebug() << item4.geometry().topLeft().rx() << item4.geometry().topLeft().ry() << item4.geometry().width() << item4.geometry().height() << "\n";
    qDebug() << item5.geometry().topLeft().rx() << item5.geometry().topLeft().ry() << item5.geometry().width() << item5.geometry().height() << "\n";
    qDebug() << item6.geometry().topLeft().rx() << item6.geometry().topLeft().ry() << item6.geometry().width() << item6.geometry().height() << "\n";
    qDebug() << item7.geometry().topLeft().rx() << item7.geometry().topLeft().ry() << item7.geometry().width() << item7.geometry().height() << "\n";
    qDebug() << item8.geometry().topLeft().rx() << item8.geometry().topLeft().ry() << item8.geometry().width() << item8.geometry().height() << "\n";
    qDebug() << item9.geometry().topLeft().rx() << item9.geometry().topLeft().ry() << item9.geometry().width() << item9.geometry().height() << "\n";
    qDebug() << item10.geometry().topLeft().rx() << item10.geometry().topLeft().ry() << item10.geometry().width() << item10.geometry().height() << "\n";
    qDebug() << item11.geometry().topLeft().rx() << item11.geometry().topLeft().ry() << item11.geometry().width() << item11.geometry().height() << "\n";
    qDebug() << "Nice!";*/

    return a.exit();
}
