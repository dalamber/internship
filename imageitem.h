#ifndef IMAGEITEM_H
#define IMAGEITEM_H

#include <QFile>

#include "item.h"

namespace masonry
{
    class ImageItem : public Item
    {
    public:
        explicit ImageItem(const QSize &size);
        ImageItem();
        ~ImageItem();

        quint32 heightForWidth(quint32 width) override;

    private:
        QSize imageSize;
    };
}

#endif // MASONRY_IMAGEITEM_H
