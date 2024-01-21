#include <iostream>

class Name{
    const char* s;
    //....
};

class Table{
    Name* p;
    size_t sz;
public:
    Table(size_t s = 15){
        p = new Name[sz = s];
    }
    ~Table(){delete[] p;}

    Name* lookup(const char*);
    bool insert(Name*);
};

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
void func(int n){
    Table aa;
    Table bb;
    if(n > 0){
        Table cc;
        //.....
    }
    Table dd;
    //...
}

int main(){

    return 0;
}