#include <iostream>
#include <math.h>
#include "2.hpp"

using namespace std;

Complex::Complex() {
  re = 0;
  im = 0;
}

Complex::Complex(double re_) {
  re = re_;
  im = 0;
}

Complex::Complex(const Complex &c) {
  re = c.re;
  im = c.im;
}

Complex::Complex(double re_, double im_) {
  re = re_;
  im = im_;
}

double Complex::getLen() {
  return sqrt(re * re + im * im);
}

void Complex::print() {
  cout << re << " " << im << "*i" << endl;
}

Complex& Complex::operator* (double a) {
  re *= a;
  return *this;
}

Complex& Complex::operator* (Complex c) {
  re = re * c.re - im * c.im;
  im = re * c.im + c.re * im;
  return *this;
}

Complex& Complex::operator+ (Complex c) {
  re += c.re;
  im += c.im;
  return *this;
}


