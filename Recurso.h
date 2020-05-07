#ifndef CLASE_RECURSO
#define CLASE_RECURSO
#include <iostream>
using namespace std;

class Recurso{
private:
    int num;    
public:
    Recurso(int num) : num(num) {}
    void imprimir(){
        cout << num;
    }
    int getNum() const{
        return num;
    }

};

#endif