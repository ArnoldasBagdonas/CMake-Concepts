// Botanically, fruits contain seeds and come from the flower of
// a plant, while the rest of the plant is considered a vegetable.

#pragma once

#include <string>

namespace fruit
{
   class Fruit
   {
   public:
      Fruit(std::string name, std::string color, float price);
      ~Fruit();
      std::string getName() const; // This function doesn't modify the Fruit instance it is called on", so in a way it marks it as a pure getter
      std::string getColor() const;
      float getPrice() const;
      void setPrice(float price);

   private:
      std::string _name;
      std::string _color;
      float _price;
   };
}