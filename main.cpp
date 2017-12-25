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
    myContainer.setItemMinimumWidth(40);
    if (myContainerSize.width() < myContainer.itemMinimumWidth())
    {
        qDebug() << "Error\n";
        return 1;
    }
    myContainer.setItemMaximumWidth(80);
    myContainer.setSpacingBetweenItems(5);

    QTime now = QTime::currentTime();
    qsrand(now.msec());
    const quint32 itemCount = 100;
    quint32 wd = 50;
    for (quint32 i = 0; i < itemCount; ++i)
    {
        quint32 ht = qrand() % 50 + 50;
        ImageItem *item = new ImageItem(QSize(wd, ht));
        myContainer.addItem(item);
        QString str = QString::number(i + 1);
        QPushButton *ok = new QPushButton(str, &w);
        w.addWidget(ok);
    }

    w.setContainer(myContainer);

    w.setGeometry(200, 200, myContainer.containerWidth(), 500);
    area->setGeometry(200, 200, myContainer.containerWidth(), 500);

    area->show();

    return a.exec();
}
