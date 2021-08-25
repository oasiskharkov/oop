#pragma once

#include <cstdint>
#include <iostream>

class RGBA
{
public:
  explicit RGBA(std::uint8_t red = 0, std::uint8_t green = 0, std::uint8_t blue = 0, std::uint8_t alpha = 255) :
    m_red{ red },
    m_green{ green },
    m_blue{ blue },
    m_alpha{ alpha }
  {}
  void print() const
  {
    std::cout << "Red: " << (int)m_red << " Green: " << (int)m_green << " Blue: " << (int)m_blue << " Alpha: " << (int)m_alpha << std::endl;
  }
private:
  std::uint8_t m_red;
  std::uint8_t m_green;
  std::uint8_t m_blue;
  std::uint8_t m_alpha;
};