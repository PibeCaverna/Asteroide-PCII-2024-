#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QKeySequence>
#include <QKeyCombination>

#include "gamelogic.h"

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *evento) override;
    void handleEvent(QKeyEvent *event);

protected:
    GameLogic * juego;
    float refresh_period = 20;
    QTimer timer;

};

#endif // GAMEWIDGET_H
