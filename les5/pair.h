#pragma once

template <typename T, typename U>
class Pair
{
public:
   Pair(const T& first, const U& second) :
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
   void setSecond(const U& second)
   {
      m_second = second;
   }
private:
   T m_first;
   U m_second;
};

template <typename U>
class Pair<std::string, U>
{
public:
   Pair(const std::string& first, const U& second) :
      m_first{ first },
      m_second{ second }
   {}
   const auto& first() const
   {
      return m_first;
   }
   const auto& second() const
   {
      return m_second;
   }
   void setFirst(const std::string& first)
   {
      m_first = first;
   }
   void setSecond(const U& second)
   {
      m_second = second;
   }
private:
   std::string m_first;
   U m_second;
};

template <typename U>
class StringValuePair : public Pair<std::string, U>
{
public:
   StringValuePair(const std::string& first, const U& second) :
      Pair<std::string, U>(first, second)
   {}
};
