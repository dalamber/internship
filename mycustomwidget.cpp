#include "mycustomwidget.h"
#include "webimagewidget.h"

#include <QtWidgets>

MyCustomWidget::MyCustomWidget()
{
    layout = new QVBoxLayout(this);
    w = new WebImageWidget();
}

QString MyCustomWidget::getRandomString() const
{
   const QString capitalCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
   const QString lowercaseCharacters("abcdefghijklmnopqrstuvwxyz");
   const int randomStringLength = qrand() % 6 + 5;

   QString randomString;
   for(int i = 0; i < randomStringLength; ++i)
   {
       if (i == 0)
       {
           int index = qrand() % capitalCharacters.length();
           QChar nextChar = capitalCharacters.at(index);
           randomString.append(nextChar);
       }
       else
       {
           int index = qrand() % lowercaseCharacters.length();
           QChar nextChar = lowercaseCharacters.at(index);
           randomString.append(nextChar);
       }
   }
   return randomString;
}

void MyCustomWidget::getImage(QString &url)
{
    w->getImage(url);
}

int MyCustomWidget::makeLayout()
{
    int resultHeight = 200;
    w->setMinimumSize(200, 200);
    w->setParent(this);
    layout->setMargin(0);
    layout->addWidget(w);
    QGridLayout *grid = new QGridLayout();
    int labelCount = qrand() % 4 + 2;
    for (int i = 0; i < labelCount; ++i)
    {
        QLabel *label1 = new QLabel(getRandomString(), this);
        label1->setMaximumHeight(30);
        grid->addWidget(label1, i, 0, 1, 1, Qt::AlignLeft);
        QLabel *label2 = new QLabel(QString::number(i + 1), this);
        label2->setMaximumHeight(30);
        grid->addWidget(label2, i, 1, 1, 1, Qt::AlignRight);
        resultHeight += 30;
    }
    layout->addLayout(grid);
    return resultHeight;
}

void MyCustomWidget::setNewGeometry(const QRect &geometry)
{
    this->setGeometry(geometry);
    w->resizeLabel();
}
