#ifndef INC_1_PROC_H
#define INC_1_PROC_H

#endif //INC_1_PROC_H

struct Compl
{
  double re, im;
};

struct Vec
{
  double x, y;
};

struct Circle
{
  Vec Center;
  double Rad;
};

void Swap_ptr(int *a, int *b);
void Swap_ref(int &a, int &b);

void FloatToInt_ptr(double *a);
void FloatToInt_ref(double &a);

void ComplMulNum_ptr(Compl *c, double a);
void ComplMulNum_ref(Compl &c, double a);

void MoveCirc_ptr(Circle *c, Vec v);
void MoveCirc_ref(Circle &c, Vec v);
