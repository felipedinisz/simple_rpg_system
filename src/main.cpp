#include <iostream>
#include <limits>
#include <memory>
// #include "../include/item.hpp"
#include "../include/character.hpp"

std::unique_ptr<Character> createCharacter(const std::string& name) {
    std::cout << "Choose your character class: \n";
    std::cout << "1 - Warrior \n";
    std::cout << "2 - Mage \n";
    std::cout << "3 - Archer \n";

    int option;

    while(true) {
        if (!(std::cin >> option)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch(option) {
            case 1:
                return std::make_unique<Character>(name, CharacterClass::Warrior);
            case 2:
                return std::make_unique<Character>(name, CharacterClass::Mage);
            case 3:
                return std::make_unique<Character>(name, CharacterClass::Archer);
            default:
                std::cout << "Invalid Option. Try again.\n";
        }   
    }
}

void showCharacterStats (const std::unique_ptr<Character>& character) {
    std::cout << "================================" << "\n";
    std::cout << character->getName() << "'s stats:" "\n";
    std::cout << "Combat class > " << character->getCharacterClass() << "\n";
    std::cout << "Health > " << character->getCurrentHP() << "/" << character->getMaxHP() << "\n";
    std::cout << "Level > " << character->getLevel() << "\n";
    std::cout << "Experience > " << character->getXP() << "\n";
    std::cout << "Damage > " << character->getDamage() << "\n";
    std::cout << "Defense > " << character->getDefense() << "\n";
    character->showInventory();
    std::cout << "================================" << "\n";
}

int main() {

    std::unique_ptr<Character> c1 = createCharacter("Aragorn");
    showCharacterStats(c1);


    // std::cout << c1->getPosition() << "\n";


    // std::cout << c1->getAbilities() << "\n";
    
    /*
    Item item("heal Potion", "Item", 5, "Heals the user.");

    std::cout << item.getName() << std::endl;
    std::cout << item.getType() << std::endl;
    std::cout << item.getPrice() << std::endl;
    std::cout << item.getDescription() << std::endl;
    item.display();
            if (!(std::cin >> option)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
    */

    return 0;
}