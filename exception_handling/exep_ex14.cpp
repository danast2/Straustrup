//проверка спецификации исключений
#include <exception>
#include <memory>

int f() throw(std::bad_alloc);

int func() { //error отсутствует спецификация исключений
    //...
}

/*Виртуальная функция может замещаться функцией с не менее ограничительной
спецификацией исключений. Например:*/

class B{
public:
    virtual void foo(); //может генерировать любые исключения
    virtual void g(X, Y);
    virtual void h(X);
};

class D: public B{
    virtual void foo(X); //ок
    virtual void g(X); //ок
    virtual void h(X, Y); //error: D::h() менее ограничителен, чем B::h()
};