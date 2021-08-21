#include <iostream>
#include "power.h"
#include "rgba.h"
#include "stack_array.h"

int main()
{
  // ========== TASK #1 ==========
  Power p1;
  std::cout << p1.calculate() << std::endl;

  Power p2(2.0, 3.0);
  std::cout << p2.calculate() << std::endl;

  Power p3;
  p3.set(4.0, 5.0);
  std::cout << p3.calculate() << std::endl;

  // ========== TASK #2 ==========
  RGBA c1;
  c1.print();

  RGBA c2{ 12, 152, 200, 244 };
  c2.print();

  RGBA c3{ 43, 14, 111, 0 };
  c3.print();

  // ========== TASK #3 ==========
  StackArray<int, 10> stack;
  stack.reset();
  stack.print();

  stack.push(3);
  stack.push(7);
  stack.push(5);
  stack.print();

  stack.pop();
  stack.print();

  stack.pop();
  stack.pop();
  stack.print();

  return 0;
}
