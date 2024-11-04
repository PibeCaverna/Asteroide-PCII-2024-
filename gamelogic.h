#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include "drawable.h"
#include "ovni.h"
#include "pj.h"
#include "bala.h"
#include "asteroide.h"
#include "ui.h"
#include <QList>
#include <QPointF>
#include <QWidget>
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QDateTime>
#include <QElapsedTimer>
class GameLogic:Drawable
{
public:
    GameLogic();
    void Dibujar(QPainter * p) override;
    void Update(double dt) override;
    void Disparar();
    void Collision_Handler();
    void Spawn_Roid(qreal Q);
    void Spawn_Ovni();
    PJ * get_nave(){return this -> _nave;}
private:
    int _ancho;
    int _alto;
    QList<Drawable*> dibujables;
    QList<Asteroide*> Asteroides;
    QList<Bala*> Balas;
    QList<Ovni*> Ovnis;
    PJ *_nave = nullptr;
    qreal _Puntos;
    qreal _Roidmount;
    UI *_Interfaz = new UI();
    int PlayerTimeout = 0;
    int RoundTimeout = 0;
    QElapsedTimer timer;
};

#endif // GAMELOGIC_H
