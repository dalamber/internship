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
    void resizeLabel();
private slots:
    void replyFinished(QNetworkReply *reply);
private:
    QLabel *_label;
    QPixmap myPixmap;
};

#endif // WEBIMAGEWIDGET_H
