#include "../include/character.hpp"
#include "iostream"

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
                setInitializationAttributes(150, 20, 50, "Powerful fist");
                break;
            case CharacterClass::Mage:
                setInitializationAttributes(75, 50, 25, "Fireball");
                break;
            case CharacterClass::Archer:
                setInitializationAttributes(50, 15, 120, "Arrow shower");
                break;
        }
}

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

const std::vector<Item*>& Character::getInventory() const {
    return this->inventory;
}

const std::set<std::string>& Character::getAbilities() const {
    return this->abilities;
}

void Character::showInventory() const {

    if(this->inventory.empty()) {
        std::cout << "The inventory is empty. \n";
        return;
    }

    for(const Item* item : this->inventory) {
        if(item) {
            std::cout << item->getName() << "\n";
        }
    }
}