#include "nave.h"

Nave::Nave(QList<QPointF> Forma, QPointF centroMasa):Drawable(Forma,centroMasa){
    this->Velocidad = QPointF(0,0);
    this->update_p();
}

void Nave::Dibujar(QPainter *p){
    //qsy
}

void Nave::CgeSpeed(QPointF Spd){
    this->Velocidad+= Spd;
}

void Nave::update_p(){
    this->centroMasa+=this->Velocidad;
    for (int i = 0; i < this ->P_Rel.length(); i++){
        this ->P_Abs.replace(i, this ->centroMasa + this ->P_Rel[i]);
    }
}
