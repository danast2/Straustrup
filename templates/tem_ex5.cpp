#include "tem_ex2.cpp"
template<class T, int max> T& lookup(Buffer<T, max>& b, const char *p);

class Record{
    const char v[12];
    //.........
};

Record& func(Buffer<Record, 128>& buff, const char *p){
    return lookup(buff, p); //вызвать lookup(), где T есть Record, а i - 128
}