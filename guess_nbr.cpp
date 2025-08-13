#include "utils.hpp"

int random_nbr(int limit) { return rand() % (limit + 1); }
bool check_nbr(int nbr, int bot_nbr) {
    if (nbr > bot_nbr) {
        std::cout << "Plus petit" << std::endl;
        return false;
    } else if (nbr < bot_nbr) {
        std::cout << "Plus grand" << std::endl;
        return false;
    } else {
        std::cout << "Trouvé ! Bien joué" << std::endl;
        return true;
    }
}
void print_help_guess_nbr() {
    std::cout << ".\\guess_nbr.exe"
                 " --limit"
                 " {nbr}" << std::endl;
}

int main(int argc, char *argv[]) {
    srand(time(0));
    int nbr{}, bot_nbr{};
    
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "--limit") {
            if (argc > i + 1) {
                bot_nbr = random_nbr(std::stoi(argv[i+1]));
            } else {
                std::cerr << "Pas assez d'arguments" << std::endl;
                return 1;
            }
        } else if (arg == "--help") {
            print_help_guess_nbr();
            return 0;
        }
    }

    std::cout << "-----------| Deviner le nombre |-----------" << std::endl;
    do {
        std::cout << "--> ";
        std::cin >> nbr;
    } while (!check_nbr(nbr, bot_nbr));
    
    return 0;
}