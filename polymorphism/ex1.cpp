#include <iostream>

class Complex{
private:
    double re, im;
public:
    Complex(double r = 0, double i = 0):re(r), im(i){}
    Complex operator+(Complex) const;
    Complex operator*(Complex) const;
    Complex& operator+=(Complex);
    Complex& operator*=(Complex) ;
    double real()const;
    double image()const;
};

Complex Complex::operator*(Complex c) const{
    return Complex(this->re *  c.re, this->im * c.im);
}

Complex Complex::operator+(Complex c) const {
    return Complex(this->re +  c.re, this->im + c.im);
}

inline Complex& Complex::operator+=(Complex c) {
    this->re += c.re;
    this->im += c.im;
}

inline Complex& Complex::operator*=(Complex c) {
    this->re *= c.re;
    this->im *= c.im;
    return *this;
}

double Complex::real() const {
    return this->re;
}

double Complex::image() const {
    return this->im;
}

int main(){
    Complex a1(3 , 4);
    Complex a2(2 , 1);
    a1+=a2;
    return 0;
}