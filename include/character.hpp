#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>
#include <vector>
#include <tuple>
#include <set>
#include "item.hpp"
class Character {
    private:
        std::string name;
        std::string characterClass; // Warrior, Mage or Archer
        int maxHP;
        int currentHP;
        int level;
        int XP;
        int damage;
        int defense;
        std::tuple<int,int> position;
        std::vector<Item*> inventory;
        std::set<std::string> abilities;
    public:
        Character(std::string name, std::string characterClass);

        // Getters
        std::string getName() const;
        std::string getCharacterClass() const;
        int getMaxHP() const;
        int getCurrentHP() const;
        int getLevel() const;
        int getXP() const;
        int getDamage() const;
        int getDefense() const;
        std::tuple<int, int> getPosition() const;
        std::vector<Item*> getInventory() const;
        std::set<std::string> getAbilities() const;

        // Setters 
        void setName(const std::string& name);
        void setCharacterClass(const std::string& characterClass);
        void setMaxHP(const int maxHP);
        void setCurrentHP(const int currentHP);
        void setLevel(const int level);
        void setXP(const int XP);
        void setDamage(const int damage);
        void setDefense(const int defense);        
};

#endif // Character_HPP