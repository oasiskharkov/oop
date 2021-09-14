#include <iostream>
#include "div.h"
#include "exbar.h"
#include "robot.h"
#include "conio.h"

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
      char choice = '0';
      do
      {
         int dir_x;
         int dir_y;
         std::cout << "\nThe robot can only walk horizontally or vertically!" << std::endl;
         std::cout << "Directions(x, y): right(1, 0), left(-1, 0), down(0, 1), up(0, -1)" << std::endl;
         std::cout << "Input x direction: ";
         std::cin >> dir_x;
         std::cout << "Input y direction: ";
         std::cin >> dir_y;
         robot.move(dir_x, dir_y);
         robot.draw();
         std::cout << "Press 'y' button if you want to exit or other key to continue: ";
         choice = _getch();
      } while (choice != 'y' and choice != 'Y');
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
