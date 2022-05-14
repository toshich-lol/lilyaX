#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "bird.h"
#include "column.h"
#include <QPainter>
#include <QTimer>
#include <QPen>
#include <QBrush>
#include <QImage>
#include <QPaintEvent>
#include <QMainWindow>
#include <cmath>
#include <QFont>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);

    void dieBird();

    void checkScore();

    void keyPressEvent(QKeyEvent *event);
    ~MainWindow();

public slots:
    void startGame();
    void switchBird();
    void moveObject();
    double distance(QPoint First, QPoint Second);
private slots:
    void on_PlayButton_clicked();
    void on_RestartButton_clicked();

private:
    Ui::MainWindow *ui;
    column column1;
    column column2;
    bird bird;
    QTimer timer;
    QTimer birdTimer;
    int counter;
    QString score;
};
#endif // MAINWINDOW_H
