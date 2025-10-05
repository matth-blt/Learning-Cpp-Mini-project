#ifndef LION_H
#define LION_H

#include "Animal.h"
#include <iostream>
#include <string>

class Lion : public Animal {
public:
    using Animal::Animal;

    Lion() : Animal(), type{"Lion"} {}
    Lion(int x_init, int y_init, int e_init) : Animal(x_init, y_init, e_init), type{"Lion"} {}
    ~Lion() = default;

    std::string getType() const;
    void affiche() const override;
private:
    std::string type;
};

#endif