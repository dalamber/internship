#include "imageitem.h"
#include "item.h"

#include <QtWidgets>

using namespace masonry;

ImageItem::ImageItem()
{
    imageSize = QSize(1, 1);
    _geometry = QRect(QPoint(0, 0), imageSize);
}

ImageItem::ImageItem(const QSize &size)
{
    imageSize = size;
    _geometry.setSize(size);
}

ImageItem::~ImageItem()
{
    imageSize = QSize(1, 1);
}

quint32 ImageItem::heightForWidth(quint32 width)
{
    return ((imageSize.height() * width) / imageSize.width());
}
