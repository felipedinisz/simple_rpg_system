#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>
#include <vector>
#include <tuple>
#include <set>
#include <memory>
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
        std::vector<std::unique_ptr<Item>> inventory;
        std::set<std::string> abilities;
    public:
        Character(const std::string& name, enum CharacterClass characterClass);
        ~Character();
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
        const std::vector<std::unique_ptr<Item>>& getInventory() const;
        const std::set<std::string>& getAbilities() const;

        // Setters 
        void setName(const std::string& name);
        void setCharacterClass(const CharacterClass& characterClass);
        void setMaxHP(int maxHP);
        void setCurrentHP(int currentHP);
        void setLevel(int level);
        void setXP(int XP);
        void setDamage(int damage);
        void setDefense(int defense);        

        // Inventory methods
        void addItem(std::unique_ptr<Item> item);
        void removeItem(const std::string& itemName);
        Item* getItem(std::size_t index) const;
        std::size_t getInventorySize() const;
        void showInventory() const;
        void clearInventory();

        // Abilities methods
        bool hasAbility(const std::string& ability) const;
        void showAbilities() const;
        bool learnAbility(const std::string& ability); 
        std::size_t getAbilitiesCount() const;

        //Position methods 
        void move(int deltaX, int deltaY);
        void moveNorth();
        void moveSouth();
        void moveEast();
        void moveWest();
        void getX();
        void getY();

        // Other methods
        void display() const;
        void levelUP();

};

#endif // Character_HPP