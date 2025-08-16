#include "utils.hpp"

void write_in_file(std::string txt, char fichier[256]) {
    FILE *f = fopen(fichier, "w");
}
void choice_1() {
    std::string txt;
    int importance{-2};
    
    std::cout << "---------| VOTRE TACHE |--------" << std::endl;
    std::cout << "--> ";
    std::getline(std::cin, txt);
    
    system("cls");
    
    std::cout << "---------| IMPORTANCE |---------" << std::endl;
    std::cout << "|1|          Eleve             |" << std::endl;
    std::cout << "|2|          Medium            |" << std::endl;
    std::cout << "|3|          Bas               |" << std::endl;
    std::cout << "|0|          Exit              |" << std::endl;
    std::cout << "|-1|         Help              |" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "--> ";
    std::cin >> importance;
}
void choice_2() {
    
}
void choice_3() {
    
}

int main(int argc, char *argv[]) {
    int choice{-2};

    do {
        std::cout << "------------| CHOIX |------------" << std::endl;
        std::cout << "|1|      Ajouter une Tâche      |" << std::endl;
        std::cout << "|2|  Changer l'ordre des Tâches |" << std::endl;
        std::cout << "|3|    Supprimer une Tâche      |" << std::endl;
        std::cout << "|0|           Exit              |" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "--> ";
        std::cin >> choice;

        switch (choice) {
            case 1: system("cls"); choice_1(); break;
            case 2: system("cls"); choice_2(); break;
            case 3: system("cls"); choice_3(); break;
        }
    } while (choice != 0);


    return 0;
}