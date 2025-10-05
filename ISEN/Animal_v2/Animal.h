#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

const int kTaille = 4;

class Animal {
public:
    Animal() : x{0}, y{0}, energie{0} {}
    Animal(int x_init, int y_init, int e_init) : x{x_init}, y{y_init}, energie{e_init} {}
    virtual ~Animal() = default;

    int getX() const;
    int getY() const;
    int getEnergie() const;
    static int getNbAnimaux() { return nb_animaux; }
    void setX(int x_init);
    void setY(int y_init);
    void setEnergie(int e_init);
    static void setNbAnimaux(int nb) { nb_animaux = nb; }
    virtual void affiche() const;
private:
    int x;
    int y;
    int energie;
    static inline int nb_animaux{0};
};

#endif