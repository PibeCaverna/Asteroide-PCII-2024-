#include "gameobject.h"

GameObject::GameObject(QList<QPointF> P_R,QPointF cM) {

    this->centroMasa = cM;
    this->P_Rel = P_R;
}
