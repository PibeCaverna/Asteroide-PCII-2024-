#include "pj.h"

PJ::PJ(QPointF CentroDeMasa) {
    this ->_CentroDeMasa = CentroDeMasa;
    this ->_Speed = QPointF(0,0);
    this ->_theta = 0; // me parece que el angulo deveria empezar en 90
    for(int i = 0; i < 5; i++){
        this->_PoligonoRelativo.append(_PoligonoAbsoluto[i]);
        this->_PoligonoRelativo[i]+=CentroDeMasa;
    }
}
void PJ::Dibujar(QPainter *p){
    QPen Pen{Qt::white};
    Pen.setWidth(2);
    p->setPen(Pen);

    p->drawPolygon(QPolygonF(_PoligonoRelativo));
}
void PJ::Rototrasladar(){
    for (int i =0; i<5;i++){
        qreal a = _PoligonoAbsoluto[i].x();
        qreal b = _PoligonoAbsoluto[i].y();
        qreal x = a*cos(_theta) - b*sin(_theta);
        qreal y = a*sin(_theta) + b*cos(_theta);
        this -> _PoligonoRelativo[i] = QPointF(x,y);
        this -> _PoligonoRelativo[i]+= _CentroDeMasa;

    }

}
void PJ::update_theta(qreal Angulo, double dt){
    qreal newdeg = (_theta*180/M_PI) + Angulo*dt;
    if (newdeg > 360){newdeg -= 360 * (int)newdeg % 360;}
    this ->_theta = newdeg*M_PI/180;
}
void PJ::Xlr8(qreal polenta){
    this -> _Speed += QPointF(polenta*cos(_theta-M_PI/2),polenta*sin(_theta-M_PI/2));
    qreal mod = sqrt(pow(_Speed.x(),2)+pow(_Speed.y(),2));
    if (mod > 20){
        this -> _Speed /= mod;
        this -> _Speed *= 20;
    }
    //qDebug() << _Speed;
}
void PJ::UpdateCoM(double dt){
    this -> _CentroDeMasa += _Speed*dt;
    this -> _Speed -= (_Speed/50)*dt;
}
void PJ::Update(double dt){
    this -> UpdateCoM(dt);
    if (_CentroDeMasa.x() > 3200 + 150)
    {_CentroDeMasa.rx() -= 3200 + 150;}
    if (_CentroDeMasa.x() < -150)
    {_CentroDeMasa.rx() += 3200 + 150;}
    if (_CentroDeMasa.y() > 2400 + 150)
    {_CentroDeMasa.ry() -= 2400 + 150;}
    if (_CentroDeMasa.y() < -150)
    {_CentroDeMasa.ry() += 2400 + 150;}

    this ->Rototrasladar();
}
void PJ::ressurect(){
    this ->_isalive = true;
    this ->_CentroDeMasa = QPointF(1600,1200);
    this ->_Speed = QPointF(0,0);
    this ->_theta = 0;
}
