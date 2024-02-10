//класс или шаблонный класс могут иметь члены, которые сами являются шаблонами.

template<class Scalar> class complex{
    Scalar re, im;
public:
    template<class T> complex(const complex<T>& c): re(c.real()), im(c.image()){}
    complex(Scalar rr, Scalar ii): re(rr), im(ii){}
    complex(){}
    Scalar real() const{
        return re;
    }
    Scalar image() const{
        return im;
    }
    //.......
};

complex<float> cf(0,0);
complex<double> cd = cf; //ок, используется приведенеи float к double

class Quad{
    //отсутствует приведение к int
};

complex<Quad> cq;
//complex<int> ci = cq; //error, тк нет приведения   Quad к int


/*К сожалению, C++ допускает некоторые неразумные операции преобразования
        встроенных типов, такие как double в int. Сопутствующие проблемы потери
        точности можно обнаружить во время выполнения с помощью проверяемых
преобразований в стиле implicit_cast и функции checked()*/

template<class Scalar> class new_complex{
    Scalar re, im;
public:
    new_complex():re(0), im(0){}
    new_complex(const new_complex<Scalar>& c):re(checked_cast<Scalar> (c. real ())) , im (checked_cast<Scalar> (c. imag () ) ) { }
};


//Шаблонная функция-член не может быть виртуальной. Например:
class Shape
{
    //template<class T> virtual boot_intersect {const T&) const=0; //error: virtual template
    };