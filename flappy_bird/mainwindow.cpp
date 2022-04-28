#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "column.h"
#include "bird.h"
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    this->column2.mainPoint.setX(950);
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), SLOT(moveColumn()));
    timer->start(20);

    QTimer* birdTimer = new QTimer(this);
    connect(birdTimer, SIGNAL(timeout()), SLOT(switchBird()));
    birdTimer->start(30);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::switchBird(){
    bird.Switch();
};

void MainWindow::moveColumn(){
    this->column1.mainPoint.setX(column1.speed + column1.mainPoint.x());
    this->column2.mainPoint.setX(column2.speed + column2.mainPoint.x());
    this->bird.centre.setY(this->bird.centre.y() + bird.speed);
    if (bird.speed <= 25){
    bird.speed++;
    }
    update();
}
void MainWindow:: keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt:: Key_Space){
        bird.speed = -12;
    }
}


void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QImage bgImage("D:/qt/labsQT/flappy_bird/sprites/bg1.png");
    painter.drawImage(0,0, bgImage);
    column1.drawColumn(&painter);
    column2.drawColumn(&painter);
    bird.drawBird(&painter);
}

