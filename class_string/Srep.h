#ifndef CLASS_STRING_SREP_H
#define CLASS_STRING_SREP_H

#include <iostream>
struct Srep{
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
private://предотвращение копирования
    Srep(const Srep&);
    Srep& operator=(const Srep&);
};

#endif //CLASS_STRING_SREP_H
