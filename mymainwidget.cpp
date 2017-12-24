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

Container MyMainWidget::container()
{
    return myContainer;
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

void MyMainWidget::setContainerSettings(const QSize &size, quint32 minWidth, quint32 maxWidth, quint32 spacing)
{
    myContainer = Container(size);
    myContainer.setItemMinimumWidth(minWidth);
    myContainer.setItemMaximumWidth(maxWidth);
    myContainer.setSpacingBetweenItems(spacing);
}

std::vector <QWidget *> MyMainWidget::widgets() const
{
    return widgetVector;
}
