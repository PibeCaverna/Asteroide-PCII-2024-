#include "gamelogic.h"

GameLogic::GameLogic() {
    this ->_Puntos = 0;
    this ->_Roidmount = 3;
    this ->RoundTimeout = 100;
    this -> _nave = new PJ(QPointF(1600,1200));
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
                        if ((Asteroides[j]->Golpe_Poly(this->_nave)) && (this -> _nave -> lives()) ){
                            this -> _Interfaz->auch();
                            this -> _nave -> kill();
                        }
                        if (Asteroides[j]->Golpe_Punto(Balas[i])){
                            switch (Asteroides[j]->get_value()){
                            case 20:
                                Asteroides.append(new Asteroide(Asteroides[j]->get_COM(),50,(Balas[i]->get_Speed()-Asteroides[j]->get_speed())/4));
                                Asteroides.append(new Asteroide(Asteroides[j]->get_COM(),50,(Balas[i]->get_Speed()+Asteroides[j]->get_speed())/4));
                                break; //ta bien?
                            case 50:
                                Asteroides.append(new Asteroide(Asteroides[j]->get_COM(),100,(Balas[i]->get_Speed()-Asteroides[j]->get_speed())/3));
                                Asteroides.append(new Asteroide(Asteroides[j]->get_COM(),100,(Balas[i]->get_Speed()+Asteroides[j]->get_speed())/3));
                                break; //ta bien?
                            }
                            this -> _Interfaz->MasPuntos(Asteroides[j]->get_value());
                            Deadstones.prepend(j);
                            if (!DeadBullets.contains(i)){DeadBullets.prepend(i);}
                        }
                    }
                }
        }
    }
    else if(!Asteroides.isEmpty()){
        for (Asteroide *A : Asteroides){
            if ((this ->_nave->Golpe_Poly(A)) && (this -> _nave -> lives())){
                this -> _Interfaz->auch();
                this -> _nave -> kill();
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
    X.seed(QDateTime::currentMSecsSinceEpoch()%100);
    Y.seed(QDateTime::currentMSecsSinceEpoch()%100+1);
    V.seed(QDateTime::currentMSecsSinceEpoch()%100+2);
    for (int i = 0; i < Q; i++){
        r = QPointF(X.bounded(3200),Y.bounded(2400));
        v = QPointF(V.generateDouble()*5*((r.x()-1600)/abs(r.x()-1600)),V.generateDouble()*5*((r.y()-1600)/abs(r.y()-1600)));
        this -> Asteroides.append(new Asteroide(r,20,v));
    }

}

void GameLogic::Update(){

    if (Asteroides.isEmpty()){
        if (RoundTimeout < 200){
            RoundTimeout += 1;
        }
        else{
            this -> _Roidmount += 1;
            this -> Spawn_Roid(_Roidmount);}
    }
    this ->Collision_Handler();
    dibujables.clear();
    if ((!_nave->lives())){
        if (PlayerTimeout < 100){
            PlayerTimeout +=1;
        }
        else if (this ->_Interfaz -> Health()>0){
            this -> PlayerTimeout = 0;
            this ->_nave->ressurect();}
    }
    else{dibujables.append(_nave);}

    for (Asteroide *A :Asteroides){dibujables.append(A);}
    for (Bala *B :Balas){dibujables.append(B);}
    for (Ovni *O :Ovnis){dibujables.append(O);}
    dibujables.append(_Interfaz);

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

void GameLogic::Disparar(){
    if (Balas.empty() || (Balas.last()->get_dt() >150)){
        Bala* b = new Bala(_nave->get_punta(), _nave->get_angulo());
        Balas.append(b);
    }
}
