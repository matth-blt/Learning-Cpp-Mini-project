#ifndef POINT_H
#define POINT_H

#include <iostream>

const int kTaille = 4;

class Animal {
private:
    int x;
    int y;
    int energie;
    static inline int nb_animaux{0};
public:
    int getX() const;
    int getY() const;
    int getEnergie() const;
    static int getNbAnimaux() { return nb_animaux; }
    void setX(int x_init);
    void setY(int y_init);
    void setEnergie(int e_init);
    static void setNbAnimaux(int nb) { nb_animaux = nb; }
    void affiche() const;

    Animal() : x{0}, y{0}, energie{0} {}
    Animal(int x_init, int y_init, int e_init) : x{x_init}, y{y_init}, energie{e_init} {}
    ~Animal() = default;
};

#endif