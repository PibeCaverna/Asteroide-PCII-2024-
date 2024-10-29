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
bool PolyColider::Golpe_Poly(PolyColider *Poligono){
    //Chequeamos cada punto del poligono que llama respecto del otro poligono,
    //puede funcionar porque solo corre 2 o 3 veces por update
    /*bool Pepazo = false;
    for (int j = 0; j < this -> get_tope();j++){
        Pepazo = false;
        QPointF este = QPointF(0,0);
        QPointF otro = QPointF(0,0);
        QPointF pepa = this -> get_vertex(j);
        //Comparamos cada par de vertices adyacentes con el punto
        for (int i = 0; i < Poligono -> get_tope(); i++){
            este = Poligono -> get_vertex(i);
            if (i < Poligono -> get_tope()-1){
                otro = Poligono ->get_vertex(i);}
            else{
                otro = Poligono -> get_vertex(0);}
            //si la altura del punto está entre la altura de los vertices y cumple un teorema de
            //curvas medio raro, dame vuelta Pepazo
            if(((este.y() > pepa.y())!=(otro.y() > pepa.y())) &&
                (pepa.x() < ((otro.x()-este.x())*(pepa.y()-este.y())/(otro.y()-este.y())+este.x())))
            {Pepazo = !Pepazo;}
        };
        este.~QPointF();
        otro.~QPointF();
        pepa.~QPointF();
        if(Pepazo){return Pepazo;}
    }
        return false;*/
    QList<QPointF> Este, Otro;
    for (int i = 0; i < this ->get_tope(); i++){
        Este.append(this->get_vertex(i));
    }
    for (int i = 0; i < Poligono->get_tope(); i++){
        Otro.append(Poligono->get_vertex(i));
    }
    bool seladio = QPolygonF(Este).intersects(QPolygonF(Otro));
    Este.clear();
    Otro.clear();
    return seladio;
}
