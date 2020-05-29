#include "ColaBloqueante.h"
#include <unistd.h>
#include "ColaEstaCerradaException.h"

ColaBloqueante::ColaBloqueante() : esta_cerrada(false){}

void ColaBloqueante::encolar(const char recurso){
    std::unique_lock<std::mutex> lk(m);
    cola.push(recurso);
    cv.notify_all();
}

const char ColaBloqueante::desencolar(){
    std::unique_lock<std::mutex> lk(m);
    while (cola.empty()){
        if (esta_cerrada){
            throw ColaEstaCerradaException();
        }
        cv.wait(lk);
    }
    const char recurso = cola.front();
    cola.pop();
    return recurso;
}

void ColaBloqueante::cerrar(){
    std::unique_lock<std::mutex> lk(m);
    esta_cerrada = true;
    cv.notify_all();
}

ColaBloqueante::~ColaBloqueante() {}

