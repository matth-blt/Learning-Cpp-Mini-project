#include "utils.hpp"
#include <string>
#include <iostream>
#include <iomanip>

// ========================= UI / AFFICHAGE =========================
namespace ui {
    // ANSI (Windows 10+ / Windows Terminal)
    static const char* RST  = "\033[0m";
    static const char* BOLD = "\033[1m";
    static const char* DIM  = "\033[2m";
    static const char* IT   = "\033[3m";

    static const char* F_CYAN  = "\033[36m";
    static const char* F_MAG   = "\033[35m";
    static const char* F_YEL   = "\033[33m";
    static const char* F_RED   = "\033[31m";
    static const char* F_GRN   = "\033[32m";
    static const char* F_GRY   = "\033[90m";

    inline void clear() { std::system("cls"); }

    inline void hr(int w = 60) {
        std::cout << F_GRY << "\n" << std::string(w, '\u2500') << RST << "\n"; // ─
    }

    inline void title(const std::string& t, int w = 60) {
        std::string label = " " + t + " ";
        int pad = std::max(0, w - (int)label.size());
        int left = pad / 2, right = pad - left;
        std::cout << F_CYAN << "\u250C" << std::string(w, '\u2500') << "\u2510\n"; // ┌───┐
        std::cout << "\u2502" << std::string(left, ' ') << BOLD << label << RST
                  << F_CYAN << std::string(right, ' ') << "\u2502\n";             // │ title │
        std::cout << "\u2514" << std::string(w, '\u2500') << "\u2518" << RST << "\n"; // └───┘
    }

    inline void section(const std::string& t) {
        std::cout << F_MAG << BOLD << "\n" << t << RST << "\n";
    }

    inline void field(const std::string& label) {
        std::cout << F_YEL << label << RST << " " << IT << "→" << RST << " ";
    }

    inline void info(const std::string& msg) {
        std::cout << F_GRN << "✔ " << msg << RST << "\n";
    }
    inline void warn(const std::string& msg) {
        std::cout << F_YEL << "! " << msg << RST << "\n";
    }
    inline void error(const std::string& msg) {
        std::cout << F_RED << "✖ " << msg << RST << "\n";
    }

    inline void pause_line(int w = 60) {
        std::cout << F_GRY << std::string(w, '\u2500') << RST << "\n";
    }

    inline void menu_item(int key, const std::string& label) {
        std::cout << F_CYAN << "  [" << key << "] " << RST << label << "\n";
    }
    inline void menu_item(const std::string& key, const std::string& label) {
        std::cout << F_CYAN << "  [" << key << "] " << RST << label << "\n";
    }
}
// ==================================================================

// ========================= BANQUE (logique) ========================
Compte new_client() {
    ui::title("Nouveau client");

    std::string n;
    ui::field("Nom du titulaire");
    std::getline(std::cin >> std::ws, n);

    int s{0}, d{0};
    ui::field("Solde initial (par défaut: 0)");
    std::cin >> s;
    ui::field("Dette initiale (par défaut: 0)");
    std::cin >> d;

    bool c = (d != 0);
    ui::info("Client créé");
    return Compte(n, s, d, c);
}

Compte& search_account(std::vector<Compte>& clients, std::string& titulaire) {
    for (auto& c : clients) {
        if (c.get_titulaire() == titulaire) {
            ui::info("Compte trouvé");
            return c;
        }
    }
    ui::warn("Aucun compte avec ce nom. Création d'un nouveau compte…");
    return creer_compte(clients);
}

// Compte& login(std::vector<Compte>& clients) {
//     ui::title("Login");
//     std::string n;
//     ui::field("Nom du titulaire");
//     std::getline(std::cin >> std::ws, n);
//     return search_account(clients, n);
// }

