//перехват любых исключений

void m (){
    try{
        //smth
    }catch (...){ // обработка любых исключений
        //обработка (очистка)
        throw ;
    }
}

/*То есть если основная часть функции т () сгенерирует любое исключение, в
обработчике будут выполнены необходимые при этом завершающие действия (очистка)*/