#include "bala.h"

Bala::Bala(QPointF pos, QPointF speed) {
    this->_pos = pos;
    this->_speed = speed;
}

void Bala::Dibujar(QPainter *p){
    QPen Pen{Qt::white};
    Pen.setWidth(10);
    p->setPen(Pen);


    p->drawPoint(_pos);
    //
}

void Bala::Update(){
    _pos += _speed;
}
