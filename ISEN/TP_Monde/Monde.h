#ifndef MONDE_H
#define MONDE_H

#include <iostream>
#include <vector>
#include "Animal.h"
#include <cstdlib>
#include <ctime>

class Monde {
public:
    Monde() : nb_animaux{0} {}
    Monde(int nb_animaux_init) : nb_animaux{nb_animaux_init} {}
    ~Monde() = default;

    static int getMax_x() { return kMax_x ; }
    static int getMax_y() { return kMax_y ; }
    void peuplement() {
        for (int i = 0; i < nb_animaux; i++) {
            int temp_x = rand() % 11;
            int temp_y = rand() % 11; 
            int temp_e = rand() % 11;

            tab_anim.push_back(Animal(temp_x, temp_y, temp_e));
            tab2D[temp_y][temp_x] = 'A';
        }
    }
    void affiche() const {
        std::cout << "ANIMAUX" << std::endl;
        for (auto i : tab_anim) {
            std::cout << "{" << i.getX()
                      << ", " << i.getY()
                      << ", " << i.getEnergie()
                      << "}" << std::endl; 
        }
        std::cout << "POSITION" << std::endl;
        // for (int j = 0; j < kMax_x; j++) {
        //    for (int i = 0; i < kMax_y; i++) {
        //         std::cout << "{" << i << "} ";
        //    }
        // }
    }
private:
    int nb_animaux;
    static const int kMax_x{10};
    static const int kMax_y{10};
    char tab2D[kMax_y][kMax_x];
    std::vector<Animal> tab_anim;

};

#endif