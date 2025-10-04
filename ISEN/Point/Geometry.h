#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <iostream>
#include <cmath>
#include "Point.h"

class Geometry {
public:
    Geometry() = default;
    Geometry(Point pts[10], int nb_pt) : nb_pt{this->nb_pt} {
        for (int i = 0; i < nb_pt; i++) {
            tab_pt[i] = pts[i];
        }
    }
    ~Geometry() = default;

    void addPt(Point& p);
    double calcPerimetre();
    void affiche() {
        for (auto e : tab_pt) {
            std::cout << "{" << e.getX() << ", " << e.getY() << "}" << std::endl;
        }
    }
private:
    Point tab_pt[10];
    int nb_pt{0};
};

#endif