#include <iostream>
#include <vector>

void afficher(std::vector<int> tab) {
    for (auto e : tab) {
        std::cout << "{" << e << "} ";
    }
}

int moyenne(std::vector<int>& tab, int& nbr_note) {
    int result{0};
    
    for (auto e : tab) {
        result+= e;   
    }
    
    return result / nbr_note;
}

int main(void) {
    std::vector<int> tab_n;
    int choice;

    std::cout << "Nombre de Notes : ";
    std::cin >> choice;
    int i = choice;
    
    int note;
    do {
        std::cout << "Vos Notes : ";
        std::cin >> note;
        tab_n.push_back(note);
        i--;
    } while (i != 0);

    afficher(tab_n);

    std::cout << moyenne(tab_n, choice) << std::endl;

    return 0;
}