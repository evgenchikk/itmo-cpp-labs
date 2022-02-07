#include <iostream>
#include "2.hpp"

int main() {
  Complex c1(15, 10);
  Complex c2(20, 20);
  Complex c3 = c1 * c2;
  c3.print();
  return 0;
}
