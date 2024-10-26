#ifndef PJ_H
#define PJ_H
#include "drawable.h"
#include <cmath>
#include <QDebug>
#include <QPen>
class PJ:public Drawable
{
public:
    PJ(QPointF CentroDeMasa);
    void Dibujar(QPainter * p) override;
    void Rototrasladar();
    void update_theta(qreal Angulo);
    void Xlr8(qreal polenta);
    void UpdateCoM();
    void Update() override;
protected:
    QPointF _PoligonoAbsoluto[5]{
        QPointF( 000, -150),
        QPointF( 100,  100),
        QPointF( 040,  060),
        QPointF(-040,  060),
        QPointF(-100,  100),
    };
    QPointF _PoligonoRelativo[5];
    QPointF _CentroDeMasa;
    QPointF _Speed;
    qreal   _theta;
};

#endif // PJ_H
