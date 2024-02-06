#include "string"
#include "list"
#include "iostream"

class Employee{
    std::string first_name, second_name;
    short department;
public:
    Employee& operator=(const Employee&);
    Employee(const Employee&);
    Employee(const std::string& n, int d);
    //.....
};

class Manager:public Employee{
    std::list<Employee* > emp_group;
    short level;
    //......
public:
    Manager(const std::string &n, int d, int lvl);
    //.......
};
//производный класс тоже можеть быть базовым классом
class Director: public Manager{
    std::list<Manager* > man_group;
    int stake_in_the_company;
    //.........
public:
    Director(const std::string &n, int d, int lvl, int sitc);
};

//такой набор связанных классов традиционно называют
// классовой иерархией наследования или просто классовой иерархией (class hierarchy)

// она может иметь структуру графа

class Temporary{/**/};
class Secretary : public Employee{/**/};
class Tsec:public Temporary, public Secretary{/**/};
class Consultant: public Temporary, public Manager{/**/};
