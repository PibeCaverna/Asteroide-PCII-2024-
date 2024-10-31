#ifndef UI_H
#define UI_H
#include "drawable.h"

class UI
{
public:
    UI();
    UI operator+=(int);
    void Dibujar(QPainter *p) override;
    void Update() override;
    int auch();
    int oneup();
protected:
    int _Puntos;
    int _vidas;
    QPointF _txtanchor = QPointF(3200,200);
    QPointF _Formavida[5] = (
        QPointF( 25, 10),
        QPointF( 35, 35),
        QPointF( 29, 31),
        QPointF( 21, 31),
        QPointF( 11, 35),);

};

#endif // UI_H
