template <class T> T max(T,T);
const int s = 7;

void k(){
    max(1, 2);
    max('a', 'b');
    max(2.7, 4.9);
    max(s, 7);

    //max('a', 1); //error: ambiguous (нет стандартного преобразования)
    //max(2.7, 4); //error: (нет стандартного преобразования)
}


//Здесь две неоднозначности можно разрешить либо явной квалификацией вызова
void f(){
    max<int>('a', 1); //max(int(int('a')), 1)
    max<double>(2.7, 4); //max<double>()
}
//либо дабавлением подходящих определений "разрешающий ф-ций"
inline int max(int i, int j){return max<int>(i, j);}
inline double max(int i, double d){return max<double>(i, d);}
inline double max(double d, int i){return max<double>(d, i);}
inline double max(double d1, double d2){return max<double>(d1,d2);}

void g(){
    max('a', 1); //max(int('a'), 1)
    max(2.7, 4); //max(2.7, 4)
}