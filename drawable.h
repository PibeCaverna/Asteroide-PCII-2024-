#ifndef DRAWABLE_H
#define DRAWABLE_H
#include <QPainter>
#include <QPointF>
#include <QList>

class Drawable
{

public:

    Drawable();
    virtual void Dibujar(QPainter * p) = 0; //copiado del ejemplo de la pelotita, nidea de que significa
    virtual void Update() = 0;//p es el nuvo centro

};

#endif // DRAWABLE_H
