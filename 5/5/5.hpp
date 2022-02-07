#include "exception.hpp"

template<class T>
T& max(T* arr, std::size_t size) {
  T& res = *arr;
  for (int i = 0; i < size; ++i)
    if (arr[i] > res)
      res = arr[i];
  return res;
}

//template<class T>
//T max(T* first, T* last) {
//  T res = *first;
//  for (; *first != *last; ++first)
//    if (*first > res)
//      res = *first;
//  return res;
//}

template<int N = 16, class T = int>
class Stack {
private:
  int cur = 0;
  T *st = new T[N];
public:
  void push(const T& val) {
    if (cur < N) {
      st[cur] = val;
      ++cur;
    }
    else
      throw my_exception("Stack overflow\n");
  }
  
  T& pop() {
    if (cur == 0)
      throw my_exception("Stack is empty\n");
    --cur;
    return st[cur];
  }
  
  ~Stack() {
    delete[] st;
  }
};



