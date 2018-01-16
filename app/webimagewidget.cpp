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
    QObject::connect(manager, &QNetworkAccessManager::finished, this, &WebImageWidget::replyFinished);
    QUrl _url = QUrl(url);
    QNetworkRequest request(_url);
    manager->get(request);
}

void WebImageWidget::resizeLabel()
{
    _label->setGeometry(this->geometry());
}

void WebImageWidget::replyFinished(QNetworkReply *reply)
{
    if(reply->error() != QNetworkReply::NoError)
    {
        qDebug() << "Error: " << reply->errorString();
    }
    else
    {
        _label->setScaledContents(true);
        myPixmap.loadFromData(reply->readAll());
        _label->setMinimumWidth(myPixmap.width());
        _label->setMinimumHeight(myPixmap.height());
        _label->setGeometry(this->geometry());
        _label->setPixmap(myPixmap);
    }
    reply->deleteLater();
}
