//Исключения, не являющиеся ошибками

//можно рассматривать механизм обработки исключений как еще одну управляющую структуру.
//Например:

void func(Queue <X> &q) {
    try {
        for (;;) {
            X m = q.get();
        }
    } catch (Queue<X>::Empty) {
        return;
    }
}

/*В этом примере есть свое очарование, ибо это как раз тот случай, когда
невозможно определенным образом сказать, что тут ошибка, а что нет.*/

void fnd(Tree *p, const strings s) {
    if (s == p->str) throw p; //s найдено
    if (p->left) fnd(p->left, s);
    if (p->right) fnd(p->right, s);
}

Tree *find(Tree *p, const string& s) {
    try {
        fnd(p, s);
    }catch (Tree * q) // q->str==s
        {
            return q;
        }
        return 0;
    }
}