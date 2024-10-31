#ifndef BALA_H
#define BALA_H
#include "ptcolider.h"
#include <QList>
#include <QDebug>
#include <cmath>
#include <QTimer>
#include <QElapsedTimer>
#include "drawable.h"


class Bala: public Drawable, public PtColider
{
    QElapsedTimer _dt;
    QPointF _pos;
    QPointF _speed;

public:
    Bala(QPointF pos, qreal angulo);
    void Update() override;
    void Dibujar(QPainter *p) override;
    bool expiro();
    int get_dt(){return _dt.elapsed();}
    QPointF get_pt() override{return _pos;}
    QPointF get_Speed(){return _speed;}

};

#endif // BALA_H
