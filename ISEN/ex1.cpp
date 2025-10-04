#include <iostream>

int main(void) {
    std::string tab;

    std::cout << "Votre Mot : ";
    std::getline(std::cin, tab);

    int i{0};
    for (auto e : tab) {
        if (e == 'a' || e == 'e' || e == 'i' || e == 'o' || e == 'u' || e == 'y') {
            i++; 
        }    
    }
    std::cout << "Il y a " << i << " voyelle(s) " << "dans " 
              << "'" << tab << "'" << std::endl;

    return 0;
}