#include "gamewidget.h"
#include "gamelogic.h"
#include <QPainter>

GameWidget::GameWidget(QWidget *parent)
    : QWidget{parent}
{
    juego = new GameLogic(800,600);

    timer.setInterval(refresh_period); //setea la tabla de refresco a 20ms
    //connect(&timer,signals(timeout()),this,SLOT(update()));
    timer.start();
}
void GameWidget::paintEvent(QPaintEvent *evento)
{
    QPainter p(this);
    juego->Dibujar(&p);
}
