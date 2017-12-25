#include "container.h"
#include "item.h"

#include <QtWidgets>

using namespace masonry;

// Работает только через отладку
/*class Container::Impl
{
public:
    QSize containerSize;
    quint32 _spacingBetweenItems;
    quint32 _itemMinimumWidth;
    quint32 _itemMaximumWidth;
    std::vector<Item *> vectorOfItems;
};*/

Container::Container()
{
    qDebug() << "Container has been created\n";
}

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
    for (int i = 1; i < vectorOfItems.size(); ++i)
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
        if (numberOfColumns < 1)
            numberOfColumns = 1;
        quint32 numberOfSpaces = numberOfColumns - 1;
        quint32 itemWidth = (containerSize.width() - (numberOfSpaces * _spacingBetweenItems)) / numberOfColumns;
        if (itemWidth > _itemMaximumWidth)
            itemWidth = _itemMaximumWidth;
        masonryLayout(numberOfColumns, itemWidth);
    }
    else
        qDebug() << "Wrong!"; //masonryLayoutDifferentWidths();
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
/*void Container::removeItem(Item *item)
{
    std::vector<Item *>::iterator it;
    it = find (vectorOfItems.begin(), vectorOfItems.end(), item);
    if (it != vectorOfItems.end())
    {
        vectorOfItems.erase(it);
    }
    else
    {
        qDebug() << "Not found\n";
    }
}*/

// Returns ordered list of stored Items
std::vector<Item *> Container::items() const
{
    return vectorOfItems;
}

// Masonry
void Container::masonryLayout(quint32 numberOfColumns, quint32 itemWidth)
{
    quint32 tmpWidth = 0;
    quint32 numberOfFilledColumns = 0;
    std::vector<quint32> heights(numberOfColumns);
    for(quint32 i = 0; i < numberOfColumns; ++i)
        heights[i] = 0;

    if (numberOfColumns >= vectorOfItems.size())
    {
        for (quint32 i = 0; i < vectorOfItems.size(); ++i)
        {
            quint32 tmpHeight = vectorOfItems[i]->heightForWidth(_itemMinimumWidth);
            QPoint pt(i * _itemMinimumWidth + i * _spacingBetweenItems, 0);
            QSize sz(_itemMinimumWidth, tmpHeight);
            QRect rc(pt, sz);
            vectorOfItems[i]->setGeometry(rc);
        }
    }
    else
    {
        for (quint32 j = 0; j < vectorOfItems.size();)
        {
            numberOfFilledColumns = 0;
            tmpWidth = 0;
            for (quint32 i = 0; ; ++i)
            {
                if ((i + j) >= vectorOfItems.size())
                {
                    numberOfFilledColumns = i;
                    break;
                }
                if (tmpWidth + itemWidth > containerSize.width())
                {
                    numberOfFilledColumns = i;
                    break;
                }
                quint32 tmpHeight = vectorOfItems[i + j]->heightForWidth(itemWidth);
                if ((numberOfFilledColumns == 0) && (numberOfColumns > 1)
                        && (tmpHeight + heights[numberOfColumns - 1] <= heights[numberOfColumns - 2]))
                {
                    QPoint pt((numberOfColumns - 1) * itemWidth + (numberOfColumns - 1) * _spacingBetweenItems,
                              heights[numberOfColumns - 1]);
                    QSize sz(itemWidth, tmpHeight);
                    QRect rc(pt, sz);
                    vectorOfItems[i + j]->setGeometry(rc);
                    heights[numberOfColumns - 1] += tmpHeight + _spacingBetweenItems;
                }
                else if (((numberOfFilledColumns >= 2)
                     && (tmpHeight + heights[numberOfFilledColumns - 1] <= heights[numberOfFilledColumns - 2]))
                        || ((numberOfFilledColumns == 1) && (tmpHeight + heights[0] <= heights[1])))
                {
                    QPoint pt((numberOfFilledColumns - 1) * itemWidth + (numberOfFilledColumns - 1) * _spacingBetweenItems,
                              heights[numberOfFilledColumns - 1]);
                    QSize sz(itemWidth, tmpHeight);
                    QRect rc(pt, sz);
                    vectorOfItems[i + j]->setGeometry(rc);
                    heights[numberOfFilledColumns - 1] += tmpHeight + _spacingBetweenItems;
                }
                else
                {
                    QPoint pt(numberOfFilledColumns * itemWidth + numberOfFilledColumns * _spacingBetweenItems,
                              heights[numberOfFilledColumns]);
                    QSize sz(itemWidth, tmpHeight);
                    QRect rc(pt, sz);
                    vectorOfItems[i + j]->setGeometry(rc);
                    heights[numberOfFilledColumns] += tmpHeight + _spacingBetweenItems;
                    tmpWidth += vectorOfItems[i + j]->geometry().width();
                    tmpWidth += _spacingBetweenItems;
                    ++numberOfFilledColumns;
                }
            }
            j += numberOfFilledColumns;
        }
    }
    heights.clear();
}

// Пока что очень сырая версия
// Изменения ширины элементов еще нет
// Masonry with different widths
/*
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
        tmpWidth +=  _spacingBetweenItems;
    }
    // запоминаем кол-во элементов в предыдущем ряду
    numberOfItemsInPreviousRow = numberOfColumns;

    // укладываем последующие ряды
    for(quint32 j = numberOfColumns; j < vectorOfItems.size();)
    {
        numberOfColumns = 0;
        quint32 prevHeight = 0; // tmp для занятой высоты над текущим элементом
        tmpWidth = 0;
        for (quint32 i = 0; tmpWidth <  containerSize.width(); i++)
        {
            if ((i + j) >= vectorOfItems.size())
                break; // превысили число элементов
            if (tmpWidth + vectorOfItems[i + j]->geometry().width() >  containerSize.width())
                break; // заполнили ряд
            quint32 tmpHeight = vectorOfItems[i + j]->geometry().height();
            if (((heights[i] >= heights[i + 1]) && heights[i + 1] != 0) ||
                    (widths[i + j - numberOfItemsInPreviousRow - 1] >=
                     tmpWidth + vectorOfItems[i + j]->geometry().width()))
            {
                if (i >= numberOfItemsInPreviousRow)
                {
                    prevHeight = vectorOfItems[numberOfItemsInPreviousRow - 1]->geometry().height() +  _spacingBetweenItems;
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
*/
