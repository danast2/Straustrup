#include <iostream>

//cerr - s a standard output stream for errors. This object is declared in the <iostream> header file.
// It is basically used to print some information or error on the console.
class Mather{
    //.....
public:
    virtual void debug_print()const{ std::cerr << "Math error";}
};

class Overflow: public Mather{};
class Underflow: public Mather{};
class Zerodivide: public Mather{};


class Int_overflow:public Mather{
    const char* op;
    int a1, a2;
public:
    Int_overflow(const char* p, int a, int b):op(p), a1(a), a2(b){}
    virtual void debug_print()const {std::cerr << op << " (" << a1 << ", " << a2 << ") ";}
    //.....
};

void g ()
{
    try{
        //..........
    }
    catch (Overflow) {/*...*/}
    catch (Underflow) {/*...*/}
    catch (Zerodivide) {/*...*/}
}


void func(){
    try{
        g();
    }catch (Mather m){
        //.........
    }
}

/*Когда вызывается обработчик для Mather, m является объектом типа Mather —
даже если функция g () во время своей работы сгенерировала исключение типа
Int overflow. Это означает, что добавочная информация, сопутствующая типу
Intoverflow, недоступна !*/

//можно использовать указатели и ссылки во избежание потери информации, например:

int add(int x, int y){
    if ((x > 0 && y > 0 && x > INT64_MAX - y) || (x < 0 && y < 0 && x < INT64_MIN - y)){
        throw Int_overflow("+", x, y);
    }
    return x + y; // вычисление не вызовет исключений
}

void f(){
    try {
        int i1 = add(1 , 2);
        int i2 = add(INT64_MAX , -2);
        int i3 = add(INT64_MAX , 2); //приехали
    }
    catch (Mather& m){
        //..........
        m.debug_print();
    }
}