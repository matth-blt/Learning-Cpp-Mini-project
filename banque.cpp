#include "utils.hpp"

Compte new_client() {
    std::string n;
    std::cout << "Nom : ";
    std::getline(std::cin >> std::ws, n);

    std::string input;
    int s = 0, d = 0;

    std::cout << "Solde (default: 0) : ";
    std::getline(std::cin >> std::ws, input);
    if (!input.empty()) s = std::stoi(input);

    std::cout << "Dette (default: 0) : ";
    std::getline(std::cin >> std::ws, input);
    if (!input.empty()) d = std::stoi(input);

    bool c;
    if (d != 0) { c = true; }
    
    return Compte(n, s, d, c);
}

int main(void) {
    int choice;
    
    do {
        std::cout << "---------| BANQUE |---------" << std::endl;
        std::cout << "|1|    Ajouter Client      |" << std::endl;
        std::cout << "|2|        Depot           |" << std::endl;
        std::cout << "|3|     Transaction        |" << std::endl;
        std::cout << "|0|        Exit            |" << std::endl;
        std::cout << "|-1|       Help            |" << std::endl;
        std::cout << "----------------------------" << std::endl;
        std::cout << "--> ";
        std::cin >> choice;

        std::vector<Compte> clients;
        switch (choice) {
            case 1: {
                Compte c = new_client();
                clients.push_back(c);
            }
        }

        for (const auto& c : clients) {
            c.afficher();
            std::cout << std::endl;
        }
    } while (choice != 0);

    return 0;
}