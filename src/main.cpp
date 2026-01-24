#include <iostream>

#include <memory>
#include <string>
#include <algorithm>
#include <vector>
// #include "../include/item.hpp"
#include "../include/character.hpp"

std::string readName() {
    std::string name;
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
    std::cout << " 3. Show party members\n";
    std::cout << " 4. Remove member from the party\n";
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
    std::string _;
    std::getline(std::cin, _);
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


    while(true) {
        std::string line;
        std::cout << "Choose your character class: \n";
        std::cout << "1 - Warrior \n";
        std::cout << "2 - Mage \n";
        std::cout << "3 - Archer \n";
        std::getline(std::cin, line);

        int option;
        try {
            option = std::stoi(line);
        } catch (...) {
            std::cout << "Invalid input. Please enter a number.\n";
            enterToContinue();
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
                enterToContinue();
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

        if(name == character->getName()) {
            character->display();
            return;
        }
    }

    std::cout << "This party member doesn't exist.\n";
    return;
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

void removeMemberFromTheParty(const std::string& name, std::vector<std::unique_ptr<Character>>& party) {
        auto it = std::find_if(
            party.begin(), party.end(),
            [&](const std::unique_ptr<Character>& c) {
                return name == c->getName();
            }
        );
        if (it != party.end()) {
            std::cout << (*it)->getName() << ", the "
                    << (*it)->getCharacterClass()
                    << " is banned from the party.\n";

            party.erase(it);
        } else {
            std::cout << "Character not found.\n";
        }
}


int main() {
    std::vector<std::unique_ptr<Character>> party;
    
    
     do {

        std::string line;
        printMenu();
        std::getline(std::cin, line);

        if (line.empty()) {
            std::cout << "Please, choose an option.\n";
            enterToContinue();
            continue; 
        }

        int option;

        try {
            option = std::stoi(line);
        } catch (...) {
            std::cout << "Invalid input. Please enter a number.\n";
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
                if(!partyHasMember(party)) break; 
                showPartyMembers(party);
                enterToContinue();
                break;
            }
            case 4: {
                if(!partyHasMember(party)) break;
                showPartyMembers(party);
                std::string name = readName();
                if(!nameValidation(name)) break;
                removeMemberFromTheParty(name, party);
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