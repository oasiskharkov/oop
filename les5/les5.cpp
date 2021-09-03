#include <iostream>

#include "pair1.h"
#include "pair.h"

int main()
{
   // ========== TASK #1 ==========
   Pair1 p1(1, 2);
   std::cout << "Pair: " << p1.first() << ' ' << p1.second() << std::endl;
   Pair1<int> p2(3, 4);
   std::cout << "Pair: " << p2.first() << ' ' << p2.second() << std::endl;
   p2.setFirst(10);
   p2.setSecond(20);
   std::cout << "Pair: " << p2.first() << ' ' << p2.second() << std::endl;

   Pair1 p3(1.3, 2.5);
   std::cout << "Pair: " << p3.first() << ' ' << p3.second() << std::endl;
   Pair1<double> p4(3.4, 4.6);
   std::cout << "Pair: " << p4.first() << ' ' << p4.second() << std::endl;

   Pair1 p5(true, true);
   std::cout << "Pair: " << std::boolalpha << p5.first() << ' ' << std::boolalpha << p5.second() << std::endl;
   p5.setFirst(false);
   p5.setSecond(false);
   std::cout << "Pair: " << std::boolalpha << p5.first() << ' ' << std::boolalpha << p5.second() << std::endl;
   p5.setFirst(false);
   p5.setSecond(false);
   std::cout << "Pair: " << std::boolalpha << p5.first() << ' ' << std::boolalpha << p5.second() << std::endl;

   Pair1<bool> p6(false, true);
   std::cout << "Pair: " << std::boolalpha << p6.first() << ' ' << std::boolalpha << p6.second() << std::endl;
   p6.setFirst(true);
   p6.setSecond(false);
   std::cout << "Pair: " << std::boolalpha << p6.first() << ' ' << std::boolalpha << p6.second() << std::endl;

   Pair1 p7(true, false);
   std::cout << "Pair: " << std::boolalpha << p7.first() << ' ' << std::boolalpha << p7.second() << std::endl;
   p7.setFirst(false);
   p7.setSecond(true);
   std::cout << "Pair: " << std::boolalpha << p7.first() << ' ' << std::boolalpha << p7.second() << std::endl;

   Pair1<bool> p8(false, false);
   std::cout << "Pair: " << std::boolalpha << p8.first() << ' ' << std::boolalpha << p8.second() << std::endl;
   p8.setFirst(true);
   p8.setSecond(true);
   std::cout << "Pair: " << std::boolalpha << p8.first() << ' ' << std::boolalpha << p8.second() << std::endl;
   p8.setFirst(true);
   p8.setSecond(true);
   std::cout << "Pair: " << std::boolalpha << p8.first() << ' ' << std::boolalpha << p8.second() << std::endl;

   // ========== TASK #2 ==========
   Pair p9(1, 2.1);
   std::cout << "Pair: " << p9.first() << ' ' << p9.second() << std::endl;
   Pair<double, int> p10(3.3, 4);
   std::cout << "Pair: " << p10.first() << ' ' << p10.second() << std::endl;
   p10.setFirst(10.2);
   p10.setSecond(20);
   std::cout << "Pair: " << p10.first() << ' ' << p10.second() << std::endl;

   Pair p11(1.3, 2);
   std::cout << "Pair: " << p11.first() << ' ' << p11.second() << std::endl;
   Pair<int, double> p12(4, 7.6);
   std::cout << "Pair: " << p12.first() << ' ' << p12.second() << std::endl;
   p12.setFirst(5);
   p12.setSecond(31.1);
   std::cout << "Pair: " << p12.first() << ' ' << p12.second() << std::endl;

   // ========== TASK #3 ==========
   StringValuePair<int> svp("Amazing", 7);
   std::cout << "Pair: " << svp.first() << ' ' << svp.second() << std::endl;
   svp.setFirst("Ungly");
   svp.setSecond(69);
   std::cout << "Pair: " << svp.first() << ' ' << svp.second() << std::endl;

   StringValuePair svp2("Apple", 10);
   std::cout << "Pair: " << svp2.first() << ' ' << svp2.second() << std::endl;
   svp2.setFirst("Dell");
   svp2.setSecond(20);
   std::cout << "Pair: " << svp2.first() << ' ' << svp2.second() << std::endl;

   return EXIT_SUCCESS;
}
