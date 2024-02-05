#include "string"
#include "iostream"

class Employee_0{
    std::string first_name, second_name;
    char middle_initial;
    //.......
public:
    void print() const;
    std::string full_name() const{
        return first_name+ ' ' + middle_initial+ ' ' + second_name;
    }
};

class Manager_0:public Employee_0{
    //...
public:
    void print () const;
    //......
};

void Manager_0::print() const {
    std::cout << "name is " << full_name() << '\n';
    //......
}


//закрытые члены базового класса напрямую не доступны в производном классе
/*
void Manager::print() const {
    std::cout << "name is " << second_name << '\n'; //error!!!
}
*/


//чтобы получить доступ, нужно использовать ключевое слово protected
class Employee_1{
protected:
    std::string first_name, second_name;
    char middle_initial;
    //.......
public:
    void print() const;
    std::string full_name() const{
        return first_name+ ' ' + middle_initial+ ' ' + second_name;
    }
};

class Manager_1:public Employee_1{
    //...
public:
    void print () const;
    //......
};

/*void Manager_1::print() const {
    std::cout << "name is " << second_name << '\n'; } все ок!*/

void Manager_1::print() const {
    Employee_1::print(); // обязательно использование Employee_1::
    print(); // печатает только то, что было определено в классе Manager(порождается рекурсия)
}