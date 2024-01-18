#include <iostream>
#include <string>
class Date {
public:
  enum Month { jan = 1, feb, mar, apr, may, jun, ju, aug, sep, oct, nov, dec };
  class Bad_date {}; // класс исключений
  Date(int dd = 0, Month mm = Month(0), int yy = 0);

  int day() const;
  Month month() const;
  int year() const;
  std::string string_rep() const; // string представление
  void char_rep(char s[]) const; // представление С строкой

  static void set_default(int, Month, int);

  Date &add_year(int n);
  Date &add_month(int n);
  Date &add_day(int n);

private:
  int d, m, y;
  static Date default_date;
};

int main() { return 0; }
