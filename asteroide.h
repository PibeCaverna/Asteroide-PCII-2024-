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
        QPointF(500,1500),
        QPointF(500,2500),
        QPointF(-500,2500),
        QPointF(-1500,1500),
        QPointF(-2500,-500),
        QPointF(-1500,-2500),
        QPointF(500,-2500),
        QPointF(2500,-500),
        QPointF(2500,1500),
        QPointF(1500,2500),
    };
    QPointF _PoligonoRelativo[10];
public:
    Asteroide(QPointF CdMasa, qreal Puntos);
    void Dibujar(QPainter * p) override;
};

#endif // ASTEROIDE_H
