template<class T>
struct token {
  token<T>* prev;
  token<T>* next;
  T value;
  bool end__ = false;

  token()
  : prev(nullptr)
  , next(nullptr)
  , value(0)
  , end__(false)
  {}
  
  token(T& val)
  : prev(nullptr)
  , next(nullptr)
  , value(val)
  , end__(false)
  {}
  
  token(const token<T>& other)
  : prev(other.prev)
  , next(other.next)
  , value(other.value)
  , end__(other.end__)
  {}
  
  token<T>& operator= (token<T>& other) {
    token<T>* tmp = this;
    this = new token<T>;
    prev = other.prev;
    next = other.next;
    value = other.value;
    end__ = other.end__;
    
    delete tmp;
    return *this;
  }
  
  T& operator= (T& val) {
    return value = val;
  }
  
  std::ostream& operator<< (std::ostream& stream) {
    stream << this->value;
    return stream;
  }
};


template<class T>
class buffer_iterator {
private:
  T* ptr_;
  
public:
  buffer_iterator() = delete;
  
  buffer_iterator(token<T>* el)
  : ptr_(el)
  {}
  
  buffer_iterator(T* ptr)
  : ptr_(ptr)
  {}
  
  buffer_iterator(const buffer_iterator<T>& other)
  : ptr_(other.ptr_)
  {}
  
  
  T& operator* () const {
    return *ptr_;
  }
  
  buffer_iterator<T>& operator= (T* tok) {
    return ptr_ = tok;
  }
  
  bool operator!= (T* tok) const {
    return ptr_ != tok;
  }
  
  buffer_iterator<T>& operator= (buffer_iterator<T>& other) {
    ptr_ = other.ptr_;
    return *this;
  }
  
  buffer_iterator<T>& operator++ () { //prefix ++
    ++ptr_;
    return *this;
  }
  buffer_iterator<T>& operator-- () { //prefix --
    --ptr_;
    return *this;
  }
  
  buffer_iterator<T>& operator++ (int) { //postfix ++
    buffer_iterator<T>& old(*this);
    ++ptr_;
    return old;
  }
  buffer_iterator<T>& operator-- (int) { //postfix --
    buffer_iterator<T>& old(*this);
    --ptr_;
    return old;
  }
  
  buffer_iterator<T>& operator+ (int val) {
    ptr_ += val;
    return *this;
  }
  buffer_iterator<T>& operator- (int val) {
    ptr_ -= val;
    return *this;
  }
  
  bool operator== (buffer_iterator<T>& other) {
    return ptr_ == other.ptr_;
  }
  bool operator!= (buffer_iterator<T>& other) {
    return ptr_ != other.ptr_;
  }
  bool operator== (T& other) {
    return ptr_->value == other.value_;
  }
  bool operator!= (T& other) {
    return ptr_->value != other.value;
  }
};



template<class T>
class circular_buffer {
public:
  typedef buffer_iterator<token<T>> iterator;
  
private:
//  token<T> el_;
  token<T>* start_;
  token<T>* end_;
  size_t size_;
  size_t capacity_;
  bool empty_ = true;
  
public:
  token<T>* begin() {
    return start_;
  }
  token<T>* end() {
    return end_;
  }
  
  circular_buffer(size_t size)
  : size_(size)
  {
    capacity_ = size * 2;
//    start_ = new token<T>[capacity_];
    start_ = end_ = nullptr;
//    end_->end__ = true;
//    token<T>* tmp = start_;
//    while (!tmp->end__) {
//      tmp->next = (tmp + 1);
//      ++tmp;
//    }
//    tmp->next = start_;
//    start_->prev = tmp;
  }
  
  circular_buffer(size_t size, T val)
  : size_(size)
  , empty_(false)
  {
    capacity_ = size * 2;
    start_ = new token<T>[capacity_];
    end_ = start_ + size;
    end_->end__ = true;
    token<T>* tmp = start_;
    while (!tmp->end__) {
      tmp->next = (tmp + 1);
      ++tmp;
    }
    tmp->next = start_;
    start_->prev = tmp;
    
    for (iterator it = begin(); it != end(); ++it) 
      *it = val;
  }
  
  circular_buffer(const circular_buffer<T>& other)
  : size_(other.size_)
  , capacity_(other.capacity_)
  , empty_(other.empty_)
  {
    start_ = new token<T>[other.capacity_];
    end_ = start_ + size_;
    end_->end__ = true;
    
    iterator it_other(other.start_);
    for (iterator it = start_; it != end_; ++it) {
      *it = *it_other;
      ++it_other;
    }
  }
  
//  ~circular_buffer() {
//    token<T>* p = begin();
//    token<T>* n = p;
//    while (!n->end__) {
//      n = p->next;
//      delete p;
//    }
//    delete n;
//  }
  
  size_t size() const {
    return size_;
  }
  size_t capacity() const {
    return capacity_;
  }
  
  bool is_empty() {
    return empty_;
  }
  
  void push_back(T& val) {
    token<T> tok(val);
    token<T>* t = &tok;
    
    if (is_empty()) {
      start_ = end_ = t;
      t->end__ = true;
      empty_ = false;
    }
    else {
      token<T>* tmp = end();
      tmp->end__ = false;
      tmp->next = t;
      t->prev = tmp;
      t->end__ = true;
    }
  }
};


