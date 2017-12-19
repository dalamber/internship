#include <QtWidgets>
#include "Item.h"
#include "mymainwidget.h"

using namespace masonry;

void MyMainWidget::addItemAndWidget(Item *item, QWidget *w)
{
   widgetMap.insert(std::pair<Item *, QWidget *> (item, w));
}

std::map<Item *, QWidget *> MyMainWidget::widgets() const
{
    return widgetMap;
}
