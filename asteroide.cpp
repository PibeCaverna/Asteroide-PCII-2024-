#include "asteroide.h"

Asteroide::Asteroide(QPointF CdMasa, qreal Puntos,QPointF vel)
{

    this ->_velocidad = vel;
    this ->_CentroDeMasa = CdMasa;
    for(int i = 0; i < 10; i++){
        this->_PoligonoAbsoluto[i]/= Puntos;
        this->_PoligonoRelativo.append(_PoligonoAbsoluto[i]);
        this->_PoligonoRelativo[i]+=CdMasa;
    }
}
void Asteroide::Dibujar(QPainter *p){
    QPen Pen{Qt::white};
    Pen.setWidth(2);
    p->setPen(Pen);

    p->drawPolygon(QPolygonF(_PoligonoRelativo));
}

void Asteroide::Update(){
    qreal mod = sqrt(pow(_velocidad.x(),2)+pow(_velocidad.y(),2));
    if (mod > 1){
        this -> _velocidad /= mod;
        this -> _velocidad *= 5;
    }
    this->_CentroDeMasa += _velocidad;
    if (_CentroDeMasa.x() > 3200 + _PoligonoAbsoluto[7].x())
        {_CentroDeMasa.rx() -= 3200 + _PoligonoAbsoluto[7].x();}
    if (_CentroDeMasa.x() < _PoligonoAbsoluto[3].x())
        {_CentroDeMasa.rx() += 3200 + _PoligonoAbsoluto[7].x();}
    if (_CentroDeMasa.y() > 2400 - _PoligonoAbsoluto[1].y())
        {_CentroDeMasa.ry() -= 2400 - _PoligonoAbsoluto[1].y();}
    if (_CentroDeMasa.y() < _PoligonoAbsoluto[1].y())
        {_CentroDeMasa.ry() += 2400 - _PoligonoAbsoluto[1].y();}

    for (int i =0; i<10;i++){
        this ->_PoligonoRelativo[i]=_PoligonoAbsoluto[i] +_CentroDeMasa;
    }
}
