#include <fstream>

void use_file_0(const char* fn){
    FILE* f = fopen(fn, "r");
    //используем f;
    fclose(f);
}

//1 попытка сделать ф-цию use_file устойчивой к исключениям:

void use_file_1(const char* fn){
    FILE *f = fopen(fn, "r");
    try {
        //используем fn
    }catch (...){
        fclose(f);
        throw ;
    }
    fclose(f);
}