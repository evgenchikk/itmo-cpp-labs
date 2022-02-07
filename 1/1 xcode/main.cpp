//VARIANT 1

#include <iostream>
#include "proc.h"

void Task1()
{
  int a, b;
  int &ref1 = a, &ref2 = b;

  std::cout << "Input a: ";
  std::cin >> a;
  std::cout << "Input b: ";
  std::cin >> b;
  std::cout << "a = " << a << std::endl << "b = " << b << std::endl;

  //Swap_ptr(&a, &b);
  Swap_ref(ref1, ref2);

  std::cout << "Result: " << std::endl << "a = " << a << std::endl << "b = " << b << std::endl;
}

void Task4()
{
  double a;
  double &ref = a;

  std::cout << "Input a: ";
  std::cin >> a;

  //FloatToInt_ptr(&a);
  FloatToInt_ref(ref);

  std::cout << "Integer part of a: " << a << std::endl;
}

void Task9()
{
  Compl c;
  double a;
  Compl &ref = c;

  std::cout << "Input real part of complex number: ";
  std::cin >> c.re;
  std::cout << "Input imaginary part of complex number: ";
  std::cin >> c.im;
  std::cout << "Input multiple number: ";
  std::cin >> a;

  //ComplMulNum_ptr(&c, a);
  ComplMulNum_ref(ref, a);

  std::cout << "Result: " << c.re << " + i*" << c.im << std::endl;
}

void Task12()
{
  Circle c;
  Vec v;
  Circle &ref = c;

  std::cout << "Input circle center: ";
  std::cin >> c.Center.x >> c.Center.y;
  std::cout << "Input vector: ";
  std::cin >> v.x >> v.y;

  //MoveCirc_ptr(&c, v);
  MoveCirc_ref(ref, v);

  std::cout << "New circle center: " << c.Center.x << ", " << c.Center.y << std::endl;
}

int main()
{
  //Task1();
  //Task4();
  //Task9();
  Task12();

  return 1;
}
