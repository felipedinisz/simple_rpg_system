#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>
#include <vector>
#include <tuple>
#include <set>
#include <string_view>
#include "item.hpp"
enum class CharacterClass {
    Warrior,
    Mage,
    Archer,
};

class Character {
    private:
        std::string name;
        CharacterClass characterClass; // Warrior, Mage or Archer
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
        Character(const std::string& name, enum CharacterClass characterClass);
        void setInitializationAttributes(int maxHP, int damage, int defense, const std::string& ability);

        // Getters
        const std::string& getName() const;
        std::string_view getCharacterClass() const;
        int getMaxHP() const;
        int getCurrentHP() const;
        int getLevel() const;
        int getXP() const;
        int getDamage() const;
        int getDefense() const;
        std::tuple<int, int> getPosition() const;
        const std::vector<Item*>& getInventory() const;
        const std::set<std::string>& getAbilities() const;

        // Setters 
        void setName(const std::string& name);
        void setCharacterClass(const std::string& characterClass);
        void setMaxHP(int maxHP);
        void setCurrentHP(int currentHP);
        void setLevel(int level);
        void setXP(int XP);
        void setDamage(int damage);
        void setDefense(int defense);        

        // Inventory methods
        void addItem(Item* item);
        void removeItem(const std::string& itemName);
        void clearInventory();
        const Item* getItem(int index) const;
        int getInventorySize() const;
        void showInventory() const;

        // Abilities methods
        bool hasAbility(const std::string& ability) const;
        void showAbilities() const;
        bool learnAbility(const std::string& ability); 
        int getAbilitiesCount() const;

        //Position methods 
        void move(int deltaX, int deltaY);
        void moveNorth();
        void moveSouth();
        void moveEast();
        void moveWest();

        // Other methods
        void display() const;
        void levelUP() const;

};

#endif // Character_HPP