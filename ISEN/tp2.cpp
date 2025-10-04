#include <iostream>

void affiche(int v) { std::cout << v << std::endl; }
void affiche(int tab_v[]) {
    for (int i = 0; i < 10; i++) {
        std::cout << "{" << tab_v[i] << "} ";
    }
    std::cout << std::endl;
}
int mult(int a, int b = 1) { return a * b; }

int main(void) {
    int *tab = new int[10];

    for (int i = 0; i < 10; i++) {
        tab[i] = i;
    }

    affiche(12);
    affiche(tab);

    std::cout << mult(5, 5) << std::endl;
    std::cout << mult(2) << std::endl;

    delete[] tab;
    return 0;
}