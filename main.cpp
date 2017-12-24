#include "container.h"
#include "imageitem.h"
#include "item.h"
#include "mymainwidget.h"

#include <QApplication>
#include <QSize>
#include <QtWidgets>

using namespace masonry;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSize myContainerSize(300, 500);
    QScrollArea *area = new QScrollArea;
    MyMainWidget w;
    w.setMinimumHeight(2200);
    area->setWidgetResizable(true);
    area->setWidget(&w);
    Container myContainer(myContainerSize);
    myContainer.setItemMinimumWidth(60);
    if (myContainerSize.width() < myContainer.itemMinimumWidth())
    {
        qDebug() << "Error\n";
        return 1;
    }
    myContainer.setItemMaximumWidth(120);
    myContainer.setSpacingBetweenItems(10);

    ImageItem item1(QSize(100, 200));
    ImageItem item2(QSize(100, 60));
    ImageItem item3(QSize(100, 90));
    ImageItem item4(QSize(100, 170));
    ImageItem item5(QSize(100, 240));
    ImageItem item6(QSize(100, 145));
    ImageItem item7(QSize(100, 200));
    ImageItem item8(QSize(100, 150));
    ImageItem item9(QSize(100, 200));
    ImageItem item10(QSize(100, 160));
    ImageItem item11(QSize(100, 120));

    myContainer.addItem(&item1);
    myContainer.addItem(&item2);
    myContainer.addItem(&item3);
    myContainer.addItem(&item4);
    myContainer.addItem(&item5);
    myContainer.addItem(&item6);
    myContainer.addItem(&item7);
    myContainer.addItem(&item8);
    myContainer.addItem(&item9);
    myContainer.addItem(&item10);
    myContainer.addItem(&item11);

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

    w.addWidget(&ok1);
    w.addWidget(&ok2);
    w.addWidget(&ok3);
    w.addWidget(&ok4);
    w.addWidget(&ok5);
    w.addWidget(&ok6);
    w.addWidget(&ok7);
    w.addWidget(&ok8);
    w.addWidget(&ok9);
    w.addWidget(&ok10);
    w.addWidget(&ok11);

    w.setContainer(myContainer);

    area->setGeometry(200, 200, myContainer.containerWidth(), 500);

    area->show(); //w.show();

    return a.exec();
}
