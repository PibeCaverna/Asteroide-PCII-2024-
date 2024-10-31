#include "gamelogic.h"

GameLogic::GameLogic() {


    this ->_nave = new PJ(QPointF(800,600));

    //Drawable* nave = new Nave( puntos, pu);
    //this ->_nave = nave;
    dibujables.append(_nave);
    dibujables.append(new Asteroide(QPointF(400,800),50,QPointF(10,10)));
    dibujables.append(new Asteroide(QPointF(400,500),20));
    dibujables.append(new Asteroide(QPointF(400,1000),100));
    dibujables.append(new Ovni(QPointF(1200,400),200));
    dibujables.append(new Ovni(QPointF(1200,600),1000));
    //dibujables.append(new Bala(QPointF(1300,700),QPointF(1,1)));
}


void GameLogic::Dibujar(QPainter * p){
    p->fillRect(0,0,3200,2400,Qt::black);
    for(Drawable *D : dibujables)
    {
        D->Dibujar(p);
    }
}

void GameLogic::Update(){
    //_nave->Update();

    for(Drawable *D : dibujables)
    {
        D->Update();
    }

    if (!Balas.empty()){
        for(int i=0; i < Balas.length();i++)
        {

            if( Balas[i]->expiro() ){
                dibujables.removeOne(Balas[i]);
                delete Balas[i];
                Balas[i] = nullptr;
                Balas.removeAt(i);

            }
        }
    }
}

void  GameLogic::handleInput(QKeyEvent *event){

    if (event->key() == Qt::Key_Right){
        _nave->update_theta(5);
    }
    if (event->key() == Qt::Key_Left){
        _nave->update_theta(-5);
    }
    else if (event->key() == Qt::Key_Up){
        _nave->Xlr8(4);
    }
    else if (event->key() == Qt::Key_Space){
        Disparar();
    }
}

void GameLogic::Disparar(){

    Bala* b = new Bala(_nave->get_punta(), _nave->get_angulo());
    Balas.append(b);
    dibujables.append(b);
}
