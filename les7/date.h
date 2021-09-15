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
   std::string to_string() const;
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

inline std::string Date::to_string() const
{
   char buf[11];
   sprintf_s(buf, "%04d.%02d.%02d", m_year, m_month, m_day);
   return buf;
}

std::ostream& operator << (std::ostream& out, const Date& d)
{
   out << d.m_day << '.' << d.m_month << '.' << d.m_year;
   return out;
}

