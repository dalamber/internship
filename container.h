#ifndef CONTAINER_H
#define CONTAINER_H

#include "item.h"

namespace masonry
{
    class Container
    {
    public:
        Container();
        explicit Container(const QSize &size);
        ~Container();

        void setContainerSize(const QSize &size);
        void setSpacingBetweenItems(quint32 spacing);
        void setItemMinimumWidth(quint32 width);
        void setItemMaximumWidth(quint32 width);
        void setContainerHeight(quint32 height);
        void enableCenterAlignment(bool enable);

        quint32 containerWidth() const;
        quint32 spacingBetweenItems() const;
        quint32 itemMinimumWidth() const;
        quint32 itemMaximumWidth() const;
        quint32 containerHeight() const;
        bool centerAlignment() const;

        void addItem(Item *item);

        // Removes Item from container.
        //void removeItem(Item *item);

        std::vector<Item *> items() const;

    private:
        class Impl;
        Impl *_impl;
        void masonryLayout(quint32 numberOfColumns, quint32 itemWidth);
    };
}

#endif // CONTAINER_H
