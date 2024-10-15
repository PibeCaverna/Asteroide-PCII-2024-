#ifndef ASTEROIDE_H
#define ASTEROIDE_H
//#include <QPainter>
#include "gameobject.h"
#include <QPointF>
#include <QList>

class Asteroide: public GameObject
{
protected:
    int _Punto;
    int _Tamanio;
    QList<QPointF> P_Rel;
public:
    Asteroide(QList<QPointF>P_R, QPointF c,int punto,int tamanio,QList<QPointF> rel);

};

#endif // ASTEROIDE_H
