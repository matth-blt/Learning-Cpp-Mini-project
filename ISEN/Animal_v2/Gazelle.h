#ifndef GAZELLE_H
#define GAZELLE_H

#include "Animal.h"
#include <iostream>
#include <string>

class Gazelle : public Animal {
public:
    using Animal::Animal;

    Gazelle() : Animal(), type{"Gazelle"} {}
    Gazelle(int x_init, int y_init, int e_init) : Animal(x_init, y_init, e_init), type{"Gazelle"} {}
    ~Gazelle() = default;

    std::string getType() const;
    void affiche() const override;
private:
    std::string type;
};

#endif