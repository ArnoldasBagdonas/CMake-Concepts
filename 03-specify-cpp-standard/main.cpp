#include <iostream>
#include "cogen.hpp"

cogen::Generator<int> foo(int n = 0)
{
   for (int i = 0; i <= n; ++i)
   {
      if (i > 10)
         throw std::runtime_error("Elements would overflow.");
      
      co_yield i;
   }

   co_return;
}

int main(int argc, char *argv[])
{
   std::cout << "C++20 coroutine generator example version " << COGEN_VERSION << std::endl;

   try
   {
      auto gen = foo(15);
      int j = 0;
      while(gen)
         std::cout << "foo(" << (j++) << ")=" << gen() << '\n';
   }
   catch (const std::exception &ex)
   {
      std::cerr << "Exception: " << ex.what() << '\n';
   }
   catch (...)
   {
      std::cerr << "Unknown exception.\n";
   }

   std::exit(EXIT_SUCCESS);
}