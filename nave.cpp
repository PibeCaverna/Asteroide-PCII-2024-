#include "nave.h"

Nave::Nave(QList<QPointF>, QPointF centroMasa) {
    Drawable(Forma,centroMasa);
    this->Velocidad = 0;
    this->update_p();
}

Nave::Dibujar(QPainter *p){
    //qsy
}

Nave::CgeSpeed(QPointF Spd){
    this->Velocidad+= Spd;
}

Nave::update_p(){
    this->centroMasa+=this->Velocidad;
    for (int i = 0; i < this ->P_Rel.length(); i++){
        this ->P_Abs.replace(i, this ->centroMasa + this ->P_Rel[i]);
    }

}
