#include "imageitem.h"
#include "item.h"

#include <QtWidgets>

using namespace masonry;

namespace
{
    static unsigned int g_Counter = 0;
}

ImageItem::ImageItem(const QSize &size)
{
    if (!(++g_Counter % 2))
        preferredHeight = 100;
    else
        preferredHeight = 500;

    imageSize = size;
    _geometry.setSize(size);
}

ImageItem::~ImageItem()
{
    imageSize = QSize(1, 1);
}

quint32 ImageItem::heightForWidth(quint32 width)
{
    Q_UNUSED(width);

    return preferredHeight;
}
