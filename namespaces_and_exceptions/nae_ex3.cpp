#include "nae_ex1.cpp"


/*Когда имя часто используется вне пределов своего пространства имен, может
быть утомительно то и дело дополнительно квалифицировать его. Рассмотрим
следующий пример:*/
/*double Parser::prim(bool get){
    if(get){Lexer::get_token();}

    switch (Lexer::curr_tok) {
        case Lexer::NUMBER: //константа с плавающей запятой
            Lexer::get_token();
            return Lexer::number_value;
        case Lexer::NAME:
        {
            double & v = table[Lexer::string_value];
            if (Lexer::get_token() == Lexer::ASSIGN){
                v = expr(true);
            }
            return v;
        }
        case Lexer::MINUS: //унарный минус
            return -prim(true);
        case Lexer::LP:
        {
            double e = expr(true);
            if(Lexer::curr_tok!= Lexer::RP){
                return Error::error(") expected");
            }
            Lexer::get_token(); //пропустить скобку ')'
            return e;
        }case Lexer::END:
            return 1;
        default:
            return Error::error("primary expected");
    }
}*/


double Parser::print (bool get){

} //обработка первичных выражений
    using Lexer::get_token ;
using Lexer: : currtok;
using Error: : error;
if {get) getjoken () ;
switch {currtok)
// использовать get token из Lexer
// использовать currtok из Lexer
// использовать error из Error
case Lexer: : NUMBER:
gettoken () ;
return Lexer: -.number value;
case Lexer: : NAME:
{
// константа с плавающей запятой
doubled v = table [Lexer:
ifigettoken () == Lexer:
return v;
} ^
case Lexer: : MINUS:
return -prim (true) ;
case Lexer: : LP:
{
: stringvalue] ;
.ASSIGN) v = expr(true)
//унарный минус
double e=expr (true) ;
if(curr_tok ! = Lexer: :RP) return error(") expected") ;
gettoken () ; // пропустить скобку ')'
return e;
}
:END:
case Lexer:
return 1;
default:
return error ("primary expected"
}
}