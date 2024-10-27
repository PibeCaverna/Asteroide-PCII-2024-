#include "gamewidget.h"
#include "gamelogic.h"
#include <QPainter>

GameWidget::GameWidget(QWidget *parent)
    : QWidget{parent}
{
    juego = new GameLogic();

    timer.setInterval(refresh_period); //setea la tabla de refresco a 20ms
    //connect(&timer,signals(timeout()),this,SLOT(update()));
    connect(&timer, &QTimer::timeout, this, QOverload<>::of(&GameWidget::update)); //hace que paintEvent sea llamado constantemente
    timer.start();
    setFocusPolicy(Qt::TabFocus); //permite que reciba inputs de teclado
}

void GameWidget::paintEvent(QPaintEvent *evento)
{
    QPainter p(this);
    p.setWindow(0,0,3200,2400);

    if (this ->width() > this ->height()*4/3){//achatado
        double x0 = this->width()/2-this->height()*(4/3.0)/2;
        p.setViewport(x0,0,this->height()*(4/3.0),this->height());
    }
    else{//alto
        double y0 = this->height()/2-(float)this->width()*(3.0/4)/2;
        p.setViewport(0,y0,this->width(),(float)this->width()*(3.0/4));
    }


    juego->Update(); //antes de dibujar hay que actualizar el frame
    juego->Dibujar(&p);
    //qDebug() << "dibuja";
}


void GameWidget::handleEvent(QKeyEvent *event){
    juego->handleInput(event);
}


