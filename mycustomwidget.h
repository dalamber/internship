#ifndef MYCUSTOMWIDGET_H
#define MYCUSTOMWIDGET_H

#include "webimagewidget.h"

#include <QtWidgets>

class MyCustomWidget : public QWidget
{
public:
    MyCustomWidget();
    void makeLayout(WebImageWidget *w);
private:
    QVBoxLayout *layout;
};

#endif // MYCUSTOMWIDGET_H
