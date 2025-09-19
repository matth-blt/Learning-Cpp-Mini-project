#include "utils.hpp"

Compte new_client() {
    std::string n;
    std::cout << "Nom : ";
    std::getline(std::cin >> std::ws, n);

    int s{0}, d{0};
    std::cout << "Solde (default: 0) : ";
    std::cin >> s;
    std::cout << "Dette (default: 0) : ";
    std::cin >> d;

    bool c{false};
    if (d != 0) { c = true; }
    
    return Compte(n, s, d, c);
}

Compte& search_account(std::vector<Compte>& clients, std::string& titulaire) {
    bool found = false;

    for (auto& c : clients) {
        if (c.get_titulaire() == titulaire) {
            std::cout << "Compte Trouvé !" << std::endl;
            return c;
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Compte Inexistant !" << std::endl;
        return creer_compte(clients);
    }
}

Compte& login(std::vector<Compte>& clients) {
    std::string n;
    std::cout << "---------| LOGIN |---------" << std::endl;
    std::cout << "| Nom du Titulaire : ";
    std::getline(std::cin >> std::ws, n);

    return search_account(clients, n);
}

Compte& creer_compte(std::vector<Compte>& clients) {
    std::cout << "+--------| CREER VOTRE COMPTE |--------+" << std::endl;
    clients.push_back(new_client());
    return clients.back();
}

void faire_depot(std::vector<Compte>& clients) {
    int s;
    Compte c = login(clients);
    std::cout << "Montant du Depot : " << std::endl;
    std::cin >> s;
    c.set_solde(c.get_solde() + s);
}

void faire_transaction(std::vector<Compte>& clients) {
    Compte& titu = login(clients);
    
    std::string nom_receveur;
    std::cout << std::endl;
    std::cout << "+--------| TRANSACTION |--------+" << std::endl;
    std::cout << "| Nom du Receveur : ";
    std::getline(std::cin >> std::ws, nom_receveur);
    Compte& receveur = search_account(clients, nom_receveur);

    int montant{0};
    std::cout << "\nMontant de la Transaction : ";
    std::cin >> montant;
    
    int choice{0};
    bool eta{false};
    if (titu.get_solde() < montant) {
        eta = true;
        std::cout << "Vous n'avez pas les fonds necessaire pour effectuer cette transaction !\n" << std::endl;
        std::cout << "+------| VOUS VOULEZ |------+" << std::endl;
        std::cout << "|1|        Annuler          |" << std::endl;
        std::cout << "|2|   Faire un Emprunt      |" << std::endl;
        std::cout << "+---------------------------+" << std::endl;
        std::cout << "--> ";
        std::cin >> choice;

        switch (choice) {
            case 1: return;
            break;
            case 2: { 
                system("cls"); 
                faire_emprunt(clients, eta, montant); 
            }
            break;
        }
    } else {
        titu.set_solde(titu.get_solde() - montant);
        receveur.set_solde(receveur.get_solde() + montant);
        std::cout << "Transaction Effectue" << std::endl;
    }

}

void faire_emprunt(std::vector<Compte>& clients, bool eta, int diff) {
    Compte& c = login(clients);

    if (eta = true) {
        int choice{0};
        std::cout << "+--------| VOUS VOULEZ |--------+" << std::endl;
        std::cout << "|1|    Choisir un Montant       |" << std::endl;
        std::cout << "|2|   Emprunter la Somme Exact  |" << std::endl;
        std::cout << "+-------------------------------+" << std::endl;
        std::cout << "--> ";
        std::cin >> choice;

        int val{0};
        switch (choice) {
            case 1: {
                std::cout << "Votre Montant : ";
                std::cin >> val;

                c.set_solde(c.get_solde() + val);
                if (c.get_credit() != true) { c.set_credit(true); }
            }
            break;
            case 2: {
                val = diff - c.get_solde();
                std::cout << "Somme Emprunter : " << val << std::endl;
                c.set_dette(c.get_dette() + val);
                c.set_solde(c.get_solde() + val);
                if (c.get_credit() != true) { c.set_credit(true); }
            }
        }
    } else {
        int val{0};
        std::cout << "+--------| EMPRUNT |--------+" << std::endl;
        std::cout << "| Somme Emprunter : ";
        std::cin >> val;
        c.set_dette(c.get_dette() + val);
        c.set_solde(c.get_solde() + val);
        if (c.get_credit() != true) { c.set_credit(true); }
    }
}

void print_help_banque() {
    std::cout << "+---------------------------------------------------------------------| HELP |---------------------------------------------------------------------+" << std::endl;
    std::cout << "|                                                 [Choix 1 : Ajoute un Nouveau Client à la Banque]                                                 |" << std::endl;
    std::cout << "|                           Vous rentrez le Nom, le Solde (argent sur le compte) et la dette (s'il y a un credit déjà contracté)                   |" << std::endl;
    std::cout << "+--------------------------------------------------------------------------------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                                                     [Choix 2 : Effectue un Depot d'argent]                                                       |" << std::endl;
    std::cout << "|              Vous vous connecter a votre compte (s'il exsite sinon vous le creer) et vous renseigner la somme a ajouter a votre livret           |" << std::endl;
    std::cout << "+--------------------------------------------------------------------------------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                                 [Choix 3 : Effectue une Transaction entre vous et un autre client de la banque]                                  |" << std::endl;
    std::cout << "|                                     Vous vous connecter a votre compte (s'il exsite sinon vous le creer)                                         |" << std::endl;
    std::cout << "|                                 et vous renseignez le nom du client avec qui vous realiser votre transaction                                     |" << std::endl;
    std::cout << "+--------------------------------------------------------------------------------------------------------------------------------------------------+" << std::endl;
    std::cout << "|                                                         [Choix 4 : Effectue un Emprunt]                                                          |" << std::endl;
    std::cout << "|  |";
}

int main(void) {
    int choice;
    std::vector<Compte> clients;

    do {
        std::cout << "+--------| BANQUE |--------+" << std::endl;
        std::cout << "|1|    Ajouter Client      |" << std::endl;
        std::cout << "|2|        Depot           |" << std::endl;
        std::cout << "|3|     Transaction        |" << std::endl;
        std::cout << "|4|       Emprunt          |" << std::endl;
        std::cout << "|5|   Afficher Clients     |" << std::endl;
        std::cout << "|0|        Exit            |" << std::endl;
        std::cout << "|-1|       Help            |" << std::endl;
        std::cout << "+--------------------------+" << std::endl;
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
                system("cls");
                faire_transaction(clients);
            }
            break;
            case 5: {
                int i = 1;
                for (const auto& c : clients) {
                    std::cout << "+---------------------| Client n°" << i << " |---------------------+" << std::endl;
                    c.afficher();
                    std::cout << "+--------------------------------------------------------+" << std::endl;
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