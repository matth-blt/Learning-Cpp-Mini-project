#include <iostream>
#include <algorithm>

struct Point {
    int x;
    int y;
};

void affiche(Point p) { std::cout << "{" << p.x << ", " << p.y << "} "; }
void modif_point1(Point p) { p.x = 2; }
void modif_point2(Point *p) { p->x = 3; }
void modif_point3(Point& p) { p.x = 4; }
void transforme_en_maj(char& c) { c -= 32; }
void tranforme_en_maj_phrase(std::string& p) {
    for (auto& l : p) {
        l = std::toupper(static_cast<unsigned char>(l));
    }
    std::cout << p << std::endl;
}

int main(void) {
    // PARTIE 1
    Point p1{70, 80};
   
    modif_point1(p1);
    affiche(p1); std::cout << std::endl;
    modif_point2(&p1);
    affiche(p1); std::cout << std::endl;
    modif_point3(p1);
    affiche(p1); std::cout << std::endl;

    std::cout << std::endl;

    // PARTIE 2
    Point tab_p[5]{ {1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10} };
    for (auto& element : tab_p) {
        affiche(element);
        modif_point3(element);
        std::cout << "--> ";
        affiche(element);
        std::cout << std::endl;
    }

    std::cout << std::endl;

    // PARTIE 3
    char lettre{'r'};
    transforme_en_maj(lettre); std::cout << lettre << std::endl;
    lettre = 'b';
    transforme_en_maj(lettre); std::cout << lettre << std::endl;
    lettre = 'y';
    transforme_en_maj(lettre); std::cout << lettre << std::endl;

    // PARTIE 4
    std::string phrase;
    std::cout << "Votre Phrase : ";
    std::getline(std::cin, phrase);
    tranforme_en_maj_phrase(phrase);

    return 0;
}