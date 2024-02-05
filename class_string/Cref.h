#ifndef CLASS_STRING_CREF_H
#define CLASS_STRING_CREF_H
#include "String.cpp"

class Cref{
    friend class String;
    String& s;
    int i;

    Cref(String& ss, int ii): s(ss), i(ii){}
    Cref(const Cref& r): s(r.s), i(r.i){}
    Cref(); // не определяется (не используется)
public:
    operator char() const {s.check(i); return s.read(i);} // выдает значение
    void operator=(char c) {s.write(i, c);}
};

#endif //CLASS_STRING_CREF_H
