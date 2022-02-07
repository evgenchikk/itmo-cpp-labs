#include <iostream>
#include "5.hpp"

int main() {
//  int arr[] = {2, 12, 42, 1, 23, 52, 12, 34, 12, 0, 100, 25};
//  float arr2[] = {2.1, 4.3, 0.9, 0.35, 12.45, 36.6};
//
//  std::cout << max(arr, 12) << "\n";
//  std::cout << max(arr2, 6) << "\n";
  

  Stack<4, float> s;
  try {
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
//    s.push(5);
  }
  catch (my_exception& err) {
    std::cout << err.what();
  }
  
  try {
    std::cout << s.pop() << " " << s.pop() << " " << s.pop() << " " << s.pop() << " " << s.pop();
  }
  catch (my_exception& err) {
    std::cout << err.what();
  }

  return 0;
}