static Compte* login_auth(std::vector<Compte>& clients) {
    ui::title("Login");
    std::string nom, pw;

    ui::field("Nom du titulaire");
    std::getline(std::cin >> std::ws, nom);

    if (!find_client(clients, nom)) {
        ui::error("Compte inexistant.");
        return nullptr;
    }

    ui::field("Mot de passe");
    std::getline(std::cin, pw);

    if (!verify_password(nom, pw)) {
        ui::error("Mot de passe incorrect.");
        return nullptr;
    }

    ui::info("Authentification réussie");
    return find_client(clients, nom);
}


Compte& creer_compte(std::vector<Compte>& clients) {
    ui::title("Créer votre compte");
    clients.push_back(new_client());
    auto& acc = clients.back();
    g_idx[acc.get_titulaire()] = clients.size() - 1;

    std::string pw1, pw2;
    do {
        ui::field("Mot de passe");
        std::getline(std::cin >> std::ws, pw1);
        ui::field("Confirmer le mot de passe");
        std::getline(std::cin, pw2);
        if (pw1 != pw2) ui::warn("Les mots de passe ne correspondent pas. Réessayez.");
    } while (pw1 != pw2);

    g_pwdhash[acc.get_titulaire()] = weak_hash(acc.get_titulaire() + ":" + pw1);
    ui::info("Compte créé et mot de passe enregistré");
    return acc;
}

void faire_depot(std::vector<Compte>& clients) {
    ui::title("Dépôt");
    if (Compte* c = login_auth(clients)) {
        int s{};
        ui::field("Montant du dépôt");
        std::cin >> s;
        c->set_solde(c->get_solde() + s);
        ui::info("Dépôt effectué");
    } else {
        ui::warn("Opération annulée.");
    }
}

void faire_transaction(std::vector<Compte>& clients) {
    ui::title("Transaction");
    Compte* titu = login_auth(clients);
    if (!titu) { ui::warn("Opération annulée."); return; }

    std::string nom_receveur;
    ui::field("Nom du receveur");
    std::getline(std::cin >> std::ws, nom_receveur);

    Compte* receveur = find_client(clients, nom_receveur);
    if (!receveur) { ui::error("Receveur introuvable."); return; }

    int montant{0};
    ui::field("Montant de la transaction");
    std::cin >> montant;

    int choice{0};
    if (titu->get_solde() < montant) {
        ui::error("Fonds insuffisants.");
        ui::section("Souhaitez-vous…");
        ui::menu_item(1, "Annuler");
        ui::menu_item(2, "Faire un emprunt");
        ui::field("Choix");
        std::cin >> choice;

        switch (choice) {
            case 1:
                ui::warn("Transaction annulée");
                return;
            case 2:
                ui::clear();
                faire_emprunt(clients, true, montant);
                break;
            default:
                ui::warn("Choix invalide – annulation");
                return;
        }
    } else {
        titu->set_solde(titu->get_solde() - montant);
        receveur->set_solde(receveur->get_solde() + montant);
        ui::info("Transaction effectuée");
    }
}

void faire_emprunt(std::vector<Compte>& clients, bool eta, int diff) {
    ui::title("Emprunt");
    Compte* c = login_auth(clients);
    if (!c) { ui::warn("Opération annulée."); return; }

    if (eta == true) {
        int choice{0};
        ui::section("Vous voulez…");
        ui::menu_item(1, "Choisir un montant");
        ui::menu_item(2, "Emprunter la somme exacte manquante");
        ui::field("Choix");
        std::cin >> choice;

        int val{0};
        switch (choice) {
            case 1: {
                ui::field("Votre montant");
                std::cin >> val;
                c->set_solde(c->get_solde() + val);
                if (!c->get_credit()) c->set_credit(true);
                ui::info("Emprunt enregistré");
                break;
            }
            case 2: {
                val = diff - c->get_solde();
                if (val < 0) val = 0;
                std::cout << ui::F_YEL << "Somme empruntée : " << ui::RST << val << "\n";
                c->set_dette(c->get_dette() + val);
                c->set_solde(c->get_solde() + val);
                if (!c->get_credit()) c->set_credit(true);
                ui::info("Emprunt enregistré");
                break;
            }
            default:
                ui::warn("Choix invalide – annulation");
                return;
        }
    } else {
        int val{0};
        ui::field("Somme à emprunter");
        std::cin >> val;
        c->set_dette(c->get_dette() + val);
        c->set_solde(c->get_solde() + val);
        if (!c->get_credit()) c->set_credit(true);
        ui::info("Emprunt enregistré");
    }
}

