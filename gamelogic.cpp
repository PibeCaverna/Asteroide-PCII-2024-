#include "gamelogic.h"

GameLogic::GameLogic(int Ancho, int Alto) {
    this->_ancho=Ancho;
    this->_alto=Alto;

    QList<QPointF> puntos = {
        QPointF(-30, -30),
        QPointF(30, -30),
        QPointF(0, 50)
    };
    QPointF pu(0, 5);
    Drawable* nave = new Nave( puntos, pu);
    dibujables.append(nave);

}

void GameLogic::Dibujar(QPainter * p){
    p->setWindow(0,0,_ancho,_alto);
    p->setViewport(0,0,_ancho,_alto);
    p->fillRect(0,0,_ancho,_alto,Qt::red);

    for(Drawable *D : dibujables)
    {
        D->Dibujar(p);
    }
}
