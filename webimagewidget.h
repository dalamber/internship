#ifndef WEBIMAGEWIDGET_H
#define WEBIMAGEWIDGET_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtWidgets>

class WebImageWidget : public QWidget
{
    Q_OBJECT
public:
    WebImageWidget();
    void getImage(QString &url);
private slots:
    void replyFinished(QNetworkReply *reply);
private:
    QLabel *_label;
};

#endif // WEBIMAGEWIDGET_H
