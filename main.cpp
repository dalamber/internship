#include "mywidget.h"
#include <QApplication>
#include "masonry.h"

using namespace masonry;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    Container *mycontainer = new Container;
    QSize size(750, 750);
    mycontainer(size);
    mycontainer->setItemMinimumWidth(200);
    mycontainer->setItemMaximumWidth(300);

    w.show();

    return a.exec();
}
