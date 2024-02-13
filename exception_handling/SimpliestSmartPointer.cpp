#include <iostream>
template<class T> class SmartPointer{
private:
    T* p;
public:
    SmartPointer(T* ptr):p(ptr){}
    SmartPointer(T ptr):p(&ptr){}
    ~SmartPointer(){delete p;}
    T& get_pointer()const{ return *(p); }
};

int main(){
    int y = 5;
    //лучше не передавать что-то не полученное при динамическом выделении памяти
    //SmartPointer<int> z  =  (&y);
    //std::cout << z.get_pointer() << std::endl;
    SmartPointer<int> x = new int(5);
    std::cout << x.get_pointer();
    return 0;
}