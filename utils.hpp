#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <utility>

// ------------------------ Calculator --------------------------
int addition(int a, int b);
int soustraction(int a, int b);
int multiplication(int a, int b);
int division(int a, int b);
bool division_checker(int b);
double puissance(int a, int b);
int modulo(int a, int b);
std::pair<int, int> lire_nombres(int i, char *argv[]);
void print_help();
// ------------------------ Convertissor -------------------------
class unite {
    public:
    float convert_km_mi(int nbr);
};

#endif