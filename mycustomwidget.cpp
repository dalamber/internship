#include "mycustomwidget.h"
#include "webimagewidget.h"

#include <QtWidgets>

MyCustomWidget::MyCustomWidget()
{
    layout = new QVBoxLayout(this);
}

void MyCustomWidget::makeLayout(WebImageWidget *w)
{
    w->setMinimumSize(200, 200);
    layout->setMargin(0);
    layout->addWidget(w, 0, Qt::AlignCenter);
    QGridLayout *grid = new QGridLayout();
    QLabel *label1 = new QLabel("One", this);
    grid->addWidget(label1, 0, 0, 1, 1, Qt::AlignLeft);
    QLabel *label2 = new QLabel("1", this);
    grid->addWidget(label2, 0, 1, 1, 1, Qt::AlignRight);
    QLabel *label3 = new QLabel("Two", this);
    grid->addWidget(label3, 1, 0, 1, 1, Qt::AlignLeft);
    QLabel *label4 = new QLabel("2", this);
    grid->addWidget(label4, 1, 1, 1, 1, Qt::AlignRight);
    layout->addLayout(grid);
}
