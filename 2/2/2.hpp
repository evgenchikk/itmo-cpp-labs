class Complex {
private:
  double re, im;
public:
  Complex();
  Complex(double re_);
  Complex(const Complex &c);
  Complex(double re_, double im_);
  
  double getLen();
  void print();
  Complex& operator* (double a);
  Complex& operator* (Complex c);
  Complex& operator+ (Complex c);
};


