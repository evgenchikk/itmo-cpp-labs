#include <iostream>
#include <vector>
#include "6.h"

int main() {
  std::vector<int> vec = {2, 4, 6, 8};
  std::cout << all_of_(vec.begin(), vec.end(), even<int>()) << "\n";

  std::vector<double> vec2 = {11.2, 23.3, 10.5, 9};
//  std::cout << is_sorted_(vec2.begin(), vec2.end(), greater<double>()) << "\n";
  std::cout << is_sorted_(vec2.begin(), vec2.end(), less<double>()) << "\n";

  std::string s = "abcdefg";
  std::cout << is_sorted_(s.begin(), s.end(), greater<char>()) << "\n";

  std::vector<int> pal = {1, 2, 3, 4, 3, 2, 1};
//  std::string pal_str = "abccba";
  std::cout << is_palindrome_(pal.begin(), pal.end(), equal<int>()) << "\n";
//  std::cout << is_palindrome_(pal_str.begin(), pal_str.end(), equal<char>()) << "\n";

  CPoint mas[] = {{1, 2}, {3, 4}, {1, 2}, {0, 0}};
  std::cout << is_palindrome_(mas, mas + 4, equal<CPoint>()) << "\n";
//  std::cout << all_of_(mas, mas + 5, even<int>()) << "\n";
  
  
  return 0;
}
