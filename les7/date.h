#pragma once

#include <iostream>

class Date
{
public:
   Date(int day, int month, int year) :
      m_day{day},
      m_month{month},
      m_year{year}
   {}
   Date(const Date& d)
   {
      m_day = d.day();
      m_month = d.month();
      m_year = d.year();
   }
   int day() const;
   int month() const;
   int year() const;
   friend std::ostream& operator << (std::ostream& out, const Date& d);
private:
   int m_day;
   int m_month;
   int m_year;
};

inline int Date::day() const
{
   return m_day;
}

inline int Date::month() const
{
   return m_month;
}

inline int Date::year() const
{
   return m_year;
}

std::ostream& operator << (std::ostream& out, const Date& d)
{
   out << d.m_day << '.' << d.m_month << '.' << d.m_year;
   return out;
}

