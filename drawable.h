#ifndef DRAWABLE_H
#define DRAWABLE_H
#include <QPainter>
#include <QPointF>
#include <QList>

class Drawable
{


public:

    Drawable();
    virtual void Dibujar() = 0; //copiado del ejemplo de la pelotita, nidea de que significa
    virtual void update_p();//p es el nuvo centro

};

#endif // DRAWABLE_H
