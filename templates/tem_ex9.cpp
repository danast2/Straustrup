#include "tem_ex8.cpp"
//специализация шаблонов ф-ций

template<class T> bool less(T a, T b) {return a < b; }

template<class T> void sort(Vector<T>& v){
    const size_t n = v.size();
    for (int gap=n / 2; 0 < gap; gap /=2)
        for (int i = gap; i < n; i++)
        for (int j = i-gap; 0 <= j; j -= gap)
            if (less(v[j+gap], v [j]))
                swap(v[j], v[j+gap] );
        else
            break;
}

template<> bool less<const char*>(const char* a, const char* b){
    return strcmp(a, b) < 0;
}