#include "bala.h"

Bala::Bala(QPointF pos, qreal angulo) {

    this->_pos = pos;
    this->_speed = QPointF(cos(angulo-M_PI/2),sin(angulo-M_PI/2));
    _dt.start();
}

void Bala::Dibujar(QPainter *p){
    QPen Pen{Qt::white};
    Pen.setWidth(10);
    p->setPen(Pen);


    p->drawPoint(_pos);
    //
}

void Bala::Update(double dt){
    _pos += _speed*50*dt;

    if (_pos.x() > 3200)
        _pos.rx() = 0;
    else if (_pos.x() < 0)
        _pos.rx() = 3200;
    else if (_pos.y() < 0)
        _pos.ry() = 2400;
    else if (_pos.y() > 2400)
        _pos.ry() = 0;
}

bool Bala::expiro(){
    if (_dt.elapsed() >= 700)
        return true;
    return false;
}
