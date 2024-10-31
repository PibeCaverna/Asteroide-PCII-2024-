#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QKeyEvent>
#include <QKeySequence>
#include <QKeyCombination>
#include <QList>
#include <QDebug>

#include "gamelogic.h"

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *evento) override;
    void handleEvent();
    void addEvent(QKeyEvent *event);
    void removeEvent(QKeyEvent *event);

protected:
    GameLogic * juego;
    float refresh_period = 20;
    QTimer timer;
    QList<QKeyEvent*> eventos;

};

#endif // GAMEWIDGET_H
