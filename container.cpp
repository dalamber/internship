#include "container.h"
#include "item.h"

#include <QtWidgets>

using namespace masonry;

Container::Container(const QSize &size)
{
    containerSize = size;
}

Container::~Container()
{
    vectorOfItems.clear();
}

// Sets new container size.
void Container::setContainerSize(const QSize &size)
{
    containerSize = size;
    quint32 numberOfColumns = containerSize.width() / (_itemMinimumWidth + _spacingBetweenItems);
    quint32 numberOfSpaces = numberOfColumns - 1;
    quint32 itemWidth = (containerSize.width() - (numberOfSpaces * _spacingBetweenItems)) / numberOfColumns;
    masonryLayout(numberOfColumns, itemWidth);
}

// Sets fixed vertical/horizontal spacing between the items.
void Container::setSpacingBetweenItems(quint32 spacing)
{
    _spacingBetweenItems = spacing;
}

// Specifies the min/max values for Item width.
void Container::setItemMinimumWidth(quint32 width)
{
    _itemMinimumWidth = width;
}

void Container::setItemMaximumWidth(quint32 width)
{
    _itemMaximumWidth = width;
}

quint32 Container::containerWidth() const
{
    return containerSize.width();
}

quint32 Container::spacingBetweenItems() const
{
    return _spacingBetweenItems;
}

quint32 Container::itemMinimumWidth() const
{
    return _itemMinimumWidth;
}

quint32 Container::itemMaximumWidth() const
{
    return _itemMaximumWidth;
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

//std::vector<Item *>::const_iterator it=this->vectorOfItems.begin();
//it!=this->vectorOfItems.end();
//++it

// Recalculates geometry of all items
void Container::update()
{

}

// Masonry
void Container::masonryLayout(quint32 numberOfColumns, quint32 itemWidth)
{
    quint32 *heights = new quint32[numberOfColumns];
    for(quint32 i = 0; i < numberOfColumns; i++)
        heights[i] = 0;

    for(quint32 j = 0; j < vectorOfItems.size(); j += numberOfColumns)
    {
        for (quint32 i = 0; i < numberOfColumns; i++)
        {
            if ((i + j) >= vectorOfItems.size())
                break;
            quint32 horizontalSpacing = _spacingBetweenItems;
            quint32 verticalSpacing;
            /*if (j == 0)
                verticalSpacing = 0;
            else*/
                verticalSpacing = _spacingBetweenItems;
            quint32 tmpHeight = vectorOfItems[i + j]->heightForWidth(itemWidth);
            QPoint pt(i * itemWidth + i * horizontalSpacing, heights[i] + verticalSpacing * (j / numberOfColumns)); //
            QSize sz(itemWidth, tmpHeight);
            QRect rc(pt, sz);
            vectorOfItems[i + j]->setGeometry(rc);
            heights[i] += tmpHeight;
            /*if (j == 0)

            else
                heights[i] += tmpHeight + verticalSpacing;*/
        }
    }
    delete[] heights;
}