void print_help_banque() {
    ui::title("Aide — Banque");

    ui::section("[1] Ajouter un client");
    std::cout << "Crée un nouveau compte. Renseignez : nom, solde initial et dette initiale.\n"
                 "Si la dette est non nulle, le statut crédit passe à \"oui\".\n";
    ui::pause_line();

    ui::section("[2] Dépôt");
    std::cout << "Connexion à votre compte puis ajout d'une somme à votre solde.\n";
    ui::pause_line();

    ui::section("[3] Transaction");
    std::cout << "Transfère une somme de votre compte vers celui d'un autre client.\n"
                 "Si vos fonds sont insuffisants, possibilité d'effectuer un emprunt avant de réessayer.\n";
    ui::pause_line();

    ui::section("[4] Emprunt");
    std::cout << "Permet d'emprunter une somme. Deux options :\n"
                 "  • choisir librement le montant,\n"
                 "  • emprunter exactement la somme manquante pour une opération en cours.\n"
                 "La somme empruntée s'ajoute au solde et à la dette; le statut crédit passe à \"oui\".\n";
    ui::pause_line();

    ui::section("[5] Afficher clients");
    std::cout << "Affiche la liste des comptes avec : titulaire, solde, dette et statut crédit.\n";
    ui::pause_line();

    ui::section("[0] Quitter");
    std::cout << "Ferme le programme.\n";
    ui::pause_line();

    ui::section("[-1] Aide");
    std::cout << "Affiche cet écran d'aide.\n";
}

static std::string weak_hash(const std::string& s) {
    return std::to_string(std::hash<std::string>{}(s));
}

static Compte* find_client(std::vector<Compte>& clients, const std::string& nom) {
    auto it = g_idx.find(nom);
    if (it == g_idx.end()) return nullptr;
    return &clients[it->second];
}

static bool verify_password(const std::string& nom, const std::string& pw) {
    auto it = g_pwdhash.find(nom);
    if (it == g_pwdhash.end()) return false;
    return it->second == weak_hash(nom + ":" + pw);
}


int main(void) {
    int choice;
    std::vector<Compte> clients;

    do {
        ui::title("BANQUE");
        ui::menu_item(1, "Ajouter un client");
        ui::menu_item(2, "Dépôt");
        ui::menu_item(3, "Transaction");
        ui::menu_item(4, "Emprunt");
        ui::menu_item(5, "Afficher les clients");
        ui::menu_item("-1", "Aide");
        ui::menu_item(0, "Quitter");
        ui::hr();
        ui::field("Choix");
        std::cin >> choice;
        ui::clear();

        switch (choice) {
            case 1: {
                // clients.push_back(new_client());
                creer_compte(clients);
                ui::clear();
                break;
            }
            case 2: {
                ui::clear();
                faire_depot(clients);
                break;
            }
            case 3: {
                ui::clear();
                faire_transaction(clients);
                break;
            }
            case 4: {
                ui::clear();
                bool eta = false;
                int diff = 0;
                faire_emprunt(clients, eta, diff);
                break;
            }
            case 5: {
                ui::title("Clients");
                int i = 1;
                for (const auto& c : clients) {
                    std::cout << ui::F_CYAN << "#" << i << ": " << ui::RST;
                    c.afficher();
                    ++i;
                }
                ui::pause_line();
                break;
            }
            case -1:
                print_help_banque();
                break;
            case 0:
                break;
            default:
                ui::warn("Choix invalide");
                break;
        }
    } while (choice != 0);

    ui::info("À bientôt.");
    return 0;
}
