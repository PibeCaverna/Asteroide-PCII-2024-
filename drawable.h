#ifndef DRAWABLE_H
#define DRAWABLE_H
#include <QPainter>
#include <QPointF>
#include <QList>

class Drawable
{

protected:

QList<QPointF> P_Rel;
QPointF centroMasa;
QList<QPointF> P_Abs;

public:
    Drawable(QList<QPointF>P_R, QPointF c);
    virtual void Dibujar(QPainter * p) = 0; //copiado del ejemplo de la pelotita, nidea de que significa
    virtual void update_p(QPointF P);//p es el nuvo centro


};

#endif // DRAWABLE_H
