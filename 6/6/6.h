class CPoint {
private:
  double x, y;
public:
  CPoint(double a, double b)
  : x(a)
  , y(b)
  {}
  CPoint(const CPoint& p)
  : x(p.x)
  , y(p.y)
  {}
  bool operator== (CPoint& p) {
    if ((x == p.x) && (y == p.y))
      return true;
    return false;
  }
  CPoint operator* () {
    return *this;
  }
  void print() {
    std::cout << x << " " << y << "\n";
  }
};

template<class T>
class even {
public:
  bool operator() (T a) {
    return  (a % 2 == 0) ? true : false;
  }
};

template<class T>
class greater {
public:
  bool operator() (T a, T b) {
    return a <= b;
  }
};

template<class T>
class less {
public:
  bool operator() (T a, T b) {
    return a >= b;
  }
};

template<class T>
class equal {
public:
  bool operator() (T a, T b) {
    return a == b;
  }
};

template<class Iterator, class Compare>
bool all_of_(Iterator first, Iterator last, Compare comp) {
  for (Iterator it = first; it != last; ++it)
    if (!comp(*first))
      return false;
  return true;
}

template<class Iterator, class Compare>
bool is_sorted_(Iterator first, Iterator last, Compare comp) {
  for (Iterator it = first; it != last - 1; ++it)
    if (!comp(*it, *(it + 1)))
      return false;
  return true;
}

template<class Iterator, class Compare>
bool is_palindrome_(Iterator first, Iterator last, Compare comp) {
  long delta = last - first;
  
  last -= 1;
  for (long i = 0; i < delta; ++i) {
    if (!comp(*first, *last))
        return false;
    ++first;
    --last;
  }
  return true;
}
