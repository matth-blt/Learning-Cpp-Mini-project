#include "Geometry.h"

void Geometry::addPt(Point& p) { 
        if (nb_pt < 10)
            tab_pt[nb_pt++] = p;
}
double Geometry::calcPerimetre() {
    double peri{0};
        for (int i = 0; i < nb_pt; i++) {
            if (i + 1 < nb_pt) {
                peri += tab_pt[i].calcDistance(tab_pt[i + 1]);
            } else {
                peri += tab_pt[i].calcDistance(tab_pt[0]);
            } 
        }
        return peri;
}