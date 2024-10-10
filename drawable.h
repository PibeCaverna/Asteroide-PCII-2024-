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
    Drawable(P_R, c);
    virtual void Draw();
    virtual void update_p(P);//p es el nuvo centro


};

#endif // DRAWABLE_H
