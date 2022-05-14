#include "bird.h"

bird::bird(): radius(25), speed(1), index(0){
images[0] = new QImage("D:/qt/labsQT/flappy_bird/sprites/1.png");
images[1] = new QImage("D:/qt/labsQT/flappy_bird/sprites/2.png");
images[2] = new QImage("D:/qt/labsQT/flappy_bird/sprites/3.png");
images[3] = new QImage("D:/qt/labsQT/flappy_bird/sprites/4.png");
images[4] = new QImage("D:/qt/labsQT/flappy_bird/sprites/die1.png");
images[5] = new QImage("D:/qt/labsQT/flappy_bird/sprites/die2.png");
mainImage = *images[0];
centre.setX(300);
centre.setY(400);
}

void bird::drawBird(QPainter* painter){
   // painter->drawEllipse(this->centre, this->radius, this->radius);
    painter->drawImage(this->centre.x()- this->radius - 3, this->centre.y() - this->radius , mainImage);
}

void bird::Switch(){
    index = (index + 1) % 4;
    mainImage = *images[index];
}

void bird::Die(QTimer *timer, QTimer *birdTimer){\
    mainImage = *images[4];
    birdTimer->stop();
    if(centre.y() + radius >= 765){
    timer->stop();
    centre.setY(778);
    mainImage = *images[5];
    }
}
