#include "nave.h"

Nave::Nave(QList<QPointF> Forma, QPointF centroMasa):GameObject(Forma,centroMasa){
    this->Velocidad = QPointF(0,0);
    this->angulo = 90;
    //this->update_p();
}


//void Nave::Dibujar(QPainter * p){
    //qsy
//}


void Nave::CgeSpeed(QPointF Spd){
    this->Velocidad+= Spd;
}

/*void Nave::update_p(){
    this->centroMasa+=this->Velocidad;
    for (int i = 0; i < this ->P_Rel.length(); i++){
        this ->P_Abs.replace(i, this ->centroMasa + this ->P_Rel[i]);
    }
}*/

void Nave::handleInput(QKeyEvent *event){
    //falta implementar la funcion rotar
    if (event->key() == Qt::Key_Left)
    {rotar(1);}
    else if  (event->key() == Qt::Key_Right)
    {rotar(-1);}
    else if  (event->key() == Qt::Key_Up)
    {centroMasa += QPointF(10,0);}
}

void Nave::rotar(int C){//si c = -1 rota a la derecha y si c =1 rota a la izquierda

}
