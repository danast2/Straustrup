#include <iostream>

class String{
    struct Srep; // представление
    Srep* rep;
    class Cref; // ссылка на char
public:
    class Range{}; // для исключений
    String();
    String(const char*);
    String(const String&);
    String operator=(const char*);
    String & operator=(const String&);
    ~String();
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
private://предотврашение копирования
    Srep(const Srep&);
    Srep& operator=(const Srep&);
};

String::String()
{
    rep = new Srep(0, "");
}

String::String(const String& x) {
    x.rep->n++;
    rep = x.rep; //разделяемое представление
}

String::~String(){
    if(--rep->n == 0) delete rep;
};

String& String::operator=(const String& x) {
    x.rep->n++; // защита от st = st
    if(--rep->n==0) delete rep;
    rep = x.rep; //разделяемое представление
    return *this;
}

String::String(const char * s) {
    rep = new Srep(strlen(s), s);
}


//todo
String& String::operator=(const char * s) {
    if(rep->n == 1){
        rep->assign(strlen(s),s); //используем старый Srep
    } else{
        rep->n--;
        rep = new Srep(strlen(s), s); // используем новый Srep
    }
    return *this;
}





int main(){
    return 0;
}
