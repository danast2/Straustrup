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

/*По счастью, имеется очевидное решение. Все контейнеры указателей могут
разделить единственную специальную реализацию, называемую специализацией
(specialization). Определяем специфическую версию (специализацию) шаблона Vector
для указателей на void:*/
template<> class Vector<void*>
{
    void** p;
    //.....
    void* & operator [ ] (int i) ;
};
/*Эта специализация может затем использоваться как общая реализация для всех
векторов указателей.
Префикс template<> говорит о том, что определяется специализация, не нуждающаяся в параметрах шаблона*/

Vector<int> vi;
Vector<std::string> vs;
Vector<char*> vpc;