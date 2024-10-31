#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *ev){
    ui->widget->addEvent(ev);
    //qDebug() << ev;
}

void MainWindow::keyReleaseEvent(QKeyEvent *ev){
    ui->widget->removeEvent(ev);
}
