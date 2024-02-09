#include <string>
//пользовательские специализации (или просто специализации)
template<class T> class Vector{ //general vector type
    T* v;
    int sz;
public:
    Vector();
    explicit Vector(int);

    T& elem(int i ) {return v[i];}
    T& operator[](int i);
    void swap(Vector&);
    //..
};



Vector<int> vi;
Vector<std::string> vs;
Vector<char*> vpc;



/*  Все контейнеры указателей могут
разделить единственную специальную реализацию, называемую специализацией
(specialization). Определяем специфическую версию (специализацию) шаблона Vector
для указателей на void:*/
template<> class Vector<void*>
{
    //Vector(int ii){}
    void** p;
    //.....
    void* & operator [ ] (int i) ;
};
/*Эта специализация может затем использоваться как общая реализация для всех
векторов указателей.
Префикс template<> говорит о том, что определяется специализация, не
 нуждающаяся в параметрах шаблона. Аргументы шаблона, для которых эта специализация
должна использоваться, указываются в угловых скобках после имени. Таким
образом, <void*> означает, что данное определение должно использоваться в качестве
реализации для всех Vector, у которых T есть void*.*/


//Определение Vector<void*> называется полной специализацией (complete
//specialization), поскольку параметры шаблона отсутствуют. Оно используется в клиентском
//коде следующим образом:
Vector<void* > vpv;



/*Для того чтобы определить специализацию, которую можно использовать для
любого вектора указателей (и только для векторов указателей), требуется частичная
специализация (partial specialization):
 */

template<class T> class Vector<T*> :private Vector<void*>{
public:
public:
    typedef Vector<void*> Base;
    Vector () { }
    explicit Vector (int i) : Base (i) { } // чтобы Base заработало, нужно определить конструктор для Vector<void*>

    T*& elem (int i) {return reinterpret_cast<T* &>(Base::elem (i) ) ; }
    T* & operator [ ] (int i) {return reinterpret_cast<T* &> (Base:: operator [ ] (i));}
//...
};

/*Паттерн (схема, форма) специализации (specialization pattern) в виде <Т*> после
имени означает, что специализация используется для любого типа указателей; то
есть это определение используется всегда, когда указывается аргумент шаблона
в виде Т*. Например:
Vector<Shape*> vps; // <T*> есть <Shape*>, так что Т есть Shape
Vector<int**> vppi; // <T*> есть <int**>, так что Т есть int**/