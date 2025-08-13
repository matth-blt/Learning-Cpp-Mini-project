#include "utils.hpp"

Unite string_to_unite(const std::string& s) {
    if (s == "km") return km;
    if (s == "hm") return hm;
    if (s == "dam") return dam;
    if (s == "m") return m;
    if (s == "dm") return dm;
    if (s == "cm") return cm;
    if (s == "mm") return mm;
    throw std::invalid_argument("Unité inconnue: " + s);
}

std::pair<Unite, Unite> recup_msr(int i, char *argv[]) {
    try {
        Unite u1 = string_to_unite(argv[i+2]);
        Unite u2 = string_to_unite(argv[i+3]);
        return { u1, u2 };
    } catch (const std::exception& e) {
        std::cerr << "Erreur dans la recup des mesures" << std::endl;
        return {m, m};
    }
}

double conversion(int nbr, Unite u1, Unite u2) {
    double val_m = nbr * facteur[u1];
    return val_m / facteur[u2];
}

void print_help_convertissor() {
    std::cout << ".\\convertissor.exe"
                 " convert"
                 " {nbr}"
                 " {u1}"
                 " {u2}" << std::endl;
}

int main(int argc, char *argv[]) {
    int nbr{}; 
    Unite u1, u2;
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "convert") {
            try {
                nbr = std::stoi(argv[i+1]);
            } catch (const std::exception& e) {
                std::cerr << "Erreur dans la recup de la valeur" << std::endl;
                return 1;
            }
            auto [u1, u2] = recup_msr(i, argv);
            std::cout << conversion(nbr, u1, u2) << argv[i+3] << std::endl;
        } else if (arg == "--help") {
            print_help_convertissor();
        }
    }
    return 0;
}