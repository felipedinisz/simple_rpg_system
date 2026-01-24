#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <algorithm>
// #include "../include/item.hpp"
#include "../include/character.hpp"

std::string readName() {
    std::string name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter the character's name: ";
    std::getline(std::cin, name);
    return name;
}

void printMenu() {
        std::cout << "\n========================================\n";
    std::cout << "        JUST A BASIC RPG GAME        \n";
    std::cout << "========================================\n";
    std::cout << " 1. Create a new character\n";
    std::cout << " 2. Display character stats\n";
    std::cout << " 3. \n";
    std::cout << " 4. \n";
    std::cout << " 5. \n";
    std::cout << " 6. \n";
    std::cout << " 7. \n";
    std::cout << " 8. \n";
    std::cout << " 9. Exit\n";
    std::cout << "========================================\n";
    std::cout << "Please, choose an option: ";
}

void enterToContinue() {
    std::cout << "Press enter to continue...";
    std::cin.get();
}


bool nameValidation(const std::string& name) {
    
    if(name.length() == 0) {
        std::cout << "You should enter an non-empty name. \n";
        return false;
    }
    bool onlySpaces = std::all_of(
        name.begin(), name.end(),
        [](unsigned char c) { return std::isspace(c); }
    );

    if(onlySpaces) {
        std::cout << "You should enter a proper name. Name cannot contain only spaces. \n";
        return false;
    }   

    return true;
}

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

void showPartyMembers(std::vector<std::unique_ptr<Character>>& party) {
    std::cout << "Party Members:\n";
    for(const std::unique_ptr<Character>&  character : party) {
        std::cout << character->getName() << " (" << character->getCharacterClass() << ")\n";
    }
}

void showCharacterStats(std::string& name, std::vector<std::unique_ptr<Character>>& party) {
    for(const std::unique_ptr<Character>&  character : party) {

        if(name != character->getName()) {
            std::cout << "This party member doesn't exist.\n";
            return;
        }

        if(name == character->getName()) {
            character->display();
            return;
        }
    }
}

bool partyHasMember(const std::vector<std::unique_ptr<Character>>& party) {
    if(party.empty()) {
        std::cout << "The party is empty. \n";
        enterToContinue();
        return false;
    }

    return true;
}

bool characterIsAlreadyInParty(std::string& name, std::vector<std::unique_ptr<Character>>& party) {
    for(const std::unique_ptr<Character>&  character : party) {
        if(name == character->getName()) {
            std::cout << "Character already exists. \n";
            enterToContinue();
            return true;
        }
    }

    return false;
}


int main() {
    std::vector<std::unique_ptr<Character>> party;
    

     do {
        int option;

        printMenu();

        if (!(std::cin >> option)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (option) {
            case 1: {
                std::string name = readName();
                if(!nameValidation(name)) break;
                if(characterIsAlreadyInParty(name, party)) break;
                std::unique_ptr<Character> character = createCharacter(name);
                party.push_back(std::move(character));
                std::cout << "Character created successfully!\n";
                enterToContinue();
                break;
            }
            case 2: {
                if(!partyHasMember(party)) break; 
                showPartyMembers(party);
                std::string name = readName();
                if(!nameValidation(name)) break;
                showCharacterStats(name, party);
                enterToContinue();
                break;
            }
            case 3: {
                enterToContinue();
                break;
            }
            case 4: {
                enterToContinue();
                break;
            }
            case 5: {
                enterToContinue();
                break;
            }
            case 6: {
                enterToContinue();
                break;
            }
            case 7: {
                enterToContinue();
                break;
            }
            case 8: {
                enterToContinue();
                break;
            }
            case 9: 
                std::cout << "Shutdowning down..." << std::endl;
                return 0;
            default:
                std::cout << "Please, choose a valid option." << std::endl;
                break;
        }
    } while(true);

    return 0;
}