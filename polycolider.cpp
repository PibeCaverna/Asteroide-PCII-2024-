#include "polycolider.h"
#include "ptcolider.h"

bool PolyColider::Golpe_Punto(PtColider *Punto){
    return this->get_poly().containsPoint(Punto->get_pt(),Qt::OddEvenFill);
}
bool PolyColider::Golpe_Poly(PolyColider *Poligono){
    return this->get_poly().intersects(Poligono->get_poly());
}
