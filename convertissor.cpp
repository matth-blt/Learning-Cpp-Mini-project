#include "utils.hpp"

float unite::convert_km_mi(int nbr) { return nbr * 1.609; }

std::pair<std::string, std::string> recup_msr(int i, char *argv[]) {
    try {
        return { argv[i+2], argv[i+3] };
    } catch (const std::exception& e) {
        std::cerr << "Erreur dans la recup des mesures" << std::endl;
        return {"error", "error"};
    }
}

int main(int argc, char *argv[]) {
    int nbr = 0; 
    std::string msr1, msr2;
    unite a;
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "convert") {
            try {
                nbr = std::stoi(argv[i+1]);
            } catch (const std::exception& e) {
                std::cerr << "Erreur dans la recup de la valeur" << std::endl;
                return 1;
            }
            auto [msr1, msr2] = recup_msr(i, argv);
            if (msr1 == "km" && msr2 == "mi") {
                std::cout << a.convert_km_mi(nbr) << std::endl;
            }
        }
    }
    return 0;
}