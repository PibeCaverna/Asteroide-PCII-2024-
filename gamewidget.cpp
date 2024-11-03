#include "gamewidget.h"
#include "gamelogic.h"
#include <QPainter>

GameWidget::GameWidget(QWidget *parent)
    : QWidget{parent}
{
    juego = new GameLogic();

    timer.setInterval(refresh_period); //setea la tabla de refresco a 20ms
    //connect(&timer,signals(timeout()),this,SLOT(update()));
    connect(&timer, &QTimer::timeout, this, QOverload<>::of(&GameWidget::update)); //hace que paintEvent sea llamado constantemente
    timer.start();
    setFocusPolicy(Qt::TabFocus); //permite que reciba inputs de teclado

    this->elapsedTimer.start(); // Start the elapsed timer
}

void GameWidget::paintEvent(QPaintEvent *evento)
{
    QPainter p(this);
    p.setWindow(0,0,3200,2400);

    if (this ->width() > this ->height()*4/3){//achatado
        double x0 = this->width()/2-this->height()*(4/3.0)/2;
        p.setViewport(x0,0,this->height()*(4/3.0),this->height());
    }
    else{//alto
        double y0 = this->height()/2-(float)this->width()*(3.0/4)/2;
        p.setViewport(0,y0,this->width(),(float)this->width()*(3.0/4));
    }
    double dt = elapsedTimer.restart()/20.0;
    handleEvent(dt);
    juego->Update(dt); //antes de dibujar hay que actualizar el frame
    juego->Dibujar(&p);
}


void GameWidget::handleEvent(double dt){

    if (!eventos.empty()){
        for(int i=0;i<eventos.size();i++){
            //juego->handleInput(eventos[i]);
            if (juego->get_nave() -> lives()){
                switch (eventos[i]->key())  {
                    case Qt::Key_Right:
                        juego->get_nave()->update_theta(5,dt);
                        break;
                    case Qt::Key_Left:
                        juego->get_nave()->update_theta(-5,dt);
                        break;
                    case Qt::Key_Up:
                        juego->get_nave()->Xlr8(0.8);
                        break;
                    case Qt::Key_Space:
                        juego -> Disparar();
                        break;
                }
            }
        }
    }
}

void GameWidget::addEvent(QKeyEvent *event){
    //es la unica forma en la que funciona
    QKeyEvent *ev = new QKeyEvent(event->type(), event->key(),
                                  event->modifiers(), event->text(),
                                  event->isAutoRepeat(), event->count());


    if (!eventos.empty()){
            bool yaEsta = false;
            for(int i=0; i<eventos.size() ;i++){
                if(ev->key() == eventos[i]->key()){
                    yaEsta = true;
                }
            }
            if(!yaEsta)
                eventos.append(ev);
        }
        else
            eventos.append(ev);

}

void GameWidget::removeEvent(QKeyEvent *event){
//puede tener leak de memoria
//se podria romper ya que elimino un objeto de la
//lista mientras la enstoy recorriendo
    if(!event->isAutoRepeat()) {
        for(int i=0;i<eventos.size();i++){
            if(event->key() == eventos[i]->key()){
                eventos.removeAt(i);
            }
        }
    }
}
