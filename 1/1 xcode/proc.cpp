#include "proc.h"

void Swap_ptr(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Swap_ref(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void FloatToInt_ptr(double *a)
{
    *a = (int)*a;
}

void FloatToInt_ref(double &a)
{
  a = (int)a;
}

void ComplMulNum_ptr(Compl *c, double a)
{
  c->re *= a;
  c->im *= a;
}

void ComplMulNum_ref(Compl &c, double a)
{
  c.re *= a;
  c.im *= a;
}

void MoveCirc_ptr(Circle *c, Vec v)
{
  c->Center.x += v.x;
  c->Center.y += v.y;
}

void MoveCirc_ref(Circle &c, Vec v)
{
  c.Center.x += v.x;
  c.Center.y += v.y;
}
