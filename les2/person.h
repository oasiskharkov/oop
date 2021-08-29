#pragma once

#include <string>

enum class Sex { male, female };

class Person
{
public:
   
public:
   Person() : // default constructor
      m_name{""},
      m_age{0},
      m_sex{Sex::male},
      m_weight{0.0}
   {}
   
   Person(std::string&& name, int age, Sex sex, double weight) : // regular constructor
      m_name{std::move(name)},
      m_age{age},
      m_sex{sex},
      m_weight{ weight }
   {}

   Person(const Person& p) : // copy constructor
      m_name{ std::move(p.name()) },
      m_age{ p.age() },
      m_sex{ p.sex() },
      m_weight{ p.weight() }
   {}

   Person(Person&& p) noexcept : // move constructor
      m_name{ std::move(p.name()) },
      m_age{ p.age() },
      m_sex{ p.sex() },
      m_weight{ p.weight() }
   {}
   
   std::string name() const;
   int age() const;
   Sex sex() const;
   double weight() const;

   void setName(const std::string& name);
   void setAge(int age);
   void setSex(Sex sex);
   void setWeight(double weight);

private:
   std::string m_name;
   int m_age;
   Sex m_sex;
   double m_weight;
};

inline std::string Person::name() const
{
   return m_name;
}

inline int Person::age() const
{
   return m_age;
}

inline Sex Person::sex() const
{
   return m_sex;
}

inline double Person::weight() const
{
   return m_weight;
}

inline void Person::setName(const std::string& name)
{
   m_name = name;
}

inline void Person::setAge(int age)
{
   m_age = age;
}

inline void Person::setSex(Sex sex)
{
   m_sex = sex;
}

inline void Person::setWeight(double weight)
{
   m_weight = weight;
}