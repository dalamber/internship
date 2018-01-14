#include "container.h"
#include "item.h"
#include "mymainwidget.h"

#include <QtWidgets>

using namespace masonry;

void MyMainWidget::addWidget(QWidget *w)
{
    widgetVector.push_back(w);
}

void MyMainWidget::resizeEvent(QResizeEvent *e)
{
    myContainer->setContainerSize(this->size());
    this->setMinimumHeight(myContainer->containerHeight());
}

void MyMainWidget::setContainer(QSharedPointer<Container> c)
{
    myContainer = c;
}

void MyMainWidget::newSettings(quint32 min, quint32 max, quint32 spacing)
{
    if (min != 0)
        myContainer->setItemMinimumWidth(min);
    if (max != 0)
        myContainer->setItemMaximumWidth(max);
    myContainer->setSpacingBetweenItems(spacing);
}
