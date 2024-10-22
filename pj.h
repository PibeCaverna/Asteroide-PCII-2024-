#ifndef PJ_H
#define PJ_H
#include "drawable.h"
#include <QPointF>
class PJ:public Drawable
{
public:
    PJ(QPointF CentroDeMasa);
    void Dibujar(QPainter * p) override;
protected:
    QPointF _PoligonoAbsoluto[5]{
        QPointF(0000,-0150),
        QPointF(100,100),
        QPointF(040,060),
        QPointF(-0040,060),
        QPointF(-0100,100), //se va al cuerno, no se por qué
    };
    QPointF _PoligonoRelativo[5];
};

#endif // PJ_H
