#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <fstream>
#include <vector>

// ------------------------ Calculator --------------------------
int addition(int a, int b);
int soustraction(int a, int b);
int multiplication(int a, int b);
int division(int a, int b);
bool division_checker(int b);
double puissance(int a, int b);
int modulo(int a, int b);
std::pair<int, int> lire_nombres(int i, char *argv[]);
void print_help_calculator();
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
void print_help_convertissor();
// ------------------------ Guess Number -------------------------
int random_nbr(int limit);
bool check_nbr(int nbr, int bot_nbr);
void print_help_guess_nbr();
// ------------------------ To Do List -------------------------
void add_task(const std::string& task, int importance, const char* fichier = "List.txt");
void choice_1();
// ------------------------ Banque -------------------------
class Compte {
private:
    std::string titulaire;
    int solde;
    int dette;
    bool credit;
public:
    int get_solde() { return solde; };
    void set_solde(int s) { solde = s; };
    int get_dette() { return dette; };
    void set_dette(int d) { dette = d; };
    bool get_credit() { return credit; };
    void set_credit(int c) { credit = c; };
    std::string get_titulaire() const { return titulaire; }
    void set_titulaire(std::string n) { titulaire = n; }

    void afficher() const {
        std::cout << "Titulaire: " << titulaire
                  << " | Solde: " << solde
                  << " | Dette: " << dette
                  << " | Credit: " << (credit ? "oui" : "non")
                  << std::endl;
    }

    Compte() : titulaire("Inconnu"), solde(0), dette(0), credit(false) {}

    Compte(const std::string& n, int s, int d, bool c) : titulaire(n), solde(s), dette(d), credit(c) {};
};

#endif