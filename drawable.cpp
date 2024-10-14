#include "drawable.h"

Drawable::Drawable(QList<QPointF>P_R,QPointF c) {
    this ->P_Rel = P_R;
    this ->update_p(c);
}

//Drawable::Draw(){
//    QPainter PoliLinea(P_Abs);
//    PoliLinea.drawPolygon();
//}

void Drawable::update_p(QPointF P){
    this ->centroMasa = P;
    for (int i = 0; i < this ->P_Rel.length(); i++){
        this ->P_Abs.replace(i, this ->centroMasa + this ->P_Rel[i]);
    }

}



