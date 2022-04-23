#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "column.h"

#include <QPainter>
#include <QTimer>
#include <QPen>
#include <QBrush>
#include <QImage>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    this->column1 = column();
    this->column2 = column();
    this->column2.mainPoint.setX(900);
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), SLOT(moveColumn()));
    timer->start(5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::moveColumn(){
    this->column1.mainPoint.setX(column1.speed + column1.mainPoint.x());
    this->column2.mainPoint.setX(column2.speed + column2.mainPoint.x());
    update();
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QImage bgImage("D:/qt/labsQT/flappy_bird/sprites/bg1.png");
    painter.drawImage(0,0, bgImage);
    column1.drawColumn(&painter);
    column2.drawColumn(&painter);
}

