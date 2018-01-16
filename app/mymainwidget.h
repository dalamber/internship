#ifndef MYMAINWIDGET_H
#define MYMAINWIDGET_H

#include "container.h"
#include "item.h"

#include <QtWidgets>

using namespace masonry;

class MyMainWidget : public QWidget
{
    Q_OBJECT
public:
    void addWidget(QWidget *w);
    void resizeEvent(QResizeEvent *e) override;
    void setContainer(QSharedPointer<Container> c); // пока так
public slots:
    void newSettings(quint32 min, quint32 max, quint32 spacing);
private:
    QSharedPointer<Container> myContainer;
    std::vector <QWidget *> widgetVector;
};

#endif // MYMAINWIDGET_H
