#ifndef ASTEROIDE_H
#define ASTEROIDE_H
#include "drawable.h"
#include <QPointF>
#include <QList>

class Asteroide: public Drawable
{
protected:
    qreal _Valor;
    QPointF _PoligonoAbsoluto[10]{
        QPointF(00000,-4000),
        QPointF(-2000,-6000),
        QPointF(-6000,-2000),
        QPointF(-2000,-2000),
        QPointF(-6000,00000),
        QPointF(-4000,04000),
        QPointF(04000,04000),
        QPointF(06000,00000),
        QPointF(06000,-4000),
        QPointF(02000,-6000),
    };
    QPointF _PoligonoRelativo[10];
    QPointF _CentroDeMasa;
    QPointF _velocidad;
public:
    Asteroide(QPointF CdMasa, qreal Puntos,QPointF vel=QPointF(0,0));
    void Dibujar(QPainter * p) override;
    void Update();

};

#endif // ASTEROIDE_H

