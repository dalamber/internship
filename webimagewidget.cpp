#include "webimagewidget.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtWidgets>

WebImageWidget::WebImageWidget()
{
    _label = new QLabel(this);
}

void WebImageWidget::getImage(QString &url)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply *)),  // написание по новому стандарту выдавало ошибку,
            this, SLOT(replyFinished(QNetworkReply *))); // пока что написал так
    QUrl _url = QUrl(url);
    QNetworkRequest request(_url);
    manager->get(request);
}

void WebImageWidget::replyFinished(QNetworkReply *reply)
{
    if(reply->error() != QNetworkReply::NoError)
    {
        qDebug() << "Error: " << reply->errorString();
    }
    else
    {
        QPixmap myPixmap;
        myPixmap.loadFromData(reply->readAll());
        _label->setFixedWidth(myPixmap.width());
        _label->setFixedHeight(myPixmap.height());
        _label->setPixmap(myPixmap);
        _label->setScaledContents(true);
    }
}
