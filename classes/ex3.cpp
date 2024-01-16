// объявление mutable
#include <iostream>
#include <string>

class Date {
  mutable bool cache_valid;
  mutable std::string cache;
  void compute_cache_value() const; // заполнить кещ
  //...
public:
  //...
  std::string string_rep() const; // строковое представление
};

std::string Date::string_rep() const {
  if (!cache_valid) {
    compute_cache_value();
    cache_valid = true;
  }
  return cache;
}

void Date::compute_cache_value() const { cache = "filled cache"; }

int main() {
  Date d3;
  // const Date d4;
  std::string s3 = d3.string_rep();
  std::cout << s3;
  // std::string s4 = d4.string_rep(); // правильно!
  return 0;
}
