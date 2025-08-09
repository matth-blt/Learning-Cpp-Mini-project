#include <iostream>
#include <cmath>

int addition(int a, int b) { return a + b; }
int soustraction(int a, int b) { return abs(a - b); }
int multiplication(int a, int b) { return a * b; }
int division(int a, int b) { return (a != 0 && b != 0) ? a / b : 0; }

int main(int argc, char *argv[]) {
    int nbr1 = 0, nbr2 = 0;
    for (int i = 0; i < argc; i++) {
        if (std::string(argv[i]) == "--add") {
            nbr1 = atoi(argv[i+1]), nbr2 = atoi(argv[i+2]);
            std::cout << addition(nbr1, nbr2) << std::endl;
        } else if (std::string(argv[i]) == "--sous") {
            nbr1 = atoi(argv[i+1]), nbr2 = atoi(argv[i+2]);
            std::cout << soustraction(nbr1, nbr2) << std::endl;
        } else if (std::string(argv[i]) == "--mult") {
            nbr1 = atoi(argv[i+1]), nbr2 = atoi(argv[i+2]);
            std::cout << multiplication(nbr1, nbr2) << std::endl;
        } else if (std::string(argv[i]) == "--div") {
            nbr1 = atoi(argv[i+1]), nbr2 = atoi(argv[i+2]);
            if (division(nbr1, nbr2) == 0)
                std::cout << "Erreur Division par 0" << std::endl;
            else
                std::cout << division(nbr1, nbr2) << std::endl;
        }
    }
    return 0;
}