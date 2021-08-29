#pragma once

#include <corecrt_math_defines.h>
#include <string>

class Figure
{
public:
   virtual double area() const = 0;
   virtual std::string name() const = 0;
};

class Circle final : public Figure
{
public:
   Circle(double radius) :
      m_radius{ radius }
   {}
   double area() const override;
   std::string name() const override;
private:
   double m_radius;
};

inline double Circle::area() const
{
   return M_PI * m_radius * m_radius;
}

inline std::string Circle::name() const
{
   return "Circle";
}

class Tetragon : public Figure
{

};

class Parallelogram final : public Tetragon
{
public:
   Parallelogram(double base, double height) :
      m_base{ base },
      m_height{ height }
   {}
   double area() const override;
   std::string name() const override;
private:
   double m_base;
   double m_height;
};

inline double Parallelogram::area() const
{
   return m_base * m_height;
}

inline std::string Parallelogram::name() const
{
   return "Parallelogram";
}

class Square final : public Tetragon
{
public:
   Square(double side) :
      m_side{ side }
   {}
   double area() const override;
   std::string name() const override;
private:
   double m_side;
};

inline double Square::area() const
{
   return m_side * m_side;
}

inline std::string Square::name() const
{
   return "Sguare";
}

class Rectangle final: public Tetragon
{
public:
   Rectangle(double sideA, double sideB) :
      m_sideA{ sideA },
      m_sideB{ sideB }
   {}
   double area() const override;
   std::string name() const override;
private:
   double m_sideA;
   double m_sideB;
};

inline double Rectangle::area() const
{
   return m_sideA * m_sideB;
}

inline std::string Rectangle::name() const
{
   return "Rectangle";
}

class Rhombus final : public Tetragon
{
public:
   Rhombus(double d1, double d2) :
      m_d1{ d1 },
      m_d2{ d2 }
   {}
   double area() const override;
   std::string name() const override;
private:
   double m_d1;
   double m_d2;
};

inline double Rhombus::area() const
{
   return m_d1 * m_d2 / 2;
}

inline std::string Rhombus::name() const
{
   return "Rhombus";
}