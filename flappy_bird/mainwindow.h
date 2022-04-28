#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPainter>
#include <QTimer>
#include <QPen>
#include <QBrush>
#include <QImage>
#include <QPaintEvent>
#include "column.h"
#include <QMainWindow>
#include "bird.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);

    void keyPressEvent(QKeyEvent *event);
    ~MainWindow();

public slots:
    void switchBird();
    void moveColumn();
private:
    Ui::MainWindow *ui;
    column column1;
    column column2;
    bird bird;
};
#endif // MAINWINDOW_H
