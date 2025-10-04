#include "Point.h"
#include "Geometry.h"

int main(void) {
    const int kTaille{10};

    Point pt1{10, 10}; // instanciation
    Point pt2{20, 20}; // instanciation

    std::cout << "La distance entre pt1 et pt2 est de : " 
              << pt1.calcDistance(pt2) << std::endl;
    
    Point tab[]{ {10, 10}, {20, 20}, {10, 10} }; 
    Geometry rectangle{tab, 3};

    rectangle.addPt(pt2);
    rectangle.affiche(); std::cout << std::endl;

    std::cout << "Le périmètre est egal à : " 
              << rectangle.calcPerimetre() << std::endl;

    std::cout << std::endl;
    // Point *p_p; // pas d'instanciation
    Point *p_p{ new Point{15, 12} }; // instanciation = creation d'un objet
    p_p->affiche();

    Point *tab_p[kTaille];
    for (auto& i : tab_p) {
        i = new Point;
    }
    for (const auto& i : tab_p) {
        i->affiche();
    }

    delete p_p;
    for (auto& i : tab_p) {
        delete i;
    }

    return 0;
}