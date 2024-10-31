#ifndef POLYCOLIDER_H
#define POLYCOLIDER_H
#include "ptcolider.h"
#include <QPointF>
#include <QPolygonF>
class PtColider;//forward declaration, salió de chatgpt, no se si hay forma más elegante

class PolyColider
{
public:
    PolyColider(){};
    virtual QPolygonF get_poly() = 0;
    bool Golpe_Punto(PtColider *Punto);
    bool Golpe_Poly(PolyColider *Otro);
};

#endif // POLYCOLIDER_H
