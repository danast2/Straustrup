#include "tem_ex8.cpp"
//специализация шаблонов ф-ций

template<class T> bool less(T a, T b) {return a < b; }

template<class T> void sort(Vector<T>& v){
    const size_t n = v.size();
    for (int gap=n / 2; 0 < gap; gap /=2)
        for (int i = gap; i < n; i++)
        for (int j = i-gap; 0 <= j; j -= gap)
            if (less(v[j+gap], v [j]))
                swap(v[j], v[j+gap] );
        else
            break;
}

/*template<> bool less<const char*>(const char* a, const char* b){
    return strcmp(a, b) < 0;
}*/

/*Как и для классовых шаблонов , для функциональных шаблонов префикс
template означает специализацию, не нуждающуюся в параметрах шаблона.

Конструкция <const char*> после имени функции означает, что эта специализация
должна использоваться в случае, когда фактические параметры вызова имеют тип
const char*. Поскольку параметры функциональных шаблонов могут быть
выведены из фактических параметров вызова, нет нужды специфицировать их явно.
Поэтому мы можем упростить определение специализации:
*/

/*template<> bool less<>(const char* a, const char* b)
{
return strcmp (a, b) < 0;
}*/


template<> bool less(const char* a, const char* b)
{
return strcmp (a, b) < 0;
}

//рассмотрим очевидное определение для swap()

//Такое решение неэффективно для типа Vector, поскольку при этом будут
//копироваться все элементы векторов. Элементы х будут даже копироваться дважды.
template<class T> void swap(T& x, T& y){
    T t;
    x = y;
    y = t;
}

template<class T> void Vector<T>::swap(Vector& a) //меняемся представлениями
{
    swap (v, a.v) ;
    swap (sz, a.sz) ;
}

//Теперь эту функцию-член можно использовать в качестве альтернативы общему
// шаблону swap ():

template<class T> void swap(Vector<T>& a, Vector<T>& b){
    a.swap(b);
}