#include <iostream>
//#include <istream>
//#include <ostream>
#include <string>
#include <vector>

class Date {
public:
  enum Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
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

Date Date::default_date(22, jan, 1901);

// просто пример реализации
bool midnigth() {
  // сюда передается время, если 00:00 => true, иначе => false
  return true;
}

void func(Date &d) {
  Date lvb_day = Date(16, Date::dec, d.year());
  if (d.day() == 29 && d.month() == Date::feb) {
    //.......
  }
  if (midnigth())
    d.add_day(1);
  std::cout << "day after: " << d.day() << '\n';
}

//Функции поддержки (helper functions)
/*int diff(Date a, Date b); //кол-во дней между a и b
//int lepyaer(int y);
Date next_weekday(Date d);
Date next_saturday(Date d);*/

//мы бы могли установить явно связь функций поддержки и класса  Date
/*namespace Chrono{
    class Date {................};
    int diff(Date a, Date b); //кол-во дней между a и b
    int lepyaer(int y);
    Date next_weekday(Date d);
    Date next_saturday(Date d);
}*/

int leapyaer(int &yy) {
  // тут функция проверяет год, если високосный, то => return 1, если нет, то
  // return 0
  return 1;
}

Date::Date(int dd, Month mm, int yy) {
  if (yy == 0)
    yy = default_date.year();
  if (mm == 0) {
    mm = default_date.month();
  }
  if (dd == 0) {
    dd = default_date.day();
  }
  int max;
  switch (mm) {
  case feb:
    max = 28 + leapyaer(yy);
    break;
  case apr:
  case jun:
  case sep:
  case nov:
    max = 30;
    break;
  case jan:
  case mar:
  case may:
  case jul:
  case aug:
  case oct:
  case dec:
    max = 31;
    break;
  default:
    throw Bad_date(); // выдаем ошибку
  }
  if (dd < 1 || max < dd)
    throw Bad_date();
  y = yy;
  m = mm;
  d = dd;
}

void fill(std::vector<Date>& a){
  while (std::cin) {
    Date d;
    try {
      //std::cin >> d; // предполагается, что >> уже переопределана
    } catch (Date::Bad_date) { // обработка ошибки
      continue;
    }
    a.push_back(d);
  }
}

inline int Date::day() const {
    return d;
}


Date& Date::add_month(int n) {
    if (n == 0){return *this;}
    if (n > 0){
        int delta_y = n / 12;
        int mm = m + n % 12;
        if (12 < mm){ // int(dec) == 12;
            delta_y++;
            mm-=12;
            //работа со случаями, когда день d не существует для класса Month
            y += delta_y;
            m = Month(mm);
            return *this;
        }
        //отрицательное n
        return *this;
    }
}

//перегруженные операции
inline bool operator==(Date a, Date b){ // проверка на равенство
    return a.day() == b.day() && a.month() == b.month() && a.year() == b.year();
}

bool operator !=(Date, Date); // не равно
bool operator<(Date, Date);
bool operator<(Date, Date);
//......
Date& operator++(Date & d){// увеличить на 1 день
    d.add_day(1);
    return d;
}

Date& operator--(Date & d); //уменьшить на 1 день

Date& operator+=(Date & d, int n); //увеличить на n
Date& operator-=(Date & d, int n); //уменьшить на n

Date& operator+(Date & d, int n); //прибавить n  дней
Date& operator-(Date & d, int n); //уменьшить n дней

//(ostream&, Date d); // вывести d
//istream & operator>> (istream&, Date D); //считатб d

//int main() { return 0; }
