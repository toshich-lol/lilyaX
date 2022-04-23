#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPaintEvent>
#include "column.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);

    ~MainWindow();

public slots:
    void moveColumn();

private:
    Ui::MainWindow *ui;
    column column1;
    column column2;
};
#endif // MAINWINDOW_H
