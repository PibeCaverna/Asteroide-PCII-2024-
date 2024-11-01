#ifndef OVNI_H
#define OVNI_H
#include "drawable.h"
#include "polycolider.h"

class Ovni: public Drawable, public PolyColider
{
public:
    Ovni(QPointF CdMasa, qreal Puntos);
    void Dibujar(QPainter * p) override;
    void Update() override;
    QPolygonF get_poly(){
        return QPolygonF(_PoligonoRelativo);
    }

protected :
    QList<QPointF> _PoligonoAbsoluto = {
        QPointF(-10000,-20000),
        QPointF(-16000, -8000),
        QPointF(-30000,  0000),
        QPointF(-20000, 12000),
        QPointF( 20000, 12000),
        QPointF( 30000,  0000),
        QPointF( 16000, -8000),
        QPointF( 10000,-20000),

    };
    QList <QPointF> _PoligonoRelativo;
    QPointF _CentroDeMasa;
};

#endif // OVNI_H
