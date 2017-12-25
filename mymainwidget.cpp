#include "container.h"
#include "item.h"
#include "mymainwidget.h"

#include <QtWidgets>

using namespace masonry;

void MyMainWidget::addWidget(QWidget *w)
{
    widgetVector.push_back(w);
}

void MyMainWidget::connectItemAndWidget(Item *item, int i)
{
   widgetVector[i]->setGeometry(item->geometry());
}

void MyMainWidget::resizeEvent(QResizeEvent * e)
{
    //QWidget::resizeEvent(e);
    myContainer.setContainerSize(this->size());
    std::vector<Item *> tmpItems;
    tmpItems = myContainer.items();
    for (int i = 0; i < tmpItems.size(); ++i)
    {
        connectItemAndWidget(tmpItems[i], i);
    }
}

void MyMainWidget::setContainer(Container c)
{
    myContainer = c;
}

std::vector <QWidget *> MyMainWidget::widgets() const
{
    return widgetVector;
}
