#include "gameobject.h"

GameObject::GameObject(QList<QPointF> P_R,QPointF cM) {

    this->centroMasa = cM;
    this->P_Rel = P_R;
    for(int i = 0; i< P_Rel.size();i++)
    {
        P_Abs.append(P_Rel[i] + cM);
    }
}

