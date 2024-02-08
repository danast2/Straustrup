#include "tem_ex1.cpp"
//шаблоны могут иметь как параметры обычных фиксированных типов(int), так и шаблонных типов (один шаблон может иметь несколько параметров)
template<class T, T def_val> class Cont{/**/};


/*  Простые, ограниченные контейнеры, вроде Buffer, полезны в задачах,
требующих высочайшей эффективности и компактности кода (так что там не подходят
универсальные контейнеры типа string и vector). Передача размера в виде аргумента
шаблона Buffer позволяет избежать затратных операций динамического выделения
свободной памяти.*/
template<class T, int max> class Buffer{
    T v[max];
public:
    Buffer();
    //........
};

Buffer<char, 128> cbuf;
Buffer<int, 5000> ibuf;
//Buffer<Record, 8> rbuf;

//эквивалентность типов

String<char> s1;
String<unsigned char> s2;
String<int> s3;

typedef unsigned char Uchar;
String<Uchar> s4;
String<char> s5;

Buffer<String<char>, 10> b1;
Buffer<char, 10> b2;
Buffer<char, 20 - 10> b3;

/*
    Предоставляя один и тот же набор аргументов шаблона, мы имеем дело с одним
и тем же сгенерированным типом. Но что в данном контексте означает «один и тот
же»? Так как typedef не создает нового типа, то String<Uchar> есть то же самое, что
и String<unsigned char>. И наоборот, так как char и unsigned char суть разные типы
(§4.3), то и типы String<char> и String<unsigned char> тоже разные.
Компилятор может вычислять константные выражения, поэтому тип Buffer<char, 20-10> эквивалентен типу Buffer<char, 10>.
 */