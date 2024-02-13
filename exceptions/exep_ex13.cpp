//спецификация исключений
#include <exception>

void func(int a) throw(x2, x3){
    //нечто
}

//эквивалентен

void foo(){
    try{
        //нечто
    }catch (x2) {throw; }
    catch (x3){throw;}
    catch (...) {std::unexpected();} //unexpected() не возвращает управление
}