#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Item {
    private:
        std::string name;
        std::string type; // Weapon, armor, consumable or special
        int price;
        std::string description;
    public:
        Item(std::string name, std::string type, int price, std::string description);

        // GETTERS 
        std::string getName() const;
        std::string getType() const;
        int getPrice() const;
        std::string getDescription() const;
        
        // Other methods
        void display() const;

};
#endif // ITEM_HPP