#include "ptcolider.h"

PtColider::PtColider() {}
bool PtColider::Golpe_Poly(PolyColider Poligono){
    //Algoritmo robado de https://www.jeffreythompson.org/collision-detection/poly-point.php
    bool Pepazo = false;
    QPointF este = QPointF(0,0);
    QPointF otro = QPointF(0,0);
    QPointF pepa = this -> get_pt();
    //Comparamos cada par de vertices adyacentes con el punto
    for (int i = 0; i < Poligono.get_tope(); i++){
        este = Poligono.get_vertex(i);
        if (i < Poligono.get_tope()-1){
            otro = Poligono.get_vertex(i);}
            else{
                otro = Poligono.get_vertex(0);}
            //si la altura del punto está entre la altura de los vertices y cumple un teorema de
            //curvas medio raro, dame vuelta Pepazo
            if(((este.y() > pepa.y())!=(otro.y() > pepa.y())) &&
                (pepa.x() < ((otro.x()-este.x())*(pepa.y()-este.y())/(otro.y()-este.y())+este.x())))
            {Pepazo = !Pepazo;}
        };
        este.~QPointF();
        otro.~QPointF();
        pepa.~QPointF();
        return Pepazo;
    }
