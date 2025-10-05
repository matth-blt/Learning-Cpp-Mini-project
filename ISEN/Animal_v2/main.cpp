#include "Animal.h"
#include "Gazelle.h"
#include "Lion.h"

int main(void) {
    const int kTaille{6};

    Animal *tab_a[kTaille];
    for (int i = 0; i < kTaille; i++) {
        if (i % 2 == 0) {
            tab_a[i] = new Gazelle;
        } else {
            tab_a[i] = new Lion;
        }
    }
    for (int i = 0; i < kTaille; i++) {
        tab_a[i]->affiche();
        std::cout << std::endl;
    }

    return 0;
}