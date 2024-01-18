#include <string>

struct cache {
  bool valid_cache;
  std::string rep;
};

class Date {
  cache *c; // инициализация конструктором
  void compute_cache_value() const; // заполнение кэша
  ///....
private:
  std::string str_repres() const; // строковое представление
};

std::string Date::str_repres() const {
  if (!c->valid_cache) {
    compute_cache_value();
    c->valid_cache = true;
  }
  return c->rep;
}

int main() { return 0; }
