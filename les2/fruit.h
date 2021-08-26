#pragma once

#include <string>
#include <sstream>

class Fruit
{
public:
   Fruit(std::string&& color) :
      m_color{ std::move(color) }
   {}
   virtual std::string getName() const = 0;
   std::string getColor() const;
   void setColor(const std::string& color);
private:
   std::string m_color;
};

inline std::string Fruit::getColor() const
{
   return m_color;
}

inline void Fruit::setColor(const std::string& color)
{
   m_color = color;
}

class Apple : public Fruit
{
public:
   Apple(std::string&& color) :
      Fruit{std::move(color)}
   {}
   std::string getName() const override;
};

inline std::string Apple::getName() const
{
   return "apple";
}

class Banana : public Fruit
{
public:
   Banana(std::string&& color = "yellow") :
      Fruit{ std::move(color) }
   {}
   std::string getName() const override;
};

inline std::string Banana::getName() const
{
   return "banana";
}

class GrannySmith : public Apple
{
public:
   GrannySmith(std::string&& color = "green") :
      Apple{ std::move(color) }
   {}
   std::string getName() const override;
};

inline std::string GrannySmith::getName() const
{
   std::stringstream ss;
   ss << "GrannySmith" << " " << Apple::getName();
   return ss.str();
}