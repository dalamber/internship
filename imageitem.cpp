#include "item.h"
#include "imageitem.h"

#include <QtWidgets>

using namespace masonry;

ImageItem::ImageItem()
{
    _geometry = QRect(QPoint(0, 0), QSize(1, 1));
}

ImageItem::ImageItem(QSize &size)
{
    imageSize = size;
    _geometry.setSize(size);
}

ImageItem::~ImageItem()
{
    imageSize = QSize(0, 0);
}

quint32 ImageItem::heightForWidth(quint32 width)
{
    return ((imageSize.height() * width) / imageSize.width());
}

void ImageItem::setRectangle(QPoint &point, QSize &size)
{
    _geometry = QRect(point, size);
}
