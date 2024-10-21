#include "pj.h"

PJ::PJ(QPointF CentroDeMasa) {
    for(int i = 0; i < 5; i++){
        this->_PoligonoRelativo[i] = _PoligonoAbsoluto[i];
        this->_PoligonoRelativo[i]+=CentroDeMasa;
    }
}
void PJ::Dibujar(QPainter *p){
    p->setPen(Qt::white);
    p->drawPolygon(_PoligonoRelativo,5);
}
