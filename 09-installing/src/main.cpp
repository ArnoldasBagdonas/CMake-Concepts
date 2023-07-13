#include <iostream>
#include "fruit/fruit.h"

int main(int argc, char *argv[])
{
   std::cout << "Fruit example" << std::endl;
   fruit::Fruit apple("apple", "red", 3.14153);
   fruit::Fruit banana("banana", "yellow", 2.5623);
   std::exit(EXIT_SUCCESS);
}