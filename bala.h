#ifndef BALA_H
#define BALA_H
#include <QPointF>
#include <QList>
#include <QDebug>
#include <cmath>
#include <QTimer>
#include <QElapsedTimer>
#include "drawable.h"


class Bala: public Drawable
{
    QElapsedTimer _dt;
    QPointF _pos;
    QPointF _speed;

public:
    Bala(QPointF pos, qreal angulo);
    void Update() override;
    void Dibujar(QPainter *p) override;
    bool expiro();
};

#endif // BALA_H
