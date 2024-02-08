#include <vector>
#include <string>


template<class T> void sort(std::vector<T>&);

/*
    Когда шаблонная функция вызывается, типы фактических аргументов вызова
определяют, какая конкретная версия функционального шаблона используется —
аргументы шаблона выводятся {deduced) из типов аргументов функционального
вызова
 */
void func(std::vector<int>& vi, std::vector<std::string>& vs){
    sort(vi); //sort(std::vector<int>&)
    sort(vs); //sort(std::vector<std::string>&)
}

//swap вручную:
/*template<class T> void sort(std::vector<T>& v){
    //Shell sort
    const size_t n = v.size();
    for (int gap  = n/2; 0 < gap ; gap /=2 ) {
        for (int i = gap; i < n; i++) {
            for (int j = i - gap; 0 <= j; j-= gap) {
                if (v[j + gap] < v[j]){ //swap v[j] and v[j+gap]
                    T temp = v[j];
                    v[j] = v[j+gap];
                    v[j+gap] = temp;
                } else{
                    break;
                }
            }
        }
    }
}*/


//swap from std

template<class T> void sort(std::vector<T>& v){
    //Shell sort
    const size_t n = v.size();
    for (int gap  = n/2; 0 < gap ; gap /=2 ) {
        for (int i = gap; i < n; i++) {
            for (int j = i - gap; 0 <= j; j -= gap) {
                if (v[j + gap] < v[j]) { //swap v[j] and v[j+gap]
                    std::swap(v[j], v[j+gap]);
                } else {
                    break;
                }
            }
        }
    }
}
