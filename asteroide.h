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
        QPointF(00000,04000),
        QPointF(-2000,06000),
        QPointF(-6000,02000),
        QPointF(-2000,02000),
        QPointF(-6000,00000),
        QPointF(-4000,-4000),
        QPointF(04000,-4000),
        QPointF(06000,00000),
        QPointF(02000,06000),
    };
    QPointF _PoligonoRelativo[10];
public:
    Asteroide(QPointF CdMasa, qreal Puntos);
    void Dibujar(QPainter * p) override;
};

#endif // ASTEROIDE_H
