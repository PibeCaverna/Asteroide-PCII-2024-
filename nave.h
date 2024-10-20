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
<<<<<<< HEAD
    void Dibujar(QPainter * p) override;//QPainter * p) override;
=======
>>>>>>> 007337634b54b799d56c8db442e2f32c7e533441
    //void update_p() override;
protected:
    QPointF Velocidad;
    double angulo;

};


#endif // NAVE_H
