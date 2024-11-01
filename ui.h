#ifndef UI_H
#define UI_H
#include "drawable.h"

class UI: public Drawable
{
public:
    UI();
    void MasPuntos(int Puntos){this -> _Puntos += Puntos;}
    void Dibujar(QPainter *p) override;
    void Update() override;
    void auch();
    void oneup(){this -> _vidas += 1;}
    int Health(){return _vidas;}
protected:
    int _Puntos;
    int _vidas;
    int _n = 1;
    QPointF _txtanchor = QPointF(120,130);
    QPointF _Formavida[5] = {
        QPointF( 20,175),
        QPointF(-30,300),
        QPointF(  0,280),
        QPointF( 40,280),
        QPointF( 70,300)};

};

#endif // UI_H
