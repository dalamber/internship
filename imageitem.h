#ifndef IMAGEITEM_H
#define IMAGEITEM_H

#include <QFile>

#include "item.h"

namespace masonry
{
    class ImageItem : public Item
    {
    public:
        ImageItem();
        explicit ImageItem(QSize &size);
        ~ImageItem() override;
        quint32 heightForWidth(quint32 width) override;
        void setRectangle(QPoint &point, QSize &size);
    private:
        QSize imageSize;
    };
}

#endif // MASONRY_IMAGEITEM_H
