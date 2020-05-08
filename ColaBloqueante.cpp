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

ColaBloqueante::~ColaBloqueante() {}

/*
class ThreadProv{
    private:
    ColaBloqueante& cola;
    public:
        ThreadProv(ColaBloqueante&& cola) : cola(cola) {}
        void operator()(){
            cola.desencolar();
        }
};

int main(){
    ColaBloqueante cola;
    Recurso trigo(1);
    Recurso madera(2);
    cola.encolar(trigo);
    cola.encolar(madera);
    ThreadProv t1(std::move(cola));
    ThreadProv t2(std::move(cola));
    std::thread thr1(t1);
    std::thread thr2(t2);
    thr1.join();
    thr2.join();
    std::cout << "\n";
    return 0;
}
*/


