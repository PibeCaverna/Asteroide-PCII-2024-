#include "gamewidget.h"
#include "gamelogic.h"
#include <QPainter>

GameWidget::GameWidget(QWidget *parent)
    : QWidget{parent}
{
    juego = new GameLogic();

    timer.setInterval(refresh_period); //setea la tabla de refresco a 20ms
    connect(&timer, &QTimer::timeout, this, QOverload<>::of(&GameWidget::update)); //hace que paintEvent sea llamado constantemente
    timer.start();
    setFocusPolicy(Qt::TabFocus); //permite que reciba inputs de teclado

    this->elapsedTimer.start();
}

void GameWidget::paintEvent(QPaintEvent *evento)
{
    QPainter p(this);
    p.setWindow(0,0,3200,2400);
    //se ajusta el tamaño de la ventana del juego
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
    //se manejan los imputs en caso de que los haya y la nave no este en estado "muerta"
    if (!eventos.empty() && juego->get_nave() -> lives()){
        for(int i=0;i<eventos.size();i++){
            switch (eventos[i]->key())  {
                case Qt::Key_Right:
                    juego->get_nave()->update_theta(5,dt);
                    break;
                case Qt::Key_Left:
                    juego->get_nave()->update_theta(-5,dt);
                    break;
                case Qt::Key_Up:
                    juego->get_nave()->Xlr8(0.8,dt);
                    break;
                case Qt::Key_Space:
                    juego -> Disparar();
                    break;
            }
        }
    }
}

void GameWidget::addEvent(QKeyEvent *event){
    //Para evitar que QT modifique el evento crea uno prorio
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

    //si el evento es el resultado de soltar una tecla se elimina
    //la tecla de la lista de eventos siendo ejecutados
    if(!event->isAutoRepeat()) {
        for(int i=0;i<eventos.size();i++){
            if(event->key() == eventos[i]->key()){
                delete eventos[i];
                eventos.removeAt(i);
            }
        }
    }
}
