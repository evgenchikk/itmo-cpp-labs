#include <iostream>
#include "buffer.hpp"

int main() {
  circular_buffer<int> buf1(10);

  int a = 4;
  
  buf1.push_back(a);
  
  circular_buffer<int>::iterator i = buf1.begin();
  std::cout << (*i).value;
  
  return 0;
}
