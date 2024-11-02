#ifndef PJ_H
#define PJ_H
#include "drawable.h"
#include "polycolider.h"
#include <cmath>
class PJ:public Drawable, public PolyColider
{
public:
    PJ(QPointF CentroDeMasa);
    void Dibujar(QPainter * p) override;
    void Rototrasladar();
    void update_theta(qreal Angulo, double dt);
    void Xlr8(qreal polenta);
    void UpdateCoM(double dt);
    void Update(double dt) override;
    QPointF get_punta(){return _PoligonoRelativo[0];}
    qreal get_angulo(){return _theta;}
    QPolygonF get_poly(){
        return QPolygonF(_PoligonoRelativo);
    }
    void kill(){this -> _isalive = false;}
    bool lives(){return _isalive;}
    void ressurect();

protected:
    QList<QPointF> _PoligonoAbsoluto = {
        QPointF( 000, -150),
        QPointF( 100,  100),
        QPointF( 040,  060),
        QPointF(-040,  060),
        QPointF(-100,  100),
    };
    QList<QPointF> _PoligonoRelativo;
    QPointF _CentroDeMasa;
    QPointF _Speed;
    qreal   _theta;
    bool _isalive = true;
};

#endif // PJ_H
