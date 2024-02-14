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


double Parser::prim(bool get) {
    // использовать get token из Lexer
    // использовать currtok из Lexer
    // использовать error из Error
    //using Lexer::get_token;
    //using Lexer::curr_tok;
    //using Error::error;
    if (get) get_token();
    switch (curr_tok){
        case Lexer::NUMBER:
            get_token();
            return Lexer::number_value;
        case Lexer::NAME: {
            double v = table[Lexer::string_value]
            if (get_token() == Lexer::ASSIGN) v = expr(true);
            return v;
        }
        case Lexer::MINUS:
            return -prim(true);
        case Lexer::LP: {
            double e = expr(true);
            if (curr_tok != Lexer::RP)  throw error(") expected"); // пропустить скобку ')'
            get_token();
            return e;
        }
        case Lexer::END:
            return 1;
        default:
            throw error("asd");
    }

}

double Parser::term(bool get) {
    double left = prim(get);

    for (;;) {
        switch (curr_tok) {
            case Lexer::MUL:
                left*= prim(true);
                break;
            case Lexer::DIV:
                if(double d = prim(true)){
                    left /= d;
                    break;
                }
                throw error("divide by 0");
            default:
                return left;
        }
    }
}