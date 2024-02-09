#include "tem_ex2.cpp"
template<class T, int max> T& lookup(Buffer<T, max>& b, const char *p);

class Record{
    const char v[12];
    //.........
};

Record& func(Buffer<Record, 128>& buff, const char *p){
    return lookup(buff, p); //вызвать lookup(), где T есть Record, а max - 128
}

//Если параметр шаблона не удается вывести из аргументов функционального вызова,
//его нужно указать явно. Это делается точно так же, как и в случае явного задания параметров для
//шаблонного класса. Например :

template <class T> class vector{/*...*/};
template <class T> T* create(); // создать T и вернуть указатель на T

void foo(){
    vector<int> v;
    int* p = create<int>();
}

/*  Типичным примером явной спецификации типа является необходимость
задания конкретного типа возвращаемого шаблонной ф-цией значения:
*/

template<class T, class U>T implict_cast(U u){return u;}

void g(int i){
    //implict_cast(i); errror невозможно вывести T 
    implict_cast<double>(i); //T есть double, U есть int (ф-ция возвращает T => происходит преобразование)
    implict_cast<char, double>(i); //T есть char, U есть double (ф-ция возвращает T => происходит преобразование)
    //implict_cast<char*, int>(i); //T есть char*, U есть int, error, невозможно привести int к char* (ф-ция возвращает T => происходит преобразование)
}