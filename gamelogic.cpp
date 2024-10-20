#include "gamelogic.h"

GameLogic::GameLogic(int Ancho, int Alto) {
    this->_ancho=Ancho;
    this->_alto=Alto;
    //habria que encontrar una forma mas linda de crear la nave y los asteroides
    QList<QPointF> puntos = {
        QPointF(-20, -30),
        QPointF(1, -70),
        QPointF(20, -30),
        QPointF(-20, -30)
    };
    QPointF pu(100, 100);
    this ->_nave = new Nave( puntos, pu);
    Drawable* nave = _nave;

    //Drawable* nave = new Nave( puntos, pu);
    //this ->_nave = nave;
    dibujables.append(nave);

    dibujables.append(new Asteroide(QPointF(400,300),20));
}

void GameLogic::Dibujar(QPainter * p){
    p->setWindow(0,0,_ancho,_alto);
    p->setViewport(0,0,_ancho,_alto);
    p->fillRect(0,0,_ancho,_alto,Qt::black);
    for(Drawable *D : dibujables)
    {
        D->Dibujar(p);
    }
}

void GameLogic::update(){
}

void GameLogic::handleInput(QKeyEvent *event){
    if (event->key() != Qt::Key_Backspace) //las balas no se manejan en nave
    _nave->handleInput(event);
}
