#include "mywidget.h"
#include <QApplication>
#include <QGridLayout>
#include <QtWidgets>
#include <QSize>

#include "masonry_container.h"
#include "masonry_imageitem.h"
#include "masonry_item.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    QPushButton* A = new QPushButton("A");
    QPushButton* B = new QPushButton("B");
    QPushButton* C = new QPushButton("C");
    QPushButton* D = new QPushButton("D");

    QSize msize(300, 300);
    Container mycontainer(msize);
    //mycontainer.setItemMinimumWidth(200);
    //if (msize.width() < mycontainer.itemMinimumWidth())
    //    cout << "Error\n";
    //mycontainer.setItemMaximumWidth(300);
    //mycontainer.setSpacingBetweenItems(10);
    mycontainer.getLayout()->setMargin(5);
    mycontainer.getLayout()->setSpacing(15);
    mycontainer.addWidget(A, 0, 0);
    mycontainer.addWidget(B, 0, 1);
    mycontainer.addWidget(C, 1, 0);
    mycontainer.addWidget(D, 1, 1);
    w.setLayout(mycontainer.getLayout());

    w.show();

    return a.exec();
}

/*Item item1, item2, item3, item4, item5;
item1.heightForWidth(250);
item2.heightForWidth(250);
item3.heightForWidth(250);
item4.heightForWidth(250);
item5.heightForWidth(250);
mycontainer.addItem(item1);
mycontainer.addItem(item2);
mycontainer.addItem(item3);
mycontainer.addItem(item4);
mycontainer.addItem(item5);*/

/*    QPoint pt(10, 10);
    QSize sz(20, 10);
    QRect item0(pt, sz);*/
