#include <iostream>
#include <algorithm>
#include <vector>
#include "4.hpp"

bool CompareByMass(Figure* f1, Figure* f2) {
  return f1->mass() < f2->mass();
}

int main() {
  std::vector<Figure*> figures;
  bool flag = true;

  int i = 0;
  while (flag) {
    std::cout << "Menu:\n"
    "0 - exit\n"
    "1 - new figure\n"
    "2 - draw all\n"
    "3 - square of all\n"
    "4 - perimeter of all\n"
    "5 - center mass\n"
    "6 - size of all\n"
    "7 - sort by mass\n"
    "Your choice: ";

    int ch;
    double SumSquare = 0, SumPerimeter = 0, SumMass = 0, SumMemory = 0;
    CVector2D CenterMass = {0, 0};
    std::cin >> ch;
    switch (ch) {
      case 0:
        flag = false;
        break;
      case 1:
        int fig;
        std::cout << "1 - circle\n"
        "2 - trianlge\n";
        std::cin >> fig;
        if (fig == 1)
          figures.push_back(new Circle);
        else if (fig == 2)
          figures.push_back(new Triangle);
        else
          std::cout << "\nIncorrect choice!\n\n";
        figures[i]->initFromDialog();
        ++i;
        break;
      case 2:
        std::cout << "\n";
        for (int j = 0; j < i; ++j)
          figures[j]->draw();
        break;
      case 3:
        for (int j = 0; j < i; ++j)
          SumSquare += figures[j]->square();
        std::cout << "\nSquare of all figures is " << SumSquare << "\n\n";
        break;
      case 4:
        for (int j = 0; j < i; ++j)
          SumPerimeter += figures[j]->perimeter();
        std::cout << "\nPerimeter of all figures is " << SumPerimeter << "\n\n";
        break;
      case 5:
        for (int j = 0; j < i; ++j) {
          CenterMass.x += figures[j]->position().x * figures[j]->mass();
          CenterMass.y += figures[j]->position().y * figures[j]->mass();
          SumMass += figures[j]->mass();
        }
        std::cout << "\nCenter mass of all figures is (" << CenterMass.x / SumMass << ", "
                  << CenterMass.y / SumMass << ")\n\n";
        break;
      case 6:
        for (int j = 0; j < i; ++j) {
          SumMemory += figures[j]->size();
        }
        std::cout << "\nSize of all is " << SumMemory << "\n\n";
        break;
      case 7:
        std::sort(figures.begin(), figures.end(), CompareByMass);
        for (int j = 0; j < i; ++j)
          std::cout << figures[j]->mass() << " ";
        std::cout << "\n\n";
        break;
      default:
        std::cout << "\nIncorrect choice!\n\n";
        break;
    }
  }

  return 0;
}




