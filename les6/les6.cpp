#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <climits>
#include <string>
#include <sstream>

std::ostream& endll(std::ostream& o)
{
   o.write("\n\n", 2);
   o.clear();
   o.flush();
   return o;
}

int main()
{
	// ========== TASK #1 ==========
	int number;
   std::string line;
   std::cout << "Enter a number: ";
   while (std::getline(std::cin, line))
   {
      std::stringstream ss(line);
      if (ss >> number)
      {
         if (ss.eof())
         {
            break;
         }
      }
      std::cout << "Error! Try one more time." << std::endl;
      std::cout << "Enter a number: ";
   }
	std::cout << "You entered: " << number << std::endl;

   // ========== TASK #2 ==========
   std::cout << "Test endll" << endll;
   std::cout << "Hello, geekbrains!" << std::endl;

   return 0;
}
