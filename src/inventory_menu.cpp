#include "../include/character.hpp"
#include "../include/menu.hpp"
#include <iostream>

void printInventoryMenu() {
    std::cout << "\n========================================\n";
    std::cout << "        Inventory Menu        \n";
    std::cout << "========================================\n";
    std::cout << " 1. Use an Item\n";
    std::cout << " 2. Remove an Item\n";
    std::cout << " 3. Show Inventory\n";
    std::cout << " 4. Clear Inventory\n";
    std::cout << " 5. Return to the main menu\n";
    std::cout << "========================================\n";
    std::cout << "Please, choose an option: ";
}

void showInventoryWithIndex(const Character& character) {
    for (std::size_t i = 0; i < character.getInventorySize(); ++i) {

        Item* item = character.getItem(i);
        if (item) {
            std::cout << i + 1 << ". " << item->getName() << '\n';
        }
    }
}


void removeAnItemMenuOption(Character* character) {
    if (!character) {
    std::cout << "Invalid character.\n";
    enterToContinue();
    return;
}

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
    if (option <= 0) {
        std::cout << "Invalid item number.\n";
        enterToContinue();
    return;
    }

    if (index >= character->getInventorySize()) {
        std::cout << "Invalid item number.\n";
        enterToContinue();
        return;
    }

    Item* item = character->getItem(index);
    std::cout << item->getName() << " removed from inventory.\n";
    character->removeItemAt(index);

}
