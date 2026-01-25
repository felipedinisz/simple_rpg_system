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
bool characterIsAlreadyInParty(std::string& name, std::vector<std::unique_ptr<Character>>& party);

// <! -- Menu Actions -- >

std::unique_ptr<Character> createCharacter(const std::string& name);
void showPartyMembers(std::vector<std::unique_ptr<Character>>& party);
void showCharacterStats(std::string& name, std::vector<std::unique_ptr<Character>>& party);
void removeMemberFromTheParty(const std::string& name, std::vector<std::unique_ptr<Character>>& party);


// <! -- Handlers -- >
void handleCreateCharacter(std::vector<std::unique_ptr<Character>>& party);
void handleShowCharacterStats(std::vector<std::unique_ptr<Character>>& party);
void handleShowPartyMembers(std::vector<std::unique_ptr<Character>>& party);
void handleRemoveMemberFromTheParty(std::vector<std::unique_ptr<Character>>& party);
#endif