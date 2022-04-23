#include "column.h"
#include <QPainter>
#include <QImage>
#include <stdlib.h>
#include <time.h>
column::column():speed(-2), width(100), space(174)
{
mainPoint.setX(600);
srand(time(NULL));
mainPoint.setY(30 + (rand()*200)%740 - space);

}
void column::drawColumn(QPainter* painter){
    QImage pipe("D:/qt/labsQT/flappy_bird/sprites/pipe.png");
    painter->drawRect(this->mainPoint.x(), 0, this->width,this->mainPoint.y());
    painter->drawRect(this->mainPoint.x(), this->mainPoint.y() + this->space, this->width, 800 - this->space - this->mainPoint.y());

    painter->drawImage(this->mainPoint.x(),this->mainPoint.y() - 800, pipe);
    if(this->mainPoint.x() + this->width < 0){
        mainPoint.setX(600);
        srand(time(NULL));
        mainPoint.setY(30 + (rand()*200)%740 - space);
    }
}


