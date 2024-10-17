#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include "drawable.h"
#include "asteroide.h"
class GameLogic:Drawable
{
public:
    GameLogic(int Ancho, int Alto);
    void Dibujar(QPainter * p) override;
private:
    int _ancho;
    int _alto;
};

#endif // GAMELOGIC_H
