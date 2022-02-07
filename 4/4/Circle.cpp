#include <iostream>
#include <cmath>
#include "4.hpp"

Circle::Circle()
: Center({0, 0})
, Radius(0)
, Mass(0)
, Position({0, 0})
{}

Circle::Circle(double r)
: Radius(r)
, Center({0, 0})
, Mass(0)
, Position({0,0})
{}

Circle::Circle(CVector2D c, double r)
: Center({c.x, c.y})
, Radius(r)
, Position({c.x, c.y})
, Mass(0)
{}

Circle::Circle(CVector2D c, double r, double mass)
: Center({c.x, c.y})
, Radius(r)
, Position({c.x, c.y})
, Mass(mass)
{}

Circle::Circle(const Circle& c)
: Center(c.Center)
, Radius(c.Radius)
, Position(c.Position)
, Mass(c.Mass)
{}

double Circle::square() {
  return Radius * Radius * M_PI;
}

double Circle::perimeter() {
  return 2 * M_PI * Radius;
}

double Circle::mass() {
  return Mass;
}

CVector2D Circle::position() {
  return Position;
}

bool Circle::operator==(IPhysObject& ob) {
  return mass() == ob.mass();
}

bool Circle::operator< (IPhysObject& ob) {
  return mass() < ob.mass();
}

void Circle::draw() {
  std::cout << "Center = (" << Center.x << ", " << Center.y << ")" << std::endl;
  std::cout << "Radius = " << Radius << std::endl;
  std::cout << "Mass = " << mass() << std::endl;
  std::cout << "Center mass = (" << Position.x << ", " << Position.y << ")" << std::endl;
  std::cout << "Class name - " << classname() << std::endl;
  std::cout << "Size - " << size() << std::endl;
  std::cout << "\n";
}

void Circle::initFromDialog() {
  std::cout << "Input center: ";
  std::cin >> Center.x >> Center.y;
  Position = Center;
  std::cout << "Input radius: ";
  std::cin >> Radius;
  std::cout << "Input mass: ";
  std::cin >> Mass;
  std::cout << "\n\n";
}

const char* Circle::classname() {
  return "Circle";
}

unsigned int Circle::size() {
  return sizeof(*this);
}
