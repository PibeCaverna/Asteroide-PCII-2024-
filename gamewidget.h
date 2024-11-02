#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QKeyEvent>
#include <QList>
#include <QDebug>
#include <QElapsedTimer>

#include "gamelogic.h"

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *evento) override;
    void handleEvent(double dt);
    void addEvent(QKeyEvent *event);
    void removeEvent(QKeyEvent *event);

protected:
    GameLogic * juego;
    float refresh_period = 5;
    QTimer timer;
    QList<QKeyEvent*> eventos;
    QElapsedTimer elapsedTimer;


};

#endif // GAMEWIDGET_H
