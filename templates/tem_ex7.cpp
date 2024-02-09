#include <string>
#include "../class_string/String.cpp"
//рассмотрим обобщение стандартной библиотечной функции strcmp () для строк

/*template<class T, class C>
int compare (const String<T>& str1, const String<T>& str2) {
    for (int i = 0; i < str1.length() & &i < str2.length(); i++)
        if (!C::eq(str1[i], str2[i])) return C::lt(str1[i], str2[i]) ? -1 : 1;
    return str1.length() - str2.length();
}*/

template<class T> class Cmp{ //(обычное сравнение по умолчанию)
public:
    static int eq(T a, T b) {return a == b;}
    static int lt(T a, T b) {return a < b;}
};

class Literature{ //сравнение ?? имен по литературным правилам
public:
    static int eq(char a, char b){return a == b;}
    static int lt(char, char);
};



