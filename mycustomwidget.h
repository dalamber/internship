#ifndef MYCUSTOMWIDGET_H
#define MYCUSTOMWIDGET_H

#include "webimagewidget.h"

#include <QPropertyAnimation>
#include <QtWidgets>

class MyCustomWidget : public QWidget
{
public:
    MyCustomWidget();
    void getImage(QString &url);
    int makeLayout(int number);
    void setNewGeometry(const QRect &geometry);
private:
    QVBoxLayout *layout; 
    WebImageWidget *w;
    QPropertyAnimation *animation;
    QString getRandomString() const;
};

#endif // MYCUSTOMWIDGET_H
