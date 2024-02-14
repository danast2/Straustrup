/*Концепция исключений (exceptions) введена в язык для генерации сообщений об
ошибках. Например:*/
#include <limits>
#include <iostream>

struct Range_error{
    int i;
    Range_error(int ii) {i = ii;}
};

char to_char(int i)
{
    if(i < std::numeric_limits<char>::min() || std::numeric_limits<char>::max() < i){
        throw Range_error(i);
    }
    return char(i);
}

void g(int i){
    try{
        char c = to_char(i);
        //....
    }catch (Range_error){
        std::cerr << "oops\n";
    }
}

//или, если нужно узнать значение, то:

void h(int i){
    try{
        char c = to_char(i);
        //....
    }catch (Range_error x){
        std::cerr << "oops\t" << x.i;
    }
}