#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "column.h"
#include "bird.h"
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow), counter(0){
    ui->setupUi(this);
    ui->RestartButton->hide();
    connect(&birdTimer, SIGNAL(timeout()), SLOT(switchBird()));
    connect(&timer, SIGNAL(timeout()), SLOT(moveObject()));
    birdTimer.start(30);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::switchBird(){
    bird.Switch();
    update();
}

void MainWindow::startGame(){
    ui->centralwidget->grabKeyboard();
    bird.centre.setY(400);
    birdTimer.start(30);
    bird.speed = 0;
    counter = 0;
    timer.start(20);
    column1.mainPoint.setX(600);
    column2.mainPoint.setX(950);
}


void MainWindow::moveObject(){
    this->column1.mainPoint.setX(column1.speed + column1.mainPoint.x());
    this->column2.mainPoint.setX(column2.speed + column2.mainPoint.x());
    this->bird.centre.setY(this->bird.centre.y() + bird.speed);
    if (bird.speed <= 25){
    bird.speed++;
    }

    if(bird.centre.y() + bird.radius >= 800 || bird.centre.y() - bird.radius <= 0){
        dieBird(); // между трубами
    }else if(bird.centre.x() > column1.mainPoint.x() && bird.centre.x() < column1.mainPoint.x() + column1.width){
        if(bird.centre.y() + bird.radius >= column1.mainPoint.y() + column1.space || bird.centre.y() - bird.radius <= column1.mainPoint.y()){
            dieBird(); // в трубе 1
        }
    }else if(bird.centre.x() > column2.mainPoint.x() && bird.centre.x() < column2.mainPoint.x() + column2.width){
        if(bird.centre.y() + bird.radius >= column2.mainPoint.y() + column2.space || bird.centre.y() - bird.radius <= column2.mainPoint.y()){
            dieBird(); // в трубе 2
        }
    }else if(bird.centre.x() + bird.radius >= column1.mainPoint.x() && bird.centre.x() <= column1.mainPoint.x()){ // перед 1 трубой
        if(sqrt(pow((bird.centre.x() - column1.mainPoint.x()), 2) + pow((bird.centre.y() - column1.mainPoint.y()), 2)) < bird.radius ||
           sqrt(pow((bird.centre.x() - column1.mainPoint.x()), 2) + pow((bird.centre.y() - column1.mainPoint.y() - column1.space), 2)) < bird.radius ||
           bird.centre.y() <= column1.mainPoint.y() || bird.centre.y() >= column1.mainPoint.y() + column1.space){
            dieBird();
        }
    }else if(bird.centre.x() + bird.radius >= column2.mainPoint.x() && bird.centre.x() <= column2.mainPoint.x()){// перед 2 трубой
        if(sqrt(pow((bird.centre.x() - column2.mainPoint.x()), 2) + pow((bird.centre.y() - column2.mainPoint.y()), 2)) < bird.radius ||
           sqrt(pow((bird.centre.x() - column2.mainPoint.x()), 2) + pow((bird.centre.y() - column2.mainPoint.y() - column2.space), 2)) < bird.radius ||
           bird.centre.y() <= column2.mainPoint.y() || bird.centre.y() >= column2.mainPoint.y() + column2.space){
            dieBird();
        }
    }else if(bird.centre.x() >= column1.mainPoint.x() + column1.width && bird.centre.x() - bird.radius <= column1.mainPoint.x() + column1.width){ // после 1 трубы
        if(sqrt(pow((bird.centre.x() - column1.mainPoint.x()) - column1.width, 2) + pow((bird.centre.y() - column1.mainPoint.y()), 2)) < bird.radius ||
          sqrt(pow((bird.centre.x() - column1.mainPoint.x() - column1.width), 2) + pow((bird.centre.y() - column1.mainPoint.y() + column1.space), 2)) < bird.radius){
            dieBird();
        }
    }else if(bird.centre.x() >= column2.mainPoint.x() + column2.width && bird.centre.x() - bird.radius <= column2.mainPoint.x() + column2.width){ // после 2 трубы
        if(sqrt(pow((bird.centre.x() - column2.mainPoint.x()) - column2.width, 2) + pow((bird.centre.y() - column2.mainPoint.y()), 2)) < bird.radius ||
          sqrt(pow((bird.centre.x() - column2.mainPoint.x() - column2.width), 2) + pow((bird.centre.y() - column2.mainPoint.y() + column2.space), 2)) < bird.radius){
            dieBird();
        }
    }
    checkScore();
    update();
}

double MainWindow::distance(QPoint First, QPoint Second)
{
    return sqrt(pow((First.x() - Second.x()), 2) + pow((First.y() - Second.y()), 2));
}

void MainWindow::dieBird(){
    bird.Die(&timer, &birdTimer);
    if(!timer.isActive()){
        ui->RestartButton->show();
        ui->RestartButton->blockSignals(false);
    }
}

void MainWindow::checkScore(){
    if((bird.centre.x() >= column1.mainPoint.x() + column1.width/2 && bird.centre.x() <= column1.mainPoint.x() + column1.width/2 + 3) ||
       (bird.centre.x() >= column2.mainPoint.x() + column2.width/2 && bird.centre.x() <= column2.mainPoint.x() + column2.width/2 + 3)){
           counter++;
    }
}


void MainWindow:: keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Space && birdTimer.isActive()){
        bird.speed = -11;
    }
}
void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QImage bgImage("D:/qt/labsQT/flappy_bird/sprites/bg1.png");
    painter.drawImage(0,0, bgImage);
    column1.drawColumn(&painter);
    column2.drawColumn(&painter);
    bird.drawBird(&painter);
    score = QString("%1").arg(counter);
    QFont font("Courier", 800, 800, QFont::DemiBold);
    painter.setFont(font);
    painter.drawText(300, 100, score);
}


void MainWindow::on_PlayButton_clicked(){
        startGame();
        ui->PlayButton->hide();
        bird.speed = -11;
}


void MainWindow::on_RestartButton_clicked(){
    startGame();
    bird.speed = -11;
    ui->RestartButton->hide();
    }

