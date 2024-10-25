#ifndef POLYCOLIDER_H
#define POLYCOLIDER_H
#include "ptcolider.h"
#include <QPointF>
class PtColider;//forward declaration, salió de chatgpt, no se si hay forma más elegante

class PolyColider
{
public:
    PolyColider(){};
    virtual int get_tope() = 0;
    virtual QPointF get_vertex(int index) = 0;
    bool Golpe_Punto(PtColider *Punto);
};

#endif // POLYCOLIDER_H
