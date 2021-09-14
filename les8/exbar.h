#pragma once

#include <string>

class Ex : public std::exception
{
public:
   explicit Ex(float x) :
      m_x{x},
      m_error{"Exception with value = " + std::to_string(m_x)}
   {}
   const char* what() const override
   {
      return m_error.c_str();
   }
private:
   float m_x;
   std::string m_error;
};

class Bar
{
public:
   explicit Bar(float y = 0.f) :
      m_y{y}
   {}
   void set(float a)
   {
      if (m_y + a > 100)
      {
         throw Ex(a * m_y);
      }
      m_y = a;
   }
private:
   float m_y;
};
