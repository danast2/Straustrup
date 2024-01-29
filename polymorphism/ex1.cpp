#include <iostream>

class Complex{
private:
    double re, im;
public:
    Complex(double r, double i):re(r), im(i){}
    Complex operator+(Complex);
    Complex operator*(Complex);
};

Complex Complex::operator*(Complex) {
    return Complex(0, 0);
}

Complex Complex::operator+(Complex) {
    return Complex(0, 0);
}

int main(){
    return 0;
}