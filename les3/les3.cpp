#include <iostream>
#include <memory>
#include <vector>

#include "figure.h"
#include "car.h"
#include "fraction.h"

int main()
{
    // ========== TASK #1 ==========
   std::vector<std::unique_ptr<Figure>> figures;
   figures.emplace_back(std::make_unique<Circle>(2.0));
   figures.emplace_back(std::make_unique<Rectangle>(2.0, 3.1));
   figures.emplace_back(std::make_unique<Square>(3.0));
   figures.emplace_back(std::make_unique<Rhombus>(3.0, 4.0));
   figures.emplace_back(std::make_unique<Parallelogram>(4.0, 5.0));
   for (const auto& pf : figures)
   {
      std::cout << pf->name() << " has area " << pf->area() << std::endl;
   }

   // ========== TASK #2 ==========
   Car* car = new Car("KIA", "Rio");
   std::cout << car->getName() << std::endl;
   delete car;
   std::cout << std::endl;

   Bus* bus = new Bus("MAN", "sb3");
   std::cout << bus->getName() << std::endl;
   delete bus;
   std::cout << std::endl;

   PassengerCar* pcar = new PassengerCar("Opel", "Astra");
   std::cout << pcar->getName() << std::endl;
   delete pcar;
   std::cout << std::endl;

   Car* m = new Minivan("KIA", "Carnival");
   std::cout << m->getName() << std::endl;
   delete m;
   std::cout << std::endl;

   // ========== TASK #3 ==========
   try
   {
      Fraction f1(1, 3);
      Fraction f2(1, 4);
      std::cout << f1 + f2 << std::endl; // 7/12
      std::cout << f1 - f2 << std::endl; // 1/12
      std::cout << f1 * f2 << std::endl; // 1/12
      std::cout << f1 / f2 << std::endl; // 4/3
      f1 += Fraction(3, 5);
      std::cout << f1 << std::endl;      // 14/15
      f1 -= Fraction(7, 10);             
      std::cout << f1 << std::endl;      // 7/30
      f1 *= Fraction(3, 2);
      std::cout << f1 << std::endl;      // 21/60
      f1 /= Fraction(4, 3);
      std::cout << f1 << std::endl;      // 63/240
      f1.normalize();
      std::cout << -f1 << std::endl;      // -21/80

      if (Fraction(1, 3) < Fraction(1, 2))
      {
         std::cout << "1\\3 < 1\\2" << std::endl;
      }

      if (Fraction(1, 3) > Fraction(1, 4))
      {
         std::cout << "1\\3 > 1\\4" << std::endl;
      }

      if (Fraction(2, 5) == Fraction(2, 5))
      {
         std::cout << "2\\5 == 2\\5" << std::endl;
      }

      if (Fraction(1, 3) >= Fraction(1, 3))
      {
         std::cout << "1\\3 >= 1\\3" << std::endl;
      }

      if (Fraction(1, 3) <= Fraction(2, 6))
      {
         std::cout << "1\\3 <= 2\\6" << std::endl;
      }

      if (Fraction(1, 3) != Fraction(2, 7))
      {
         std::cout << "1\\3 != 2\\7" << std::endl;
      }
   }
   catch (const std::exception& ex)
   {
      std::cerr << ex.what() << std::endl;
      return EXIT_FAILURE;
   }

   return EXIT_SUCCESS;
}
