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
    //Clavo los returns acá xq son una boludez
    int get_tope() override{
        return 8;
    }
    QPointF get_vertex(int index) override{
        return _PoligonoRelativo[index];
    }

protected :
    QPointF _PoligonoAbsoluto[8]{
        QPointF(-10000,-20000),
        QPointF(-16000, -8000),
        QPointF(-30000,  0000),
        QPointF(-20000, 12000),
        QPointF( 20000, 12000),
        QPointF( 30000,  0000),
        QPointF( 16000, -8000),
        QPointF( 10000,-20000),

    };
    QPointF _PoligonoRelativo[8];
    QPointF _CentroDeMasa;
};

#endif // OVNI_H
