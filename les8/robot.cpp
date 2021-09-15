#include "robot.h"
#include "utils.h"

OffTheField::OffTheField(const int x, const int y) :
   m_x{x},
   m_y{y},
   m_error{std::string("Robot coordinates are out of field: x=") + std::to_string(x) + ", y=" + std::to_string(y)}
{

}

const char* OffTheField::what() const
{
   return m_error.c_str();
}

IllegalCommand::IllegalCommand(const int x, const int y) :
   m_x{x},
   m_y{y},
   m_error{std::string("Illegal robot direction: x=") + std::to_string(x) + ", y=" + std::to_string(y)}
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
   m_dirs.emplace(std::pair<int, int>(1, 0), std::make_unique<Right>());
   m_dirs.emplace(std::pair<int, int>(-1, 0), std::make_unique<Left>());
   m_dirs.emplace(std::pair<int, int>(0, -1), std::make_unique<Up>());
   m_dirs.emplace(std::pair<int, int>(0, 1), std::make_unique<Down>());
}

void Robot::move(int x_dir, int y_dir)
{
   if (m_dirs.find(std::pair<int, int>(x_dir, y_dir)) == m_dirs.end())
   {
      throw IllegalCommand(x_dir, y_dir);
   }
   m_dirs.at(std::pair<int, int>(x_dir, y_dir))->move(*this);
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
