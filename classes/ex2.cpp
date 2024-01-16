// физическое и логисеское постоянство
//
// кэш можно использовать по-разному: в зависимости от того, что было передано в
// конструктор или от некоторого внутреннего поведения класса (счетчики и тд)
#include <iostream>
#include <string>
class Date {
  bool cache_valid;
  std::string cache;
  void compute_cache_value();
  //...
public:
  //....
  std::string string_rep() const; // строковое представление
};

std::string Date::string_rep() const {
  if (cache_valid == false) {
    Date *th = const_cast<Date *>(this); // снимаем const приведением типа
    th->compute_cache_value();
    th->cache_valid = true;
  }
  return cache;
}

void Date::compute_cache_value() { cache = "filled the cache"; }

int main() {
  Date d1;
  // const Date d2;
  std::string s1 = d1.string_rep();
  // std::string s2 = d2.string_rep(); // UB!
  std::cout << s1;
  return 0;
}
