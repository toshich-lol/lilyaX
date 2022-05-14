#ifndef BIRD_H
#define BIRD_H

#include <QTimer>
#include <QPainter>
#include <QPoint>

class bird
{
public:
    bird();
    void drawBird(QPainter* painter);
    void Switch();
    void Die(QTimer *timer, QTimer *birdTimer);
    int index;
    int radius;
    int speed;
    QPoint centre;
    QImage mainImage;
    QImage *images[6];
};

#endif // BIRD_H
