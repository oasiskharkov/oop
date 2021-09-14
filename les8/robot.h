#pragma once

#include <exception>
#include <string>
#include <map>
#include <memory>
#include <iostream>

namespace
{
   constexpr int size = 10;
}

class OffTheField : public std::exception
{
public:
   OffTheField(const int x, const int y);
   const char* what() const override;
private:
   int m_x;
   int m_y;
   std::string m_error;
};

class IllegalCommand : public std::exception
{
public:
   IllegalCommand(const int x, const int y);
   const char* what() const override;
private:
   int m_x;
   int m_y;
   std::string m_error;
};

class Robot;

class IMovable
{
public:
   virtual void move(Robot& r) const = 0;
};

class Up : public IMovable
{
public:
   void move(Robot& r) const override;
};

class Down : public IMovable
{
public:
   void move(Robot& r) const override;
};

class Left : public IMovable
{
public:
   void move(Robot& r) const override;
};

class Right : public IMovable
{
public:
   void move(Robot& r) const override;
};

class Robot
{
public:
   Robot(int x, int y);
   void move(int x, int y);
   void draw() const;
   void setXY(int x_dir, int y_dir);
   int getX() const;
   int getY() const;
private:
   int m_x;
   int m_y;
   std::map<std::pair<int, int>, std::unique_ptr<IMovable>> m_dirs;
   char m_field[size][size];
};
