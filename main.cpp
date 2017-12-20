#include <QApplication>

#include <QtWidgets>
#include <QSize>

#include "container.h"
#include "imageitem.h"
#include "item.h"
#include "mymainwidget.h"

using namespace masonry;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyMainWidget w;
    QSize myContainerSize(500, 500);
    Container mycontainer(myContainerSize);
    mycontainer.setItemMinimumWidth(60);
    if (myContainerSize.width() < mycontainer.itemMinimumWidth())
    {
        qDebug() << "Error\n";
        return a.exit();
    }
    mycontainer.setItemMaximumWidth(80);
    mycontainer.setSpacingBetweenItems(10);

    ImageItem item1(QSize(100, 200));
    ImageItem item2(QSize(100, 60));
    ImageItem item3(QSize(100, 90));
    ImageItem item4(QSize(100, 170));
    ImageItem item5(QSize(100, 240));
    ImageItem item6(QSize(100, 145));
    ImageItem item7(QSize(100, 200));
    ImageItem item8(QSize(100, 100));
    ImageItem item9(QSize(100, 200));
    ImageItem item10(QSize(100, 160));
    ImageItem item11(QSize(100, 120));

    QPushButton ok1("1", &w);
    QPushButton ok2("2", &w);
    QPushButton ok3("3", &w);
    QPushButton ok4("4", &w);
    QPushButton ok5("5", &w);
    QPushButton ok6("6", &w);
    QPushButton ok7("7", &w);
    QPushButton ok8("8", &w);
    QPushButton ok9("9", &w);
    QPushButton ok10("10", &w);
    QPushButton ok11("11", &w);

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

    mycontainer.setContainerSize(QSize(400, 500)); // masonry works here

    w.setGeometry(200, 200, mycontainer.containerWidth(), 500);

    w.addItemAndWidget(&item1, &ok1);
    w.addItemAndWidget(&item2, &ok2);
    w.addItemAndWidget(&item3, &ok3);
    w.addItemAndWidget(&item4, &ok4);
    w.addItemAndWidget(&item5, &ok5);
    w.addItemAndWidget(&item6, &ok6);
    w.addItemAndWidget(&item7, &ok7);
    w.addItemAndWidget(&item8, &ok8);
    w.addItemAndWidget(&item9, &ok9);
    w.addItemAndWidget(&item10, &ok10);
    w.addItemAndWidget(&item11, &ok11);

    w.show();

    return a.exec();
}
