#include <map>
#include <iostream>
template <class C> class String{
    struct Srep;
    Srep* rep;
public:
    String();
    String(const C*);
    String(const String &);
    C read(int i) const;
    //..........
};

/*
    Префикс template<class C> указывает, что объявляется шаблон, и что
идентификатор С является параметром типа. В теле определения шаблона С используется
точно так же, как и другие имена типов. Область видимости С простирается до
конца определения шаблона. Обратите внимание на то, что template<class C> означает,
что С — это любой тип, не обязательно класс.
В соответствии с определением шаблона его имя с последующим конкретным
типом, заключенным в угловые скобки, является именем класса и его можно
использовать так же, как имя любого другого класса. Например:
 */

String<char> cs;
String<unsigned char> us;
String<wchar_t> ws;

class Jchar{
    //япоские символы
};

String<Jchar> js;

int main(){
    //String<char> buf;
    //std::map<String<char>, int> m;
    /*while (std::cin>>buf){
        m[buf]++;
        //вывод результата
    }*/

    //String<char> buf;
    //std::map<String<Jchar>, int> m;
    /*while (std::cin>>buf){
        m[buf]++;
        //вывод результата
    }*/

    typedef std::basic_string<char> string;

    string buf;
    std::map<string, int> m;
    while (std::cin >> buf){
        m[buf]++;
    }
    return 0 ;
}