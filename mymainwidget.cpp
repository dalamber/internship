#include <QtWidgets>
#include "item.h"
#include "mymainwidget.h"

using namespace masonry;

void MyMainWidget::addItemAndWidget(Item *item, QWidget *w)
{
   w->setGeometry(item->geometry());
   widgetMap.insert(std::pair<Item *, QWidget *> (item, w));
}

std::map<Item *, QWidget *> MyMainWidget::widgets() const
{
    return widgetMap;
}
