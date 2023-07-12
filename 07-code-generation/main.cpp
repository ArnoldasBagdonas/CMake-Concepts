#include <iostream>
#include "version.hpp"
int main(int argc, char *argv[])
{
   std::cout << "Hello World!" << std::endl;
   std::cout <<  PROJECT_VERSION_STRING << std::endl;
   std::cout <<  PROJECT_GIT_REPOSITORY_URL << std::endl;
   std::cout <<  "build: " << PROJECT_BUILD_DATE_TIME << std::endl;
   
   std::exit(EXIT_SUCCESS);
}