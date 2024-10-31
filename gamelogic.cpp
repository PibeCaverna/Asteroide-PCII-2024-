#include "gamelogic.h"

GameLogic::GameLogic() {

    this ->_Puntos = 0;
    this ->_nave = new PJ(QPointF(800,600));
    this ->_Roidmount = 4;
    this ->Spawn_Roid(_Roidmount);
    //Drawable* nave = new Nave( puntos, pu);
    //this ->_nave = nave;
    //dibujables.append(_nave);
    //Asteroides.append(new Asteroide(QPointF(400,800),50,QPointF(10,10)));
    //Asteroides.append(new Asteroide(QPointF(400,500),20));
    //Asteroides.append(new Asteroide(QPointF(400,1000),100));
    //dibujables.append(new Ovni(QPointF(1200,400),200));
    //dibujables.append(new Ovni(QPointF(1200,600),1000));
    //dibujables.append(new Bala(QPointF(1300,700),QPointF(1,1)));
}
void GameLogic::Dibujar(QPainter * p){
    p->fillRect(0,0,3200,2400,Qt::black);
    for(Drawable *D : dibujables)
    {
        D->Dibujar(p);
    }
}
void GameLogic::Collision_Handler(){
    QList<qreal> Deadstones, DeadBullets/*, DeadUFOS*/;
    if (!Balas.empty()){
        for (int i = 0; i < Balas.length(); i++){
            if (!Asteroides.empty()){
                    for (int j = 0; j < Asteroides.length(); j++){
                        if (Asteroides[j]->Golpe_Poly(this->_nave)){
                           // qDebug() << "Auch";
                        }
                        if (Asteroides[j]->Golpe_Punto(Balas[i])){
                            switch (Asteroides[j]->get_value()){
                            case 20:
                                Asteroides.append(new Asteroide(Asteroides[j]->get_COM()+Balas[i]->get_Speed(),50,Balas[i]->get_Speed()-Asteroides[j]->get_speed()));
                                Asteroides.append(new Asteroide(Asteroides[j]->get_COM()+Balas[i]->get_Speed(),50,Balas[i]->get_Speed()+Asteroides[j]->get_speed()));
                                break; //ta bien?
                            case 50:
                                Asteroides.append(new Asteroide(Asteroides[j]->get_COM()+Balas[i]->get_Speed(),100,Balas[i]->get_Speed()-Asteroides[j]->get_speed()));
                                Asteroides.append(new Asteroide(Asteroides[j]->get_COM()+Balas[i]->get_Speed(),100,Balas[i]->get_Speed()+Asteroides[j]->get_speed()));
                                break; //ta bien?
                            }
                            Deadstones.prepend(j);
                            if (!DeadBullets.contains(i)){DeadBullets.prepend(i);}
                        }
                    }
                }
        }
    }
    else if(!Asteroides.isEmpty()){
                for (Asteroide *A : Asteroides){
                    if (this ->_nave->Golpe_Poly(A)){
                        //qDebug() << "Auch";
                    }
                }
    }
    for (qreal i: DeadBullets){
        delete Balas[i];
        Balas[i] = nullptr;
        Balas.removeAt(i);
    }
    for(qreal i: Deadstones){
        _Puntos += Asteroides[i]->get_value();
        delete Asteroides[i];
        Asteroides[i] = nullptr;
        Asteroides.removeAt(i);
    }

}

void GameLogic::Spawn_Roid(qreal Q){
    QPointF r, v;
    QRandomGenerator X,Y,V;
    for (int i = 0; i < Q; i++){
        r = QPointF(X.bounded(3200),Y.bounded(2400));
        v = QPointF(V.generateDouble()*10,V.generateDouble()*10);
        this -> Asteroides.append(new Asteroide(r,20,v));
    }
    //qDebug() << Asteroides;

}

void GameLogic::Update(){
    if (Asteroides.isEmpty()){
        this -> _Roidmount += 1;
        this -> Spawn_Roid(_Roidmount);}
    this ->Collision_Handler();
    //_nave->Update();

    dibujables.clear();
    dibujables.append(_nave);
    for (Asteroide *A :Asteroides){dibujables.append(A);}
    for (Bala *B :Balas){dibujables.append(B);}
    for (Ovni *O :Ovnis){dibujables.append(O);}

    //dibujables += QList<Drawable*>(Asteroides);
    //dibujables += QList<Drawable*>(Balas);
    //dibujables += QList<Drawable*>(Ovnis);

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
    //se puede hacer con un switch

    switch (event->key())  {
    case Qt::Key_Right:
        _nave->update_theta(5);
        break;
    case Qt::Key_Left:
        _nave->update_theta(-5);
        break;
    case Qt::Key_Up:
        _nave->Xlr8(4);
        break;
    case Qt::Key_Space:
        if(!Balas.empty()){
            if(Balas.last()->get_dt() >300)
                Disparar();
        }
        else
            Disparar();
        //qDebug() << "asi que di dispara";
        break;
    }
}

void GameLogic::Disparar(){

    Bala* b = new Bala(_nave->get_punta(), _nave->get_angulo());
    Balas.append(b);
    //dibujables.append(b);
}
