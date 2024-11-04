#ifndef DRAWABLE_H
#define DRAWABLE_H
#include <QPainter>
#include <QPointF>
#include <QList>

class Drawable
{

public:

    Drawable();
    virtual void Dibujar(QPainter * p) = 0;
    virtual void Update(double dt) = 0;

};

#endif // DRAWABLE_H
