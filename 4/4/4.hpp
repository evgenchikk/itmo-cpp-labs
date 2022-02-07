class IGeoFig {
public:
  virtual double square() = 0;
  virtual double perimeter() = 0;
};

class CVector2D {
public:
  double x, y;
};

class IPhysObject {
public:
  virtual double mass() = 0;
  virtual CVector2D position() = 0;
  virtual bool operator== (IPhysObject& ob ) = 0;
  virtual bool operator< (IPhysObject& ob ) = 0;
};

class IPrintable {
public:
  virtual void draw() = 0;
};

class IDialogInitiable {
public:
  virtual void initFromDialog() = 0;
};

class BaseCObject {
public:
  virtual const char* classname() = 0;
  virtual unsigned int size() = 0;
};

class Figure: public IGeoFig, public IPhysObject, public IPrintable, public IDialogInitiable, public BaseCObject {
};

class Circle: public Figure {
private:
  double Radius;
  CVector2D Center;
  double Mass;
  CVector2D Position;
public:
  Circle();
  Circle(double r);
  Circle(CVector2D c, double r);
  Circle(CVector2D c, double r, double mass);
  Circle(const Circle& c);

  double square();
  double perimeter();
  double mass();
  CVector2D position();
  bool operator== (IPhysObject& ob);
  bool operator< (IPhysObject& ob);
  void draw();
  void initFromDialog();
  const char* classname();
  unsigned int size();
};

class Triangle: public Figure {
private:
  double side;
  double alpha;
  CVector2D a, b, c;
  double Mass;
  CVector2D Position;
public:
  Triangle();
  Triangle(double s);
  Triangle(double s, CVector2D pos, double angle, double mass);
  Triangle(const Triangle& t);

  double square();
  double perimeter();
  double mass();
  CVector2D position();
  bool operator== (IPhysObject& ob);
  bool operator< (IPhysObject& ob);
  void draw();
  void initFromDialog();
  const char* classname();
  unsigned int size();
};
