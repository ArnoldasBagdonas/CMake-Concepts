#include "vegetable/vegetable.h"
#include <iostream>

int main(int argc, char *argv[])
{
   std::cout << "Vegetable example" << std::endl;
   vegetable::Vegetable garlic("garlic", "light grey", 0.354153);
   vegetable::Vegetable tomato("tomato", "red", 1.2323);
   std::exit(EXIT_SUCCESS);
}