#include "container.h"
#include "item.h"
#include "mymainwidget.h"

#include <QtWidgets>

using namespace masonry;

void MyMainWidget::addWidget(QWidget *w)
{
    widgetVector.push_back(w);
}

void MyMainWidget::resizeEvent(QResizeEvent * e)
{
    myContainer->setContainerSize(this->size());
}

void MyMainWidget::setContainer(QSharedPointer<Container> c)
{
    myContainer = c;
}
