#ifndef POLYCOLIDER_H
#define POLYCOLIDER_H
#include "QPointF"
#include "ptcolider.h"
class PolyColider
{
public:
    PolyColider();
    virtual int get_tope();
    virtual QPointF get_vertex(int index);
    bool Golpe_Punto(PtColider Punto);
};

#endif // POLYCOLIDER_H
