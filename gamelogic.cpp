#include "gamelogic.h"

GameLogic::GameLogic(int Ancho, int Alto) {
    this->_ancho=Ancho;
    this->_alto=Alto;

    this ->_nave = new PJ(QPointF(800,600));

    //Drawable* nave = new Nave( puntos, pu);
    //this ->_nave = nave;
    dibujables.append(_nave);
    dibujables.append(new Asteroide(QPointF(100,500),20));
    dibujables.append(new Asteroide(QPointF(400,200),50));
}

void GameLogic::Dibujar(QPainter * p){
    p->setWindow(0,0,2*_ancho,2*_alto);
    p->setViewport(0,0,_ancho,_alto);
    p->fillRect(0,0,_ancho,_alto,Qt::black);
    for(Drawable *D : dibujables)
    {
        D->Dibujar(p);
    }
}

void GameLogic::update(){
}

//void GameLogic::handleInput(QKeyEvent *event){
//    if (event->key() != Qt::Key_Backspace) //las balas no se manejan en nave
//    _nave->handleInput(event);
//}
