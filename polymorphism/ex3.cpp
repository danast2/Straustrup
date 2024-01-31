#include <iostream>

class Matrix;
class Vector{
    float v[4];
    //.....
    friend Vector operator*(const Matrix& , const Vector&);
};

class Matrix{
    Vector v[4];
    //........
    friend Vector operator*(const Matrix& , const Vector&);
};

Vector operator*(const Matrix& m, const Vector& v){
    Vector r;
    for (int i = 0; i < 4 ; i++){
        r.v[i] == 0;
        for (int j = 0; j < 4; j++){
            r.v[i] += m.v[i].v[j] * v.v[j];
        }
    }
    return r;
}


int main(){
    return 0;
}