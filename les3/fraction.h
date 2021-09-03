#pragma once

#include <iostream>

class Fraction
{
public:
   Fraction(int numerator, int denominator);
   
   Fraction& operator - ();
   Fraction& operator = (const Fraction& f);
   Fraction& operator += (const Fraction& f);
   Fraction& operator -= (const Fraction& f);
   Fraction& operator *= (const Fraction& f);
   Fraction& operator /= (const Fraction& f);
   
   Fraction operator + (const Fraction& f) const;
   Fraction operator - (const Fraction& f) const;
   Fraction operator * (const Fraction& f) const;
   Fraction operator / (const Fraction& f) const;
   
   bool operator == (const Fraction& f) const;
   bool operator != (const Fraction& f) const;
   bool operator > (const Fraction& f) const;
   bool operator < (const Fraction& f) const;
   bool operator >= (const Fraction& f) const;
   bool operator <= (const Fraction& f) const;

   void normalize();

   friend std::ostream& operator << (std::ostream& o, const Fraction& f);
private:
   int gcd(int a, int b) const;
   int lcm(int a, int b) const;
private:
   int m_numerator;
   int m_denominator;
};

inline std::ostream& operator << (std::ostream& o, const Fraction& f)
{
   o << f.m_numerator << '/' << f.m_denominator;
   return o;
}