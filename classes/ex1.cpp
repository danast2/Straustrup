// ссылка на себя

class Date {
private:
  int d, m, y;
  // ....
public:
  Date &add_year(int n);
  Date &add_month(int n);
  Date &add_day(int n);
};

Date &Date::add_year(int n) {
  if (d = 29 && m == 2) {
    d = 1;
    m = 3;
  }
  y += n;
  return *this;
}

void some_func(Date &d) {
  //....
  d.add_day(1).add_month(1).add_year(1);
  // ...
}
