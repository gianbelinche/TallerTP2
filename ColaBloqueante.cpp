#include "ColaBloqueante.h"
#include <thread>
#include <unistd.h>

class ColaEstaCerradaException : public std::exception {
public:
    const char* what() {
        return "La cola esta cerrada";
    }    
};

ColaBloqueante::ColaBloqueante() : esta_cerrada(false){}

void ColaBloqueante::encolar(const Recurso& recurso){
    std::unique_lock<std::mutex> lk(m);
    cola.push(recurso);
    cv.notify_all();
}

Recurso ColaBloqueante::desencolar(){
    std::unique_lock<std::mutex> lk(m);
    while (cola.empty()){
        if (esta_cerrada){
            throw ColaEstaCerradaException();
        }
        cv.wait(lk);
    }
    Recurso recurso = cola.front();
    cola.pop();
    return recurso;
}

void ColaBloqueante::cerrar(){
    std::unique_lock<std::mutex> lk(m);
    esta_cerrada = true;
    cv.notify_all();
}

ColaBloqueante::~ColaBloqueante() {};

/*
class ThreadProv{
    private:
    ColaBloqueante& cola;
    Recurso& recurso;
    public:
        ThreadProv(ColaBloqueante&& cola, Recurso&& recurso) : cola(cola), recurso(recurso) {}
        void operator()(){
            cola.encolar(recurso);
        }
};

int main(){
    ColaBloqueante cola;
    Recurso trigo(1);
    Recurso madera(2);
    ThreadProv t1(std::move(cola),std::move(trigo));
    ThreadProv t2(std::move(cola),std::move(madera));
    std::thread thr1(t1);
    std::thread thr2(t2);
    thr1.join();
    thr2.join();
    Recurso trigo2 = cola.desencolar();
    Recurso madera2 = cola.desencolar();
    
    trigo2.imprimir();
    madera2.imprimir();
    return 0;
}
*/
