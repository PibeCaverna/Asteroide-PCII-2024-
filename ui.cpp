#include "ui.h"


UI::UI() {
    this -> _Puntos = 0;
    this -> _vidas = 3;
}

void UI::Dibujar(QPainter *p){
    QString Texto = ("Score: ");
    QPointF dibuvida[5];
    for(int i = 0; i < 5 ;i++){
        dibuvida[i] = _Formavida[i];
    }

    Texto += QString::number(_Puntos);
    QFont fuente = p->font();
    fuente.setPointSize(50);
    p -> setFont(fuente);
    p ->drawText(_txtanchor,Texto);
    if(_vidas < 1){
        fuente.setPointSize(200);
        p->setFont(fuente);
        p -> drawText(QPointF(900,1200),"Game Over");
    }
    for (int i = 0; i < _vidas; i++){
        for (int j = 0; j < 5;j++){
            dibuvida[j] += QPointF(150,0);
        }
        p ->drawPolygon(dibuvida,5);
    }
}

void UI::auch(){
    if (_vidas > 0){this -> _vidas -= 1;}
    else{this -> _vidas = 0;}
}

void UI::Update(double dt){
    if (_Puntos > _n*10000){
        _vidas += 1;
        _n += 1;
    }
}
