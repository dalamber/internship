#ifndef ITEM_H
#define ITEM_H

#include <QtWidgets>

namespace masonry
{
    class Item : public QObject
    {
        Q_OBJECT
    public:
        virtual quint32 heightForWidth(quint32 width) = 0;
        QRect geometry() const
        {
            return _geometry;
        }
        void setGeometry(const QRect &geometry)
        {
            _geometry = geometry;
            emit geometryChanged();
        }
    signals:
        void geometryChanged();
    protected:
        QRect _geometry;
    };
}

#endif // MASONRY_ITEM_H
