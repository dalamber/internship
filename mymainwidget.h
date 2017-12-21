#ifndef MYMAINWIDGET_H
#define MYMAINWIDGET_H

#include <QtWidgets>
#include "item.h"

using namespace masonry;

class MyMainWidget : public QWidget
{
public:
    void addItemAndWidget(Item *item, QWidget *w);
    std::map<Item *, QWidget *> widgets() const;
private:
    std::map<Item *, QWidget *> widgetMap;
};

#endif // MYMAINWIDGET_H
