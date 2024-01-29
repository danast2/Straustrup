#include <iostream>

class Complex{
private:
    double re, im;
public:
    Complex(double r, double i):re(r), im(i){}
    Complex operator+(Complex) const;
    Complex operator*(Complex) const;
};

Complex Complex::operator*(Complex c) const{
    return Complex(this->re *  c.re, this->im * c.im);
}

Complex Complex::operator+(Complex c) const {
    return Complex(this->re +  c.re, this->im + c.im);
}

int main(){
    return 0;
}