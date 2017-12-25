#ifndef MYMAINWIDGET_H
#define MYMAINWIDGET_H

#include "container.h"
#include "item.h"

#include <QtWidgets>

using namespace masonry;

class MyMainWidget : public QWidget
{
public:
    void addWidget(QWidget *w);
    void connectItemAndWidget(Item *item, int i);
    void resizeEvent(QResizeEvent * e);
    void setContainer(Container c);
    std::vector <QWidget *> widgets() const;
private:
    Container myContainer;
    std::vector <QWidget *> widgetVector;
};

#endif // MYMAINWIDGET_H
