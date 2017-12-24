#ifndef IMAGEITEM_H
#define IMAGEITEM_H

#include "item.h"

namespace masonry
{
    class ImageItem : public Item
    {
        Q_OBJECT
    public:
        ImageItem();
        explicit ImageItem(const QSize &size);
        ~ImageItem();
        quint32 heightForWidth(quint32 width) override;
    private:
        QSize imageSize;
    };
}

#endif // MASONRY_IMAGEITEM_H
