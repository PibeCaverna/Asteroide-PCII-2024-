#include "bala.h"

Bala::Bala(QPointF pos, qreal angulo) {

    this->_pos = pos;
    this->_speed = QPointF(cos(angulo-M_PI/2),sin(angulo-M_PI/2));
}

void Bala::Dibujar(QPainter *p){
    QPen Pen{Qt::white};
    Pen.setWidth(10);
    p->setPen(Pen);


    p->drawPoint(_pos);
    //
}

void Bala::Update(){
    _pos += _speed*22;
}
