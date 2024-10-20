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
    void handleInput(QKeyEvent *event);
    void rotar(int C);


    //virtual void PegarTiro();
    //void update_p() override;
protected:
    QPointF Velocidad;
    double angulo;

};


#endif // NAVE_H
