#ifndef PTCOLIDER_H
#define PTCOLIDER_H
#include "QPointF"
#include "polycolider.h"
class PtColider
{
public:
    PtColider();
    virtual QPointF get_pt();
    bool Golpe_Poly(PolyColider Poligono);
};

#endif // PTCOLIDER_H
