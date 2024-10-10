#include "drawable.h"

Drawable::Drawable(P_R, c) {
    this ->P_Rel = P_R;
    this ->update_p(c);
}

Drawable::Draw(){
    QPainter PoliLinea(P_Abs);
    PoliLinea.drawPolygon();
}

Drawable::update_p(){


}



