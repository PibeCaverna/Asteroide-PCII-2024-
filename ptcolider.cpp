#include "ptcolider.h"
#include "polycolider.h"

bool PtColider::Golpe_Poly(PolyColider *Poligono){
       return Poligono->get_poly().containsPoint(this->get_pt(),Qt::OddEvenFill);
    }
