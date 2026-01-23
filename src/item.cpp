#include "../include/item.hpp"
#include <iostream>

Item::Item(std::string name, std::string type, int price, std::string description) : 
    name(name), 
    type(type),
    price(price),
    description(description) {}

std::string Item::getName() const {
    return this->name;
}

std::string Item::getType() const {
    return this->type;
}

int Item::getPrice() const {
    return this->price;
}

std::string Item::getDescription() const {
    return this->description;
}

void Item::display() const {
    std::cout << "================================" << "\n";
    std::cout << "Item: " << this->getName() << "\n";
    std::cout << "Type: " <<  this->getType() << "\n";
    std::cout << "Price: " << this->getPrice() << "\n";
    std::cout << "Description: " << this->getDescription() << "\n";
    std::cout << "================================" << std::endl;
}

