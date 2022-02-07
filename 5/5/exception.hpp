class my_exception: public std::exception {
private:
  const char* error;
public:
  my_exception();
  my_exception(const char* error_)
  : error(error_)
  {}
  const char* what() const noexcept {
    return error;
  }
};
