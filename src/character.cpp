#include "../include/character.hpp"
#include "iostream"
#include <vector>

void Character::setInitializationAttributes(int maxHP, int damage, int defense, const std::string& ability) {
            this->maxHP = maxHP;
            this->damage = damage;
            this->defense = defense;
            this->abilities.insert(ability);
            this->level = 1;
            this->XP = 0;
            std::get<0>(this->position) = 0;
            std::get<1>(this->position) = 0;
            this->inventory.clear();
            this->currentHP = this->maxHP;
}

Character::Character(const std::string& name, enum CharacterClass characterClass) :
    name(name),
    characterClass(characterClass) {
        switch (characterClass) {
            case CharacterClass::Warrior:
                setInitializationAttributes(150, 20, 50, "Legendary blade");
                break;
            case CharacterClass::Mage:
                setInitializationAttributes(75, 50, 25, "Fireball");
                break;
            case CharacterClass::Archer:
                setInitializationAttributes(50, 15, 120, "Arrow shower");
                break;
        }
}

// <! -- Getters -- >

const std::string& Character::getName() const {
    return this->name;
}
std::string_view Character::getCharacterClass() const {
    switch(this->characterClass) {
        case CharacterClass::Warrior: return "Warrior";
        case CharacterClass::Mage: return "Mage";
        case CharacterClass::Archer: return "Archer";
    }
    return "Unknown";
}

int Character::getMaxHP() const  {
    return this->maxHP;
}

int Character::getCurrentHP() const {
    return this->currentHP;
}

int Character::getLevel() const {
    return this->level;
}

int Character::getXP() const {
    return this->XP;
}

int Character::getDamage() const {
    return this->damage;
}

int Character::getDefense() const {
    return this->defense;
}

std::tuple<int, int> Character::getPosition() const {
    return this->position;
}

const std::vector<std::unique_ptr<Item>>& Character::getInventory() const {
    return this->inventory;
}

const std::set<std::string>& Character::getAbilities() const {
    return this->abilities;
}
// <! -- Setters -- >
void Character::setName(const std::string& name) {
    this->name = name;
}

void Character::setCharacterClass(const CharacterClass& characterClass) {
    this->characterClass = characterClass;
}

void Character::setMaxHP(int maxHP) {
    this->maxHP = maxHP;
}

void Character::setCurrentHP(int currentHP) {
    this->currentHP = currentHP;
}

void Character::setLevel(int level) {
    this->level = level;
}

void Character::setXP(int XP) {
    this->XP = XP;
}

void Character::setDamage(int damage) {
    this->damage = damage;
}

void Character::setDefense(int defense) {
    this->defense = defense;
}

// <! -- Inventory Methods -- >
void Character::showInventory() const {

    if(this->inventory.empty()) {
        std::cout << "The inventory is empty. \n";
        return;
    }

    for(const std::unique_ptr<Item>& item : this->inventory) {
        if(item) {
            std::cout << item->getName() << "\n";
        }
    }
}


void Character::clearInventory() {
    if(this->inventory.empty()) return;
    
    this->inventory.clear();
    std::cout << "The inventory is now empty! \n";
}

// <! -- Other Methods -- >
void Character::display() const {
    std::cout << "================================" << "\n";
    std::cout << this->getName() << "'s stats:" "\n";
    std::cout << "Combat class: " << this->getCharacterClass() << "\n";
    std::cout << "Health: " << this->getCurrentHP() << "/" << this->getMaxHP() << "\n";
    std::cout << "Level: " << this->getLevel() << "\n";
    std::cout << "Experience: " << this->getXP() << "\n";
    std::cout << "Damage: " << this->getDamage() << "\n";
    std::cout << "Defense: " << this->getDefense() << "\n";
    this->showInventory();
    std::cout << "================================" << "\n";
}


Character::~Character() {
    this->clearInventory();
}