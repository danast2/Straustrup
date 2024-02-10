//класс или шаблонный класс могут иметь члены, которые сами являются шаблонами.

template<class Scalar> class complex{
    Scalar re, im;
public:
    template<class T> complex(const complex<T>& c): re(c.real()), im(c.imag()){}

    Scalar real() const{
        return re;
    }
    Scalar image() const{
        return im;
    }
    //.......
};