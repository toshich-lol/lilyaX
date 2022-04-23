#ifndef COLUMN_H
#define COLUMN_H

#include <QPainter>
#include <QPoint>
class column{
public:
    column();
    void drawColumn(QPainter* painter);
    QPoint mainPoint;
    int speed;
    int width;
    int space;
};

#endif // COLUMN_H
