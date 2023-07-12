// Reference:
// https://www.boost.org/doc/libs/1_77_0/libs/filesystem/doc/tutorial.html

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/filesystem.hpp>
using std::cout;
using namespace boost::filesystem;

int main(int argc, char *argv[])
{
   if (argc < 2)
   {
      cout << "Usage: exampleproject_binary path\n";
      return 1;
   }

   path p(argv[1]);

   try
   {
      if (exists(p))
      {
         if (is_regular_file(p))
            cout << p << " size is " << file_size(p) << '\n';

         else if (is_directory(p))
         {
            cout << p << " is a directory containing:\n";

            for (directory_entry &x : directory_iterator(p))
               cout << "    " << x.path() << '\n';
         }
         else
            cout << p << " exists, but is not a regular file or directory\n";
      }
      else
         cout << p << " does not exist\n";
   }

   catch (const filesystem_error &ex)
   {
      cout << ex.what() << '\n';
   }

   std::exit(EXIT_SUCCESS);
}
