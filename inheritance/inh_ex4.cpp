#include "string"
#include "list"
#include "iostream"


class Employee{
    std::string first_name, second_name;
    short department;
public:
    //если самому не писать оперцию присваивания, то
    //компилятор предоставляет собственный вариант этой операции
    Employee& operator=(const Employee&);
    Employee(const Employee&);
    Employee(const std::string& n, int d);
    //.....
};

class Manager:public Employee{
    std::list<Employee* > group;
    short level;
    //......
public:
    Manager(const std::string &n, int d, int lvl);
    //.......
};

void func(const Manager& m){
    Employee e = m; // конструируем е из Employee-части m
    e = m; // присваиваем Employee-часть m объекту е
}

//операции присваивания не наследуются!
//Конструкторы тоже никогда не наследуются!