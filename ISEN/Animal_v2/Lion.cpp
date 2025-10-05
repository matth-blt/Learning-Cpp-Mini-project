#include "Lion.h"

std::string Lion::getType() const { return type; }
void Lion::affiche() const {
    std::cout << "{" << getX() 
              << ", " << getY() 
              << ", " << getEnergie()
              << ", " << type
              << "}" << std::endl;
}