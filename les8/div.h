#pragma once

#include <exception>
#include <string>

class DivisionByZero : public std::exception 
{
public:
   DivisionByZero(const std::string& type) :
      m_type{ type },
      m_error{ "Divide by zero exception, type = " + m_type}
   {}
   const char* what() const override
   {
      return m_error.c_str();
   }
private:
   std::string m_type;
   std::string m_error;
};

template <typename T>
T division(const T& numerator, const T& devisor)
{
   if (devisor == 0)
   {
      throw DivisionByZero(typeid(T).name());
   }
   return numerator / devisor;
}