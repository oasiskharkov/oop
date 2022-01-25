#include <iostream>
#include "div.h"
#include "exbar.h"
#include "robot.h"
#include "utils.h"

int main()
{
   // ========== TASK #1 ==========
   try
   {
      int ai, bi; 
      ai = 10; 
      bi = 2;
      std::cout << division(ai, bi) << std::endl;
      float af, bf;
      af = 3.f;
      bf = 2.f;
      std::cout << division(af, bf) << std::endl;
      double ad, bd;
      ad = 4.;
      bd = 0.;
      std::cout << division(ad, bd) << std::endl;
   }
   catch (const DivisionByZero& dz)
   {
      std::cerr << dz.what() << std::endl;
      return EXIT_FAILURE;
   }

   // ========== TASK #2 ==========
   try
   {
      Bar b;
      int n;
      do
      {
         std::cout << "input n: ";
         std::cin >> n;
         b.set(n);
      } while (n != 0);
   }
    
   catch (const Ex& ex)
   {
      std::cerr << ex.what() << std::endl;
      return EXIT_FAILURE;
   }
   
   // ========== TASK #3 ==========
   try
   {
      Robot robot(1, 1);
      robot.draw();
      char choice;
      while(true)
      {
         std::cout << "\nThe robot can only walk horizontally or vertically!" << std::endl;
         std::cout << "Press: 'w' to move up, 's' to move down, 'd' to move right, 'a' to move left, or 'x' to exit: ";
         choice = std::tolower(Utils::getch());
         if (choice == 'x')
         {
            break;
         }
         robot.move(choice);
         robot.draw();
      }
   }
   catch (const IllegalCommand& ic)
   {
      std::cerr << ic.what() << std::endl;
      return EXIT_FAILURE;
   }
   catch (const OffTheField& otf)
   {
      std::cerr << otf.what() << std::endl;
      return EXIT_FAILURE;
   }

   return EXIT_SUCCESS;
}
