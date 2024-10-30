#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include "drawable.h"
#include "ovni.h"
#include "pj.h"
#include "bala.h"
#include "asteroide.h"
#include <QList>
#include <QPointF>
#include <QWidget> //para usar QKeyEvents
#include <QKeyEvent>
#include <QDebug>
#include <QRandomGenerator>
class GameLogic:Drawable
{
public:
    GameLogic();
    void Dibujar(QPainter * p) override;
    void Update() override;
    void handleInput(QKeyEvent *event);
    void Disparar();
    void Collision_Handler();
    void Spawn_Roid(qreal Q);
private:
    int _ancho;
    int _alto;
    QList<Drawable*> dibujables;
    QList<Asteroide*> Asteroides;
    QList<Bala*> Balas;
    QList<Ovni*> Ovnis;
    PJ *_nave;
    qreal _Puntos;
    qreal _Roidmount;

};

#endif // GAMELOGIC_H
