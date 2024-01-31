#include <iostream>

class Tiny{
    char v;
    void assign(int i){if(i& ~ 077) throw Bad_range(); v=i;}
public:
    class Bad_range {};
    Tiny(int i) { assign(i);}
    Tiny& operator=(int i) { assign(i); return *this;}
    operator int() const {return v;} //операция приведения к типу int
};

int main(){
    return 0;
}