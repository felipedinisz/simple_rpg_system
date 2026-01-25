#ifndef MENU_HPP
#define MENU_HPP
#include <memory>
#include <string>
#include <vector>
// #include "../include/item.hpp"
#include "../include/character.hpp"

// <! -- Menu Design and validation -- >
std::string readName();
void printMenu();
void enterToContinue();
bool nameValidation(const std::string& name);
bool partyHasMember(const std::vector<std::unique_ptr<Character>>& party);
bool characterIsAlreadyInParty(const std::string& name, const std::vector<std::unique_ptr<Character>>& party);

// <! -- Menu Actions -- >

std::unique_ptr<Character> createCharacter(const std::string& name);
void showPartyMembers(const std::vector<std::unique_ptr<Character>>& party);
void showCharacterStats(const std::string& name, const std::vector<std::unique_ptr<Character>>& party);
void removeMemberFromTheParty(const std::string& name, std::vector<std::unique_ptr<Character>>& party);


// <! -- Handlers -- >
void handleCreateCharacter(std::vector<std::unique_ptr<Character>>& party);
void handleShowCharacterStats(const std::vector<std::unique_ptr<Character>>& party);
void handleShowPartyMembers(const std::vector<std::unique_ptr<Character>>& party);
void handleRemoveMemberFromTheParty(std::vector<std::unique_ptr<Character>>& party);
void handleInventoryOptions(std::vector<std::unique_ptr<Character>>& party);
#endif