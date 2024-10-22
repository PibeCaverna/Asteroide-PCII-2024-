#include "ovni.h"

Ovni::Ovni(QPointF CdMasa, qreal Puntos) {
    this ->_CentroDeMasa = CdMasa;
    for(int i = 0; i < 8; i++){
        this->_PoligonoAbsoluto[i]/= Puntos;
        this->_PoligonoRelativo[i] = _PoligonoAbsoluto[i];
        this->_PoligonoRelativo[i]+=CdMasa;
    }
}

void Ovni::Dibujar(QPainter * p){
    p->setPen(Qt::white);
    p->drawPolygon(_PoligonoRelativo,8);
    p->drawLine(QLineF(_PoligonoRelativo[1],_PoligonoRelativo[6]));
    p->drawLine(QLineF(_PoligonoRelativo[2],_PoligonoRelativo[5]));
}
