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

Compte login(std::vector<Compte>& clients) {
    std::string n;
    std::cout << "---------| LOGIN |---------" << std::endl;
    std::cout << "Nom du Titulaire : ";
    std::getline(std::cin >> std::ws, n);

    bool found = false;

    for (auto& c : clients) {
        if (c.get_titulaire() == n) {
            std::cout << "Compte Trouvé !" << std::endl;
            return c;
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

void faire_transaction(std::vector<Compte>& clients) {
    int choice;

    std::string n;
    std::cout << "---------| LOGIN |---------" << std::endl;
    std::cout << "Nom du Titulaire : ";
    std::getline(std::cin >> std::ws, n);


}

void print_help_banque() {
    std::cout << "Choix 1 : Ajoute un Nouveau Client à la Banque" << std::endl;
    std::cout << "- Vous rentrez le Nom, le Solde (argent sur le compte) et la dette (s'il y a un credit déjà contracté)\n" << std::endl;
    std::cout << "Choix 2 : Effectue un Depot d'argent" << std::endl;
    std::cout << "- Vous vous connecter a votre compte (s'il exsite sinon vous le creer) et vous renseigner la somme a ajouter a votre livret\n" << std::endl;
    std::cout << "Choix 3 : Effectue une Transaction entre vous et un autre client de la banque" << std::endl;
    std::cout << "- Vous vous connecter a votre compte (s'il exsite sinon vous le creer) et vous renseignez le nom du client avec qui vous realiser votre transaction" << std::endl;
}

int main(void) {
    int choice;
    std::vector<Compte> clients;

    do {
        std::cout << "---------| BANQUE |---------" << std::endl;
        std::cout << "|1|    Ajouter Client      |" << std::endl;
        std::cout << "|2|        Depot           |" << std::endl;
        std::cout << "|3|     Transaction        |" << std::endl;
        std::cout << "|4|       Emprunt          |" << std::endl;
        std::cout << "|5|   Afficher Clients     |" << std::endl;
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
            case 3: {

            }
            break;
            case 5: {
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
            case -1: print_help_banque(); break;
        }
    } while (choice != 0);

    return 0;
}