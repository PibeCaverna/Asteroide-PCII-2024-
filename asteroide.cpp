#include "asteroide.h"

Asteroide::Asteroide(QPointF CdMasa, qreal Puntos,QPointF vel)
{

    this ->_velocidad = vel;
    this ->_CentroDeMasa = CdMasa;
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

void Asteroide::Update(){//tengo que hacer que se muevan todos los puntos del array
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
