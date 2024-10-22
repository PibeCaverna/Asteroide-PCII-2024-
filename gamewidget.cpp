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
    p.setWindow(0,0,6400,4800);

    if (this ->width() < this ->height()){
        p.setViewport(0,0,this->width(),(float)this->height());
    }
    else{
        p.setViewport(0,0,this->height()*4,this->height());
    }

    juego->update(); //antes de dibujar hay que actualizar el frame
    juego->Dibujar(&p);
    qDebug() << "dibuja";
}

void GameWidget::keyPressEvent(QKeyEvent *event){
    //juego->handleInput(event);
    //qDebug() << "press";

}
