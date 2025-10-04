#include "Point.h"

int Point::getX() const { return x; }
void Point::setX(int x) { x = this->x; }
int Point::getY() const { return y; }
void Point::setY(int y) { y = this->y; }
void Point::affiche() const { std::cout << "{" << x << ", "<< y << "}" << std::endl; }
double Point::calcDistance(Point& p2) const { 
    return sqrt(pow((p2.getX() - x), 2) + pow((p2.getY() - y), 2));
}