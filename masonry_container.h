#ifndef MASONRY_CONTAINER_H
#define MASONRY_CONTAINER_H

#include <QGridLayout>

#include "masonry_item.h"

class Container
{
public:
    // Ctor accepts initial container size.
    explicit Container(const QSize &size); //const
    ~Container();

    // Sets new container size.
    void setContainerSize(const QSize &size);

    // Sets fixed vertical/horizontal spacing between the items.
    void setSpacingBetweenItems(quint32 spacing);

    // Specifies the min/max values for Item width.
    void setItemMinimumWidth(quint32 width);
    void setItemMaximumWidth(quint32 width);

    quint32 containerWidth() const;
    quint32 spacingBetweenItems() const;
    quint32 itemMinimumWidth() const;
    quint32 itemMaximumWidth() const;

    // This is a test method
    void addWidget(QWidget *widget, quint32 posX, quint32 posY);

    // Adds Item to the end of container.
    void addItem(Item *item);

    // Removes Item from container.
    void removeItem(Item *item);

    // Returns ordered list of stored Items
    std::vector<Item *> items() const;

    // Masonry
    void masonryLayout(quint32 numberOfColumns, quint32 itemWidth);

    // Recalculates geometry of all items
    void update();

    // This is a test method
    QGridLayout * getLayout();

private:
    QGridLayout * _gridLayout; //Maybe it's not useful at all
    QSize containerSize;
    quint32 _spacingBetweenItems;
    quint32 _itemMinimumWidth;
    quint32 _itemMaximumWidth;
    std::vector<Item *> vectorOfItems;
};

#endif // MASONRY_CONTAINER_H
