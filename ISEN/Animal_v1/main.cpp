#include "Animal.h"

int main(void) {
    // PARTIE 1
    std::cout << "---------| PARTIE 1 |---------" << std::endl;
    std::cout << "Nombre d'Animaux : " << Animal::getNbAnimaux() << std::endl;
    
    Animal a1{20, 30, 100};
    Animal *a2 = new Animal{40, 50, 100};
    Animal tab_a[kTaille] = { {30, 40, 100}, {10, 20, 100}, {50, 60, 100}, {70, 80, 100} };
    Animal *tab_b = new Animal[kTaille]{ {30, 40, 100}, {10, 20, 100}, {50, 60, 100}, {70, 80, 100} };

    a1.affiche(); std::cout << std::endl;
    a2->affiche(); std::cout << std::endl;

    for (const auto& i : tab_a) {
        i.affiche();
    }

    std::cout << std::endl;

    for (int i = 0; i < kTaille; i++) {
        tab_b[i].affiche();
    }

    std::cout << std::endl;

    std::cout << a1.getX() << std::endl;
    a1.setX(2);

    a1.affiche();

    std::cout << std::endl;
    // PARTIE 2
    std::cout << "---------| PARTIE 2 |---------\n"
              << "Nombre d'Animaux : " << Animal::getNbAnimaux() << std::endl;

    delete a2;
    delete[] tab_b;

    std::cout << "Nombre d'Animaux : " << Animal::getNbAnimaux() << std::endl;

    return 0;
}