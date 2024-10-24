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
class GameLogic:Drawable
{
public:
    GameLogic();
    void Dibujar(QPainter * p) override;
    void Update() override;
    void handleInput(QKeyEvent *event);
private:
    int _ancho;
    int _alto;
    QList<Drawable*> dibujables;
    PJ *_nave;


};

#endif // GAMELOGIC_H
