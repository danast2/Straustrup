//как определить истинный (производный) тип объекта,
//адресуемого указателем типа Base*(т.е. указателем на базовый класс ?)
//решения проблемы:
/*
 * 1) гарантировать, что адресуются лишь объекты единственного типа
 *
 * 2) поместить специальное поле типа в базовый класс, чтобы ф-ции могли его проверять
 *
 * 3) использовать dynamic_cast
 *
 * 4) использовать виртуальные ф-ции
 */

//решение основанное на полях типа (его лучше избегать)

#include "string"
#include "list"
#include "iostream"

struct Employee{
    enum Empl_type{M, E};
    Empl_type type;

    Employee():type(E){}
    std::string first_name, second_name;
    char middle_initial;

    short department;
    //........
};

struct Manager: public Employee{
    Manager(){type=M;}

    std::list<Employee* > emp_group;
    short level;
    //.....
};

void print_employee(const Employee* e){
    switch (e->type) {
        case Employee::E:
        {
            std::cout << e->second_name << '\t' << e->department << '\n';
            //.....
            break;
        }
        case Employee::M:
        {
            std::cout << e->second_name << '\t' << e->department << '\n';
            //....
            const Manager* p = static_cast<const Manager*>(e);
            std::cout << "level" << p->level << '\n';
            //......
            break;
        }
    }
}

//функция для вывода элементов списка:

void print_list(const std::list<Employee*>& elist){
    for (std::list<Employee* >::const_iterator p = elist.begin(); p != elist.end(); p++){
        print_employee(*p);
    }
}

//пердставленное решение имеет фундаментальную слабость,
// так как зависит от манипуляций с типами, которые не контролируются компилятором

//становится еще хуже, если ф-ции вроде print_employee()
//пытаются извлечь пользу от общности типов:

void print_employee_new(const Employee* e){
    std::cout << e->second_name << '\t' << e->department << '\n';
    //.....
    if(e->type == Employee::M){
        const Manager* p = static_cast<const Manager* >(e);
        std::cout << "level" << p->level << '\n';
        //.......
    }
}

//техника применения полей типа
// способствует ошибкам и усложняет сопровождение