#pragma once

template<typename T>
class Pair1
{
public:
   Pair1(const T& first, const T& second) :
      m_first{first},
      m_second{second}
   {}
   const auto& first() const
   {
      return m_first;
   }
   const auto& second() const
   {
      return m_second;
   }
   void setFirst(const T& first)
   {
      m_first = first;
   }
   void setSecond(const T& second)
   {
      m_second = second;
   }
private:
   T m_first;
   T m_second;
};

template<>
class Pair1<bool>
{
public:
   Pair1(bool first, bool second) :
      holder{0}
   {
      if (first)
      {
         char mask = 1;
         holder |= mask;
      }
      if (second)
      {
         char mask = 2;
         holder |= mask;
      }
   }
   bool first() const
   {
      char mask = 1;
      return mask & holder;
   }
   bool second() const
   {
      char mask = 2;
      return (mask & holder) >> 1;
   }
   void setFirst(bool first)
   {
      char mask = ~1;
      holder &= mask;
      if (first)
      {
         char mask = 1;
         holder |= mask;
      }
   }
   void setSecond(bool second)
   {
      char mask = ~(1 << 1);
      holder &= mask;
      if (second)
      {
         char mask = 2;
         holder |= mask;
      }
   }
private:
   unsigned char holder;
};