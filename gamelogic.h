#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include "drawable.h"
#include "nave.h"
#include "bala.h"
#include "asteroide.h"
#include <QList>
#include <QPointF>
class GameLogic:Drawable
{
public:
    GameLogic(int Ancho, int Alto);
    void Dibujar(QPainter * p) override;
    void update();
    void handleInput(QKeyEvent *event);
private:
    int _ancho;
    int _alto;
    QList<Drawable*> dibujables;
    Nave *_nave;

};

#endif // GAMELOGIC_H
