#include <iostream>
#include <cmath>
#include "4.hpp"

Triangle::Triangle()
: side(0)
, alpha(0)
, a({0, 0})
, b({0, 0})
, c({0, 0})
, Mass(0)
, Position({0, 0})
{}

Triangle::Triangle(double s)
: side(s)
, alpha(0)
, a({0, 0})
, b({s / 2, sqrt(3) / 2 * s})
, c({s, 0})
, Position({(a.x + b.x) / 2, (a.y + c.y) / 2})
, Mass(0)
{}

Triangle::Triangle(double s, CVector2D pos, double angle, double mass)
: side(s)
, alpha(angle)
, a({pos.x, pos.x})
, b({pos.x + cos(M_PI / 3 + angle) * s, pos.y + sin(M_PI / 3 + angle) * s})
, c({pos.x + cos(angle) * s, pos.y + sin(angle) * s})
, Position({(a.x + c.x) / 2, (a.y + b.y) / 2})
, Mass(mass)
{}

Triangle::Triangle(const Triangle& t)
: side(t.side)
, alpha(t.alpha)
, a(t.a)
, b(t.b)
, c(t.c)
, Position(t.Position)
, Mass(t.Mass)
{}

double Triangle::square() {
  return sqrt(3) / 4 * side * side;
}

double Triangle::perimeter() {
  return 3 * side;
}

double Triangle::mass() {
  return Mass;
}

CVector2D Triangle::position() {
  return Position;
}

bool Triangle::operator== (IPhysObject& ob) {
  return mass() == ob.mass();
}

bool Triangle::operator< (IPhysObject& ob) {
  return mass() < ob.mass();
}

void Triangle::draw() {
  std::cout << "Side = " << side << std::endl;
  std::cout << "Vertex A (" << a.x << ", " << a.y << ")" << std::endl;
  std::cout << "Vertex B (" << b.x << ", " << b.y << ")" << std::endl;
  std::cout << "Vertex C (" << c.x << ", " << c.y << ")" << std::endl;
  std::cout << "Mass = " << mass() << std::endl;
  std::cout << "Center mass = (" << Position.x << ", " << Position.y << ")" << std::endl;
  std::cout << "Class name - " << classname() << std::endl;
  std::cout << "Size - " << size() << std::endl;
  std::cout << "\n";
}

void Triangle::initFromDialog() {
  std::cout << "Input side: ";
  std::cin >> side;
  std::cout << "Input vertex position: ";
  std::cin >> a.x >> a.y;
  std::cout << "Input angle: ";
  std::cin >> alpha;
  std::cout << "Input mass: ";
  std::cin >> Mass;
  *this = Triangle(this->side, this->a, this->alpha, this->Mass);
  std::cout << "\n\n";
}

const char* Triangle::classname() {
  return "Triangle";
}

unsigned int Triangle::size() {
  return sizeof(*this);
}




