#ifndef BIRD_H
#define BIRD_H

#include <QPainter>
#include <QPoint>

class bird
{
public:
    bird();
    void drawBird(QPainter* painter);
    void Switch();
    int index;
    int radius;
    int speed;
    QPoint centre;
    QImage mainImage;
    QImage *images[4];
};

#endif // BIRD_H
