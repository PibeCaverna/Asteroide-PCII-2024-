#include "ovni.h"

Ovni::Ovni(QPointF CdMasa, qreal Puntos) {
    this ->_CentroDeMasa = CdMasa;
    this -> _Puntos = Puntos;
    for(int i = 0; i < 8; i++){
        this->_PoligonoAbsoluto[i]/= Puntos;
        this->_PoligonoRelativo.append(_PoligonoAbsoluto[i]);
        this->_PoligonoRelativo[i]+=CdMasa;
    }
    this -> setspeed();
}

void Ovni::Dibujar(QPainter * p){
    QPen Pen{Qt::white};
    Pen.setWidth(2);
    p->setPen(Pen);

    p->drawPolygon(QPolygonF(_PoligonoRelativo));
    p->drawLine(QLineF(_PoligonoRelativo[1],_PoligonoRelativo[6]));
    p->drawLine(QLineF(_PoligonoRelativo[2],_PoligonoRelativo[5]));
}

void Ovni::Update(){
    if (this ->_isshooting){_isshooting = false;}
    this ->_CentroDeMasa += _Speed;
    if (_tsinceshot > 5000/_Puntos){
        _isshooting = true;
        _tsinceshot = 0;
    }
    else{_tsinceshot++;}
    if (_tsincemove > 20000/_Puntos){
        this -> setspeed();
        _tsincemove = 0;
    }
    else{_tsincemove++;}

    for (int i = 0; i < 8; i++){
        this ->_PoligonoRelativo[i] = _PoligonoAbsoluto[i] + _CentroDeMasa;
    }
}

void Ovni::setspeed(){
    QRandomGenerator V_x, V_y;
    V_x.seed(QDateTime::currentMSecsSinceEpoch()%100);
    V_y.seed(QDateTime::currentMSecsSinceEpoch()%100+1);
    this ->_Speed = QPointF(V_x.generateDouble()*_Puntos*0.1,V_y.generateDouble()*_Puntos*0.1);
}
