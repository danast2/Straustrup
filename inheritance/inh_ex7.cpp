#include <string>
#include <list>
#include <iostream>

class Employee{
    std::string first_name, second_name;

    short department;
    //........
public:
    Employee(const std::string & name, int dept);
    /*
     * ключевое слово virtual указывает на то, что ф-ция print() символизирует общий
     * интерфейс к набору одноименных ф-ций, определенных в базовом и производных от него классах.
     * Если такие ф-ции действительно определены в производных классах,
     * компилятор гарантирует вызов своего варианта ф-ции print()
     * для каждого объекта классовой иерархии
     */
    //типы аргументов всех ф-ций должны быть одинаковыми,
    // а для возвращаемого значения допускаются лишь незначительные отличия
    virtual void print() const;
    //......
};


//виртуальная ф-ция обязана быть определена в классе,
//в котором она впервые объявляется (за исключение ф-ций чисто виртуальных ф-ций)
void Employee::print() const {
    std::cout << second_name<<'\t' << department;
}

/*
    Разумеется, виртуальную функцию можно использовать и в случаях, когда
у класса отсутствуют производные классы. Производный класс, который не
нуждается в собственном варианте функции, не обязан замещать виртуальную
функцию, определенную в базовом классе. Определяя производный класс,
определите и новый вариант виртуальной функции, если он, конечно, нужен.
Например:
*/

class  Manager: public Employee{
    std::list<Employee* > emp_group;
    short level;
    //.....
public:
    Manager(const std::string & name, int dept, int lvl);
    void print()const;
    //.....
};

void Manager::print() const {
    Employee::print();

    std::cout << "\tlevel" << level << '\n';
    //.........
}

/*
    Функция производного класса, имеющая то же имя и те же параметры, что
и виртуальная функция, определенная в базовом классе, замещает (override)
вариант от базового класса. За исключением случаев прямых указаний на конкретный
вариант используемой виртуальной функции (например, Employee: : print()),
выбирается замещаемая для класса объекта функция.
Теперь отпадает нужда в глобальной функции print employee () (§12.2.5),
поскольку ее место занято функциями-членами print {). Список сотрудников теперь
выводится следующим образом:
 */

void print_list(const std::list<Employee*>& s){
    for(std::list<Employee*>::const_iterator  p = s.begin(); p!= s.end(); ++p){
        (*p)->print();
    }
}

//или еще проще:
void print_list_simp(const std::list<Employee*> & s){
    std::for_each(s.begin(), s.end(), std::mem_fun(&Employee::print));
};

int main(){
    Employee e("Brown", 1234);
    Manager m("Smith", 1234, 5);
    std::list<Employee* > empl;
    empl.push_front(&e);
    empl.push_front(&m);
    print_list(empl);
    return 0;
}
