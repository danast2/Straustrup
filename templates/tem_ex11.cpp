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
complex<int> ci = cq; //error, тк нет приведения   Quad к int
