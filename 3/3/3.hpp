#define max_size 100

class Point
{
public:
  double x, y;
  Point(double x_, double y_);
  Point(const Point& p_);
  Point();
  void operator= (Point p_);
  void operator+ (Point p_);
};

class Triangle
{
private:
  Point a, b, c;
  double la, lb, lc;
public:
  Triangle(Point a, Point b, Point c);
  Triangle(const Triangle& t_);
  void check();
  double square();
  void MoveVec(const Point& vec);
  Triangle& operator= (const Triangle& t_);
  bool operator> (Triangle& t_);
  bool operator< (Triangle& t_);
  bool operator== (Triangle& t_);
  bool operator!= (Triangle& t_);
};



