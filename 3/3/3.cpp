#include <iostream>
#include <cmath>
#include "3.hpp"

using namespace std;

Point::Point(double x_, double y_)
: x(x_)
, y(y_)
{}

Point::Point(const Point& p_)
: x(p_.x)
, y(p_.y)
{}

Point::Point() {}

void Point::operator= (Point p_) {
  x = p_.x;
  y = p_.y;
}

void Point::operator+ (Point p_) {
  x += p_.x;
  y += p_.y;
}

Triangle::Triangle(Point a_, Point b_, Point c_) {
  a = a_;
  b = b_;
  c = c_;
  la = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
  lb = sqrt((b.x - c.x)*(b.x - c.x) + (b.y - c.y)*(b.y - c.y));
  lc = sqrt((c.x - a.x)*(c.x - a.x) + (c.y - a.y)*(c.y - a.y));
}

Triangle::Triangle(const Triangle& t_)
: a(t_.a)
, b(t_.b)
, c(t_.c)
, la(t_.la)
, lb(t_.lb)
, lc(t_.lc)
{}

void Triangle::check() {
  cout << a.x << " " << a.y << endl;
  cout << b.x << " " << b.y << endl;
  cout << c.x << " " << c.y << endl;
  cout << la << " " << lb << " " << lc << " " << endl;
}

double Triangle::square()
{
  double s, p;
  
  p = (la + lb + lc) / 2;
  s = sqrt(p * (p - la) * (p - lb) * (p - lc));
  return s;
}

void Triangle::MoveVec(const Point& vec) {
  this->a + vec;
  this->b + vec;
  this->c + vec;
}

Triangle& Triangle::operator= (const Triangle& t_) {
  a = t_.a;
  b = t_.b;
  c = t_.c;
  la = t_.la;
  lb = t_.lb;
  lc = t_.lc;
  return *this;
}

bool Triangle::operator== (Triangle& t_) {
  return this->square() == t_.square();
}

bool Triangle::operator!= (Triangle& t_) {
  return this->square() != t_.square();
}

bool Triangle::operator> (Triangle& t_) {
  return this->square() > t_.square();
}

bool Triangle::operator< (Triangle& t_) {
  return this->square() < t_.square();
}



