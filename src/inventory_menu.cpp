#include "../include/character.hpp"
#include "../include/menu.hpp"
#include <iostream>

void showInventoryWithIndex(const Character& character) {
    for (std::size_t i = 0; i < character.getInventorySize(); ++i) {
        std::cout << i + 1 << ". "
                  << character.getItem(i)->getName()
                  << '\n';
    }
}


void removeAnItemMenuOption(Character* character) {
    if(character->isTheInventoryEmpty()) {
        std::cout << "The inventory is empty.\n";
        enterToContinue();
        return;
    }

    showInventoryWithIndex(*character);
    std::cout << "Choose an item number to remove: ";
    std::string line;
    std::getline(std::cin, line);

    int option;
    try {
        option = std::stoi(line);
    } catch (...) {
        std::cout << "Invalid input.\n";
        enterToContinue();
        return;
    }

    std::size_t index = option - 1;

    if (index >= character->getInventorySize()) {
        std::cout << "Invalid item number.\n";
        enterToContinue();
        return;
    }

    Item* item = character->getItem(index);
    std::cout << item->getName() << " removed from inventory.\n";
    character->removeItemAt(index);

    enterToContinue();
}
