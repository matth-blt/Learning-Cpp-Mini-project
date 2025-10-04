#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

class Point {
public:
    Point() : x{0}, y{0} {}
    Point(int x, int y) : x{this->x}, y{this->y} {}
    Point(const Point &pt_init): x{pt_init.x}, y{pt_init.y} {}
    ~Point() = default;

    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    void affiche() const;
    double calcDistance(Point& p2) const;
private:
    int x;
    int y;
};

#endif