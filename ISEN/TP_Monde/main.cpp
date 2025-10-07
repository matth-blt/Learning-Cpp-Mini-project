#include "Animal.h"
#include "Monde.h"

int main() {
    srand(time(NULL));
    Monde m1{5};

    m1.peuplement();
    m1.affiche();

    return 0;
}