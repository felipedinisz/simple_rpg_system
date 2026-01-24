#include <iostream>
#include "../include/menu.hpp"



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
            enterToContinue();
            continue;
        }

        switch (option) {
            case 1: {
                handleCreateCharacter(party);
                break;
            }
            case 2: {
                handleShowCharacterStats(party);
                break;
            }
            case 3: {
                handleShowPartyMembers(party);
                break;
            }
            case 4: {
                handleRemoveMemberFromTheParty(party);
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
                enterToContinue();
                break;
        }
    } while(true);

    return 0;
}