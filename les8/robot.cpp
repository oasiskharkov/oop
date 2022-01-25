#include "robot.h"
#include "utils.h"

OffTheField::OffTheField(const int x, const int y) :
   m_x{x},
   m_y{y},
   m_error{std::string("\nRobot coordinates are out of field: x=") + std::to_string(x) + ", y=" + std::to_string(y)}
{

}

const char* OffTheField::what() const
{
   return m_error.c_str();
}

IllegalCommand::IllegalCommand(char key) :
m_error {std::string("\nIllegal command, pressed key '") + key + "'"}
{}

const char* IllegalCommand::what() const
{
   return m_error.c_str();
}

void Up::move(Robot& r) const
{
   int x = r.getX();
   int y = r.getY() - 1;
   r.setXY(x, y);
}

void Down::move(Robot& r) const
{
   int x = r.getX();
   int y = r.getY() + 1;
   r.setXY(x, y);
}

void Left::move(Robot& r) const
{
   int x = r.getX() - 1;
   int y = r.getY();
   r.setXY(x, y);
}

void Right::move(Robot& r) const
{
   int x = r.getX() + 1;
   int y = r.getY();
   r.setXY(x, y);
}

Robot::Robot(int x, int y) :
   m_x{x},
   m_y{y}
{
   if (x < 1 or x > size or y < 1 or y > size)
   {
      throw OffTheField(x, y);
   }
   memset(m_field, 'O', size * size);
   m_field[y - 1][x - 1] = 'X';
   m_dirs.emplace('d', std::make_unique<Right>());
   m_dirs.emplace('a', std::make_unique<Left>());
   m_dirs.emplace('w', std::make_unique<Up>());
   m_dirs.emplace('s', std::make_unique<Down>());
}

void Robot::move(char key)
{
   if (m_dirs.find(key) == m_dirs.end())
   {
      throw IllegalCommand(key);
   }
   m_dirs.at(key)->move(*this);
}

void Robot::draw() const
{
   Utils::clearScreen();
   for(size_t i = 0; i < size; ++i)
   {
      for (size_t j = 0; j < size; ++j)
      {
         std::cout << m_field[i][j] << ' ';
      }
      std::cout << std::endl;
   }
}

void Robot::setXY(int x, int y)
{
   if (x < 1 or x > size or y < 1 or y > size)
   {
      throw OffTheField(x, y);
   }
   m_field[m_y - 1][m_x - 1] = 'O';
   m_x = x;
   m_y = y;
   m_field[m_y - 1][m_x - 1] = 'X';
}

int Robot::getX() const
{
   return m_x;
}

int Robot::getY() const
{
   return m_y;
}
