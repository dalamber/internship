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
    bool flagDifferentWidths = false;
    for (int  i = 1; i < vectorOfItems.size(); i++)
    {
        if (vectorOfItems[i]->geometry().width() != vectorOfItems[i - 1]->geometry().width())
        {
            flagDifferentWidths = true;
            break;
        }
    }
    if (flagDifferentWidths == false)
    {
        quint32 numberOfColumns = containerSize.width() / (_itemMinimumWidth + _spacingBetweenItems);
        quint32 numberOfSpaces = numberOfColumns - 1;
        quint32 itemWidth = (containerSize.width() - (numberOfSpaces * _spacingBetweenItems)) / numberOfColumns;
        if (itemWidth > _itemMaximumWidth)
            itemWidth = _itemMaximumWidth;
        masonryLayout(numberOfColumns, itemWidth);    
    }
    else
        masonryLayoutDifferentWidths();
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
            quint32 tmpHeight = vectorOfItems[i + j]->heightForWidth(itemWidth);
            /*
            // группируем маловысотные элементы вместе, друг под другом
            if (((i >= 2) && ((tmpHeight + vectorOfItems[i + j - 1]->geometry().height()) <
                              vectorOfItems[i + j - 2]->geometry().height())) ||
                    ((i == 1) && (tmpHeight + heights[i - 1] < heights[numberOfColumns - i])))
            {
                QPoint pt((i - 1) * itemWidth + (i - 1) * _spacingBetweenItems, heights[i - 1] + _spacingBetweenItems * (2 * j / numberOfColumns));
                QSize sz(itemWidth, tmpHeight);
                QRect rc(pt, sz);
                vectorOfItems[i + j]->setGeometry(rc);
                heights[i - 1] += tmpHeight;
            }
            */
            QPoint pt(i * itemWidth + i * _spacingBetweenItems, heights[i] + _spacingBetweenItems * (j / numberOfColumns));
            QSize sz(itemWidth, tmpHeight);
            QRect rc(pt, sz);
            vectorOfItems[i + j]->setGeometry(rc);
            heights[i] += tmpHeight;
        }
    }
    delete[] heights;
}

// Пока что очень сырая версия
// Изменения ширины элементов еще нет
// Masonry with different widths
void Container::masonryLayoutDifferentWidths()
{
    std::vector<quint32> heights(vectorOfItems.size());
    std::vector<quint32> widths(vectorOfItems.size());
    quint32 numberOfColumns = 0;
    quint32 numberOfItemsInPreviousRow = 0;
    quint32 tmpWidth = 0;

    // укладываем первый ряд
    for (quint32 i = 0; tmpWidth < containerSize.width(); i++)
    {
        if (tmpWidth + vectorOfItems[i]->geometry().width() >= containerSize.width())
            break;
        quint32 tmpHeight = vectorOfItems[i]->geometry().height();
        QPoint pt(tmpWidth, 0);
        QSize sz(vectorOfItems[i]->geometry().width(), tmpHeight);
        QRect rc(pt, sz);
        vectorOfItems[i]->setGeometry(rc);
        heights[i] = tmpHeight + _spacingBetweenItems; // запоминаем высоты элементов
        tmpWidth += vectorOfItems[i]->geometry().width();
        numberOfColumns++;
        widths[i] = tmpWidth;
        tmpWidth += _spacingBetweenItems;
    }
    // запоминаем кол-во элементов в предыдущем ряду
    numberOfItemsInPreviousRow = numberOfColumns;

    // укладываем последующие ряды
    for(quint32 j = numberOfColumns; j < vectorOfItems.size();)
    {
        numberOfColumns = 0;
        quint32 prevHeight = 0; // tmp для занятой высоты над текущим элементом
        tmpWidth = 0;
        for (quint32 i = 0; tmpWidth < containerSize.width(); i++)
        {
            if ((i + j) >= vectorOfItems.size())
                break; // превысили число элементов
            if (tmpWidth + vectorOfItems[i + j]->geometry().width() > containerSize.width())
                break; // заполнили ряд
            quint32 tmpHeight = vectorOfItems[i + j]->geometry().height();
            if (((heights[i] >= heights[i + 1]) && heights[i + 1] != 0) ||
                    (widths[i + j - numberOfItemsInPreviousRow - 1] >= tmpWidth + vectorOfItems[i + j]->geometry().width())) // высота над и справа от него
            {
                if (i >= numberOfItemsInPreviousRow)
                {
                    prevHeight = vectorOfItems[numberOfItemsInPreviousRow - 1]->geometry().height() + _spacingBetweenItems;
                    heights[i] = prevHeight;
                }
                else
                {
                    prevHeight = heights[i];
                }
                QPoint pt(tmpWidth, prevHeight);
                QSize sz(vectorOfItems[i + j]->geometry().width(), tmpHeight);
                QRect rc(pt, sz);
                vectorOfItems[i + j]->setGeometry(rc);
            }
            else
            {
                if (i >= numberOfItemsInPreviousRow)
                {
                    prevHeight = vectorOfItems[numberOfItemsInPreviousRow - 1]->geometry().height() + _spacingBetweenItems;
                    heights[i] = prevHeight;
                }
                else if (heights[i + 1] == 0)
                {
                    if (widths[i + j - numberOfItemsInPreviousRow - 1] < tmpWidth + vectorOfItems[i + j]->geometry().width())
                        prevHeight = heights[i - 1] - vectorOfItems[i + j - 1]->geometry().height() - _spacingBetweenItems;
                    else
                        prevHeight = heights[i];
                }
                else
                {
                    prevHeight = heights[i + 1];
                }
                QPoint pt(tmpWidth, prevHeight);
                QSize sz(vectorOfItems[i + j]->geometry().width(), tmpHeight);
                QRect rc(pt, sz);
                vectorOfItems[i + j]->setGeometry(rc);
            }
            numberOfColumns++;      
            heights[i] += (tmpHeight + _spacingBetweenItems);
            tmpWidth += vectorOfItems[i + j]->geometry().width();
            widths[i + j] = tmpWidth;
            tmpWidth += _spacingBetweenItems;
        }
        numberOfItemsInPreviousRow = numberOfColumns;
        j += numberOfColumns;  
    }
    heights.clear();
}

/*(vectorOfItems[i + j]->geometry().width() <=
                    vectorOfItems[i + j - numberOfItemsInPreviousRow]->geometry().width()) || // ширина текущего и над ним*/
