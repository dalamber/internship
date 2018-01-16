#include "container.h"
#include "imageitem.h"
#include "item.h"
#include "mycustomwidget.h"
#include "mymainwidget.h"
#include "settingswidget.h"
#include "webimagewidget.h"

#include <QApplication>
#include <QSize>
#include <QtNetwork/QNetworkAccessManager>
#include <QtWidgets>

using namespace masonry;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSize myContainerSize(800, 500);
    QScrollArea *area = new QScrollArea;
    MyMainWidget w;
    w.setBaseSize(myContainerSize);
    area->setWidget(&w);
    area->setWidgetResizable(true);
    QSharedPointer<Container> myContainer(new Container(myContainerSize));
    myContainer->setItemMinimumWidth(200); //200
    if (myContainerSize.width() < myContainer->itemMinimumWidth())
    {
        qDebug() << "Error\n";
        return 1;
    }
    myContainer->setItemMaximumWidth(300); //300
    myContainer->setSpacingBetweenItems(10);

    myContainer->enableCenterAlignment(true); // center alignment has been enabled

    QTime now = QTime::currentTime();
    qsrand(now.msec());
    const quint32 itemCount = 50;
    quint32 wd = 200;
    for (quint32 i = 0; i < itemCount; ++i)
    {
        QString myUrl = "http://lorempixel.com/200/200/";
        MyCustomWidget *custom = new MyCustomWidget();
        custom->getImage(myUrl);
        int ht = custom->makeLayout(i + 1);
        custom->setParent(&w);
        w.addWidget(custom);
        ImageItem *item = new ImageItem(QSize(wd, ht));
        myContainer->addItem(item);
        custom->setStyleSheet("border: 1px solid black"); // for testing
        QObject::connect(item, &ImageItem::geometryChanged, custom, [item, custom] (QRect)
        {
            custom->setNewGeometry(item->geometry());
        });
    }

    w.setContainer(myContainer);

    w.setMinimumWidth(myContainer->itemMinimumWidth());
    area->setMinimumWidth(myContainer->itemMinimumWidth() + 20);
    w.setGeometry(200, 200, myContainer->containerWidth(), 500);
    area->setGeometry(200, 200, myContainer->containerWidth(), 500);

    SettingsWidget stW(&w);
    QObject::connect(&stW, &SettingsWidget::settingsChanged, &w, &MyMainWidget::newSettings);
    stW.show();

    area->show();

    return a.exec();
}
