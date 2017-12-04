#include "masonry.h"

#include <QGridLayout>
#include <QtWidgets>

using namespace masonry;

ImageItem::ImageItem(QFile file)
{

}

ImageItem::~ImageItem()
{

}

quint32 ImageItem::heightForWidth(quint32 width)
{
    return ((imageSize.height() * width) / qMax(imageSize.width(), 1));
}

QRect ImageItem::geometry() const
{

}

void ImageItem::setGeometry(const QRect &geometry)
{
    _geometry = geometry;
    emit geometryChanged();
}

//signal
void ImageItem::geometryChanged()
{

}

////////////////////////////////////////////////////////////////////////////////

explicit Container::Container(const QSize &size)
{
    containerSize = size; //(?)
}

Container::~Container()
{

}

// Sets new container size.
void Container::setContainerSize(const QSize &size)
{
    containerSize = size;
}

// Sets fixed vertical/horizontal spacing between the items.
void Container::setSpacingBetweenItems(quint32 spacing)
{
    //_gridLayout->setHorizontalSpacing(spacing);
    //_gridLayout->setVerticalSpacing(spacing);
    spacingBetweenItems = spacing;
}

// Specifies the min/max values for Item width.
void Container::setItemMinimumWidth(quint32 width)
{
    itemMinWidth = width;
}

void Container::setItemMaximumWidth(quint32 width)
{
    itemMaxWidth = width;
}

quint32 Container::containerWidth() const
{
    return containerSize.width();
}

quint32 Container::spacingBetweenItems() const
{
    return spacingBetweenItems;
}

quint32 Container::itemMinimumWidth() const
{
    return itemMinWidth;
}

quint32 Container::itemMaximumWidth() const
{
    return itemMaxWidth;
}

// Adds Item to the end of container.
void Container::addItem(Item *item)
{
    vectorOfItems.push_back(item);
}

// Removes Item from container.
void Container::removeItem(Item *item)
{
    vectorOfItems.pop_back(); //or erase
}

// Returns ordered list of stored Items
std::vector<Item *> Container::items() const
{
    return vectorOfItems;
}

// Recalculates geometry of all items
void Container::update()
{

}
