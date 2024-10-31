#include "ui.h"


UI::UI() {
    this -> _Puntos = 0;
    this -> _Vidas = 0;
}

void UI::Dibujar(QPainter *p){
    QString Texto = ("Score: ");
    QPointF dibuvida[5] = _Formavida;

    Texto += QString::number(_Puntos);
    p ->drawText(_txtanchor,Texto);
    for (int i = 0; i < _Vidas; i++){
        for (int j = 0; j < 5;j++){
            dibuvida[j] += QPointF(25,0);
        }
        p ->drawPolygon(Dibuvida,5);
    }
}
