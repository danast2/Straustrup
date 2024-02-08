#include <iostream>

template<class T> class List{
    struct Link{
        Link* pre;
        Link* suc;
        T val;
        Link(Link* p, Link* s, const T& v): pre(p), suc(s), val(v){}
    };
    Link* head;
public:
    /*
        В определении шаблона можно обнаружить ошибки, не
    связанные непосредственно с возможными конкретными значениями аргументов шаблона.
    Например:
     */

    //Link():head(7){} error: указатель инициализируется типом int
    //List (const T& t) : head new (Link (0,o,t)) {} // error: неопределенный идентификатор 'о'
    //....................
    void print_all()const {
        for (Link* p = head; p ; p=p->suc) {
            std::cout << p->val << '\n';
        }
    }
};


//Ошибки, имеющие отношение к использованию конкретных значений параметров шаблонов, нельзя обнаружить
// до момента конкретизации шаблона. Например:

//class Rec{/**/};

//перегрузил <<, чтобы не было ошибки
class Rec{
    int some_field;
public:
    Rec():some_field(5){}
    friend std::ostream& operator<<(std::ostream &os, const  Rec& r);
};

std::ostream& operator<<(std::ostream &os, const  Rec& r){
    std::cout << r.some_field;
    return os;
}




void func(const List<int>& li, const List<Rec>& lr){
    li.print_all(); //вполне корректно, так как передается int
    lr.print_all(); //порождает сообщение об ошибке использовании типа, так как операция вывода << не определена
    // для типа Rec
}

int main(){
    Rec r;
    std::cout << r;
    return 0;
}