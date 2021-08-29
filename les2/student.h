#pragma once

#include "person.h"

class Student : public Person
{
public:
   Student() : m_year{ 0 } // default constructor
   {
      counter++;
   }

   Student(std::string&& name, int age, Sex sex, double weight, int year) : // reqular constructor
      Person{ std::move(name), age, sex, weight },
      m_year{ year }
   {
      counter++;
   }

   Student(const Student& st) : m_year{st.year()} // copy constructor
   {
      counter++;
   }

   Student(Student&& st) noexcept : m_year{st.year()} // move constructor
   {
      counter++;
   }

   ~Student()
   {
      counter--;
   }

   int year() const;
   void setYear(int year);
   static int getStudentsCount();
private:
   int m_year;
   static int counter;
};

int Student::counter = 0;

inline int Student::year() const
{
   return m_year;
}

inline void Student::setYear(int year)
{
   m_year = year;
}

inline int Student::getStudentsCount()
{
   return counter;
}
