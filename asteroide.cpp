#include "asteroide.h"

Asteroide::Asteroide(QList<QPointF>P_R, QPointF c,int punto,int tamanio,QList<QPointF> rel):
    GameObject(P_R, c)
{
    this ->P_Rel = rel;
    this ->_Punto = punto;
    this ->_Tamanio = tamanio;
}
void Asteroide::Dibujar(QPainter *p){

}
