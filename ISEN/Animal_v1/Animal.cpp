#include "Animal.h"

int Animal::getX() const { return x; }
int Animal::getY() const { return y; }
int Animal::getEnergie() const { return energie; }
void Animal::setX(int x_init) { x = x_init; }
void Animal::setY(int y_init) { y = y_init; }
void Animal::setEnergie(int e_init) { energie = e_init; }
void Animal::affiche() const { 
    std::cout << "{" << x 
              << ", " << y 
              << ", " << energie 
              << "}" << std::endl;
}