#include "gamewidget.h"
#include "gamelogic.h"
#include <QPainter>

GameWidget::GameWidget(QWidget *parent)
    : QWidget{parent}
{
    juego = new GameLogic(1600,1200);

    timer.setInterval(refresh_period); //setea la tabla de refresco a 20ms
    //connect(&timer,signals(timeout()),this,SLOT(update()));
    connect(&timer, &QTimer::timeout, this, QOverload<>::of(&GameWidget::update)); //hace que paintEvent sea llamado constantemente
    timer.start();
    setFocusPolicy(Qt::TabFocus); //permite que reciba inputs de teclado
}

void GameWidget::paintEvent(QPaintEvent *evento)
{
    QPainter p(this);
    juego->update(); //antes de dibujar hay que actualizar el frame
    juego->Dibujar(&p);
    qDebug() << "dibuja";
}

void GameWidget::keyPressEvent(QKeyEvent *event){
    //juego->handleInput(event);
    //qDebug() << "press";

}
