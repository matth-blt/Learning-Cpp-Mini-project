#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <utility>
#include <map>

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
enum Unite { km, hm, dam, m, dm, cm, mm };
std::map<Unite, double> facteur = {
    { km, 1000.0 },
    { hm, 100.0 },
    { dam, 10.0 },
    { m, 1.0 },
    { dm, 0.1 },
    { cm, 0.01 },
    { mm, 0.001 }
};
Unite string_to_unite(const std::string& s);
std::pair<Unite, Unite> recup_msr(int i, char *argv[]);
double conversion(int nbr, Unite u1, Unite u2);

#endif