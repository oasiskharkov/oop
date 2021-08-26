#include <iostream>
#include <set>
#include <algorithm>

#include "student.h"
#include "fruit.h"

Student getEmptyStudent()
{
   Student s;
   return s;
}

const auto& getPredicate(Sex sex)
{
   const auto& pred = [sex](const Student* st)
   {
      if (st->sex() == sex)
      {
         std::cout << "Name: " << st->name() << ", age: " << st->age() << ", weight: " << st->weight() << ", year: " << st->year() << std::endl;
      }
   };
   return pred;
}

int main()
{
   // ========== TASK #1 ==========
   Student st1;                       // test default constructor
   Student st2 = st1;                 // test copy constructor
   Student st3 = getEmptyStudent();   // test move constructor

   std::set<Student*> students;

   st1.setName("Ivanova");
   st1.setAge(20);
   st1.setSex(Sex::female);
   st1.setWeight(45.6);
   st1.setYear(1991);
   students.emplace(&st1);

   st2.setName("Petrova");
   st2.setAge(21);
   st2.setSex(Sex::female);
   st2.setWeight(48.2);
   st2.setYear(1990);
   students.emplace(&st2);

   st3.setName("Kozlova");
   st3.setAge(19);
   st3.setSex(Sex::female);
   st3.setWeight(43.2);
   st3.setYear(1992);
   students.emplace(&st3);

   Student st4{ "Sidorov", 20, Sex::male, 64.4, 1990 };    // test regular constructor
   Student st5{ "Semenov", 20, Sex::male, 65.3, 1990 };
   Student st6{ "Yakovlev", 20, Sex::male, 63.2, 1990 };
   Student st7{ "Petuhov", 21, Sex::male, 68.1, 1989 };
   students.emplace(&st4);
   students.emplace(&st5);
   students.emplace(&st6);
   students.emplace(&st7);

   std::cout << "Student count: " << Student::getStudentsCount() << std::endl;
   std::cout << "Girls: " << std::endl;
   std::for_each(students.begin(), students.end(), getPredicate(Sex::female));
   std::cout << "Boys: " << std::endl;
   std::for_each(students.begin(), students.end(), getPredicate(Sex::male));
   std::cout << std::endl;

   // ========== TASK #2 ==========
   Apple a("red");
   Banana b;
   GrannySmith c;

   std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
   std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
   std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

   return 0;
}