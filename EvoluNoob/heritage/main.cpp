#include "unit.hpp"
#include <iostream>

int main() {
    Unit npc{114, "Forgeron Gibbons"};

    std::cout << npc.getName() << std::endl;
    std::cout << npc.getId() << std::endl;

    return 0;
}