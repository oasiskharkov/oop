#pragma once

#include <string>
#include <iostream>

class Car
{
public:
   Car(std::string&& company, std::string&& model) :
      m_company{ std::move(company) },
      m_model{ std::move(model) }
   {
      std::cout << "Car ctor" << std::endl;
   }
   virtual ~Car()
   {
      std::cout << "Car dtor" << std::endl;
   }
   std::string getName() const;
private:
   std::string m_company;
   std::string m_model;
};

inline std::string Car::getName() const
{
   return m_company + ' ' + m_model;
}

class Bus : virtual public Car
{
public:
   Bus(std::string&& company, std::string&& model) :
      Car{ std::move(company), std::move(model) }
   {
      std::cout << "Bus ctor" << std::endl;
   }
   virtual ~Bus()
   {
      std::cout << "Bus dtor" << std::endl;
   }
};

class PassengerCar : virtual public Car
{
public:
   PassengerCar(std::string&& company, std::string&& model) :
      Car{ std::move(company), std::move(model) }
   {
      std::cout << "PassengerCar ctor" << std::endl;
   }
   virtual ~PassengerCar()
   {
      std::cout << "PassengerCar dtor" << std::endl;
   }
};

class Minivan final : public Bus, public PassengerCar
{
public:
   Minivan(std::string&& company, std::string&& model) :
      Car{ std::move(company), std::move(model) },
      Bus{ std::move(company), std::move(model) },
      PassengerCar{ std::move(company), std::move(model) }
   {
      std::cout << "Minivan ctor" << std::endl;
   }
   virtual ~Minivan()
   {
      std::cout << "Minivan dtor" << std::endl;
   }
};