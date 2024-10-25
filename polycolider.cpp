#include "polycolider.h"
#include "ptcolider.h"

//PolyColider::PolyColider() {}
bool PolyColider::Golpe_Punto(PtColider *Punto){
    //Algoritmo robado de https://www.jeffreythompson.org/collision-detection/poly-point.php
    bool Pepazo = false;
    QPointF este = QPointF(0,0);
    QPointF otro = QPointF(0,0);
    QPointF pepa = Punto -> get_pt();
    //Comparamos cada par de vertices adyacentes con el punto
    for (int i = 0; i < this->get_tope(); i++){
        este = this->get_vertex(i);
        if (i < this->get_tope()-1){
            otro = this->get_vertex(i);}
        else{
            otro = this->get_vertex(0);}
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
