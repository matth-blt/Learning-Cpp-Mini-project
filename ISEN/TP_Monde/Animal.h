#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

const int kTaille = 4;

class Animal {
public:
    Animal() : x{0}, y{0}, energie{0} {}
    Animal(int x_init, int y_init, int e_init) : x{x_init}, y{y_init}, energie{e_init} { nb_animaux++; }
    Animal(const Animal& a) : x{a.x}, y{a.y}, energie{a.energie} { nb_animaux++; }
    ~Animal() { nb_animaux--; };

    int getX() const { return x; }
    int getY() const { return y; }
    int getEnergie() const { return energie; }
    static int getNbAnimaux() { return nb_animaux; }
    static char getLettre() { return nb_animaux; }
    void setX(int x_init) { x = x_init; }
    void setY(int y_init) { y = y_init; }
    void setEnergie(int e_init) { energie = e_init; }
    static void setNbAnimaux(int nb) { nb_animaux = nb; }
    void affiche() const { 
        std::cout << "{" << x 
                << ", " << y 
                << ", " << energie
                << "}" << std::endl;
    }
private:
    int x;
    int y;
    int energie;
    static inline int nb_animaux{0};
};

#endif