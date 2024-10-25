#ifndef PTCOLIDER_H
#define PTCOLIDER_H
#include "polycolider.h"
#include <QPointF>
class PolyColider;
class PtColider
{
public:
    PtColider(){};
    virtual QPointF get_pt() = 0;
    bool Golpe_Poly(PolyColider *Poligono);
};

#endif // PTCOLIDER_H
