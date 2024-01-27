#include <iostream>
#include "ex5.cpp"

class Name{
    const char* str;
    //....
};

class Table{
    Name* p;
    size_t sz;
public:
    Table(size_t s = 15) {p = new Name[sz = s];}
    Table(const Table&); // копирующий конструктор
    Table& operator= (const Table&); //присваивание
    ~Table(){delete[] p;}

    Name* lookup(const char*);
    bool insert(Name*);
};

Table::Table(const Table &t) { // копирующий конструктор
    p = new Name[sz = t.sz];
    for (int i = 0; i < sz; i++){
        p[i] = t.p[i];
    }
}

Table& Table::operator=(const Table &t) {
    if(this!= &t){ //помним о возможности самоприсваивания t = t
        delete[] p;
        p = new Name[sz = t.sz];
        for (int i = 0; i < sz; i++){
            p[i] = t.p[i];
        }
    }
    return *this;
}

struct Tables{
    int i;
    int vi[10];
    Table t1; //при инициализации tt будет использован конструктор по умолчанию
    Table vt[10]; //при инициализации tt тоже будет использован конструктор по умолчанию
                  // для каждого объекта массива
};

Tables tt;

//так будет ошибка, так как константы и ссылки должны быть инициалзированы
//(нет конструктора по умолчанию)
/*struct X{
    const int a;
    const int& r;
};

X x;*/

//its ok!
struct Y{
    const int b = 5;
    const int& s = b;
};


struct Z{
    const int a;
    const int& r;
    Z() : a(10), r(a){
        std::cout << &a << std::endl;
        std::cout << &r << std::endl;
    }
};

Z z;

//aa, bb, (cc), dd  - конструируются в указанном порядке, а удаляются dd, (cc), bb, aa
void func(int n) {
    Table aa;
    Table bb;
    if (n > 0) {
        Table cc;
        //.....
    }
    Table dd;
    //...
}

//копирование объектов
/*void h(){
    Table t1;
    Table t2 = t1; // копирующая инициализация (проблема)

    Table t3;
    t3 = t2; // копирующее присваивание (проблема)
}*/

class Club{
    std::string name;
    Table members;
    Table officers;
    Date founded;
    //....
    Club (const std::string &n, Date fd);
};

Club::Club(const std::string &n, Date fd):name(n), founded(fd){
    //...
}

int main(){
    Table* p = new Table;
    Table* q = new Table;

    delete p;
    //delete p; двойное освобождение памяти ведет к ошибке при выполнения программы
    delete q;
    return 0;
}