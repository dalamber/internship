#ifndef MASONRY_IMAGEITEM_H
#define MASONRY_IMAGEITEM_H

#include <QFile>

#include "masonry_item.h"

class ImageItem : public Item
{
public:
    explicit ImageItem(QImage &image);
    ~ImageItem();
    quint32 heightForWidth(quint32 width);
    QRect geometry() const;
    void setGeometry(const QRect &geometry);
//signals:
//    void geometryChanged();
private:
    QImage _image;
};

#endif // MASONRY_IMAGEITEM_H
