#ifndef MYCUSTOMWIDGET_H
#define MYCUSTOMWIDGET_H

#include "webimagewidget.h"

#include <QtWidgets>

class MyCustomWidget : public QWidget
{
public:
    MyCustomWidget();
    void getImage(QString &url);
    int makeLayout();
    void setNewGeometry(const QRect &geometry);
private:
    QVBoxLayout *layout; 
    WebImageWidget *w;
    QString getRandomString() const;
};

#endif // MYCUSTOMWIDGET_H
