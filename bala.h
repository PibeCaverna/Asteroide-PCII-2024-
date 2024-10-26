#ifndef BALA_H
#define BALA_H
#include <QPointF>
#include <QList>
#include <QDebug>
#include "drawable.h"

class Bala: public Drawable
{
    QPointF _pos;
    QPointF _speed;
public:
    Bala(QPointF pos, QPointF speed);
    void Update() override;
    void Dibujar(QPainter *p) override;
};

#endif // BALA_H
