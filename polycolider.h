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
    virtual int get_tope() = 0;
    virtual QPointF get_vertex(int index) = 0;
    bool Golpe_Punto(PtColider *Punto);
    bool Golpe_Poly(PolyColider *Otro);
};

#endif // POLYCOLIDER_H
