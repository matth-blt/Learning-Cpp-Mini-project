#include <cstdio>

void affiche(int v) { printf("%d\n", v); }
void affiche(int tab_v[]) {
    for (int i = 0; i < 10; i++) {
        printf("{%d} ", tab_v[i]);
    }
}
int mult(int a, int b = 1) { return a * b; }

int main(void) {
    int tab[10]{12, 13, 18, 28, 1, 2, 5, 90, 45, 60};
    affiche(12);
    affiche(tab);

    printf("\n%d\n", mult(5, 5));
    printf("%d", mult(2));

    return 0;
}