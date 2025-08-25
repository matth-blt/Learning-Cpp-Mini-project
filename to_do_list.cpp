#include "utils.hpp"

void add_task(const std::string& task, int importance, const char* fichier = "List.txt") {
    std::ifstream in(fichier);
    std::vector<std::string> tasks;
    std::string line;

    while (std::getline(in, line)) {
        size_t pos = line.find("- ");
        if (pos != std::string::npos)
            tasks.push_back(line.substr(pos + 2));
        else
            tasks.push_back(line);
    }
    in.close();

    size_t pos = tasks.size(); 
    if (importance == 1) {    
        pos = 0;
    } else if (importance == 2) {
        pos = tasks.size() / 2;
    } else if (importance == 3) {
        pos = tasks.size();
    }

    tasks.insert(tasks.begin() + pos, task);

    std::ofstream out(fichier, std::ios::trunc);
    for (size_t i = 0; i < tasks.size(); ++i) {
        out << (i+1) << "- " << tasks[i] << "\n";
    }
    out.close();
}
void choice_1() {
    std::string txt;
    int importance{-2};
    
    std::cout << "---------| VOTRE TACHE |--------" << std::endl;
    std::cout << "--> ";
    std::getline(std::cin >> std::ws, txt);
    
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

    add_task(txt, importance);
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