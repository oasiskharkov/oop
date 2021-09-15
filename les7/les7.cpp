#include <memory>
#include <iostream>

#include "date.h"

std::unique_ptr<Date> compare(const std::unique_ptr<Date>& d1, const std::unique_ptr<Date>& d2);
void swap_uniques(std::unique_ptr<Date>& d1, std::unique_ptr<Date>& d2);

int main()
{
   // ========== TASK #1 ==========
   std::unique_ptr<Date> today = std::make_unique<Date>(10, 9, 2021);
   std::cout << *today << std::endl;
   std::cout << "Day: " << today->day() << std::endl;
   std::cout << "Month: " << (*today).month() << std::endl;
   std::cout << "Year: " << today.get()->year() << std::endl;
   std::unique_ptr<Date> date;
   today.swap(date);

   if (today)
   {
      std::cout << *today << std::endl;
   }
   else
   {
      std::cout << "today is nullptr" << std::endl;
   }

   if (date)
   {
      std::cout << *date << std::endl;
   }
   else
   {
      std::cout << "date is nullptr" << std::endl;
   }

   today.reset(new Date(11, 9, 2021));
   std::cout << *today << std::endl;

   date.release();
   if (!date)
   {
      std::cout << "Date released" << std::endl;
   }

   // ========== TASK #2 ==========
   std::unique_ptr<Date> d1 = std::make_unique<Date>(10, 6, 2021);
   std::unique_ptr<Date> d2(new Date(15, 6, 2021));

   std::unique_ptr<Date> greater = compare(d1, d2);
   std::cout << *greater << std::endl;

   swap_uniques(d1, d2);
   std::cout << *d1 << std::endl;
   std::cout << *d2 << std::endl;

   return EXIT_SUCCESS;
}

std::unique_ptr<Date> compare(const std::unique_ptr<Date>& d1, const std::unique_ptr<Date>& d2)
{
   int result = strcmp(d1->to_string().c_str(), d2->to_string().c_str());
   if (result >= 0)
   {
      return std::make_unique<Date>(*d1);
   }
   return std::make_unique<Date>(*d2);
}

void swap_uniques(std::unique_ptr<Date>& d1, std::unique_ptr<Date>& d2)
{
   std::unique_ptr<Date> temp(std::move(d1));  // 1 way
   d1 = std::move(d2);
   d2 = std::move(temp);

   /*Date* temp = d1.get();                    // 2 way 
   d1.release();
   d1.reset(d2.get());
   d2.release();
   d2.reset(temp);*/

   /*std::swap(d1, d2);*/                      // 3 way
}