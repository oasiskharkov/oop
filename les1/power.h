#pragma once

#include <cmath>

class Power
{
public:
  void set(double base, double power)
  {
    m_base = base ;
    m_power = power;
  }

  double calculate() const
  {
    return pow(m_base, m_power);
  }

private:
  double m_base = 0.0;
  double m_power = 0.0;
};