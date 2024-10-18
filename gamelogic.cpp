#include "gamelogic.h"

GameLogic::GameLogic(int Ancho, int Alto) {
    this->_ancho=Ancho;
    this->_alto=Alto;
}

void GameLogic::Dibujar(QPainter * p){
    p->setWindow(0,0,_ancho,_alto);
    p->setViewport(0,0,_ancho,_alto);
    p->fillRect(0,0,_ancho,_alto,Qt::red);


}
