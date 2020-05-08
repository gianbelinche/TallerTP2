#include "ColaBloqueante.h"
#include <unistd.h>

class ColaEstaCerradaException : public std::exception {
public:
    const char* what() {
        return "La cola esta cerrada";
    }    
};

ColaBloqueante::ColaBloqueante() : esta_cerrada(false){}

void ColaBloqueante::encolar(const Recurso* recurso){
    std::unique_lock<std::mutex> lk(m);
    cola.push(recurso);
    cv.notify_all();
}

const Recurso* ColaBloqueante::desencolar(){
    std::unique_lock<std::mutex> lk(m);
    while (cola.empty()){
        if (esta_cerrada){
            throw ColaEstaCerradaException();
        }
        cv.wait(lk);
    }
    const Recurso* recurso = cola.front();
    cola.pop();
    return recurso;
}

void ColaBloqueante::cerrar(){
    std::unique_lock<std::mutex> lk(m);
    esta_cerrada = true;
    cv.notify_all();
}

ColaBloqueante::~ColaBloqueante() {}

