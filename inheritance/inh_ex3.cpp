#include "string"
#include "iostream"
#include "list"

class Employee{
    std::string first_name, second_name;
    short department;
public:
    Employee(const std::string& n, int d);
    //.....
};

class Manager:public Employee{
    std::list<Employee* > group;
    short level;
    //......
public:
    //аргументы для конструктора базового класса
    // указываются в аргументах конструктора производного класса
    Manager(const std::string &n, int d, int lvl);
    //.......
};

//базовый класс функционирует в точности как член производного класса

Employee::Employee(const std::string &n, int d):second_name(n), department(d) //инициализация класса Employee
{
    //...
}

Manager::Manager(const std::string &n, int d, int lvl): Employee(n , d), level (lvl)
{
    //.....
}

//ошибка, конструктор производного класса
// может задавать инициализаторы только для своих членов и
// непосредственных базовых классов

/*
 Manager::Manager(const std::string &n, int d, int lvl): second_name(n), department(d), level(lvl)
{
///.............
}
 */