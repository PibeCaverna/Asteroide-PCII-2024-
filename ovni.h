#ifndef OVNI_H
#define OVNI_H
#include "drawable.h"
#include "polycolider.h"
#include <QRandomGenerator>
#include <QDateTime>
class Ovni: public Drawable, public PolyColider
{
public:
    Ovni(QPointF CdMasa, qreal Puntos);
    void Dibujar(QPainter * p) override;
    void Update(double dt) override;
    QPolygonF get_poly(){
        return QPolygonF(_PoligonoRelativo);
    }
    void setspeed();
    bool shooting(){
        return this -> _isshooting;
    }
    int get_puntos(){return _Puntos;}

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
    QPointF _Speed;
    bool _isshooting = false;
    int _tsinceshot = 0;
    int _tsincemove = 0;
    int _Puntos;
};

#endif // OVNI_H
