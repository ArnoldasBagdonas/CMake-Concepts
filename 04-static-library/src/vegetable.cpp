// Botanically, fruits contain seeds and come from the flower of
// a plant, while the rest of the plant is considered a vegetable.

#include "vegetable/vegetable.h"
#include <iostream>
#include <iomanip>

namespace vegetable
{
    Vegetable::Vegetable(std::string name, std::string color, float price)
    {
        _name = name;
        _color = color;
        _price = price;
        std::cout << "Vegetable: " << name << "(" << color  << ") " <<  std::fixed << std::setw(0) << std::setprecision(2) << price << " per kg" << std::endl;
    }
    Vegetable::~Vegetable() = default;
    std::string Vegetable::getName() const { return _name; };
    std::string Vegetable::getColor() const { return _color; };
    float Vegetable::getPrice() const { return _price; };
    void Vegetable::setPrice(float price) { _price = price; };
}