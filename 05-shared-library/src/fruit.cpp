// Botanically, fruits contain seeds and come from the flower of
// a plant, while the rest of the plant is considered a vegetable.

#include "fruit/fruit.h"
#include <iostream>
#include <iomanip>

namespace fruit
{
    Fruit::Fruit(std::string name, std::string color, float price)
    {
        _name = name;
        _color = color;
        _price = price;
        std::cout << "Fruit: " << name << "(" << color  << ") " <<  std::fixed << std::setw(0) << std::setprecision(2) << price << " per kg" << std::endl;
    }
    Fruit::~Fruit() = default;
    std::string Fruit::getName() const { return _name; };
    std::string Fruit::getColor() const { return _color; };
    float Fruit::getPrice() const { return _price; };
    void Fruit::setPrice(float price) { _price = price; };
}