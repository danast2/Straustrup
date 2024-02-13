//квалифицированные имена

#include "nae_ex1.cpp"

double  Parser::term(bool get){
    double left = prim(get);

    for (;;) {
        switch (Lexer::curr_tok) { //нужна квалификация Lexer
            case Lexer::MUL:
                left*=prim(true);
                //......
        }
    }
}