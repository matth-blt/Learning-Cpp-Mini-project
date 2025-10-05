#include "Gazelle.h"

std::string Gazelle::getType() const { return type; }
void Gazelle::affiche() const {
    std::cout << "{" << getX() 
              << ", " << getY() 
              << ", " << getEnergie()
              << ", " << type
              << "}" << std::endl;
}