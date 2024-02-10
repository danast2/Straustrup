#include <cstdio> //для size_t
//наследование и шаблоны

/*Если члены базового класса должны соответствовать тому же параметру, что и члены производного класса,
 * то имя базового класса следует соответственно параметризировать. Например: */

template<class T> class vector{/*.......*/};
template<class T> class Vec: public vector<T> {/*.......*/};


/*Случай, когда производный и базовый классы имеют один и тот же параметр
шаблона, является наиболее распространенным, но это не обязательное
требование. В редких и интересных случаях в качестве параметра базового класса
указывается сам производный класс. Например:*/

template<class C> class Basic_ops{ //базовые операции над контейнерами
public:
    bool operator==(const C&)const; //сравнивает все элементы
    bool operator!=(const C&)const;
    //........
    //доступ к операциям типа С:
    const C& derived() const {return static_cast<const C&>(*this);}
};

template<class T> class Math_container: public Basic_ops<Math_container<T> >{
public:
    size_t size () const;
    T& operator[] (size_t);
    //........
};
/*Это позволяет один раз определить базовые операции над контейнерами и
отделить их от определений самих контейнеров. В то же время, поскольку определение
операций вроде == и != должно выражаться в терминах и контейнера, и его
элементов, то тип элементов должен передаваться шаблону контейнера.*/

template<class C> bool Basic_ops<C>::operator==(const C & a) const {
    if (derived().size() != a.size()){
        return false;
    }
    for(int i = 0; i < derived().size(); ++i){
        if(derived()[i] != a[i]){
            return false;
        }
    }
    return true;
}

//Другой техникой разделения контейнеров и операций является их комбинирование
// через параметры шаблонов (а не использование наследования)

template<class T, class C> class Mcontainer{
    C elements;
public:
    T& operator[](size_t i) {return elements;}

    //friend bool operator==<>(const Mcontainer&, const Mcontainer&);
    //friend bool operator!=<>(const Mcontainer&, const Mcontainer&);
    //..............
};

template <class T> class My_array{/*........*/};
Mcontainer<double, My_array<double> > me;

//Класс, генерируемый из шаблона класса, является обычным классом. Следовательно, он может иметь дружественные ф-ции.
