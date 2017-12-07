#include "masonry_container.h"
#include "masonry_item.h"

#include <QGridLayout>
#include <QtWidgets>


Container::Container(const QSize &size)
{
    _gridLayout = new QGridLayout;
    containerSize = size;
}

Container::~Container()
{
    //delete[] vectorOfItems;
}

// Sets new container size.
void Container::setContainerSize(const QSize &size)
{
    containerSize = size;
}

// Sets fixed vertical/horizontal spacing between the items.
void Container::setSpacingBetweenItems(quint32 spacing)
{
    _gridLayout->setHorizontalSpacing(spacing);
    _gridLayout->setVerticalSpacing(spacing);
    //_spacingBetweenItems = spacing;
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

// This is a test method
void Container::addWidget(QWidget *widget, quint32 posX, quint32 posY)
{
    _gridLayout->addWidget(widget, posX, posY);
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
            quint32 tmpHeight = vectorOfItems[i + j]->heightForWidth(itemWidth);
            QPoint pt(i * itemWidth, heights[i]); //spacing
            QSize sz(itemWidth, tmpHeight);
            QRect rc(pt, sz);
            vectorOfItems[i]->setGeometry(rc);
            heights[i] = tmpHeight;
            //может, стоит сделать что-то с сигналом
        }
    }
    delete[] heights;
}

//std::vector<Item *>::const_iterator it=this->vectorOfItems.begin();
//it!=this->vectorOfItems.end();
//++it

// Recalculates geometry of all items
void Container::update()
{
    /*quint32 numberOfColumns = containerSize.width() / ((itemMaximumWidth() + itemMinimumWidth()) / 2); //spacing

    if ()
    {
        //item->setGeometry(&geometry);
    }*/
}

// This is a test method
QGridLayout * Container::getLayout()
{
    return _gridLayout;
}
