#ifndef NAVE_H
#define NAVE_H
#include "drawable.h"
#include "gameobject.h"
//¿Funciona?
//Funciona!
class Nave: public GameObject
{
public:
    Nave(QList<QPointF> Forma,QPointF centroMasa);
    virtual void CgeSpeed(QPointF Spd);
    //virtual void PegarTiro();
    void Dibujar(QPainter * p) override;//QPainter * p) override;
    //void update_p() override;
protected:
    QPointF Velocidad;
};


#endif // NAVE_H
