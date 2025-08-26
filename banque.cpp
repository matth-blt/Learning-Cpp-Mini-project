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

void faire_depot(std::vector<Compte>& clients) {
    int s; 
    std::string n;
    std::cout << "---------| LOGIN |---------" << std::endl;
    std::cout << "Nom du Titulaire : ";
    std::getline(std::cin >> std::ws, n);

    bool found = false;

    for (auto& c : clients) {
        if (c.get_titulaire() == n) {
            std::cout << "Compte Trouvé !" << std::endl;
            std::cout << "Montant du dépôt : ";
            std::cin >> s;
            c.set_solde(c.get_solde() + s);
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Compte Inexistant !" << std::endl;
        std::cout << "---------| CREER VOTRE COMPTE |---------" << std::endl;
        Compte c = new_client();
        clients.push_back(c);
    }
}

int main(void) {
    int choice;
    std::vector<Compte> clients;

    do {
        std::cout << "---------| BANQUE |---------" << std::endl;
        std::cout << "|1|    Ajouter Client      |" << std::endl;
        std::cout << "|2|        Depot           |" << std::endl;
        std::cout << "|3|     Transaction        |" << std::endl;
        std::cout << "|4|   Afficher Clients     |" << std::endl;
        std::cout << "|0|        Exit            |" << std::endl;
        std::cout << "|-1|       Help            |" << std::endl;
        std::cout << "----------------------------" << std::endl;
        std::cout << "--> ";
        std::cin >> choice;
        system("cls");

        switch (choice) {
            case 1: {
                Compte c = new_client();
                clients.push_back(c);
                system("cls");
            }
            break;
            case 2: {
                system("cls");
                faire_depot(clients);
            }
            break;
            case 4: {
                int i = 1;
                for (const auto& c : clients) {
                    std::cout << "----------------------| Client n°" << i << " |----------------------" << std::endl;
                    c.afficher();
                    std::cout << "----------------------------------------------------------" << std::endl;
                    std::cout << std::endl;
                    i++;
                }
            }
            break;
        }
    } while (choice != 0);

    return 0;
}