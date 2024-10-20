#include "asteroide.h"

Asteroide::Asteroide(QPointF CdMasa, qreal Puntos)
{

    for(int i = 0; i < 10; i++){
        this->_PoligonoAbsoluto[i]/= Puntos;
        this->_PoligonoRelativo[i] = _PoligonoAbsoluto[i];
        this->_PoligonoRelativo[i]+=CdMasa;
    }
}
void Asteroide::Dibujar(QPainter *p){
    p->setPen(Qt::white);
    p->drawPolygon(_PoligonoRelativo,10);
}
