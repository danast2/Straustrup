#include <iostream>

class String{
    struct Srep; // представление
    Srep* rep;
    class Cref; // ссылка на char
public:
    class Range{}; // для исключений
};

struct String::Srep{
    char *s;
    int sz;
    int n;
    Srep(int nsz, const char * p){
        n = 1;
        sz = nsz;
        s = new char [sz + 1]; // + 0 в конце
        strcpy(s, p);
    }
    ~Srep(){delete[] s;}
    Srep* get_own_copy(){
        if(n == 1) return this;
        n--;
        return new Srep(sz, s);
    }
    void assign(int nsz, const char * p){
        if(sz!=nsz){
            delete [] s;
            sz = nsz;
            s = new char[sz +1];
        }
        strcpy(s, p);
    }
};



int main(){
    return 0;
}
