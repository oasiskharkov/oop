#include "fraction.h"

Fraction::Fraction(int numerator, int denominator) :
   m_numerator{ numerator },
   m_denominator{ denominator }
{
   // invariant checker
   if (denominator == 0)
   {
      throw std::logic_error("Can't create object, denominator is null.");
   }

   if (denominator < 0)
   {
      throw std::logic_error("Can't create object, denominator is less than null.");
   }
}

Fraction& Fraction::operator - ()
{
   this->m_numerator = -this->m_numerator;
   return *this;
}

Fraction& Fraction::operator = (const Fraction& f)
{
   this->m_numerator = f.m_numerator;
   this->m_denominator = f.m_denominator;
   return *this;
}

Fraction& Fraction::operator += (const Fraction& f)
{
   *this = *this + f;
   return *this;
}

Fraction& Fraction::operator -= (const Fraction& f)
{
   *this = *this - f;
   return *this;
}

Fraction& Fraction::operator *= (const Fraction& f)
{
   *this = *this * f;
   return *this;
}

Fraction& Fraction::operator /= (const Fraction& f)
{
   *this = *this / f;
   return *this;
}

Fraction Fraction::operator + (const Fraction& f) const
{
   auto l = lcm(m_denominator, f.m_denominator);
   return Fraction(m_numerator * l / m_denominator + f.m_numerator * l / f.m_denominator, l);
}

Fraction Fraction::operator - (const Fraction& f) const
{
   auto l = lcm(m_denominator, f.m_denominator);
   return Fraction(m_numerator * l / m_denominator - f.m_numerator * l / f.m_denominator, l);
}

Fraction Fraction::operator * (const Fraction& f) const
{
   return Fraction (m_numerator * f.m_numerator, m_denominator * f.m_denominator);
}

Fraction Fraction::operator / (const Fraction& f) const
{
   return Fraction(m_numerator * f.m_denominator, m_denominator * f.m_numerator);
}

bool Fraction::operator == (const Fraction& f) const
{
   return m_numerator * f.m_denominator == m_denominator * f.m_numerator;
}

bool Fraction::operator != (const Fraction& f) const
{
   return !(*this == f);
}

bool Fraction::operator > (const Fraction& f) const
{
   return m_numerator* f.m_denominator > m_denominator * f.m_numerator;
}

bool Fraction::operator < (const Fraction& f) const
{
   return !(*this > f) and !(*this == f);
}

bool Fraction::operator >= (const Fraction& f) const
{
   return *this > f or *this == f;
}

bool Fraction::operator <= (const Fraction& f) const
{
   return *this < f or *this == f;
}

int Fraction::gcd(int a, int b) const
{
   if (a < b) 
   {
      std::swap(a, b);
   }
   while (a % b != 0) 
   {
      a = a % b;
      std::swap(a, b);
   }
   return b;
}

int Fraction::lcm(int a, int b) const
{
   return (a * b) / gcd(a, b);
}

void Fraction::normalize()
{
   auto g = gcd(m_numerator, m_denominator);
   m_numerator = m_numerator / g;
   m_denominator = m_denominator / g;
}