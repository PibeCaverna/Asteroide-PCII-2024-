#ifndef ASTEROIDE_H
#define ASTEROIDE_H
#include "drawable.h"
#include "polycolider.h"
#include <QList>
#include <QDebug>
#include <QPolygon>

class Asteroide: public Drawable, public PolyColider
{
protected:
    qreal _Valor;
    QList<QPointF> _PoligonoAbsoluto = {
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
    QList<QPointF> _PoligonoRelativo;
    QPointF _CentroDeMasa;
    QPointF _velocidad;
public:
    Asteroide(QPointF CdMasa, qreal Puntos,QPointF vel=QPointF(0,0));
    void Dibujar(QPainter * p) override;
    void Update();
    QPolygonF get_poly(){
        return QPolygonF(_PoligonoRelativo);
    }

};

#endif // ASTEROIDE_H

