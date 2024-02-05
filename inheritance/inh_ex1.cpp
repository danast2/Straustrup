#include <iostream>
#include <string>
#include <list>
#include <set>

struct Employee{
    std::string first_name, second_name;
    char middle_initial;
    short departament;
    //..........
};

struct Manager: public Employee{
    std::set<Employee* > group;
    short level;
    //.......
};


void func(Manager m1, Employee e1){
    std::list<Employee* > elist;

    elist.push_front(&m1);
    elist.push_front(&e1);
    //........
}

void foo(Manager mm, Employee ee){
    Employee* pe = &mm; // ок, каждый Manager есть Employee
    //Manager* pm = &ee; error, не каждый Employee есть Manager

    //pm->level = 2; нельзя, у объекта ee нет поля level

    //pm = static_cast<Manager*>(pe); работает, тк pe указывает на mm
    //pm->level = 2; ок pm указывает на mm, у которого есть level
}

/*struct Manager{
    Employee emp; // общие сведения о менеджере (как о сотруднике)
    std::list<Employee* > group; // подчинение
    short level;
    //...........
};*/

int main(){
    return 0;
}