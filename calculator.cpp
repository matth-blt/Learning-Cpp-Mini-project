#include "utils.hpp"

int addition(int a, int b) { return a + b; }
int soustraction(int a, int b) { return a - b; }
int multiplication(int a, int b) { return a * b; }
int division(int a, int b) { return a / b; }
bool division_checker(int b) { return b == 0; }
double puissance(int a, int b) { return pow(a, b); }
int modulo(int a, int b) { return a % b; }

std::pair<int, int> lire_nombres(int i, char* argv[]) {
    try {
        return { std::stoi(argv[i+1]), std::stoi(argv[i+2]) };
    } catch (const std::exception& e) {
        std::cout << "Erreur de lecture des nombres" << std::endl;
        return {0, 0};
    }
}

void print_help_calculator() {
    std::cout << ".\\calculator.exe"
                 " --add {nbr1} {nbr2}"
                 " --sous {nbr1} {nbr2}"
                 " --mult {nbr1} {nbr2}"
                 " --div {nbr1} {nbr2}"
                 " --pow {nbr1} {nbr2}"
                 " --mod {nbr1} {nbr2}" << std::endl;
}

int main(int argc, char *argv[]) {
    int nbr1{}, nbr2{};
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "--add") {
            if (i + 2 < argc) {
                auto [nbr1, nbr2] = lire_nombres(i, argv);
                std::cout << addition(nbr1, nbr2) << std::endl;
            } else {
                std::cerr << "Arguments insuffisants pour " << argv[i] << std::endl;
            }
        } else if (arg == "--sous") {
            if (i + 2 < argc) {
                auto [nbr1, nbr2] = lire_nombres(i, argv);
                std::cout << soustraction(nbr1, nbr2) << std::endl;
            } else {
                std::cerr << "Arguments insuffisants pour " << argv[i] << std::endl;
            }
        } else if (arg == "--mult") {
            if (i + 2 < argc) {
                auto [nbr1, nbr2] = lire_nombres(i, argv);
                std::cout << multiplication(nbr1, nbr2) << std::endl;
            } else {
                std::cerr << "Arguments insuffisants pour " << argv[i] << std::endl;
            }
        } else if (arg == "--div") {
            if (i + 2 < argc) {
                auto [nbr1, nbr2] = lire_nombres(i, argv);
                if (division_checker(nbr2))
                    std::cout << "Erreur Division par 0" << std::endl;
                else
                    std::cout << division(nbr1, nbr2) << std::endl;
            } else {
                std::cerr << "Arguments insuffisants pour " << argv[i] << std::endl;
            }
        } else if (arg == "--pow") {
            if (i + 2 < argc) {
                auto [nbr1, nbr2] = lire_nombres(i, argv);
                std::cout << puissance(nbr1, nbr2) << std::endl;
            } else {
                std::cerr << "Arguments insuffisants pour " << argv[i] << std::endl;
            }
        } else if (arg == "--mod") {
            if (i + 2 < argc) {
                auto [nbr1, nbr2] = lire_nombres(i, argv);
                std::cout << modulo(nbr1, nbr2) << std::endl;
            } else {
                std::cerr << "Arguments insuffisants pour " << argv[i] << std::endl;
            }
        } else if (arg == "--help") {
           print_help_calculator();
        }
    }
    return 0;
}