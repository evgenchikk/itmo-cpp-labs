#include <iostream>
#include "3.hpp"

using namespace std;

Triangle CreateTr() {
  Point a, b, c;
  
  cout << "Input (x, y) for a: ";
  cin >> a.x >> a.y;
  cout << "Input (x, y) for b: ";
  cin >> b.x >> b.y;
  cout << "Input (x, y) for c: ";
  cin >> c.x >> c.y;
  
  Triangle t(a, b, c);
  return t;
}

int main() {
  Triangle T1 = CreateTr();
  Triangle T2 = CreateTr();
  
  cout << T1.square() << " " << T2.square() << endl;
  cout << (T1 > T2) << endl;
  
  return 0;
}

