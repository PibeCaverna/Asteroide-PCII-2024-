#ifndef NAVE_H
#define NAVE_H
#include "drawable.h"
#include "gameobject.h"
#include <QList>
#include <QPointF>
//¿Funciona?
//Funciona!
class Nave: public GameObject
{
public:
    Nave(QList<QPointF> Forma,QPointF centroMasa);
    virtual void CgeSpeed(QPointF Spd);
    void Dibujar(QPainter * p);//) override;

    //virtual void PegarTiro();
    //void update_p() override;
protected:
    QPointF Velocidad;

};


#endif // NAVE_H
