#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <QPainter>
#include <QPointF>
#include <QList>
#include <QWidget>
#include <QKeyEvent>
#include "drawable.h"


class GameObject: public Drawable
{
protected:
    QList<QPointF> P_Rel;
    QPointF centroMasa;
    QList<QPointF> P_Abs;

public:
    GameObject(QList<QPointF> P_R,QPointF cM);
    void Dibujar(QPainter * p);
   // void update_p(QKeyEvent *event);

};

#endif // GAMEOBJECT_H
